#!/usr/bin/python
#
# Solving an etch-a-sketch puzzle.
# bit4, June 2005.
#

import sys

# Puzzle representation:
#   rows = [[3,1],[4],[],...] -- The labels next to each row.
#   cols = [[1,2,1],[3],[],...] -- The labels next to each column.
# Terminology:
#   Square: the smallest element of the grid. A square can be painted
#          (filled, black, 1) or blank (empty, white, 0).
#   Segment: one consecutive block of painted squares. Each number in the puzzle
#          description represents one segment.
#   Row: a horizontal strip of squares spanning the full width of the grid.
#   Column: a vertical strip of squares spanning the full height of the grid.
#   Bar: a generic term for either a row or a column.
# Data structures used for solving:
#   col_maxs = the same structure as 'cols'; contains the maximal starting
#         row number possible for each vertical segment. Precalculated at
#         the start of the process.
#   row_maxs = the same structure as 'rows'; contains the maximal starting
#         column number possible for each horizontal segment. Precalculated
#         at the start of the process.
#   grid = contains the currently tested solution as a map of the board.
#         This is a list of lists of ints. 0 represents an empty square,
#         1 represents a filled square.
#   vseg_positions = the same structure as 'cols'; contains the currently tested
#         solution as the starting row number for each vertical segment.
#   row_constraints = contains constraints imposed by the row definitions
#         and the currently tested solution.
#         It has the same structure as grid, but contains 0 for "must be 0",
#         1 for "must be 1" and 2 for "don't care".
# The algorithm:
#  Treat all the vertical segments as one long list, starting at the topmost
#  segment of the left column, going down, then to the top of the 2nd column,
#  etc.
#  Start at the first segment and try each possible position for it in turn.
#  Every time a square is set to 1 or to 0, check it against the constraints
#  imposed by the row. If there is a contradiction, backtrack and try the
#  next position. Else (no contradiction), continue painting the segment.
#  When a segment is successfully placed in the grid, recursively find a
#  placement for the rest of the segments.
#  When the last segment has been placed, we found a solution.
#

MUST_BE_0, MUST_BE_1, MAY_BE_EITHER = 0, 1, 2 # Values for /row_constraints/

def load_etch(fname):
    """
    Load the puzzle txt file. Returns cols,rows.
    /cols/ and /rows/ are lists of lists of ints.
    """
    lines = open(fname).readlines()
    # get rid of newline chars and empty lines
    lines = filter(lambda line: line != "", [x.strip() for x in lines])
    # Find where the section boundaries are
    for i, line in enumerate(lines):
        if 'oriz' in line:
            horiz_start = i + 1
        if 'ertic' in line:
            vert_start = i + 1
    assert horiz_start < vert_start
    # Convert each one of the two sections to a list of lists of ints
    hlines = lines[horiz_start:vert_start-1]
    vlines = lines[vert_start:]
    rows = [map(int, line.split()) for line in hlines]
    cols = [map(int, line.split()) for line in vlines]
    return cols, rows
 
def make_grid(W, H):
    """Construct and return a grid, filled with zeros."""
    # Beware of shallow copy that would create duplicate references.
    return [[0] * W for row in range(H)] 

def calc_min_positions(bars):
    """
    Return a list of lists of ints filled with the minimal possible positions
    for the segments whose lengths are given in /bars/.
    """
    starts = []
    for bar in bars:
        s = [0]
        for n in xrange(len(bar) - 1):
            s.append(s[n] + bar[n] + 1)
        starts.append(s)
    return starts

def calc_max_positions(bars, min_positions, dim):
    """
    Return a list of lists of ints filled with the maximal possible positions
    for the given bars.
    /dim/ is the bar length.
    """
    max_starts = []
    for nbar in xrange(len(bars)):
        max_starts.append(min_positions[nbar][:])
        slack = dim - (min_positions[nbar][-1] + bars[nbar][-1])
        for nseg in xrange(len(bars[nbar])):
            max_starts[-1][nseg] += slack
    return max_starts

def calc_col_in_row_constraints(col):
    """
    Given that the columns to the left of /col/ contain some partial solution,
    calculate and fill column /col/ of /row_constraints/.
    """
    for row in xrange(H):
        # Count the segments currently in the row part that is left of column /col/
        # and get the length of the rightmost one.
        nsegs = 0
        rightmost_seg_len = 0
        prev_square = 0
        for c in xrange(col):
            if prev_square == 0 and grid[row][c] == 1:
                nsegs += 1
                rightmost_seg_len = 0
            prev_square = grid[row][c]
            rightmost_seg_len += grid[row][c] # Warning: dirty code
        if col == 0:
            in_segment = False
        else:
            in_segment = (grid[row][col-1] == 1)
        if in_segment:
            if rightmost_seg_len == rows[row][nsegs-1]:
                # We are immediately after the end of a segmnet
                row_constraints[row][col] = MUST_BE_0
            else:
                # We are inside a segment
                row_constraints[row][col] = MUST_BE_1
        else:
            if nsegs == len(row_maxs[row]):
                # All segments for this row are already in the grid.
                row_constraints[row][col] = MUST_BE_0
            else:
                if col == row_maxs[row][nsegs]:
                    # We cannot start the next segment more to the right than column /col/
                    row_constraints[row][col] = MUST_BE_1
                else:
                    # We still have the freedom to start the next segment either
                    # here or more to the right.
                    row_constraints[row][col] = MAY_BE_EITHER

def paint_segment(col, startrow, segmentlen):
    """
    Paint the squares of a vertical segment, starting at column /col/,
    row /startrow/, while checking for consistency with the row starts (the
    part of each row that spans from the left edge up to and including
    the just-painted square).
    return True if succeeded, False if this breaks some row constraint.
    """
    for row in xrange(startrow, startrow + segmentlen):
        if row_constraints[row][col] == MUST_BE_0:
            return False
        grid[row][col] = 1
    return True

def clear_bottom_of_col(col, row):
    """
    Fill the bottom part of column /col/, starting at row /row/ with 0s, verifying
    this does not violate any row countraint.
    return True if succeeded, False if failed because it violates some row constraint.
    """
    for r in xrange(row, H):
        if row_constraints[r][col] == MUST_BE_1:
            return False
        grid[r][col] = 0
    return True

def solve_from_segment(col, nseg):
    """
    try to find a solution for segment /nseg/ of column /col/ and recursively
    for all the segments below it and all the segments to the right of this column.
    Returns True if found a solution or False if failed.
    When returning True, /vseg_positions/ and /grid/ contain the found solution.
    When returning False, the head of /vseg_positions/ is intact and the
    tail (from segment /col/,/nseg/ onward) is garbage, and the same goes for /grid/
    """
    if nseg == 0:
        start_row = 0
    else:
        start_row = vseg_positions[col][nseg-1] + cols[col][nseg-1] + 1
    end_row = col_maxs[col][nseg] + 1
    for row in xrange(start_row, end_row):
        vseg_positions[col][nseg] = row # keep this in the global state to ease printing of the solution when it is found.
        # Fill the grid with the current segment while checking consistency with the rows.
        if row > 0:
            # Put a blank above the segment and check it for cosistency with its row.
            # Note that there is no need to fill the whole gap from the previous
            # segment down to the current row because the loop tries the rows in
            # ascending order.
            if row_constraints[row-1][col] == MUST_BE_1:
                return False
            grid[row-1][col] = 0
        # Try to paint the current segment at its corrent position.
        if paint_segment(col, row, cols[col][nseg]):
            # Suceeded in painting this segment.
            if nseg == len(cols[col]) - 1:
                # We are done with the current column.
                if col == len(cols)-1 and nseg == len(cols[col]) - 1:
                    # We've just succeeded with the last segment. A soultion was found!
                    return True
                # Complete the current column by filling below the last segment with blanks
                if not clear_bottom_of_col(col, row + cols[col][-1]):
                    continue
                # We are done with the current column. Initialize the next column.
                next_col, next_segment = col + 1, 0
                # Calculate the list of white/black/dontcare for the squares of the new
                # column, based on the current row starts.
                calc_col_in_row_constraints(next_col)
            else:
                next_col, next_segment = col, nseg + 1
            # Recursively find a solution starting with the next segment.
            # (we can optimize here by skipping all squares up to and including the
            # offending one, but that would complicate the code).
            if solve_from_segment(next_col, next_segment):
                return True
    # No more possible positions for column /col/, segment /nseg/. Backtracking.
    return False

def print_grid(grid):
    """Print the grid in a neat graphical way."""
    for row in grid:
        print "".join(['.#'[square] for square in row]) 
# ----------------------

# Load the puzzle definition
cols,rows = load_etch(sys.argv[1]) # To solve the level, pass 'up.txt' on the command line.

import time
start_time = time.clock()

# Create the data structures we will use for solving.
# These structures are global variables, as this is convenient and reasonable
# for a quick-and-dirty small program.
W,H = len(cols),len(rows)
grid = make_grid(W, H)
row_constraints = make_grid(W, H)
vseg_positions = calc_min_positions(cols)
col_maxs = calc_max_positions(cols, vseg_positions, H)
row_maxs = calc_max_positions(rows, calc_min_positions(rows), W)

# Calculate the list of white/black/dontcare for the squares of the
# first column, based on the rows info.
calc_col_in_row_constraints(0)
# Now go for the kill
if solve_from_segment(0,0):
    print 'Found a solution:'
    print_grid(grid)
else:
    print 'No soultion found.'

print 'Running time:', time.clock() - start_time, 'seconds (not including reading the data).'
