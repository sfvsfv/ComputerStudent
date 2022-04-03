#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)//用于屏蔽序号4996的错误
typedef struct phone
{
	char ID[10]; //编号
	char name[20]; //姓名
	char tel[15]; //电话
	char sex[2];//性别 
	char email[20]; //email邮箱 
}Ipa;//给存放通讯录属性的结构体取个别名

//链栈定义 
typedef struct List
{
	Ipa data;//数据域 
	struct List *next;//指针域 

}List;

List *L = NULL;//初始化为空 

//1.初始化通讯录,建立头节点
void InitList()
{
	L = (List *)malloc(sizeof(List));//创建头节点并且分配动态内存 
	L->next = NULL;//头结点下一个初始化为空 
	printf("初始化成功!\n");
}

//2.插入数据，建立通讯录（头插法），参考数据结构书上23页 
void CreateList_Head()
{
	List *node; //插入节点
	int count = 0;//初始化为0，用于记录数据条数 
	int flag = 1;//用于判断是否继续输入下一条记录
	while (flag)//为1就执行以下语句  
	{
		count++;
		node= (List *)malloc(sizeof(List));//创建头节点 
		printf("插入第%d条记录：\n", count);
		printf("ID：");
		scanf("%s", &(node->data.ID));//输入编号 
		//判断ID是否重复
		List *p = L->next;
		while (p)
		{
			//strcmp为比较函数 基本形式为strcmp(str1,str2)，若str1=str2，则返回零 
			if (strcmp(p->data.ID, node->data.ID) == 0)//比较当前编号是否与已有的编号对比 
			{
				printf("ID重复，请重新输入!\n");
				printf("ID：");//重新输入编号 
				scanf("%s", &(node->data.ID));
			}
			else
				p = p->next;//没重复则可跳到下一个位置执行 

		}
		//编号未冲突则开始信息录入 
		printf("姓名：");
		scanf("%s", &(node->data.name));
		printf("性别：");
		scanf("%s", &(node->data.sex));
		printf("电话：");
		scanf("%s", &(node->data.tel));
		printf("邮箱：");
		scanf("%s", &(node->data.email));
		node->next = L->next;
		L->next = node;
		printf("是否继续录入(1.继续 0.完成录入)：");
		scanf("%d", &flag);
		if (flag == 0)
			break;
	}
}

//3.插入数据，建立通讯录(尾插法)， 
void CreateList_Tail()
{
	List *node, *tail; //插入节点和尾节点
	tail = L;
	int count = 0;
	int flag = 1;
	while (flag)
	{
		count++;
		node = (List *)malloc(sizeof(List)); //给节点分配空间
		printf("录入第%d条数据：", count);
		printf("ID：");
		scanf("%s", &(node->data.ID));
		//判断ID是否重复
		List *p = L->next;
		while (p)
		{
			if (strcmp(p->data.ID, node->data.ID) == 0)
			{
				printf("ID重复，请重新输入!\n");
				printf("ID：");
				scanf("%s", &(node->data.ID));
			}
			else
				p = p->next;
		}
		printf("姓名：");
		scanf("%s", &(node->data.name));
		printf("性别：");
		scanf("%s", &(node->data.sex));
		printf("电话：");
		scanf("%s", &(node->data.tel));
		printf("邮箱：");
		scanf("%s", node->data.email);
		tail->next = node;
		node->next = NULL;
		tail =  node;
		printf("是否继续录入(1.继续 0：结束)：");
		scanf("%d", &flag);
		if (flag == 0)
			break;
	}
}

//4.删除数据(根据姓名删除)，即删除节点 
void DelList()
{
	List *p = L->next;//指向下一个 
	List *q = L;
	char ID[10];//编号范围不能超出十位数 
	printf("请输入要删除的ID：");
	scanf("%s", &ID);
	while (p && strcmp(p->data.ID, ID) != 0)//比较编号是否冲突 
	{
		p = p->next;
		q = q->next;
	}
	if (p)
	{
		q->next = p->next;
		printf("删除成功!\n");
		printf("被删除数据的信息为：\n");
		printf("ID：%s\n", p->data.ID);
		printf("姓名：%s\n", p->data.name);
		printf("性别：%s\n", p->data.sex);
		printf("电话：%s\n", p->data.tel);
		printf("邮箱：%s\n", p->data.email);
		free(p);//释放删除的p 
	}
	else
	{
		printf("通讯录中不存在此人信息！\n");
	}
}

//5.插入数据（前插法）
void InsertList_Pre()
{
	List *p, *q, *r, *node;
	p = L->next;
	q = L;
	char ID[10];
	printf("请输入要插入的位置(输入该位置的ID)：");
	scanf("%s", &ID);
	while (p && strcmp(p->data.ID, ID) != 0)//比较编号是否冲突 
	{
		p = p->next;
		q = q->next;
	}
	if (p != NULL)
	{

		//给新节点分配空间
		node = (List*)malloc(sizeof(List));
		//录入新节点数据
		printf("请输入新节点信息：\n");
	   judge:	
			printf("ID：");
			scanf("%s", &(node->data.ID));
			//判断ID是否重复
		    r = L->next;
		    while (r && strcmp(r->data.ID, node->data.ID) != 0)
			{
				r = r->next;
		    }
	  if (r != NULL)
	  {
		  printf("ID重复，请重新输入！\n");
		  //free(r); 这里不能free(r),如果释放r,会失去r的下一个节点的信息，链表会被破坏
		  goto judge;
	  }
	  printf("姓名：");
	  scanf("%s", &(node->data.name));
	   printf("性别：");
	  scanf("%s", &(node->data.sex));
	  printf("电话：");
	  scanf("%s", &(node->data.tel));
	  printf("邮箱：");
	  scanf("%s", &(node->data.email));
	}
	else
	{
		//如果没有该ID
		int choice1;
		printf("通讯录中未找到该ID,是否使用默认方式将新节点插入到最后(1.是 0.否)：");
		scanf("%d", &choice1);
		if (choice1 == 1)
		{
			//给新节点分配空间
			node = (List *)malloc(sizeof(List));
			//给新节点输入数据
			printf("请输入新节点信息：\n");
		judge1:
			printf("ID：");
			scanf("%s", &(node->data.ID));
			//判断ID是否重复
			r = L->next;
			while (r && strcmp(r->data.ID, node->data.ID) != 0)
			{
				r = r->next;
			}
			if (r != NULL) //ID重复
			{
				printf("ID重复,请重新输入!\n");
				goto judge1;
			}
			printf("姓名：");
			scanf("%s", &(node->data.name));
			printf("性别：");
			scanf("%s", &(node->data.sex));
			printf("电话：");
			scanf("%s", &(node->data.tel));
			printf("邮箱：");
			scanf("%s", &(node->data.email));
		}
		else
			return;
	}
	node->next = q->next;
	q->next = node;
	printf("插入成功！\n");
}

//6.插入数据（后插法）
void InsertList_Back()
{
	List *p, *r, *q, *node;
	p = L->next;
	q = L;
	char ID[10];
	printf("请输入要插入的位置(输入该位置的ID)：");
	scanf("%s", &ID);
	while (p && strcmp(p->data.ID, ID) != 0)
	{
		p = p->next;
		q = q->next;
	}
	if (p != NULL)
	{
		//为新节点分配空间
		node = (List*)malloc(sizeof(List));
		//为新节点输入数据
		printf("请输入新节点信息：\n");
	judge:
		printf("ID：");
		scanf("%s", &(node->data.ID));
		//判断ID是否重复
		r = L->next;
		while (r && strcmp(r->data.ID, node->data.ID) != 0)
		{
			r = r->next;
		}
		if (r != NULL)
		{
			printf("ID重复，请重新输入！\n");
			goto judge;
		}
		printf("姓名：");
		scanf("%s", &(node->data.name));
		printf("性别：");
		scanf("%s", &(node->data.sex));
		printf("电话：");
		scanf("%s", &(node->data.tel));
		printf("邮箱：");
		scanf("%s", &(node->data.sex));
		node->next = p->next;
		p->next = node;
		printf("插入成功！\n");
	}
	else
	{
		//通讯录中未找到该ID
		int choice2;
		printf("通讯录中未找到该ID,是否使用默认方式将该节点插入到最后(1.是 0.否)：");
		scanf("%d", &choice2);
		if (choice2 == 1)
		{
			//为新节点分配空间
			node = (List *)malloc(sizeof(List));
			//为新节点录入信息
			printf("请输入新节点信息：\n");
		judge1:
			printf("ID：");
			scanf("%s", &(node->data.ID));
			//判断ID是否重复
			r = L->next;
			while (r && strcmp(r->data.ID, node->data.ID) != 0)
			{
				r = r->next;
			}
			if (r != NULL) //ID重复
			{
				printf("ID重复，请重新输入！\n");
				goto judge1;
			}
			printf("姓名：");
			scanf("%s", &(node->data.name));
			printf("性别：");
			scanf("%s", &(node->data.sex));
			printf("电话：");
			scanf("%s", &(node->data.tel));
			printf("邮箱：");
			scanf("%s", &(node->data.email));
			node->next = q->next;
			q->next = node;
		}
		if (choice2 == 0)
			return;
	}
	
}

//7.修改通讯录数据
void UpdateList()
{
	List *p;//分配指针 
	p = L->next;
	char ID[10];
	printf("请输入要修改的ID:");
	scanf("%s", &ID);
	while (p && strcmp(p->data.ID, ID) != 0)//如果p真且编号不冲突 
	{
		p = p->next;//指向下一个 
	}
	if (p != NULL)//p为空条件下 
	{
		int choice;
		printf("请输入需要修改的属性(1.姓名 2.性别 3.电话 4.邮箱)：");
		scanf("%d", &choice);
		if (choice == 1)
		{
			printf("请输入新的姓名：");
			scanf("%s", &(p->data.name));
		}
		if (choice == 2)
		{
			printf("请输入新的联系人性别：");
			scanf("%s", &(p->data.sex));
		}
		if (choice == 3)
		{
			printf("请输入新的电话：");
			scanf("%s", &(p->data.tel));
		}
		if (choice == 4)
		{
			printf("请输入新的邮箱：");
			scanf("%s", &(p->data.email));
		}
		printf("更新成功！\n");
	}
	else
	{
		printf("通讯录中不存在该ID!\n");
		return;
	}
}

//8.查找通讯录中的数据（通过ID查找）
void SearchList()
{
	List *p;
	char ID[10];
	p = L->next;
	printf("请输入要查找的ID：");
	scanf("%s", &ID);
	while (p && strcmp(p->data.ID, ID) != 0)
	{
		p = p->next;
	}
	if (p == NULL)
	{
		printf("通讯录中不存在此人！\n");
		return;
	}
	else
	{
		printf("ID：%s\t", p->data.ID);
		printf("姓名：%s\t", p->data.name);
		printf("性别：%s\t", p->data.sex);
		printf("电话：%s\t", p->data.tel);
		printf("邮箱：%s\n", p->data.email);
	}
	
}

//9.遍历通讯录
void TraverseList()
{
	List *p;
	if (L == NULL)
	{
		printf("通讯录为空！\n");
		return;
	}
	else
	{
		p = L->next;
		printf("通讯录中全部信息如下：\n");
		while (p)//循环遍历 
		{
			printf("ID：%s\t", p->data.ID);
			printf("姓名：%s\t", p->data.name);
			printf("性别：%s\t", p->data.sex);
			printf("电话：%s\t", p->data.tel);
			printf("邮箱：%s\n", p->data.email);
			p = p->next;
		}
	}
}

//10.释放链表
void DestroyList()
{
	List *p, *q;
	p = L->next;
	while (p)
	{
		q = p;//用q暂时存放该节点
		p = p->next; //p指向下一个节点
		free(q);// 释放当前节点
		q = NULL;
	}
	free(p);
	free(L);
	L = NULL;
	printf("释放成功！\n");
}

void Menu()
{
	printf("\t\t\t****************************************************\n");
	printf("\t\t\t1.初始化通讯录                          2.建立通讯录\n");
	printf("\t\t\t3.删除联系人                            4.修改联系人\n");
	printf("\t\t\t5.查找联系人                            6.插入联系人\n");
	printf("\t\t\t7.遍历通讯录                            8.释放通讯录\n");
	printf("\t\t\t****************************************************\n");
}
int main()
{
	int choice;
	while (1)
	{
		Menu();
		printf("请选择菜单：");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
		{
			//初始化通讯录
			InitList();
			break;
		}
		case 2:
		{
			//建立通讯录
			int num;
			printf("请选择建立方式(1.头插法 2.尾插法):");
			scanf("%d", &num);
			if (num == 1)
			{
				//头插法
				CreateList_Head();
				break;
			}
			if (num == 2)
			{
				//尾插法
				CreateList_Tail();
				break;
			}
		}
		case 3:
		{
			//删除信息
			DelList();
			break;
		}
		case 4:
		{
			//修改信息
			UpdateList();
			break;
		}
		case 5:
		{
			//查找信息
			SearchList();
			break;
		}
		case 6:
		{
			//插入信息
			int num;
			printf("请选择插入方式(1.前插法 2.尾插法 3.后插法)：");
			scanf("%d", &num);
			if (num == 1)
			{
				//前插法
				InsertList_Pre();
				break;
			}
			if (num == 2)
			{
				//后插法
				InsertList_Back();
				break;
			}
		}
		case 7:
		{
			//遍历通讯录
			TraverseList();
			break;
		}
		case 8:
		{
			//释放通讯录
			DestroyList();
			break;
		}
		default:
			break;
		}
	}
}

