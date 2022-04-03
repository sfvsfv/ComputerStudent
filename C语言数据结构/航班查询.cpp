#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

struct SLNode
{
   char start[10]; //起点
   char end [10];//终点
   char sche[10];//班期
   char time1[6];//起飞时间
   char time2[6];//到达时间
   char model[4];//机型
   int price;//票价
   char keys[6]; //关键字（航班号）
};//航班记录类型
//静态链表节点类型


typedef struct
{ 
   SLNode *sl;//动态链表
   int listsize;//最大表长
   int length;//当前表长
}SLList;//顺序表类型


//显示一条航班记录函数
void Display(SLList L,int i)
{
   printf("航班号 起点站 终点站 航班期 起飞时间 到达时间 机型 票价\n");
   printf("%6s\t%6s\t%6s\t%6s\t%6s\t%6s\t%4s\t%d\n",L.sl[i].keys,L.sl[i].start,L.sl[i].end,L.sl[i].sche,L.sl[i].time1,L.sl[i].time2,L.sl[i].model,L.sl[i].price);
}


//顺序查找函数
void SeqSearch(SLList L,char key[],int i)
{
    int k,j,m=0;
    for(j=1;j<=L.length;j++)
{
       switch(i)
    {
        case 1:
             k=strcmp(key,L.sl[j].keys);
              break;
           case 2:
                k=strcmp(key,L.sl[j].start);
                break;//起点站
           case 3:
                k=strcmp(key,L.sl[j].end);
                break;//终点站
           case 4:
                k=strcmp(key,L.sl[j].time1);
                break;//起飞时间
           case 5:
                k=strcmp(key,L.sl[j].time2);
                break;//到达时间
    }

      if(k==0)
   {
           m=1;
           Display(L,j);
   }
}
    if(m==0)
{
        printf("无此航班信息，您可能输入错误！\n"); 
}
}



void del(SLList &L,char key[],int i)
{
    int k,j,m=0;
char ch;
    for(j=1;j<=L.length;j++)
{
       switch(i)
    {
        case 1:
             k=strcmp(key,L.sl[j].keys); break;
           case 2:
                k=strcmp(key,L.sl[j].start);break;//起点站
           case 3:
                k=strcmp(key,L.sl[j].end);break;//终点站
           case 4:
                k=strcmp(key,L.sl[j].time1);break;//起飞时间
           case 5:
                k=strcmp(key,L.sl[j].time2);break;//到达时间
    }

      if(k==0)
   {
           m=1;
           Display(L,j);
     printf("是否删除此记录？Y/N:");    
     scanf("%c",&ch);
     getchar();
     if(ch=='Y'||ch=='y')
     {
      strcpy(L.sl[j].keys,L.sl[L.length].keys);
      strcpy(L.sl[j].end,L.sl[L.length].end);    
               strcpy(L.sl[j].model,L.sl[L.length].model);
      L.sl[j].price=L.sl[L.length].price;
      strcpy(L.sl[j].sche,L.sl[L.length].sche);
      strcpy(L.sl[j].start,L.sl[L.length].start);
      strcpy(L.sl[j].time1,L.sl[L.length].time1);
      strcpy(L.sl[j].time2,L.sl[L.length].time2);
      L.length = L.length-1;;
      printf("删除成功!!\n");
     }
   }
}
    if(m==0)
{
        printf("无此航班信息，您可能输入错误！\n"); 
}
}




//查询检索菜单控制程序
void serachcon(SLList L) 
{
   int i=1;
   char key[10],kl[8];
   while(1)
   {
    printf("****************************\n");
       printf("*     航班信息查询系统     *\n");
       printf("****************************\n");
       printf("*        1.航 班 号        *\n");
       printf("*        2.起 点 站        *\n");
       printf("*        3.终 点 站        *\n");
       printf("*        4.起飞时间        *\n");
       printf("*        5.到达时间        *\n");
       printf("*        0.返    回        *\n");
       printf("****************************\n");
       printf("*         请输入(0—5):");
       scanf("%d",&i);
    getchar();
   if(i>=0 && i<=5)
   {
          
          switch(i)
    {
             case 1 :
                  printf("请输入要查询的航班号（字母要大写）:");
             scanf("%s",key); 
             getchar();
              SeqSearch(L,key,i);
             break;
             case 2 :
                  printf("请输入要查询的航班的起始站名:");
             scanf("%s",key);
             getchar(); 
             SeqSearch(L,key,i);
             break;
             case 3 :
                  printf("请输入要查询的航班的终点站名:");
             scanf("%s",key);
             getchar(); 
             SeqSearch(L,key,i);
             break;
             case 4 :
                  printf("请输入要查询的航班的起飞时间:");
             scanf("%s",kl);
             getchar(); 
             SeqSearch(L,kl,i);
             break;
             case 5 :
                  printf("请输入要查询的航班的到达时间:");
             scanf("%s",kl);
             getchar(); 
             SeqSearch(L,kl,i);
             break;
             case 0 :
                  return ;
    }
   }
else
    printf("您输入的信息错误!\n");

   
}
}



//输入航班记录函数
void InputData(SLList &L)
{

     int i;
char yn='y';
while(yn=='y'||yn=='Y')
{ 
   if(L.listsize<=L.length)
   {
      SLNode *newbase;
      newbase = (SLNode *)realloc(L.sl,(L.listsize+100)*sizeof(SLNode));
      if(!newbase)
    {
        printf("存储分配失败");
        return;
    } //存储分配失败
      L.sl = newbase;    //新基址
      L.listsize += 100; //增加存储容量
   }
         i=++L.length;
         printf("航班号 起点站 终点站 航班期 起飞时间 到达时间 机型 票价\n");
         scanf("%s %s %s %s %s %s %s %d",L.sl[i].keys,L.sl[i].start,L.sl[i].end,L.sl[i].sche,L.sl[i].time1,L.sl[i].time2,L.sl[i].model,&L.sl[i].price);        
         printf("继续输入吗?y/n:");
   getchar();
         scanf("%c",&yn);
   getchar();
}
}


void menu()
{ 
    printf("**********************************\n");
       printf("*     航班信息查询与检索系统     *\n");
       printf("**********************************\n");
       printf("*       1.输 入 航 班 信 息      *\n");
       printf("*       2.删 除 航 班 信 息      *\n");
       printf("*       3.查   询    信 息      *\n");
       printf("*       4.显 示 全 部 记 录      *\n");
       printf("*       0.退             出      *\n");
       printf("**********************************\n");
       printf("*         请输入(0—4):");    
}



void del_SNode(SLList &L)
{
getchar();
if(L.length>0)
{
       int i;
    char key[10],kl[8];
    while(1)
    {
      printf("*************************************\n");
         printf("*          航班信息删除系统         *\n");
         printf("*************************************\n");
         printf("*        1. 按 航 班 号 删 除       *\n");
         printf("*        2. 按 起 点 站 删 除       *\n");
         printf("*        3. 按 终 点 站 删 除       *\n");
         printf("*        4. 按 起飞时间 删 除       *\n");
         printf("*        5. 按 到达时间 删 除       *\n");
         printf("*        0. 返             回       *\n");
         printf("*************************************\n");
         printf("*         请输入(0—5):");
      scanf("%d",&i);
   getchar();
   
      if(i>=0 && i<=5)
   {
          
           switch(i)
     {
             case 1 :
                  printf("请输入要删除的航班号（字母要大写）:");
             scanf("%s",key); getchar(); del(L,key,i);
             break;
             case 2 :printf("请输入要删除的航班的起始站名:");
             scanf("%s",key); getchar();del(L,key,i);
             break;
             case 3 :printf("请输入要删除的航班的终点站名:");
             scanf("%s",key); getchar();del(L,key,i);
             break;
             case 4 :printf("请输入要删除的航班的起飞时间:");
             scanf("%s",kl); getchar();del(L,kl,i);
             break;
             case 5 :printf("请输入要删除的航班的到达时间:");
             scanf("%s",kl); getchar();del(L,kl,i);
             break;
             case 0 :return ;
     }
   }
      else
         printf("您输入的信息错误!\n");
    }
}
else printf("没有记录!\n");
}



void displayall(SLList L)
{
if(L.length>0)
{
      printf(" 航班号 起点站  终点站  航班期  起飞时间  到达时间 机型 票价\n");   
         for(int i=1;i<=L.length;i++)
   {
          printf("%6s\t%6s\t%6s %6s  %6s    %6s  %4s  %d\n",L.sl[i].keys,L.sl[i].start,L.sl[i].end,L.sl[i].sche,L.sl[i].time1,L.sl[i].time2,L.sl[i].model,L.sl[i].price);
   }
}
else printf("没有记录!\n");
}


int main()
{
int i;
SLList L;
L.sl=(SLNode *)malloc(100*sizeof(SLNode));
L.listsize=100;
L.length=0;
system("color 1f"); 
printf("*欢迎进入航班信息查询与检索系统!!!*\n"); 
while(1)
{
   menu();
   scanf("%d",&i);
   if(i <= 4&&i >= 0)
      {
    switch(i)
    {
          case 1: InputData(L);break;
             case 2: del_SNode(L);break;          
          case 3: serachcon(L);break;
          case 4: displayall(L);break;
          case 0: printf("谢谢使用，再 见!\n");break;
    }
   }
   else printf("您输入的信息错误!\n");
}
}
