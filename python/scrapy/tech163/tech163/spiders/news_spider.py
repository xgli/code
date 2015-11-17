#!/usr/bin/env python
# coding=utf-8

import scrapy
import re
from scrapy.selector import Selector
from tech163.items import Tech163Item
from scrapy.linkextractors import LinkExtractor
from scrapy.spiders import CrawlSpider,Rule

class ExampleSpider(CrawlSpider):
    name = 'news'
    allowed_domains = ["play.163.com"]
    start_urls = ['http://play.163.com/']
    rules = (
        Rule(LinkExtractor(allow=r"/15/111\d+/\d+/*"),
        callback="parse_news",follow=True),
    )

    def printcn(uni):
        for i in uni:
            print uni.encode('utf-8')
    
    def parse_news(self,response):
        item = Tech163Item()
        item['news_thread']=response.url.strip().split('/')[-1][:-5]
        self.get_title(response,item)
        self.get_source(response,item)
        self.get_url(response,item)
        self.get_news_from(response,item)
        self.get_text(response,item)
        return item

    def get_title(self,response,item):
        title = response.xpath("/html/head/title/text()").extract()
        if title:
            item['news_title'] = title[0][:-5]

    def get_source(self,response,item):
        source = response.xpath("//div[@class='left']/text()").extract()
        if source:
            item['news_time']=source[0][:-5]

    def get_news_from(self,response,item):
        news_from = response.xpath("//div[@class='left']/a/text()").extract()
        if news_from:
            item['news_from']=news_from[0]
    
    def get_from_url(self,response,item):
        from_url = response.xpath("//div[@class='left']/a/@href").extract()
        if from_url:
            item['from_url'] = from_url[0]

    def get_text(self,response,item):
        news_body = response.xpath("//div[@id='endText']/p/text()").extract()
        if news_body:
            item['news_body'] = news_body

    def get_url(self,response,item):
        news_url = response.url
        if news_url:
            item['news_url'] = news_url


    


