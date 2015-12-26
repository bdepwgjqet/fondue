#!/bin/bash

help()
{
	cat<<HELP
b2h -- conver binary to decimal

USAGE: b2h [-h] binarynum

OPTIONS: -h help text

EXAMPLE: b2h 111010

will return 58
HELP
	exit 0
}

error()
{
	echo $1;
	exit 1
}

while [ -n "$1" ]; do
	case $1 in
	-h) help; shift 1;;
	--) shift 1;;
	-*) error "error: no such option $1. -h for help";;
	*) break;
	esac
done

num=$1
cnt=`echo -n "$num" | wc -c | sed 's/ //g'`
ans=0

for (( i=1; i<=$cnt; i++ )); do
	bit=`echo -n $num | cut -b $i`
	ans=`expr "$ans" "*" 2`
	ans=`expr "$ans" "+" "$bit"`
done

echo "The decimal of $num is $ans"
