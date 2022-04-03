#include"stdio.h"
#include"stdlib.h"
typedef char ElemType;
typedef struct stnode
{
	ElemType data;
	struct stnode* next;
}StNode, * LinkStack;
int huiwen(char str[])
{
	int i = 0;
	char ch;
	StNode* sl = NULL, * p;
	while ((ch = str[i++]) != '\0')
	{
		p = (StNode*)malloc(sizeof(StNode));//给内存
		p->data = ch;
		p->next = sl;
		sl = p;
	}
	i = 0;
	while (sl != NULL)
	{
		p = sl;
		ch = p->data;
		sl = sl->next;
		free(p);//释放内存
		if (ch != str[i++])
			return 0;
	}
	return 1;
}
void main()
{
	char string[30];//最长为30
	int hw;
	printf("请输入字符串:");
	gets_s(string);
	hw = huiwen(string);
	if (hw) printf("字符串是回文.");
	else printf("字符串不是回文");
}
