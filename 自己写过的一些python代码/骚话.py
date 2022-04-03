# coding=gbk
"""
作者：川川
公众号：玩转大数据
@时间  : 2022/2/3 0:33
群：428335755
"""

from urllib.request import urlopen
from bs4 import BeautifulSoup as Be
import urllib.parse
import string

def SAO():
    url = ("https://api.iyk0.com/sao/")
    urls = urllib.parse.quote(url,safe=string.printable)
    html = urlopen(f"{urls}")
    bs = Be(html,features="lxml")

    html_div = bs.findAll("body")
    print(html_div[0].get_text())

SAO()
