#!/usr/bin/env python
# -*- coding: utf-8 -*-

import tushare as ts

data = ts.get_today_all()
data.to_csv("test.csv", encoding="gbk")
