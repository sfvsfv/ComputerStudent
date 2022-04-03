# coding=gbk
"""
作者：川川
公众号：玩转大数据
@时间  : 2022/2/3 2:10
群：428335755
"""
import os


def test_cmd():
    radio_list = ["https://www.bilibili.com/video/BV1EW411G7hp?from=search&seid=17441052249913049501",
                  ]#自定义视频链接

    for i in range(len(radio_list)):
        try:
            show_cmd = "you-get -i " + radio_list[i]
            print(show_cmd)
            os.system(show_cmd)
            print("开始下载：" + radio_list[i])

            download_cmd = "you-get --format=flv " + radio_list[i]
            print(download_cmd)
            res = os.system(download_cmd)
            print(res)
            print(radio_list[i] + "下载完成")
        except Exception:
            print("第" + str(i) + "个视频下载出现了错误")
            print("名字是：" + radio_list[i])


if __name__ == '__main__':
    test_cmd()

