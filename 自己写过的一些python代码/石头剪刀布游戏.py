"""
作者：川川
时间：2021/7/23
"""
# 石头剪刀布游戏
# 目标：创建一个命令行游戏，游戏者可以在石头、剪刀和布之间进行选择，与计算机 PK。如果游戏者赢了，得分就会添加，直到结束游戏时，最终的分数会展示给游戏者。
# 提示：接收游戏者的选择，并且与计算机的选择进行比较。计算机的选择是从选择列表中随机选取的。如果游戏者获胜，则增加 1 分。
import random
choices=["Rock","Paper","Scissors"] #石头剪刀布
computer=random.choice(choices)
player=False
cpu_score=0
player_score=0
while True:
    player =input("Rock,Paperor,Scissors?").capitalize()
    if player == computer:
        print("Tie!")
    elif player == "Rock":
        if computer == "Paper":
            print("You lose!",computer,"covers",player)
            cpu_score += 1
        else:
            print("You win!",player,"smashes",computer)
            player_score += 1
    elif player == "Paperor":
        if computer == "Scissors":
            print("You lose!",computer,"cut",player)
            cpu_score += 1
        else:
            print("Youwin!",player,"covers",computer)
            player_score += 1
    elif player == "Scissors":
        if computer == "Rock":
            print("You lose...",computer,"smashes",player)
            cpu_score += 1
        else:
            print("You win!",player,"cut",computer)
            player_score += 1
    elif player == 'E':
        print("Final Scores:")
        print(f"CPU:{cpu_score}")
        print(f"Plaer:{player_score}")
        break
    else:
        print("That's not avalid play.Check your spelling!")
    computer=random.choice(choices)

