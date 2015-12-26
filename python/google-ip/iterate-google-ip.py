#!/usr/bin/python

import get_google_ip_range
import threading
import nmap

class ip_thread(threading.Thread):
    def __init__(self,ip):
        threading.Thread.__init__(self)
        self.ip = ip
    def run(self):
        flag = is_open(self.ip)
        if flag:



    def is_open(ip):
        nm = nmap.PortScanner()
        nm.scan(ip,'443')
        try:
            if nm[ip].has_tcp(443):
                if nm[ip]['tcp'][443]['state']=='open':
                    return False
        except:
            return False
        return True

def string_ip_to_int(ip):
    ipv = ip.split('.')
    return ipv

def int_ip_to_string(ip):
    ret_ip = ""
    e = 1<<24
    while e>0:
        ret_ip += str(ip/e)
        if e>1:
            ret_ip += "."
        ip = ip%e
        e >>= 8
    return ret_ip

def iterate_ips():
    ip_segments = get_google_ip_range.get_ip_address_range()
    for ip_segment in ip_segments:
        split_ip = ip_segment.split('/')
        start_ip = string_ip_to_int(split_ip[0])
        int_ip = 0
        for element in start_ip:
            int_ip *= 256
            int_ip += int(element)
        for i in range(0,1<<(32-int(split_ip[1]))):
            print int_ip_to_string(int_ip+i)

if __name__=='__main__':
    iterate_ips()
