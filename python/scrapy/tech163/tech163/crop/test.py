#!/usr/bin/env python
# coding=utf-8

import pynlpir
from pynlpir import nlpir



pynlpir.open()

s = '北京邮电大学是一所美丽的学校'
print(pynlpir.segment(s))

nlpir.Exit()
