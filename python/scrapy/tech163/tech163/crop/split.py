#!/usr/bin/env python
# coding=utf-8

import os


def sp(fileName):
    fo = open(fileName, "r")
    os.chdir(fileName.split('/')[-2])
    subdir = (fileName.split('/')[-1]).split('.')[0]
    read = fo.read()
    strs = read.split('<news_title>')
    num = 0
    os.mkdir(subdir)
    os.chdir(subdir)
    for i in strs:
        fname = subdir + str(num) + ".txt"
        fw = open(fname, "w")
        fw.write(i)
        fw.close()
        num += 1
    fo.close()
    print "OK"
    os.chdir("../../")

if __name__ == '__main__':
    filePath = raw_input("filePath:")
    L = os.listdir(filePath)
    for l in L:
        fileName = os.path.join(filePath, l)
        print os.getcwd()
        sp(fileName)
