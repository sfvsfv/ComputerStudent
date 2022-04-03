#include<stdio.h>

#pragma warning(disable:4996)
using namespace std;
#define  MAXSIZE  20
typedef  int  ElemType;
typedef  struct
{
    ElemType  data[MAXSIZE];//最长为20个
    int   len;
} SqList;//定义结构体变量
void move(SqList & sq)
{
    ElemType t;
    int i = 0, j = sq.len - 1;
    while (i <= j)
    {
        while (sq.data[i] % 2 == 0) i++;  //从左向右找到奇数sq.data [i]
        while (sq.data[j] % 2 == 1) j--;  //从右向左找到偶数sq. data [j]
        if (i < j) 
        {
            t = sq.data[i];//偶数用t暂代替
            sq.data[i] = sq.data[j];//把j放到i位置
            sq.data[j] = t;//t就放到j位置
            i++; j--;//i就增加一位，j就减少一位
        }
    }
}
int main()
{
    SqList  sqA;
    int i,num;
    printf("请输入你要输入的数据个数：");
    scanf("%d", &num);
    for (i = 0; i <num; i++)
    {
   
        printf("顺序表第%d个元素", i);
        scanf("%d", &sqA.data[i]);
    }
    sqA.len = num;
    move(sqA);       //调用move完成移动
    printf("奇偶排序后顺序表A中的元素为：");
    for (i = 0; i <num; i++)//遍历数组依次打印
        printf("% 5d", sqA.data[i]);
}


