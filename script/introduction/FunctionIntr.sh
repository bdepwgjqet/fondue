#!/bin/sh
#vim: set sw=4 ts=4 et:

help()
{
cat << HELP
xtitlebar -- change the name of an xterm, gnome-terminal or kde konsole

USAGE: xtitlebar [-h] "string_for_titelbar"

OPTIONS: -h help text

EXAMPLE: xtitlebar "cvs"
HELP
	exit 0
}

# in case of error or if -h is given we call the function help:

[ -z "$1" ] && help

[ "$1" = "-h" ] && help

#send the escape sequence to change the xterm titelbar;

echo -e "33]0;$107"
