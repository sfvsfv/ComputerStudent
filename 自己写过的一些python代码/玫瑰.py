# coding=gbk
"""
作者：川川
公众号：玩转大数据
@时间  : 2022/2/3 0:46
群：428335755
"""
# 绘制玫瑰花并添加文字
import turtle

# 设置画布大小
# turtle.screensize(canvwidth=None, canvheight=None, bg=None)
turtle.setup(width=0.6, height=0.6)
# 设置初始位置
turtle.penup()
turtle.left(90)
turtle.fd(200)
turtle.pendown()
turtle.right(90)

# 输出文字
printer = turtle.Turtle()
printer.hideturtle()
printer.penup()
printer.back(200)
printer.write("赠给亲爱的 猪猪\n\n", align="right", font=("楷体", 16, "bold"))
printer.write("from 宝宝", align="center", font=("楷体", 12, "normal"))

# 花蕊
turtle.fillcolor("red")
turtle.begin_fill()
turtle.circle(10, 180)
turtle.circle(25, 110)
turtle.left(50)
turtle.circle(60, 45)
turtle.circle(20, 170)
turtle.right(24)
turtle.fd(30)
turtle.left(10)
turtle.circle(30, 110)
turtle.fd(20)
turtle.left(40)
turtle.circle(90, 70)
turtle.circle(30, 150)
turtle.right(30)
turtle.fd(15)
turtle.circle(80, 90)
turtle.left(15)
turtle.fd(45)
turtle.right(165)
turtle.fd(20)
turtle.left(155)
turtle.circle(150, 80)
turtle.left(50)
turtle.circle(150, 90)
turtle.end_fill()

# 花瓣1
turtle.left(150)
turtle.circle(-90, 70)
turtle.left(20)
turtle.circle(75, 105)
turtle.setheading(60)
turtle.circle(80, 98)
turtle.circle(-90, 40)

# 花瓣2
turtle.left(180)
turtle.circle(90, 40)
turtle.circle(-80, 98)
turtle.setheading(-83)

# 叶子1
turtle.fd(30)
turtle.left(90)
turtle.fd(25)
turtle.left(45)
turtle.fillcolor("green")
turtle.begin_fill()
turtle.circle(-80, 90)
turtle.right(90)
turtle.circle(-80, 90)
turtle.end_fill()
turtle.right(135)
turtle.fd(60)
turtle.left(180)
turtle.fd(85)
turtle.left(90)
turtle.fd(80)

# 叶子2
turtle.right(90)
turtle.right(45)
turtle.fillcolor("green")
turtle.begin_fill()
turtle.circle(80, 90)
turtle.left(90)
turtle.circle(80, 90)
turtle.end_fill()
turtle.left(135)
turtle.fd(60)
turtle.left(180)
turtle.fd(60)
turtle.right(90)
turtle.circle(200, 60)

turtle.done()