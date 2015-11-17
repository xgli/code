#!/usr/bin/env python
# coding=utf-8
import urllib2
import cookielib

''''
cookie = cookielib.CookieJar()
handler = urllib2.HTTPCookieProcessor(cookie)
opener = urllib2.build_opener(handler)
respose = opener.open('http://www.renren.com')
for item in cookie:
    print 'Name = ' + item.name
    print 'Vaule =' + item.value

'''
filename = 'cookie.txt'
cookie = cookielib.MozillaCookieJar(filename)

handler = urllib2.HTTPCookieProcessor(cookie)
opener = urllib2.build_opener(handler)
respose = opener.open("http://www.baidu.com")
cookie.save(ignore_discard=True,ignore_expires=True)

cookie = cookielib.MozillaCookieJar()
cookie.load('cookie.txt',ignore_discard=True,ignore_expires=True)
req = urllib2.Request("http://www.baidu.com")
opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cookie))
respose = opener.open(req)
print respose.read()

