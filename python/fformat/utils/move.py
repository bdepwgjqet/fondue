#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# @author bdepwgjqet[at]gmail.com

import os

class bcolors:
    WHITE = '\033[1;37;40m'
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

def move(opath, npath, test):
    if opath != npath:
        if not os.path.exists(npath):
            print bcolors.OKBLUE + "success move file: " + bcolors.WHITE + opath, bcolors.HEADER + " -> ", bcolors.OKGREEN + npath
            if not test:
                os.rename(opath, npath)
        else:
            print bcolors.FAIL + "failed: " + bcolors.WHITE + "{} already exists: ".format(npath)

