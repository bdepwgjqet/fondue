#!/usr/bin/python
#refered to https://support.google.com/a/answer/60764?hl=zh-Hans

import os
import re

def get_spf_record():
    sh = os.popen('nslookup -q=TXT _spf.google.com 8.8.8.8')
    output = sh.read()
    pattern = re.compile(r'include:(.*?) ')
    match = pattern.findall(output)
    return match

def get_dns_record(spf):
    cmd = 'nslookup -q=TXT '+spf+' 8.8.8.8'
    sh = os.popen(cmd)
    output = sh.read()
    pattern = re.compile(r'ip4:(.*?) ')
    match = pattern.findall(output)
    return match


def get_ip_address_range():
    spf_record = get_spf_record()
    ips = []
    for spf in spf_record:
        dns_record = get_dns_record(spf)
        for ip in dns_record:
            ips.append(ip)
    print ips;
    return ips
