/*.已知有两个按元素值递增有序的顺序表A和B，设计一个算法将表A和表B的全部元素归并为一个按元素值非递减有序的顺序表C。
要求：
从键盘输入顺序表A和B的各元素，编程实现上述算法，输出顺序表A、顺序表B和顺序表C 的所有元素值 。*/


#include<stdio.h>
#include <stdlib.h>
#include<iomanip>
#include<iostream>
#pragma warning(disable:4996)
typedef int ElemType;
#define MAXSIZE 100
typedef struct shun
{
	ElemType data[MAXSIZE];
	int len;
}SqList;

void Mergelist_sq(SqList La, SqList Lb, SqList& Lc)//合并算法
{
	int i = 0, j = 0, k = 0;
	while (i < La.len && j < Lb.len)//当两个表都为扫描完的时候
	{
		if (La.data[i] < Lb.data[j])//如果表A的数据比表B的数据小
		{
			Lc.data[k] = La.data[i];	//把小的那个丢到C里面
			i++;//表A的位置也要+1，挪到下一个位置
			k++;//移动过去了，长度肯定+1
		}
		else if (La.data[i] > Lb.data[j])//同理
		{
			Lc.data[k] = Lb.data[j];
			j++;
			k++;
		}
		else//等于情况咯,两个都可以移动过去
		{
			Lc.data[k] = La.data[i]; i++; k++;
			Lc.data[k] = Lb.data[j]; j++; k++;
		}
	}
		while (i < La.len)//如果前面几次的移动还没移动完A，剩下的再插到C中
		{
			Lc.data[k] = La.data[i]; i++; k++;//为什么i,k加一？同上
		}
		while (j < Lb.len)//同理
		{
			Lc.data[k] = Lb.data[j]; j++; k++;
		}
		Lc.len = k;//	C顺序表合并后的实际长度
	
}


	int main()//编写主函数，传入数据
	{
		SqList sqa, sqb, sqc;//定义结构体变量
		int a, b;

		printf("请输入顺序表A的元素个数：");
		scanf_s("%d",&a);

		printf("请输入顺序表A的数据：");
		for (int i = 0; i < a; i++)//依次输入A数据
		{
			scanf_s("%d", &sqa.data[i]);
		}
		sqa.len = a;//A顺序表的长度
		printf("A顺序表的长度为：%d\n", sqa.len);


		printf("请输入顺序表B的元素个数：");
		scanf_s("%d",&b);
		printf("请输入顺序表B的数据：");
		for (int j = 0; j <b; j++)//依次输入B数据
		{
			scanf_s("%d", &sqb.data[j]);
		}
		sqb.len = b;//B顺序表的长度
		printf("B顺序表的长度为：%d", sqb.len);
		printf("\n");
		Mergelist_sq(sqa, sqb, sqc);//A,B的数据有了，调用函数把这两个表合并到空顺序表C中，C是空！！

		printf("A顺序表的元素为：");
		for (int i = 0; i <sqa.len; i++)
		{
			printf("%d", sqa.data[i]);
		}
		printf("\n");

		printf("B顺序表的元素为：");
		for (int j = 0; j <sqb.len; j++)
		{
			printf("%d", sqb.data[j]);
		}
		printf("\n");
		printf("C顺序表的元素为：");
		for (int n = 0; n < sqc.len; n++)
		{
			printf("%d", sqc.data[n]);
		} 


}