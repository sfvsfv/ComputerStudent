from turtle import *
from time import sleep

title('爱你')


def go_to(x, y):
    up()
    goto(x, y)
    down()


def head(x, y, r):
    go_to(x, y)
    speed(1)
    circle(r)
    leg(x, y)


def leg(x, y):
    right(90)
    forward(180)
    right(30)
    forward(100)
    left(120)
    go_to(x, y - 180)
    forward(100)
    right(120)
    forward(100)
    left(120)
    hand(x, y)


def hand(x, y):
    go_to(x, y - 60)
    forward(100)
    left(60)
    forward(100)
    go_to(x, y - 90)
    right(60)
    forward(100)
    right(60)
    forward(100)
    left(60)
    eye(x, y)


def eye(x, y):
    go_to(x - 50, y + 130)
    right(90)
    forward(50)
    go_to(x + 40, y + 130)
    forward(50)
    left(90)


def big_Circle(size):
    speed(20)
    for i in range(150):
        forward(size)
        right(0.3)


def line(size):
    speed(1)
    forward(51 * size)


def small_Circle(size):
    speed(10)
    for i in range(210):
        forward(size)
        right(0.786)


def heart(x, y, size):
    go_to(x, y)
    left(150)
    begin_fill()
    line(size)
    big_Circle(size)
    small_Circle(size)
    left(120)
    small_Circle(size)
    big_Circle(size)
    line(size)
    end_fill()


def main():
    pensize(2)
    color('red', 'pink')
    head(-120, 100, 100)
    heart(250, -80, 1)
    go_to(200, -300)
    write("To: 智慧与美貌并存的", move=True, align="left", font=("楷体", 20, "normal"))
    done()


main()
