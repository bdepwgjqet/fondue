#!/bin/bash

HOME=/home/bdep__/code/fondue/www/

uwsgi --master --die-on-term --emperor $HOME/conf/uwsgi.ini
