#include<stdio.h>
#include<stdlib.h>
typedef struct Bitnode
{
	char data;
	struct Bitnode* lchild, * rchild;
}Bitnode, * Bitree;
void PreOrd(Bitree T)
{
	if (T == NULL)
		return;
	printf("%c", T->data);
	PreOrd(T->lchild);
	PreOrd(T->rchild);
}
void InOrderTraverse(Bitree T)//二叉树的中序遍历
{
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild);
	printf("%c", T->data);
	InOrderTraverse(T->rchild);
}
int countleaf(Bitree* T, int count)
{
	if ((*T) != NULL)
	{
		if ((*T)->lchild == NULL && (*T)->rchild == NULL)
		{
			count++;
		}
		count = countleaf(&(*T)->lchild, count);
		count = countleaf(&(*T)->rchild, count);
	}
	return count;
}
void create(Bitree* T)
{
	char ch;
	scanf_s("%c", &ch);
	if (ch == '#')
		*T = NULL;
	else {
		*T = (Bitree)malloc(sizeof(Bitnode));
		if (!*T)
			exit(0);
		(*T)->data = ch;
		create(&(*T)->lchild);
		create(&(*T)->rchild);

	}
}
int main()
{
	Bitree T;
	printf_s("输入字符串序列：\n");
	int count = 0;
	create(&T);
	printf_s("输出序列为：\n");
	InOrderTraverse(T);
	printf_s("叶子节点数为：");
	count = countleaf(&T, count);
	printf("\n%d", count);
	return 0;
}
