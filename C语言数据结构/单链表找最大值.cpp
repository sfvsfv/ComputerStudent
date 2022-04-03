#include<iostream>
using namespace std;
typedef struct LNode    //定义结构
{
    int data;   //数据
    struct LNode* next;     //指针
}LNode, * LinkList;
void InitList(LinkList& L, int n)        //创建链表
{
    L = new LNode;			//分配内存
    L->next = NULL;			//处理指针域
    LinkList p = L;			//p指向尾结点

    while (n--)				//尾插法
    {
        LinkList q = new LNode;   	//生成新结点        
        cin >> q->data;        		//输入数据
        q->next = NULL;			//处理指针域
        p->next = q;    			//将结点q插在结点p后面
        p = q;				//更新指针p，指向新的尾结点q
    }
}

int Max(LinkList L)        		//L指向首元结点，递归求解最大值
{
    if (L->next == NULL)  //若下一个结点为空，则最大值就是本身
        return L->data;
    else
        return L->next->data > Max(L->next) ? L->next->data : Max(L->next);//两两比较找最大值1 2 5 4
}
int main()
{
    int n;
    cout << "请输入数据个数：";
    while (cin >> n && n !='n')//当n=0时输入结束。
    {
        LinkList L;        		//定义LinkList类型的链表L
        cout << "请输入不同大小的数据：";
        InitList(L, n);    		//创建链表L
       // cout << "最大值序号为：";
       // cout << next;
        cout << "最大值为：";
        cout << Max(L) << endl;    	//递归求解最大值
    }
    return 0;
}
