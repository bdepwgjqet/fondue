#!/usr/bin/env python
# -*- coding: utf-8 -*-

import xlwt


def save_to_xls(dt=None,path=None):
    if dt is None or path is None:
        return None
    book = xlwt.Workbook()
    sheet = book.add_sheet("trade")

    for i,v1 in enumerate(dt):
        for j,v2 in enumerate(v1):
            sheet.write(i,j,v2)
    book.save(path)
