#include<stdio.h>
int main()
{
	float c;
	int z = 0,f=0, n = 0, i = 0;//z为正数，f为负数，n为要输入的数，i控制最长多少
	printf_s("输入数据：");
	while (i<20&&i!='0')//循环判断
	{
		scanf_s("%d", &n);
		if (n == 0) break;
		else if (n > 0) z++;
		else f++;
	}
	printf_s("正数有%d个,负数有%d个", z, f);
}