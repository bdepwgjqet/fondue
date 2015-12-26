#!/usr/bin/env python
# -*- coding: utf-8 -*-

# following settings will replace all the files like:
# FileName.ft, file_name.ft, file_Name.ft etc...
# to be file-name.ft

# set the root folder you want to format
root = "/home/bdep__/code/fondue/"

# exist separators
exist_separators = ['_', '.']

# target separator
target_separator = '-'

# if keep the file with camel case style
keep_camel_case = False

# skip folder names
skip_folders = [".git", "www", "hadoop"]

# skip file regex
skip_files = ["__", ".*?\.pyc", ".*?\.java", ".*?\.jar", ".*?\.swp", "README"]

# True: will only show, not really rename, use this first
# False: show and rename
test_mode = True
