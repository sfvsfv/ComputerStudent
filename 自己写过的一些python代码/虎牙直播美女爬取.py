# coding=gbk
"""
作者：川川
公众号：玩转大数据
@时间  : 2022/2/3 2:24
群：428335755
"""
import requests
from lxml import etree
import time
import os
def mkdir(path):

    # 去除首位空格
    path = path.strip()
    # 去除尾部 \ 符号
    path = path.rstrip("\\")

    isExists = os.path.exists(path)

    # 判断结果
    if not isExists:
        os.makedirs(path)

        print(path + ' 创建成功')
        return True
    else:
        # 如果目录存在则不创建，并提示目录已存在
        print(path + ' 目录已存在')
        return False


# 定义要创建的目录
path = "图片\\"
# 调用函数
mkdir(path)

url='https://www.huya.com/g/4079/'
header={
 'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_13_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/65.0.3325.162 Safari/537.36'
}
response=requests.get(url=url,headers=header)#发送请求
# print(response.text)
data=etree.HTML(response.text)#转化为html格式
# print(data)
image_url=data.xpath('//a//img//@data-original')
image_name=data.xpath('//a//img[@class="pic"]//@alt')
# print(image_url)
for ur,name in zip(image_url,image_name):
    url=ur.replace('?imageview/4/0/w/338/h/190/blur/1','')
    title=name+'.jpg'
    response = requests.get(url=url, headers=header)  # 在此发送新的请求
    with open(path+title,'wb') as f:
        f.write(response.content)
    print("下载成功" + name)
    time.sleep(2)
