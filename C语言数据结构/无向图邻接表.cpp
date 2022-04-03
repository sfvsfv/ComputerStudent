#include <iostream>
using namespace std;
#define MaxVertexNum 100// 最大顶点数为100
#define VertexType char//顶点域为字符型
int visited[MaxVertexNum];//标记结点是否被访问过
typedef struct enode//边表中的结点
{
	int adjvex;//边表顶点域
	struct enode* next;//指针域
}EdgeNode;
typedef   struct vnode//顶点表
{
	VertexType vertex;//顶点域
	EdgeNode* firstedge;//边表头指针
}VertexNode;
typedef struct//邻接表
{
	VertexNode vexs[MaxVertexNum];//节点表
	int n, e;//顶点数和边数
}ALGraph;
void InsertNode(ALGraph& G, int i, int j)//在边表中插入结点
{
	EdgeNode* s;
	s = (EdgeNode*)malloc(sizeof(EdgeNode));//生成新边表结点s
	s->adjvex = j;//邻接点序号为j 
	s->next = G.vexs[i].firstedge;
	G.vexs[i].firstedge = s;//将新边表结点s插入到顶点Vi的边表头部
}
ALGraph CreateALGraph()//建立邻边表
{
	ALGraph G;
	int i, j;
	cout << "请输入顶点数和边数：\n";
	cin >> G.n >> G.e;
	cout << "请输入顶点信息：\n";
	for (i = 0; i < G.n; i++)//建立有n个顶点的顶点表
	{
		cin >> G.vexs[i].vertex;//输入顶点
		G.vexs[i].firstedge = NULL;//顶点的边表头指针设为空
	}
	cout << "请输入边的信息(输入格式为：i (空格) j )：\n";
	for (int k = 0; k < G.e; k++)//建立邻接表
	{
		cin >> i >> j;
		InsertNode(G, i, j);
		InsertNode(G, j, i);
	}
	return G;
}
void DFSAL(ALGraph G, int i) //以Vi为出发点对图G搜索
{
	EdgeNode* p;
	cout << G.vexs[i].vertex << "  ";//访问顶点Vi
	visited[i] = 1;//标记Vi已访问
	p = G.vexs[i].firstedge;//取Vi边表的头指针
	while (p)//依次搜索Vi的邻接点Vj
	{
		if (visited[p->adjvex] == 0)//若Vj尚未访问，则以Vj为出发点继续搜索
			DFSAL(G, p->adjvex);
		p = p->next;//找Vi的下一个邻接点
	}
}
void DFSTraverseAL(ALGraph G)
{
	int  i;
	for (i = 0; i < G.n; i++)
		visited[i] = 0;//初始化
	for (i = 0; i < G.n; i++)
		if (visited[i] == 0)
			DFSAL(G, i);//Vi未访问过，从Vi开始搜索
}
int main()
{
	ALGraph G = CreateALGraph();
	cout << "该图的深度优先搜索遍历得到的顶点序列为：";
	DFSTraverseAL(G);
	system("pause");
	return 0;
}

