#!/usr/bin/env python
# coding=utf-8

import re
import os

def replace(fileName):
    fr = open(fileName)
    read = fr.read()
    fr.close()
    read = re.sub(r'</news_title>','\n',read)
    read = re.sub(r'<news_thread.*?thread>','',read)
    read = re.sub(r'<news_url.*?url>','',read)
    read = re.sub(r'<.*?>','',read)
    fw = open(fileName,'wb')
    fw.write(read)
    fw.close()
  

def dirreplace(dir):
    list = os.listdir(dir)
    for line in list:
        filepath = os.path.join(dir,line)
        replace(filepath)

    


if  __name__=='__main__':
    while(True):
         dir = raw_input("input the path:")
         dirreplace(dir)
         print 'OK'
    
