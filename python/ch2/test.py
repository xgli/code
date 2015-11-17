#!/usr/bin/env python
# coding=utf-8

import operator

def file(filename):
    fr = open(filename)
    arrayLines = fr.readline()
    for line in arrayLines:
        print "%s" line
    
    return
