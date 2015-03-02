#!/bin/python2.7

import urllib2
import re
import string

def get_stock_data(code):
    pre_code = ""
    if int(code)>=600000:
        pre_code = "sh"
    else: 
        pre_code = "sz"
    url = 'http://hq.sinajs.cn/list='+pre_code+code
    response = urllib2.urlopen(url)
    html = response.read().decode('gb2312')
    pattern = re.compile(r'"(.*?)"')
    match = pattern.findall(html)
    price = match[0].split(",")
    return price

def get_code():
    file_name = 'concern.in'
    f = open(file_name)
    codes = f.read()
    code = codes.rstrip('\n').split('\n')
    return code

def show_price(stock_name,price):
    result_str = stock_name+"\t"
    now = float(price[3])
    preday = float(price[2])
    result_str += price[2]+"\t" # pre_day_close
    result_str += price[1]+"\t" # today_open
    result_str += price[5]+"\t" # lowest
    result_str += price[4]+"\t" # highest
    result_str += price[3]+"\t" # now
    result_str += "%.2f" % ((now-preday)/preday*100)+"%"
    print result_str

def filter_data():
    codes = get_code()
    for code in codes:
        code_arr = code.split(' ')
        prices = get_stock_data(code_arr[0])
        show_price(code_arr[1],prices)

if __name__=='__main__':
    filter_data()
