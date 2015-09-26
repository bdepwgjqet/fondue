#!/bin/bash

HOME=/home/bdep__/code/acmt/www/

uwsgi --master --die-on-term --emperor $HOME/conf/uwsgi.ini
