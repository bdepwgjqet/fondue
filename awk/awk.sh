#!/bin/bash

#basic
awk -F "" '{print $1,$3}' data
awk '$1==0 && $3=="LISTEN" {print $0}' data
awk '$1==0 && $3=="LISTEN"' data

# regex

# end with .png
awk '$1 ~ /.png$/' data
