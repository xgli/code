#!/usr/bin/env python
# coding=utf-8
import sys
import re
import urllib2
import urllib
import requests
import cookielib

reload(sys)
sys.setdefaultencoding("utf8")

loginurl = 'http://10.3.8.211/'

logindomain = 'http://10.3.8.211'

class Login(object):
    def __init__(self):
        self.name = ''
        self.password = ''
        self.domain = ''

        self.cj = cookielib.LWPCookieJar()
        self.opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(self.cj))
        urllib2.install_opener(self.opener)

    def setLoginInfo(self,username,password,domain):
        self.name = username
        self.password = password
        self.domain = domain
    
    def login(self):
        loginparams = {'domain':self.domain,'DDDDD':self.name,'upass':self.password}
        headers = {'User-Agent':'Mozilla/5.0 (X11;Linux x86_64) AppleWebKit/537.36 (KHTML,like Geko) Ubuntu Chromium/45.0.2454.101 Safari/537.36'}
        filename = 'cookie.txt'
        cookie = cookielib.MozillaCookieJar(filename)
        opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cookie))
        req = urllib2.Request(loginurl,urllib.urlencode(loginparams),headers=headers) 
        result = opener.open(req)
        cookie.save(ignore_discard=True,ignore_expires=True)
        

        friendurl = 'http://friend.renren.com/managefriends'
        result = opener.open(friendurl)
        print result.read()
        
        '''''
        req = urllib2.Request(loginurl,urllib.urlencode(loginparams),headers=headers)
        response = urllib2.urlopen(req)
        self.operate = self.opener.open(req)
        thePage = response.read()
        print thePage
        '''
    
if __name__ == '__main__':
    userlogin = Login()
    username = '2015140473'
    password = 'lxg910807'
    domain = logindomain
    userlogin.setLoginInfo(username,password,domain)
    userlogin.login()
        


