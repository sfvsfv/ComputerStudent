
#include <stdio.h>
#include <malloc.h>
typedef char ElemType;//二叉树数组类型为字符

//二叉树定义
typedef struct node
{
	ElemType data;//节点信息
	struct node* lchild, * rchild;//左右儿子,增加,*parent双亲指针就是三叉链
}Bnode,*BTree;
//初始化二叉链
void InitBTree(BTree& BT)
{
	BT = NULL;
}
//创建二叉链
void CreateBTree(BTree &BT)//分别指向左右
{
	char data;
	data = getchar();
	if (data == '#')	BT = NULL;
	else
	{
		BT = (BTree)malloc(sizeof(Bnode));//分配空间
		BT->data = data;
		CreateBTree(BT->lchild);//分别创建左右节点
		CreateBTree(BT->rchild);
	}
}
//void visit(BTree p)
//{
//	printf_s("%c", p->data);//访问根节点
//}
//先序（根）遍历
void preorder(BTree p)
{
	if (p != NULL)
	{
		//visit(p);
		printf_s("%c", p->data);//访问根节点
		preorder(p->lchild);//遍历左
		preorder(p->rchild);//遍历右
	}
}
//中序（根）遍历
void inorder(BTree p)
{
	if (p != NULL);
	{
		inorder(p->lchild);//中根顺序遍历左子树
		//visit(p);//访问根节点
		printf_s("%c", p->data);//访问根节点
		inorder(p->rchild);
	}
}
//后根遍历
void postorder(BTree p)
{
	if (p != NULL)
	{
		postorder(p->lchild);//按后根遍历左子树
		postorder(p->rchild);
		//visit(p);
		printf_s("%c", p->data);//访问根节点
	}
}
int main()
{
	BTree bt;
	//printf_s("二叉树初始化中....");
	InitBTree(bt);//初始化树
	printf_s("请输入给定的先根序列：\n");
	CreateBTree(bt);//创建树
	printf_s("给定的二叉树先跟序列为：\n");
	preorder(bt);//先跟遍历
	printf_s("二叉树中序序列结果为：\n");
	inorder(bt);//中根遍历
	printf_s("二叉树后序序列为：\n");
	postorder(bt);//后根遍历
	return 0;
}