#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# @author bdepwgjqet[at]gmail.com

import re

def skip_by_root(folders, path):
    return len([d for d in folders if re.search('/'+d+'(/|$)', path)]) > 0

def skip_file(regexs, file_name):
    return len([r for r in regexs if re.search(r, file_name)]) > 0

def skip_folder(folders, folder_name):
    return folder_name in set(folders)
