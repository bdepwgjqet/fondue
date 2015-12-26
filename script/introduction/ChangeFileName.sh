#!/bin/bash

#we hava less than 3 arguments. Print the help text.
if [ $# -lt 3 ]; then
cat<<HELP
ren -- renames a number of files using sed regular expressions

USAGE: ren 'regexp' 'replacement' files...

EXAMPLE: rename all *.HTM files in *.html:

ren 'HTM$' 'html' *.HTM
HELP
exit 0
fi

old="$1"
new="$2"

shift
shift

for file in $*; do
	if [ -f "$file" ]; then
		newfile=`echo "$file" | sed "s/$old/$new/g"`
		if [ $newfile = $file ]; then
			continue
		fi
		if [ -f "$newfile" ]; then
			echo "ERROR: $newfile exists already"
		else
			echo "renaming $file to $newfile..."
			mv "$file" "$newfile"
		fi
	fi
done
