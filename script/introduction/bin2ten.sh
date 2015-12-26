#!/bin/bash

help()
{
	cat<<HELP
b2h -- convert binary to decimal

USAGE: b2h [-h] binarynum

OPTIONS: -h help text

EXAMPLE: b2h 111010

will return 58
HELP
	exit 0
}

error()
{
	#print an error and exit	
	echo "$1"
	exit 1
}

lastchar()
{
#return the las character of a string in $rval
	if [ -z "$1" ]; then
		rval=""
		return
	fi
#wc puts some space behind the output this is why we need sed
	numofchar=`echo -n "$1" | wc -c | sed 's/ //g'`
#now cut out the last char
	rval=`echo -n "$1" | cut -b $numofchar`
}

chop()
{
#remove the last character in string and return it in $rval
	if [ -z "$1" ]; then
		rval=""
		return
	fi

	numofchar=`echo -n "$1" | wc -c | sed 's/ //g'`

	if [ "$numofchar" = "1" ]; then
		rval=""
		return
	fi
	numofcharminus1=`expr $numofchar "-" 1`
	rval=`echo -n "$1" | cut -b 1-${numofcharminus1}`
}

while [ -n "$1" ]; do
case $1 in
	-h) help; shift 1;;
	--) shift; break;;
	-*) error "error: no such option $1. -h for help";;
	*) break;;
esac
done

sum=0
weight=1
#one arg must be given

[ -z "$1" ] && help

binnum="$1"
binnumorig="$1"

while [ -n "$binnum" ]; do
	lastchar "$binnum"
	if [ "$rval"="1" ]; then
		sum=`expr "$weight" "+" "$sum"`
	fi
	chop "$binnum"
	binnum="$rval"
	weight=`expr "$weight" "*" 2`
done

echo "binary $binnumorig is decimal $sum"
