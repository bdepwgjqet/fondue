#!/usr/bin/python

# Copyright for the following five classes by John Eriksson
# <http://arainyday.se/>, 2006. Originally written for the AStar
# library <http://www.pygame.org/projects/9/195/> and released into the
# public domain. Thanks a lot!


from PIL import Image


class Path:
    def __init__ (self, nodes, totalCost):
        self.nodes = nodes
        self.totalCost = totalCost

    def getNodes (self):
        return self.nodes

    def getTotalMoveCost (self):
        return self.totalCost


class Node:
    def __init__ (self, location, mCost, lid, parent = None):
        self.location = location
        self.mCost = mCost
        self.parent = parent
        self.score = 0
        self.lid = lid

    def __eq__ (self, n):
        if n.lid == self.lid:
            return 1
        else:
            return 0


class AStar:
    def __init__ (self, maphandler):
        self.mh = maphandler

    def _getBestOpenNode (self):
        bestNode = None

        for n in self.on:
            if not bestNode:
                bestNode = n
            elif n.score <= bestNode.score:
                bestNode = n

        return bestNode

    def _tracePath (self, n):
        nodes = []
        totalCost = n.mCost
        p = n.parent
        nodes.insert(0, n)

        while True:
            if p.parent is None:
                break

            nodes.insert(0, p)
            p = p.parent

        return Path(nodes, totalCost)

    def _handleNode (self, node, end):
        i = self.o.index(node.lid)
        self.on.pop(i)
        self.o.pop(i)
        self.c.append(node.lid)

        nodes = self.mh.getAdjacentNodes(node, end)

        for n in nodes:
            if n.location == end:
                return n
            elif n.lid in self.c:
                continue
            elif n.lid in self.o:
                i = self.o.index(n.lid)
                on = self.on[i];
                if n.mCost < on.mCost:
                    self.on.pop(i);
                    self.o.pop(i);
                    self.on.append(n);
                    self.o.append(n.lid);
            else:
                self.on.append(n);
                self.o.append(n.lid);

        return None

    def findPath (self, fromlocation, tolocation):
        self.o = []
        self.on = []
        self.c = []

        end = tolocation
        fnode = self.mh.getNode(fromlocation)
        self.on.append(fnode)
        self.o.append(fnode.lid)
        nextNode = fnode

        while nextNode is not None:
            finish = self._handleNode(nextNode, end)

            if finish:
                return self._tracePath(finish)

            nextNode=self._getBestOpenNode()

        return None


class SQ_Location:
    def __init__ (self, x, y):
        self.x = x
        self.y = y

    def __eq__ (self, l):
        if l.x == self.x and l.y == self.y:
            return 1
        else:
            return 0


class SQ_MapHandler:
    def __init__ (self, mapdata, width, height):
        self.m = mapdata
        self.w = width
        self.h = height

    def getNode (self, location):
        x = location.x
        y = location.y

        if x < 0 or x >= self.w or y < 0 or y >= self.h:
            return None

        d = self.m[(y * self.w) + x]

        if d == -1:
            return None

        return Node(location, d, ((y * self.w) + x));

    def getAdjacentNodes (self, curnode, dest):
        result = []
        cl = curnode.location
        dl = dest
        n = self._handleNode(cl.x + 1, cl.y, curnode, dl.x, dl.y)

        if n:
            result.append(n)

        n = self._handleNode(cl.x - 1, cl.y, curnode, dl.x, dl.y)

        if n:
            result.append(n)

        n = self._handleNode(cl.x, cl.y + 1, curnode, dl.x, dl.y)

        if n:
            result.append(n)

        n = self._handleNode(cl.x, cl.y - 1, curnode, dl.x, dl.y)

        if n:
            result.append(n)

        return result

    def _handleNode (self, x, y, fromnode, destx, desty):
        n = self.getNode(SQ_Location(x, y))

        if n is not None:
            dx = max(x, destx) - min(x, destx)
            dy = max(y, desty) - min(y, desty)
            emCost = dx+dy
            n.mCost += fromnode.mCost
            n.score = n.mCost + emCost
            n.parent = fromnode

            return n

        return None


def main ():
    img = Image.open("maze.png")
    maze = img.load()
    mapdata = []

    # Translate pixel data into something that AStar understands.

    for elt in img.getdata():
        if elt == (255, 255, 255, 255):
            mapdata.append(-1)
        else:
            mapdata.append(1)

    # Define start and destination points.

    mapdata[639] = 5
    mapdata[410241] = 6

    astar = AStar(SQ_MapHandler(mapdata, 641, 641))
    start = SQ_Location(639, 0)
    end = SQ_Location(1, 640)
    p = astar.findPath(start, end)
    data = []

    # Extract data from "logs".

    for node in p.nodes:
        if node.location.x % 2 and node.location.y % 2:
            data.append(chr(maze[node.location.x, node.location.y][0]))

    h = open("unzip-me.zip", "wb")
    h.write("".join(data))
    h.close()

if __name__=='__main__':
    main()
