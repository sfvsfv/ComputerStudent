#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>	/*I/O函数*/
#include<stdlib.h>	/*其它说明*/
#include<string.h>	/*字符串函数*/

#define LEN 15		/* 学号和姓名最大字符数,实际请更改*/
#define N 50		/* 最大学生人数,实际请更改*/

int k = 1, n = 0, m = 0;/* n代表当前记录的学生人数*/

//函数声明
void readfile();
void seek();
void modify();
void insert();
void del();
void display();
void save();
void menu();

//结构体保存学生信息
struct student{
	char StudentId[LEN+1];
	char StudentName[LEN+1];
	int StudentAge;
	char StudentSex;
	float score[3];
}stu[N];

//主函数
int main()
{
	while (k)
	{
		menu();
	}
	system("pause");
	return 0;
}

//系统帮助函数
void help()
{
	printf("\n0.欢迎使用系统帮助！\n");
	printf("\n1.初次进入系统后,请先选择增加学生信息;\n");
	printf("\n2.按照菜单提示键入数字代号;\n");
	printf("\n3.增加学生信息后,切记保存;\n");
	printf("\n4.谢谢您的使用！\n");
}

//刷新文件
int flush(){
	char filename[LEN + 1];
	int i = 0;
	printf("请输入要刷新学生信息的文件名：\n");
	scanf("%s", filename);
	int j = 0;
	FILE * fp;
	if ((fp = fopen(filename, "r")) == NULL) return 0;
	//从文件读取信息 
	while (fscanf(fp, "%s %s %s %d %d %d %d ", &stu[j].StudentId, &stu[j].StudentName, &stu[j].StudentAge, &stu[j].StudentSex, &stu[j].score[0], &stu[j].score[1], &stu[j].score[2]) == 7) {
		j++;
	}
	n = j;
	printf("刷新成功!!!");
	return n;
}

//查找学生信息
void seek() /*查找*/
{
	int i, item, flag;
	char s1[21]; /* 以姓名和学号最长长度+1为准*/
	printf("------------------\n");
	printf("-----1.按学号查询-----\n");
	printf("-----2.按姓名查询-----\n");
	printf("-----3.退出本菜单-----\n");
	printf("------------------\n");
	while (1)
	{
		printf("请选择子菜单编号:");
		scanf("%d", &item);
		flag = 0;
		switch (item)
		{
		case 1:
			printf("请输入要查询的学生的学号:\n");
			scanf("%s", s1);
			for (i = 0; i<n; i++)
			if (strcmp(s1,stu[i].StudentId) == 0)
			{
				flag = 1;
				printf("学生学号\t学生姓名\t年龄\t性别\tC语言成绩\t高等数学\t大学英语成绩\n");
				printf("--------------------------------------------------------------------\n");
				printf("%s\t%s\t%d\t%6\t%.1f\t%.1f\t%.1f\n", stu[i].StudentId,stu[i].StudentName,stu[i].StudentAge,stu[i].StudentSex,stu[i].score[0],stu[i].score[1],stu[i].score[2]);
			}
			if (0 == flag)
				printf("该学号不存在！\n"); break;
		case 2:
			printf("请输入要查询的学生的姓名:\n");
			scanf("%s", s1);
			for (i = 0; i<n; i++)
			if (strcmp(stu[i].StudentName, s1) == 0)
			{
				flag = 1;
				printf("学生学号\t学生姓名\t年龄\t性别\tC语言成绩\t高等数学\t大学英语成绩\n");
				printf("--------------------------------------------------------------------\n");
				printf("%s\t%s\t%d\t%c\t%.1f\t%.1f\t%.1f\n", stu[i].StudentId, stu[i].StudentName, stu[i].StudentAge, stu[i].StudentSex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
			}
			if (0 == flag)
				printf("该姓名不存在！\n"); break;
		case 3:return;
		default:printf("请在1-3之间选择\n");
		}
	}
}

//修改学生信息
void modify() /*修改信息*/
{
	int i, item, num = -1;
	char sex1, s1[LEN + 1], s2[LEN + 1]; /* 以姓名和学号最长长度+1为准*/
	float score1;
	printf("请输入要要修改的学生的学号:\n");
	scanf("%s", s1);
	for (i = 0; i < n; i++){
		if (strcmp(stu[i].StudentId, s1) == 0){/*比较字符串是否相等*/
			num = i;
			printf("------------------\n");
			printf("1.修改姓名\n");
			printf("2.修改年龄\n");
			printf("3.修改性别\n");
			printf("4.修改C语言成绩\n");
			printf("5.修改高等数学成绩\n");
			printf("6.修改大学英语成绩\n");
			printf("7.退出本菜单\n");
			printf("------------------\n");
			while (1)
			{
				printf("请选择子菜单编号:");
				scanf("%d", &item);
				switch (item)
				{
				case 1:
					printf("请输入新的姓名:\n");
					scanf("%s", s2);
					strcpy(stu[num].StudentName, s2);
					break;
				case 2:
					printf("请输入新的年龄:\n");
					scanf("%d", stu[num].StudentAge);
					break;
				case 3:
					printf("请输入新的性别:\n");
					scanf("%s", &sex1);
					stu[i].StudentSex = sex1;
					break;
				case 4:
					printf("请输入新的C语言成绩:\n");
					scanf("%f", &score1);
					stu[num].score[0] = score1;
					break;
				case 5:
					printf("请输入新的高等数学成绩:\n");
					scanf("%f", &score1);
					stu[num].score[1] = score1;
					break;
				case 6:
					printf("请输入新的大学英语成绩:\n");
					scanf("%f", &score1);
					stu[num].score[2] = score1;
					break;
				case 7:	return;
				default:printf("请在1-7之间选择\n");
				}
			}
			printf("修改完毕！请及时保存！\n");
		}
		else{
			printf("没有该学生学号!!!");
		}
	}
}

void sort()//按学号排序
{
	int i, j, k, *p, *q, s;
	char temp[LEN + 1], ctemp;
	float ftemp;
	for (i = 0; i<n - 1; i++)
	{
		for (j = n - 1; j>i; j--)
		if (strcmp(stu[j - 1].StudentId, stu[j].StudentId)>0)
		{
			strcpy(temp, stu[j - 1].StudentId);
			strcpy(stu[j - 1].StudentId, stu[j].StudentId);
			strcpy(stu[j].StudentId, temp);
			strcpy(temp, stu[j - 1].StudentName);
			strcpy(stu[j - 1].StudentName, stu[j].StudentName);
			strcpy(stu[j].StudentName, temp);
			ctemp = stu[j - 1].StudentSex;
			stu[j - 1].StudentSex = stu[j].StudentSex;
			stu[j].StudentSex = ctemp;
			p = &stu[j - 1].StudentAge;
			q = &stu[j].StudentAge;
			s = *q;
			*q = *p;
			*p = s;
			for (k = 0; k<3; k++)
			{
				ftemp = stu[j - 1].score[k];
				stu[j - 1].score[k] = stu[j].score[k];
				stu[j].score[k] = ftemp;
			}
		}
	}
}

//添加学生信息函数
void insert() /*插入函数*/
{
	int i = n, j, flag;
	printf("请输入待增加的学生数:\n");
	scanf("%d", &m);
	if (m > 0){
		do
		{
			flag = 1;
			while (flag)
			{
				flag = 0;
				printf("请输入第%d位学生的学号:\n", i + 1);
				scanf("%s", stu[i].StudentId);
				for (j = 0; j < i; j++){
					if (strcmp(stu[i].StudentId, stu[j].StudentId) == 0){
						printf("该学号已存在，请重新输入！\n");
						flag = 1;
						break;
					}
				}
			}
			printf("请输入第%d 个学生的姓名:\n", i+1);
			scanf("%s", stu[i].StudentName);
			printf("请输入第%d 个学生的年龄:\n", i+1);
			scanf("%d", &stu[i].StudentAge);
			printf("请输入第%d 个学生的性别:\n", i+1);
			scanf(" %c", &stu[i].StudentSex);
			printf("请输入第%d 个学生的C语言成绩\n",i+1);
			scanf("%f", &stu[i].score[0]);
			printf("请输入第%d 个学生的高等数学成绩:\n", i+1);
			scanf("%f", &stu[i].score[1]);
			printf("请输入第%d 个学生的大学英语成绩:\n", i+1);
			scanf("%f", &stu[i].score[2]);
			if (0 == flag){
				i++;
			}
		} while (i<n + m);
	}
		n += m;
		printf("学生信息增加完毕！！！\n");
		system("pause");
}

//删除学生信息函数
void del()
{
	int i, j, flag = 0;
	char s1[LEN + 1];
	printf("请输入要删除学生的学号:\n");
	scanf("%s", s1);
	for (i = 0; i < n; i++){
		if (strcpy(stu[i].StudentId, s1) == 0){
			flag = 1;
			//要删除学生后面的学生往前移一位
			for (j = i; j < n - 1; j++){
				stu[j] = stu[j + 1];
			}
		}
	}
		//查找失败
		if (0 == flag){
			printf("该学号不存在!!!\n");
		}
		if (1 == flag){
			printf("删除成功！！！");
			//删除成功，学生人数减1
			n--;
		}
		system("pause");
}

//显示全部数据信息
void display()
{
	int i;
	printf("共有%d位学生的信息:\n", n);
	if (0 != n)
	{
		printf("学生学号 \t学生姓名 \t年龄   \t性别   \tC语言成绩\t高等数学 \t大学英语成绩\n");
		printf("--------------------------------------------------------------------\n");
		for (i = 0; i<n; i++)
		{
			printf("%s \t%s \t%d   \t%c   \t%.1f\t%.1f \t%.1f\n", stu[i].StudentId, stu[i].StudentName, stu[i].StudentAge, stu[i].StudentSex, stu[i].score[0],stu[i].score[1],stu[i].score[2]);
		}
	}
	system("pause");
}

void save(){
	int i;
	FILE *fp;
	char filename[LEN + 1];
	printf("请输入要保存的文件名：\n");
	scanf("%s", filename);
	fp = fopen(filename, "w");
	for (i = 0; i < n; i++){
		fprintf(fp, "%s%s%d%c%.lf%.lf%.lf\n", stu[i].StudentId, stu[i].StudentName, stu[i].StudentAge, stu[i].StudentSex,
			stu[i].score[0], stu[i].score[1], stu[i].score[2]);
	}
	printf("保存成功！！！\n");
	fclose(fp);
	system("pause");
}

void menu()/* 界面*/
{
	int num;
	printf(" \n\n                    \n\n");
	printf("  ******************************************************\n\n");
	printf("  *                学生信息管理系统                    *\n \n");
	printf("  ******************************************************\n\n");
	printf("*********************系统功能菜单*************************       \n");
	printf("     ----------------------   ----------------------   \n");
	printf("     *********************************************     \n");
	printf("     * 0.系统帮助及说明  * *  1.刷新学生信息   *     \n");
	printf("     *********************************************     \n");
	printf("     * 2.查询学生信息    * *  3.修改学生信息   *     \n");
	printf("     *********************************************     \n");
	printf("     * 4.增加学生信息    * *  5.按学号删除信息 *     \n");
	printf("     *********************************************     \n");
	printf("     * 6.显示当前信息    * *  7.保存当前学生信息*     \n");
	printf("     ********************** **********************     \n");
	printf("     * 8.退出系统        *                            \n");
	printf("     **********************                            \n");
	printf("     ----------------------   ----------------------                           \n");
	printf("请选择菜单编号:");
	scanf("%d", &num);
	switch (num)
	{
	case 0:help(); break;
	case 1:flush(); break;
	case 2:seek(); break;
	case 3:modify(); break;
	case 4:insert(); break;
	case 5:del(); break;
	case 6:display(); break;
	case 7:save(); break;
	case 8:
		k = 0; 
		printf("即将退出程序!\n");
		break;
	default:printf("请在0-8之间选择\n");
	}
}

