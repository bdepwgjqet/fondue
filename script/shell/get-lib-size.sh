#!/bin/bash

pacman -Qi | awk -F ' ' '{if($1=="Name" || $1=="Installed") print $0}' > /tmp/tmp

awk '{if(NR%2==0){print $0} else {printf"%s ",$0}}' /tmp/tmp > /tmp/tmpret

sort -rn -t ":" -k 3,3 /tmp/tmpret
