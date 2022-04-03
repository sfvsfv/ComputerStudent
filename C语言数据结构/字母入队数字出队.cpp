// 实验四.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#define QueueSize 100
typedef char ElemType;
typedef struct
{
    ElemType data[QueueSize];
    int front;//头
    int rear;//尾
}SqQueue;

//初始化
void InitQueue(SqQueue& qu)
{
    qu.rear = qu.front = 0;
}
//入队操作
int EnQueue(SqQueue& qu, ElemType e)
{
    if ((qu.rear + 1) % QueueSize == qu.front)
    {
        return 0;
    }
    qu.data[qu.rear] = e;
    qu.rear = (qu.rear + 1) % QueueSize;
    return 1;
}
//出队操作
int Dequeue(SqQueue& qu, ElemType& e)
{
    if (qu.rear == qu.front)
    {
        return 0;
    }
    e = qu.data[qu.front];
    qu.front = (qu.front + 1) % QueueSize;
    return 1;
}
//取对头操作
int GetHead(SqQueue qu, ElemType& e)
{
    if (qu.rear == qu.front)
    {
        return 0;
    }
    e = qu.data[qu.front];
    return 1;
}
//判断队列空
int QueueEmpty(SqQueue qu)
{
    return qu.rear == qu.front;
}
//判断队满
int QueueFull(SqQueue qu)
{
    return (qu.rear + 1) % QueueSize == qu.front;
}


int main()
{
    ElemType  e;
    SqQueue qu;
    InitQueue(qu);//初始化
    printf_s("请输入一串字符序列（以换行结束）:\n");
    for (int i = 0; i < QueueSize; i++)
    {
        scanf_s("%c", &e);
        if (e == '\n')
        {
            break;
        }
        else if ('a' <= e && e <= 'z' || 'A' <= e && e <= 'Z')
        {
            if (QueueFull(qu))
            {
                printf_s("队满，不能再进队了\n");
            }
            else
            {
                EnQueue(qu, e);
                printf_s("%c入队\n", e);
            }
        }
        else if ('0' <= e && e <= '9')
        {
            if (QueueEmpty(qu))
            {
                printf_s("队空，不能再出队\n");
            }
            else
            {
                Dequeue(qu, e);//出队
                printf_s("%c出队\n", e);
            }
        }
        else
        {
            printf_s("其它字符忽略%c", e);
        }
    }
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
