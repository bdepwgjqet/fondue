#!/bin/bash

iconv -f cp936 -t utf-8 $1 > $2

grep -rn --color=always $3 $2
