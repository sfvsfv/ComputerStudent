# coding=gbk
"""
作者：川川
公众号：玩转大数据
@时间  : 2022/2/3 0:35
群：428335755
"""
from pynput.mouse import Button, Controller
from pynput.keyboard import Key, Controller
import time

def input(content):

    keyboard = Controller()  # 开始控制键盘
    keyboard.type(content)  # content
    # 回车键，发送消息。点击和回车只能选一种，防止发生错误
    keyboard.press(Key.enter)


# 如果是win系统，可以选择使用点击功能，并且运行代码后将鼠标放在发送按钮上！
def click():  # 点击发送消息
    # 导入相应的库
    mouse = Controller()  # 开始控制鼠标
    mouse.press(Button.left)  # 按住鼠标左键
    mouse.release(Button.left)  # 放开鼠标左键


# number表示你要发多少条信息，content表示发送的内容
def main(number, content):
    # 此时暂停5s，方便你打开聊天窗，并把鼠标停放在发送按钮上
    time.sleep(5)
    for i in range(number):  # 用循环来控制你发送多少条消息
        input(content+str(i))
        # 通过点击按钮来发送
        # click()
        # 间隔时间
        time.sleep(0.6)


if __name__ == '__main__':
    main(100, "轰炸机来了！轰轰轰！！！")
