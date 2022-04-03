
#include "stdio.h"
#include<iostream>
using namespace std;
#define StackSize 100
typedef char ElemType;
typedef struct
{
    ElemType data[StackSize];
    int top;
}SqStack;
int trans(int d, int b, char string[])  //string用于存放转换后的字符串
{
    SqStack st;
    char ch;
    int r, i = 0;
    st.top = -1;      // 栈初始化
    if (b <= 1 || b > 36 || b == 10)  // 2≤b≤36且不为10
    {
        printf_s(" b is Error\n"); return 0;
    }
    while (d != 0)//辗转相除法
    {
        r = d % b; //求余数
        ch = r + (r < 10 ? '0' : 'A' - 10);  // 将余数转换为相应的字符
        st.top++;  st.data[st.top] = ch;   // 进栈
        d /= b;
    }
    while (st.top != -1)
    {
        string[i++] = st.data[st.top];   //将出栈的字符放入字符数组string
        st.top--;
    }
    string[i] = '\0';     //加入字符串结束标志
    return  1;
}
void main()
{
    while (1)
    {
        char str[10];
        int d, b, t;
        printf_s("请输入整数:");   //请输入待转换的整数
        scanf_s("%d", &d);
        printf("请输入要转换为几进制："); // 请输入待转换的进制
        scanf_s("%d", &b);
        t = trans(d, b, str);          // 调用进制转换函数
        cout << "进制转换结果为：";
        if (t == 0) printf("Error!");
        else printf("%s\n", str);      // 输出转换结果字符串
    }
}



