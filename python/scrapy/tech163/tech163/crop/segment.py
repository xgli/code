#!/usr/bin/env python
# coding=utf-8

import os
import pynlpir

def segment(fileName):
    fr = open(fileName,'r')
    read = fr.read()
    fr.close()
    pynlpir.open()
    dict = pynlpir.segment(read,pos_tagging=False)
    pynlpir.close()
    fw = open(fileName,'w')
    for i in dict:
        print(i)
        fw.write(i)
        fw.write(' ')
    fw.close()
  

def dirsegment(dir):
    list = os.listdir(dir)
    for line in list:
        filepath = os.path.join(dir,line)
        segment(filepath)


if  __name__=='__main__':
    while(True):
         dir = input("input the path:")
         dirsegment(dir)
         print ('OK')
    
