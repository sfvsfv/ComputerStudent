
'''
游戏玩法：回车开始游戏；空格暂停游戏/继续游戏；方向键/wsad控制小蛇走向
'''
'''
思路：用列表存储蛇的身体；用浅色表示身体，深色背景将身体凸显出来；
蛇的移动：仔细观察，是：身体除头和尾不动、尾部消失，头部增加，所以，新添加的元素放在列表头部、删除尾部元素；
游戏结束判定策略：超出边界；触碰到自己的身体：蛇前进的下一格子为身体的一部分（即在列表中）。
'''
#注：因为在列表中需要频繁添加和删除元素，所以用deque容器代替列表；是因为deque具有高效的插入和删除效率
#初始化蛇，长度为3，放置在屏幕左上角；
#导包
import random
import sys
import time
import pygame
from pygame.locals import *
from collections import deque
#基础设置
Screen_Height=480
Screen_Width=600
Size=20#小方格大小
Line_Width=1
#游戏区域的坐标范围
Area_x=(0,Screen_Width//Size-1) #0是左边界，1是右边界 #注：python中//为整数除法；/为浮点数除法
Area_y=(2,Screen_Height//Size-1)
#食物的初步设置
#食物的分值+颜色
Food_Style_List=[(10,(255,100,100)),(20,(100,255,100)),(30,(100,100,255))]
#整体颜色设置
Light=(100,100,100)
Dark=(200,200,200)
Black=(0,0,0)
Red=(200,30,30)
Back_Ground=(40,40,60)
#文本输出格式设置
def Print_Txt(screen,font,x,y,text,fcolor=(255,255,255)):
    #font.render参数意义：.render（内容，是否抗锯齿，字体颜色，字体背景颜色）
    Text=font.render(text,True,fcolor)
    screen.blit(Text,(x,y))
#初始化蛇
def init_snake():
    snake=deque()
    snake.append((2,Area_y[0]))
    snake.append((1,Area_y[0]))
    snake.append((0,Area_y[0]))
    return snake
#食物设置
#注意需要对食物出现在蛇身上的情况进行判断
def Creat_Food(snake):
    '''
    注：randint 产生的随机数区间是包含左右极限的，
    也就是说左右都是闭区间的[1, n]，能取到1和n。
    而 randrange 产生的随机数区间只包含左极限，
    也就是左闭右开的[1, n)，1能取到，而n取不到。randint
    产生的随机数是在指定的某个区间内的一个值，
    而 randrange 产生的随机数可以设定一个步长，也就是一个间隔。
    '''
    food_x=random.randint(Area_x[0],Area_x[1]) #此处有疑问
    food_y=random.randint(Area_y[0],Area_y[1])
    #如果食物出现在蛇上，重来；
    while(food_x,food_y)in snake:
        food_x = random.randint(Area_x[0], Area_x[1])
        food_y = random.randint(Area_y[[0], Area_y[1]])
    return food_x,food_y
#食物风格
def Food_Style():
    return Food_Style_List[random.randint(0,2)] #返回随机的分值和颜色
def main():
    pygame.init()
    screen=pygame.display.set_mode((Screen_Width,Screen_Height)) #初始化一个准备显示的窗口或屏幕
    pygame.display.set_caption('贪吃蛇') #Set the current window caption
    #得分字体设置
    font1=pygame.font.SysFont('SimHei',24)
    #GO字体设置
    font2 = pygame.font.SysFont(None, 72)
    fwidth, fheight = font2.size('GAME OVER') ###
    #程序bug修复：如果蛇在向右移动，快速点击分别施加向下、向左的命令，向下的命令会被覆盖，只有向左的命令被接受，直接GameOver
    # b变量为了防止这个情况发生
    b=True
    #蛇
    snake=init_snake()
    #食物
    food=Creat_Food(snake)
    food_style=Food_Style()
    #方向控制
    pos=(1,0) ###
    #启动游戏相关变量初始化
    game_over=True  #结束标志 # 是否开始，当start = True，game_over = True 时，才显示 GAME OVER
    game_start=False    #开始标志
    score=0 #得分
    orispeed=0.3  #蛇初始速度
    speed=orispeed  #蛇速度
    last_move_time=None
    pause=False #暂停
    while True:
        for event in pygame.event.get():
            if event.type==QUIT:
                sys.exit()
            elif event.type==KEYDOWN:
                if event.key==K_RETURN:
                    if game_over:
                        game_start=True
                        game_over=False
                        b=True
                        snake=init_snake()
                        food=Creat_Food(snake)
                        food_style=Food_Style()
                        pos=(1,0)
                        #得分
                        score=0
                        last_move_time=time.time()
                elif event.key==K_SPACE:
                    if not game_over:
                        pause=not pause
                #以下为防止蛇在向右移动时按向左键，导致GameOver
                elif event.key in (K_UP,K_w):
                    if b and not pos[1]: ###
                        pos=(0,-1)
                        b=False
                elif event.key in (K_DOWN,K_s):
                    if b and not pos[1]:
                        pos = (0, 1)
                        b = False
                elif event.key in (K_LEFT,K_a):
                    if b and not pos[0]:
                        pos = (-1, 0)
                        b = False
                elif event.key in (K_RIGHT,K_d):
                    if b and not pos[0]:
                        pos = (1, 0)
                        b = False
        #填充背景色
        screen.fill(Back_Ground)
        ###
        #画网格线、竖线
        for x in range(Size, Screen_Width, Size):
            pygame.draw.line(screen, Black, (x, Area_y[0] * Size), (x, Screen_Height), Line_Width)
        #画网格线、横线
        for y in range(Area_y[0] * Size, Screen_Height, Size):
            pygame.draw.line(screen, Black, (0, y), (Screen_Width, y), Line_Width)
        #蛇的爬行过程
        if not game_over:
            curTime=time.time()
            if curTime-last_move_time>speed: ###
                if not pause:
                    b=True
                    last_move_time=curTime
                    next_s = (snake[0][0] + pos[0], snake[0][1] + pos[1])
                    #如果吃到了食物
                    if next_s==food:
                        snake.appendleft(next_s)
                        score+=food_style[0]
                        speed = orispeed - 0.03 * (score // 100)
                        food = Creat_Food(snake)
                        food_style = Food_Style()
                    else:
                        #在区域内
                        if Area_x[0]<=next_s[0]<=Area_x[1] and Area_y[0]<=next_s[1]<=Area_y[1] and next_s not in snake:
                            snake.appendleft(next_s)
                            snake.pop()
                        else :
                            game_over=True
        #画食物
        if not game_over:
         '''
        rect(Surface,color,Rect,width=0)
第一个参数指定矩形绘制到哪个Surface对象上

第二个参数指定颜色

第三个参数指定矩形的范围（left，top，width，height）

第四个参数指定矩形边框的大小（0表示填充矩形）

例如绘制三个矩形：

    pygame.draw.rect(screen, BLACK, (50, 50, 150, 50), 0)
    pygame.draw.rect(screen, BLACK, (250, 50, 150, 50), 1)
    pygame.draw.rect(screen, BLACK, (450, 50, 150, 50), 10)
         '''
        # 避免 GAME OVER 的时候把 GAME OVER 的字给遮住了
        pygame.draw.rect(screen, food_style[1], (food[0] * Size, food[1] * Size, Size, Size), 0)
        #画蛇
        for s in snake:
            pygame.draw.rect(screen, Dark, (s[0] * Size + Line_Width, s[1] * Size + Line_Width,
                                            Size - Line_Width * 2, Size - Line_Width * 2), 0)
        Print_Txt(screen, font1, 30, 7, f'速度: {score // 100}')
        Print_Txt(screen, font1, 450, 7, f'得分: {score}')
        #画GameOver
        if game_over:

            if game_start:
                #print('GameOver')
                Print_Txt(screen, font2, (Screen_Width - fwidth) // 2, (Screen_Height - fheight) // 2, 'GAME OVER',Red)
        pygame.display.update()
if __name__=='__main__':
    main()

