#!/usr/bin/python

import base64
import wave

def parse_voice():
    cont = open('input','r').read()
    record = open('first.wav','wb')
    wav = base64.b64decode(cont)
    record.write(wav)
    record.close()

def reverse_voise():
    in_wav = wave.open('first.wav','rb')
    out_wav = wave.open('second.wav','wb')
    out_wav.setparams(in_wav.getparams())
    for i in range(in_wav.getnframes()):
        out_wav.writeframes(in_wav.readframes(1)[::-1])
    in_wav.close()
    out_wav.close()


def brute_solve():
    parse_voice()
    reverse_voise()



if __name__=='__main__':
    brute_solve()
