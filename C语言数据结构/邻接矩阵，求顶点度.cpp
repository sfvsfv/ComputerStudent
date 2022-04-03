#include <iostream>//蓝多多算法实验六
#include<malloc.h>
using namespace std;
#define MAXVEX 100//最大顶点数
typedef char VertexType;//顶点类型
typedef int EdgeType;//边的权值
typedef struct
{
	VertexType vexs[MAXVEX];//顶点表
	EdgeType edges[MAXVEX][MAXVEX];//邻接矩阵
	int n, e;//顶点数和边数	
}MGraph;
MGraph CreateMGraph(int pd)//建立邻接矩阵
{
	MGraph G;
	int i, j, k, n;
	cout << "请输入顶点数和边数：";
	cin >> G.n >> G.e;
	cout << "请输入顶点信息：";
	for (i = 0; i < G.n; i++)
		cin >> G.vexs[i];
	for (i = 0; i < G.n; i++)
		for (j = 0; j < G.n; j++)
			G.edges[i][j] = 0;//初始化邻接矩阵
	cout << "请输入每条边对应的两个顶点的序号及权重:\n例：0 1 2 表示标注的第0个顶点和第1个顶点之间有边且权重为2 (注意序号从0开始)\n";
	for (n = 0; n < G.e; n++)
	{
		cin >> i >> j >> k;//输入边的信息
		G.edges[i][j] = k;
		if (pd == 0)//无向图，边是双向的
			G.edges[j][i] = k;
	}
	return G;
}
void DisplayMGraph(MGraph G, int pd)//分行输出
{
	for (int i = 0; i < G.n; i++)//第i个顶点(行)
	{
		cout << "第" << i + 1 << "行：";
		for (int j = 0; j < G.n; j++)//第j列
			if (pd == 0 && G.edges[i][j] == 0)
				cout << "∞" << "\t";
			else
				cout << G.edges[i][j] << "\t";
		cout << "\n";
	}
}
int OutDegree(MGraph G, int i)//（出）度(求第i个顶点表中的结点数)
{
	int degree = 0;
	for (int j = 0; j < G.n; j++)
		if (G.edges[i][j] != 0)
			degree++;
	return degree;
}
int InDegree(MGraph G, int i)//入度
{
	int degree = 0;
	for (int j = 0; j < G.n; j++)
		if (G.edges[j][i] != 0)
			degree++;
	return degree;
}
void PrintOut(MGraph G, int pd)//度
{
	int all;
	if (pd == 0)//无向图
		for (int i = 0; i < G.n; i++)
			cout << "第" << i << "个顶点" << G.vexs[i] << "的度是" << OutDegree(G, i) << endl;
	else//有向图
		for (int i = 0; i < G.n; i++)
		{
			cout << "第" << i << "个顶点" << G.vexs[i] << "的出度是" << OutDegree(G, i) << "，入度是" << InDegree(G, i) << endl;
			all = OutDegree(G, i) + InDegree(G, i);
			cout << "第" << i << "个顶点" << G.vexs[i] << "的度是" << all << endl;
		}
}
int main()
{
	//判断是有向图还是无向图//
	cout << "如果是无向图，请输入0；如果是有向图，请输入1：";
	int pd;
	cin >> pd;
	if (pd != 0 && pd != 1)
	{
		cout << "输入有误，请退出重新输入0或1。";
		return 0;
	}
	MGraph G = CreateMGraph(pd);
	cout << "\n分行输出该邻接矩阵为：\n";
	DisplayMGraph(G, pd);
	PrintOut(G, pd);
	system("pause");
	return 0;
}

