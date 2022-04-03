from turtle import *

import math

hideturtle()

colormode(255)

def zongzi():

    pensize(2)

    pencolor(2, 51, 12)

    fillcolor(4, 77, 19)

    begin_fill()

    fd(200)

    circle(15, 120)

    fd(200)

    circle(15, 120)

    fd(200)

    circle(15, 120)

    fd(200)

    circle(15, 60)

    fd(100)

    circle(15, 90)

    fd(173)

    circle(1, 90)

    end_fill()

    penup()

    fd(100)

    right(60)

    back(105)

    a = pos()

    pendown()

    color(60, 67, 0)

    fillcolor(85, 97, 9)

    begin_fill()

    fd(120)

    goto(a)

    penup()

    back(15)

    left(90)

    fd(20)

    right(90)

    pendown()

    fd(150)

    right(120)

    fd(24)

    right(60)

    fd(120)

    right(60)

    fd(24)

    end_fill()

    begin_fill()

    left(110)

    fd(65)

    left(100)

    fd(24)

    left(80)

    fd(50)

    end_fill()



def ty(a,b,angle,steps,rotateAngle):

    minAngle = (2*math.pi/360) * angle / steps

    rotateAngle = rotateAngle/360*2*math.pi

    penup()

    setpos(b*math.sin(rotateAngle),-b*math.cos(rotateAngle))

    pendown()

    for i in range(steps):

        nextPoint = [a*math.sin((i+1)*minAngle),-b*math.cos((i+1)*minAngle)]

        nextPoint = [nextPoint[0]*math.cos(rotateAngle)-nextPoint[1]*math.sin(rotateAngle),

                     nextPoint[0]*math.sin(rotateAngle)+nextPoint[1]*math.cos(rotateAngle)]

        setpos(nextPoint)

# fillcolor(244, 244, 244)
''':cvar
用绿色盘 不用白色
'''
fillcolor('green')

begin_fill()

ty(300, 100, 360, 300, 0)

end_fill()

penup()

bk(40)

pendown()

color(229, 229, 229)
''':cvar
不要白色底盘
'''
# fillcolor(229, 229, 229)
# begin_fill()

ty(260, 60, 360, 300, 0)

end_fill()

pos_=pos()

zongzi()

penup()

goto(pos_)

seth(0)

bk(200)

right(90)

fd(30)

seth(0)

pendown()

zongzi()
''':cvar
画完图写文字
'''
hideturtle()
penup()
backward(230)
setx(40)
pendown()
write("端    午    安      康 ！", False, align="center", font=("Comic Sans", 30, "bold"))


done()