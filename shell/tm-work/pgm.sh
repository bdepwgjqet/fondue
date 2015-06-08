#!/bin/sh
  
pgm -A -b -f hosts 'grep '$1' path' > error.log

./auto-grep.sh error.log output.log $2
