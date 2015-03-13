#!/usr/bin/python

import email
import smtplib
import array
import md5

def send_mail():
    apology = email.Message.Message()
    apology.add_header('to','leopold.moz@pythonchallenge.com')
    apology.add_header('from','506729258@qq.com')
    apology.add_header('subject','Apology')
    apology.set_payload('Sorry!')
    print apology.as_string()
    server = smtplib.SMTP('localhost',1025)
    server.sendmail(apology['from'], apology['to'], apology.as_string())
    server.quit()

def gg(data, good_md5):
    allchars = map(chr, range(256))
    for i, oldch in enumerate(data):
        for newch in allchars:
            data[i] = newch
            if md5.new(data).hexdigest() == good_md5:
                return True
        data[i] = oldch
    return False

def gao():
#   send_mail() 
#   bbb8b499a0eef99b52c7f13f4e78c24b
    data = array.array("c",open("24-mybroken.zip","rb").read())
    gg(data,"bbb8b499a0eef99b52c7f13f4e78c24b")
    f = open("repaired.zip","wb")
    f.write(data)
    f.close()

if __name__=='__main__':
    gao()
