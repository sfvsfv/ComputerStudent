#include<stdio.h>
#include<stdlib.h>

#define INF 10000
#define LEN sizeof(struct hua)

char a[100][100];  //表示迷宫的字符数组
int n, m;          //表示迷宫大小
int sx, sy;        //起点坐标
int gx, gy;        //终点坐标
int wei[100][100];   //到各个位置的最短距离的数组
int ax, ay;              //ax，ay为从队列前部取出的对应值
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
struct hua
{
    int nx;
    int ny;
    struct hua *next;
};

int main()
{
    int bfs(struct hua * head);
    int i;
    int res;
    struct hua * head;
    scanf("%d %d",&n,&m);    //输入迷宫大小n*m
    scanf("%d %d",&sx,&sy);  //输入起点
    scanf("%d %d",&gx,&gy);  //输入终点
    for(i=0;i<n;i++)
        scanf("%s",a[i]);
    head = (struct hua *) malloc(LEN);
    head->nx = sx;           //将起点坐标赋给第一个建立的链表首位
    head->ny = sy;
    head->next = NULL;
    res = bfs(head);
    if(res == INF)
        printf("无法到达");
    else
        printf("%d",res);
    return 0;
}

struct hua * push(int x, int y,struct hua * q)   //添加前需要尾指针
{
    struct hua * p3;
    p3 = (struct hua *) malloc(LEN);
    p3->nx = x;
    p3->ny = y;
    q->next = p3;
    p3->next = NULL;
    return p3;            //返回链表的尾指针
}

struct hua * pop(struct hua * w)       //取出需要头指针
{
    struct hua * head;
    ax = w->nx;
    ay = w->ny;
    head = w->next;
    free(w);
    return head;          //返回链表的头指针
}



int bfs(struct hua * head)
{
    int i, j;
    struct hua * c = head, * d = head;         //c定位头指针，d定位尾指针
    for(i=0;i<n;i++)        //把所有的位置都初始化为INF
        for(j=0;j<m;j++)
            wei[i][j] = INF;
    wei[sx][sy] = 0;         //主函数已加入起点位置，这里将距离起点设置为0
    while(c != NULL)   //不断循环直到队列无元素
    {
        c = pop(c);
        if(ax == gx && ay == gy)
            break;
        for(i=0;i<4;i++)   //四个方向循环
        {
            int ux = ax + dx[i];
            int uy = ay + dy[i];   //移动后的位置记ux，uy
            if(0<=ux && ux<n && 0<=uy && uy<m && a[ux][uy] != '#' && wei[ux][uy] == INF)   //判断是否可以移动以即是否已经访问过
            {
                if(c == NULL)
                {
                    c = d = (struct hua *) malloc(LEN);
                    c->nx = ux;
                    c->ny = uy;
                    d->next = NULL;
                }
                else
                d = push(ux, uy, d);
                wei[ux][uy] = wei[ax][ay] + 1;
            }
        }
    }
    return wei[gx][gy];
}

