// ConsoleApplication23.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>                                     
#include<malloc.h>
using namespace std;
#define MAXVEX 100
typedef char VertexType;
typedef int EdgeType;
typedef struct
{
	VertexType vexs[MAXVEX];
	EdgeType edges[MAXVEX][MAXVEX];
	int n, e;
}MGraph;
MGraph CreateMGraph(int pd)
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
			G.edges[i][j] = 0;
	cout << "请输入每条边对应的两个顶点的序号及权重:\n";
	for (n = 0; n < G.e; n++)
	{
		cin >> i >> j >> k;
		G.edges[i][j] = k;
		if (pd == 0)
			G.edges[j][i] = k;
	}
	return G;
}
void DisplayMGraph(MGraph G, int pd)
{
	for (int i = 0; i < G.n; i++)
	{
		cout << "第" << i + 1 << "行：";
		for (int j = 0; j < G.n; j++)
			if (pd == 0 && G.edges[i][j] == 0)
				cout << "∞" << "\t";
			else
				cout << G.edges[i][j] << "\t";
		cout << "\n";
	}
}
int OutDegree(MGraph G, int i)
{
	int degree = 0;
	for (int j = 0; j < G.n; j++)
		if (G.edges[i][j] != 0)
			degree++;
	return degree;
}
int InDegree(MGraph G, int i)
{
	int degree = 0;
	for (int j = 0; j < G.n; j++)
		if (G.edges[j][i] != 0)
			degree++;
	return degree;
}
void PrintOut(MGraph G, int pd)
{
	int all;
	if (pd == 0)
		for (int i = 0; i < G.n; i++)
			cout << "第" << i << "个顶点" << G.vexs[i] << "的度是" << OutDegree(G, i) << endl;
	else
		for (int i = 0; i < G.n; i++)
		{
			cout << "第" << i << "个顶点" << G.vexs[i] << "的出度是" << OutDegree(G, i) << "，入度是" << InDegree(G, i) << endl;
			all = OutDegree(G, i) + InDegree(G, i);
			cout << "第" << i << "个顶点" << G.vexs[i] << "的度是" << all << endl;
		}
}
int main()
{
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

//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
