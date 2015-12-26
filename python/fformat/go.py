#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# @author bdepwgjqet[at]gmail.com

import os
import re
import settings as cfg
import utils.name as xname
import utils.skip as skip
import utils.move as move

skipd = cfg.skip_folders
skipf = cfg.skip_files
xsep = cfg.exist_separators
tsep = cfg.target_separator
test = cfg.test_mode

for root, dirs, files in os.walk(cfg.root, topdown=False):
    if skip.skip_by_root(skipd, root):
        continue
    dirs = [d for d in dirs if not skip.skip_folder(skipd, d)]
    files = [f for f in files if not skip.skip_file(skipf, f)]
    for file in files:
        nfile = xname.replace_file_sep(file, xsep, tsep)
        nfile = xname.drop_camel_case(nfile, tsep)
        opath = os.path.join(root,file)
        npath = os.path.join(root,nfile)
        move.move(opath, npath, test)
    for dir in dirs:
        ndir = xname.replace_folder_sep(dir, xsep, tsep)
        ndir = xname.drop_camel_case(ndir, tsep)
        opath = os.path.join(root,dir)
        npath = os.path.join(root,ndir)
        move.move(opath, npath, test)
