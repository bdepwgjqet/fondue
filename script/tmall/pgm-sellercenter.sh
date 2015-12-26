#!/bin/sh
  
pgm -A -b -f sellercenter-hosts 'grep '$1' /home/admin/sellercenter/logs/sellercenter.log' > sellercenter-error.log

./auto-grep.sh sellercenter-error.log sellercenter.log $2
