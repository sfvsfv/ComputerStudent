#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
typedef  struct NODE
{
	int bh;
	char* name;
	char* phone;
	struct NODE* pnext;
}Node;
int GetBh();//获得编号
char* GetName();//获得名字
char* GetPhone();//获得电话
Node* GetNode();//获得节点
char* GetString();//手动获得信息
Node* GetNodeIn();//手动获得节点
char GetKey();//获得关键字

void AddNode(Node** phead,Node** pend,Node* node);//添加节点
void InsertNode(Node** phead,Node** pend,Node* node,int bh);//插入节点
void DelNode(Node** phead,Node** pend,int bh);//删除节点
void GenerateInfo(Node** phead,Node** pend,int count);//生成信息

typedef struct PAGE
{
	int currentPage;
	int ItemPerPage;
	int totalPage;
	int totalItem;
}Page;
Page* GetPage(Node* phead);//统计分页信息
void ShowMenu(Page* page);//显示分页菜单
void ShowInfo(Node* phead,Page* page);//分页显示信息
void TurnPage(Node* phead,Page* page);//上下翻页

void ShowHomeMenu();//显示主菜单
void LookBook(Node* phead);//查看
void FindBook(Node* phead);//查询
void DelBook(Node* phead,Node* pend);//删除
void ChangeBook(Node* phead);//修改


int g_key;
int g_menu_type;
int main()
{
	Node* head=NULL;
	Node* end=NULL;

	srand((unsigned int)(time(0)));
	GenerateInfo(&head,&end,60);

	while(1)
	{
		ShowHomeMenu();
		switch(GetKey())
		{
			case '1':
				g_menu_type=1;
				LookBook(head);
				break;
			case '2':
				AddNode(&head,&end,GetNodeIn());
				break;
			case '3':
				g_menu_type=3;
				FindBook(head);
				break;
			case '4':
				g_menu_type=4;
				DelBook(head,end);
				break;
			case '5':
				g_menu_type=5;
				ChangeBook(head);
				break;
			case 'q':
				return 0;
				break;		
		}	
	}
	return 0;
}
int GetBh()//获得编号
{
	static int i=1;
	return i++;
}
char* GetName()//获得名字
{
	char*name=(char*)malloc(6);
	int i;
	for(i=0;i<5;i++)
	{
		name[i]=rand()%25+'a';		
	}
	name[5]=0;
	return name;
}
char* GetPhone()//获得电话
{
	int i;
	char* phone=(char*)malloc(12);
	switch(rand()%4)
	{
	case 0:
		strcpy(phone,"137");
		break;
	case 1:
		strcpy(phone,"139");
		break;
	case 2:
		strcpy(phone,"150");
		break;
	case 3:
		strcpy(phone,"159");
		break;
	}
	for(i=3;i<11;i++)
	{
		phone[i]=rand()%10+'0';
	}
	phone[11]=0;
	return phone;
}
Node* GetNode()//获得节点
{
	Node* node=(Node*)malloc(sizeof(Node));
	node->bh=GetBh();
	node->name=GetName();
	node->phone=GetPhone();
	node->pnext=NULL; 
	return node;
}
char* GetString()//手动获得信息
{
	char* str=(char*)malloc(5);
	int size=5;
	char* bj=str;
	char c;
	int count=0;
	char* newstr=NULL;

	while((c=getchar())!='\n')
	{
		*str=c;
		str++;
		count++;
		if(count+1==size)
		{
			size+=5;
			newstr=(char*)malloc(size);
			strcpy(newstr,bj);
			free(bj);
			bj=newstr;
			str=newstr+count;	
		}
	}
	*str=0;
	return bj;
}
Node* GetNodeIn()//手动获得节点
{
	Node* node=(Node*)malloc(sizeof(Node));
	node->bh=GetBh();
	printf("请输入学生姓名：");
	node->name=GetString();
	printf("请输入学生电话：");
	node->phone=GetString();
	node->pnext=NULL; 
	return node;
}

void AddNode(Node** phead,Node** pend,Node* node)//添加节点
{
	if(*phead==NULL)
	{
		*phead=node;
		*pend=node;
		return;
	}
	else
	{
		(*pend)->pnext=node;
		*pend=node;
		return;
	}
}
void InsertNode(Node** phead,Node** pend,Node* node,int bh)//插入节点
{
	Node* bj=*phead;
	if((*phead)->bh==bh)
	{
		node->pnext=*phead;
		*phead=node;
		return;
	}
	while(bj->pnext!=NULL)
	{
		if(bj->pnext->bh==bh)
		{
			node->pnext=bj->pnext;
			bj->pnext=node;
			return;		
		}
		bj=bj->pnext; 
	}
	(*pend)->pnext=node;
	*pend=node;
	return;
}
void DelNode(Node** phead,Node** pend,int bh)//删除节点
{
	Node* bj=*phead;
	Node* pDel=NULL;
	if((*phead)->bh==bh)
	{
		pDel=*phead;
		*phead=(*phead)->pnext;
		free(pDel);
		pDel=NULL;
		return;
	}
	while(bj->pnext!=NULL)
	{
		if(bj->pnext->bh==bh)
		{
			pDel=bj->pnext;
			bj->pnext=bj->pnext->pnext;   
			free(pDel);
			pDel=NULL;
			return;
		}
		if(bj->pnext->pnext=NULL)
		{
			pDel=bj->pnext;
			*pend=bj;  
			free(pDel);
			pDel=NULL;
			return;
		}
		bj=bj->pnext; 
	}
}
void GenerateInfo(Node** phead,Node** pend,int count)//生成信息
{
	int i;
	for(i=0;i<count;i++)
	{
		AddNode(phead,pend,GetNode());
	}
}

Page* GetPage(Node* phead)//统计分页信息
{
	Page* page=(Page*)malloc(sizeof(Page));
	page->currentPage=0;
	page->ItemPerPage=10;
	page->totalItem=0;
	while(phead)
	{
		page->totalItem++; 
		phead=phead->pnext; 
	}
	page->totalPage=(page->totalItem%page->ItemPerPage==0?page->totalItem/page->ItemPerPage:page->totalItem /page->ItemPerPage+1); 
	return page;
}
void ShowMenu(Page* page)//显示分页菜单
{
	switch(g_menu_type)
	{
	case 1:
		printf("当前第%d页  共%d页  共%d条  w上一页  s下一页  b返回 \n",page->currentPage,page->totalPage,page->totalItem);
		break;
	case 3:
		printf("当前第%d页  共%d页  共%d条  w上一页  s下一页  c查询  b返回 \n",page->currentPage,page->totalPage,page->totalItem);
		break;
	case 4:
		printf("当前第%d页  共%d页  共%d条  w上一页  s下一页   c查询  d删除 b返回 \n",page->currentPage,page->totalPage,page->totalItem);
		break;
	case 5:
		printf("当前第%d页  共%d页  共%d条  w上一页  s下一页   c查询  u修改  b返回 \n",page->currentPage,page->totalPage,page->totalItem);
		break;	
	}	
}
void ShowInfo(Node* phead,Page* page)//分页显示信息
{
	int begin=(page->currentPage-1)*page->ItemPerPage+1; 
	int end=(page->currentPage-1)*page->ItemPerPage+page->ItemPerPage; 
	int count=0;
	while(phead)
	{
		count++;
		if(count<=end&&count>=begin)
		{
			printf("%d  %s  %s \n",phead->bh,phead->name,phead->phone);
		}
		phead=phead->pnext; 
	}
}
void TurnPage(Node* phead,Page* page)//上下翻页
{
	char key='s';
	while(1)
	{
		switch (key)
		{
		case 'w':
			if(page->currentPage ==1)
			{
				printf("当前已经是第一页了！\n");
			}
			else
			{
				page->currentPage--;
				ShowInfo(phead,page);//分页显示信息
				ShowMenu(page);
			}
			break;
		case 's':
			if(page->currentPage ==page->totalPage )
			{
				printf("当前已经是最后一页了！\n");
			}
			else
			{
				page->currentPage++;
				ShowInfo(phead,page);//分页显示信息
				ShowMenu(page);
			}
			break;
		case 'b':
		case 'c':
		case 'd':
		case 'u':
			return;
			break;
		default:
			printf("请重新输入信息：");
			break;		
		}
		g_key=key=GetKey();
	}
}
char GetKey()
{
	char key;
	char c;
	int a=1;
	while((c=getchar())!='\n'||a==1)
	{
		key=c;
		a=0;
	}
	return key;
}

void ShowHomeMenu()//显示主菜单
{
	printf("1.查看\n");
	printf("2.添加\n");
	printf("3.查询\n");
	printf("4.删除\n");
	printf("5.修改\n");
	printf("q.退出\n");
}
void LookBook(Node* phead)//查看
{
	TurnPage(phead,GetPage(phead));
}
void FindBook(Node* phead)//查询
{
	char* keyword=NULL;
	char key;

	Node* bj=phead;

	Node* newnode=NULL;
	Node* newhead=NULL;
	Node* newend=NULL;
	Node* newbj=NULL;

	while(1)
	{
		//1.输入查询信息，按a确认
		while(1)
		{
			printf("请输入要查询得关键字：");
			keyword=GetString();

			printf("按a确认：");
			key=GetKey();
			if(key!='a')
			{
				printf("请重新输入要查询的关键字：");
				continue; 
			}
			else
			{
				printf("要查询得关键字是：");
				break;
			}					
		}
		//2.将查到的信息形成新的链表
		phead=bj;
		while(phead)
		{
			if(strncmp(keyword,phead->name,strlen(keyword))==0||strncmp(keyword,phead->phone,strlen(keyword))==0)
			{
				newnode=(Node*)malloc(sizeof(Node));
				newnode->bh=phead->bh;
				newnode->name=phead->name;
				newnode->phone=phead->phone;
				newnode->pnext=NULL;

				AddNode(&newhead,&newend,newnode);
			}
			phead=phead->pnext; 
		}
		//3.判断：（1）空链表，即是没找到（2）否则，找到了，查看一下，并释放空间，重新查询
		if(newhead==NULL)
		{
			printf("没找到相应信息！");
		}
		else
		{
			LookBook(newhead);

			while(newhead!=NULL)
			{
				newbj=newhead;
				newhead=newhead->pnext; 
				free(newbj);
				newbj=NULL;
			}

			if(g_key=='b'||g_key=='d'||g_key=='u')
			{
				return;
			}
		}
	}
}
void DelBook(Node* phead,Node* pend)//删除
{
	int bh;
	FindBook(phead);

	if(g_key=='b')
	{
		return;
	}
	printf("请输入要删除学生的编号：");
	bh=atoi(GetString());
	DelNode(&phead,&pend,bh);
}
void ChangeBook(Node* phead)//修改
{
	int bh;
	FindBook(phead);

	if(g_key=='b')
	{
		return;
	}
	printf("请输入要修改学生的编号：");
	bh=atoi(GetString());

	while(phead)
	{
		if(phead->bh==bh)
		{
			printf("请输入学生名字：");
			phead->name=GetString();
			printf("请输入学生电话：");
			phead->phone=GetString(); 
		}
		phead=phead->pnext; 
	}
}
