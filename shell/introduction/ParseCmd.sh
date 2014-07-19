#!/bin/bash

help()
{
cat << HELP
	This is a generic command line parser demo.
	USAGE EXAMPLE: cmdparser -l hello -f -- -somefile1 somefile2
HELP
HELP
}

while [ -n "$1" ]; do
	case $1 in
		-h) help; shift 1;;
		-f) opt_f=1; shift 1;;
		-l) opt_l=$2; shift 2;;
		--) shift; break;;
		-*) echo "error: no such option $1. -h for help"; exit 1;;
		*) break;;
	esac
done

echo "opt_f is $opt_f"
echo "opt_l is $opt_l"
echo "first arg is $1"
echo "2nd arg is $2"
