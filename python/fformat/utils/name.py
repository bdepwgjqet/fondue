#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# @author bdepwgjqet[at]gmail.com

import re

def pre_seps(seps):
    metas = ['^', '$', '*', '+', '?', '.', '|', '\\' ]
    return ['\\'+x if x in metas else x for x in seps]

def replace_file_sep(file, old_seps, new_sep):
    old_seps = pre_seps(old_seps)
    if file.find('.') < 0:
        return replace_folder_sep(file,old_seps,new_sep)
    name_section = new_sep.join(file.split('.')[:-1])
    type_section = file.split('.')[-1]
    return re.sub("|".join(old_seps), new_sep, name_section) + "." + type_section

def replace_folder_sep(folder, old_seps, new_sep):
    old_seps = pre_seps(old_seps)
    return re.sub("|".join(old_seps), new_sep, folder)

def drop_camel_case(name, sep):
    name = re.sub(r'([a-z]+)(?=[A-Z][a-z]*)', r'\1'+sep, name) #FileName or fileName
    name = re.sub(r'([A-Z]+)(?=[A-Z][a-z]+)',r'\1'+sep, name)   #FILEName
    return name.lower()
