#!/bin/sh
  
pgm -A -b -f sellermanager-hosts 'grep '$1' /home/admin/sellermanager/logs/sellermanager.log' > sellermanager-error.log

./auto-grep.sh sellermanager-error.log sellermanager.log $2
