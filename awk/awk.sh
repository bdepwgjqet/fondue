#!/bin/bash

awk -F "" '{print $1,$3}' data
awk '$1==0 && $3=="LISTEN" {print $0}' data
awk '$1==0 && $3=="LISTEN"' data
