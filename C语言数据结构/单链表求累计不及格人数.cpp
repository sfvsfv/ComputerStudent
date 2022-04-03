#include<iostream>
#include<malloc.h>
#include <iomanip>
using namespace std;
typedef int ElemType;
#define M 20
typedef struct LNode
{
	ElemType data;	//定义数据与
	struct LNode* next;	//指针域
}LNode, * LinkList;
void CreateLink(LinkList& h, ElemType a[], int n)
{
	LinkList s, tc; int i;
	h = (LinkList)malloc(sizeof(LinkList));
	tc = h;
	for (i = 0; i < n; i++)
	{
		s = (LinkList)malloc(sizeof(LinkList));	//头节点创建
		s->data = a[i];
		tc->next = s;
		tc = s;
	}
	tc->next = NULL;
}
int Count(LinkList sl)
{
	int k = 0;
	LNode* p;
	if (sl->next == NULL)return 0;
	p = sl->next;

	//不及格判断
	while (p != NULL)
	{
		if (p->data < 60) { k++; }
		p = p->next;
	}
	return k;
}
//void main()
//{
//	int N;
//	//cout << "请输入学生人数：" << endl;
//	cout << "学生人数为：";
//	cin >> N;
//	LinkList head;
//	ElemType a[M];
//	int i, k;
//	cout << "请依次输入所有学生的成绩：" << endl;
//	for (i = 0; i < N; i++)
//		scanf_s("%d", &a[i]);
//	cout << "所有学生的成绩依次为：" << endl;
//	for (i = 0; i < N; i++)
//	{
//		cout << a[i] << setw(6);
//	}
//	cout << endl;
//	CreateLink(head, a, N);//创建单链表
//	k = Count(head);//调用求计数值的函数
//	cout << "所有学生的成绩中不及格的人数为：" << k << "人";
//	cout << endl;
//}
