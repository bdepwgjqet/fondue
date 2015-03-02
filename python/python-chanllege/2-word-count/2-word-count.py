#!/usr/bin/python

#get 'equality'
def brute_solve(s):
    ret={}
    for c in s:
        if ret.has_key(c):
            ret[c]=ret[c]+1
        else:
            ret[c]=1
    return ret

def beauty_solve(s):
    ret={}
    for c in s:
        ret[c]=ret.get(c,0)+1
    return ret

if __name__=='__main__':
    file=open('2.in')
    s=file.read()
    #print brute_solve(s)
    print beauty_solve(s)
