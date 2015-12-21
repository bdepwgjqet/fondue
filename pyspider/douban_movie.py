#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# Created on 2015-12-18 02:57:39
# Project: DoubanMovie

from pyspider.libs.base_handler import *
import re

class Handler(BaseHandler):
    crawl_config = {
    }

    @every(minutes=24 * 60)
    def on_start(self):
        self.crawl('http://movie.douban.com/tag/', callback=self.index_page)

    @config(age=10 * 24 * 60 * 60)
    def index_page(self, response):
        for each in response.doc('a[href^="http"]').items():
            if re.match("http://www.douban.com/tag/\d{4}/\?focus=movie$", each.attr.href):
                self.crawl(each.attr.href, callback=self.tag_page)

    @config(age=10 * 24 * 60 * 60)
    def tag_page(self, response):
#        for each in response.doc('a[href^="http"]').items():
 #           if re.match("http://movie.douban.com/subject/\d+", each.attr.href):
 #               self.crawl(each.attr.href, callback=self.detail_page)
        self.crawl(response.doc('.more-links').attr.href,callback=self.full_tag_page)
        
    @config(age=10 * 24 * 60 * 60)
    def full_tag_page(self, response):
        for each in response.doc('a[href^="http"]').items():
            if re.match("http://movie.douban.com/subject/\d+", each.attr.href):
                self.crawl(each.attr.href, callback=self.detail_page)
        self.crawl(response.doc('.next > a').attr.href, callback=self.full_tag_page)
                
    @config(priority=2)
    def detail_page(self, response):
        return {
            "url": response.url,
            "title": response.doc('title').text(),
            "cn_title": response.doc('[property="v:itemreviewed"]').text()
        }

