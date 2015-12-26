#!/bin/sh
  
pgm -A -b -f selleradmin-hosts 'grep '$1' /home/admin/selleradmin/logs/selleradmin.log' > selleradmin-error.log

./auto-grep.sh selleradmin-error.log selleradmin.log $2
