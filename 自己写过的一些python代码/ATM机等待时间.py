import random#导入随机模块
class ATM():        #定义ATM类对象
    def __init__(self, maxtime=10):          #初始化，定义最大操作时间10分钟
        self.t_max = maxtime    #maxtime传递给self.t_max

    def getServCompleteTime(self, start=0):             #定义实例 getServCompleteTime
        return start + random.randint(1, self.t_max)  #返回TM当次操作结束的时间，累加下次 ATM 操作时长，范围在 [1, maxtime] 之间。


class Customers():   #定义Customers类
    def __init__(self, n):  #初始化，设置客户库中总数 self.count 为 n，初始时剩余客户数 self.left 相同。
        self.count = n  #传递
        self.left = n

    def getNextArrvTime(self, start=0, arrvtime=10):  #定义实例 getNextArrvTime()
        if self.left != 0: #如果剩余不为0
            self.left -= 1 #执行下一个，剩余量就减少1
            return start + random.randint(1, arrvtime) #返回从某个时间点 start，累加下位客户到达银行需要的时间
        else:
            return 0

    def isOver(self):  #定义实例方法 isOver()，作用是判断客户库存是否清零,
        return True if self.left == 0 else False




c = Customers(100)   #假设有100个客户
a = ATM()   #a 表示 ATM机
wait_list = []      #等待列表
wait_time = 0       #客户总排队等候时间，第一个人初始为0
cur_time = 0        #当前时间，第一个人初始为0
cur_time += c.getNextArrvTime() #来一个人就要花费时间，所以当前时间就要增加，更新当前时间，我们调用getNextArrvtime
wait_list.append(cur_time) #第一位客户到达银行后，默认自动加入等待列表


while len(wait_list) != 0 or not c.isOver(): #当排队列表不为空，或者客户库存未清零时执行操作
    if wait_list[0] <= cur_time:  #如果排第一的客户到达时间比当前时间早，或者等于当前时间，就将客户移除列表去操作 ATM
        next_time = a.getServCompleteTime(cur_time) #返回在 cur_time 上累加操作 ATM 时长，即 ATM 在 next_time 才闲置
        del wait_list[0]
#由于 A 到达时间即是当前时间，也无其他客户，此时 A 无需排队，直接使用 ATM 机器。用 a.getServCompleteTime(cur_time) 获取 A 操作完 ATM 的时间，即 next_time。将 A 移除队列
    else:
        next_time = cur_time + 1   #如果排第一的客户在当前时间之后到达，那就是客户还在路上，ATM 闲置，时间逐步 +1 推进进程，直至客户抵达
#一种情况是提前，一种情况是迟到
    if not c.isOver() and len(wait_list) == 0:  #如果排队列表可能清零
        next_arrv = c.getNextArrvTime(cur_time)
        wait_list.append(next_arrv) #将客户提取至排队列表。
#第 2 个 if 语句：当前排队列表为空，从库存提取客户 B，用 c.getNextArrvTime(cur_time) 获取 B 到达时间，即 next_arrv，并增加至排队列表。

    if not c.isOver() and wait_list[-1] < next_time:#列表排最后的客户到达时间比当次 ATM 操作完毕的时间早，而且还有客户库存
        next_arrv = c.getNextArrvTime(wait_list[-1])#最后一个客户到达时间
        wait_list.append(next_arrv)#将客户提取至排队列表。
        while next_arrv < next_time and not c.isOver():#最后的客户到达时间比当次 ATM 操作完毕的时间迟
            next_arrv = c.getNextArrvTime(next_arrv)#下一个客户到达时间
            wait_list.append(next_arrv)#提取客户到排队列表
#根据判断条件 wait_list[-1] < next_time，而队列中 B 到达时间比当前 next_time 迟，故不执行操作

    for i in wait_list:#遍历列表，统计排队列表中每位客户的等待时间
        if i <= cur_time:
            wait_time += next_time - cur_time
        elif cur_time < i < next_time:
            wait_time += next_time - i
        else:
            pass

    cur_time = next_time    #将 ATM 机器下次执行完毕时间 赋给 当前时间

print(wait_time / c.count)##当库存清零，总时间除以人数计算平均等待时间，每次结果可能不一样，因为每个客户等待时间是随机的




