#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



const int INF = 1000000000;

/*Dijkstra算法解决的是单源最短路径问题，即给定图G(V,E)和起点s(起点又称为源点),
求从起点s到达其它顶点的最短距离，并将最短距离存储在矩阵d中*/
void Dijkstra(int n, int s, vector<vector<int>> G, vector<bool>& vis, vector<int>& d, vector<int>& pre)
{
	/*
	param
	n：           顶点个数
	s：           源点
	G：           图的邻接矩阵
	vis：         标记顶点是否已被访问
	d：           存储源点s到达其它顶点的最短距离
	pre：         存储从起点s到达顶点v的最短路径上v的前一个顶点 （新添加）
	*/
	fill(d.begin(), d.end(), INF);                         //初始化最短距离矩阵，全部为INF

	for (int i = 0; i < n; ++i)                            //新添加
		pre[i] = i;

	d[s] = 0;                                              //起点s到达自身的距离为0
	for (int i = 0; i < n; ++i)
	{
		int u = -1;                                     //找到d[u]最小的u
		int MIN = INF;                                  //记录最小的d[u]
		for (int j = 0; j < n; ++j)                     //开始寻找最小的d[u]
		{
			if (vis[j] == false && d[j] < MIN)
			{
				u = j;
				MIN = d[j];
			}
		}
		//找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
		if (u == -1)
			return;
		vis[u] = true;                                  //标记u已被访问
		for (int v = 0; v < n; ++v)
		{
			//遍历所有顶点，如果v未被访问&&u能够到达v&&以u为中介点可以使d[v]更优
			if (vis[v] == false && d[u] + G[u][v] < d[v]) {
				d[v] = d[u] + G[u][v];             //更新d[v]
				pre[v] = u;                        //记录v的前驱顶点为u（新添加）
			}
		}
	}
}

//输出从起点s到顶点v的最短路径
void DFSPrint(int s, int v, vector<int> pre)
{
	if (v == s) {
		cout << s << " ";
		return;
	}
	DFSPrint(s, pre[v], pre);
	cout << v << " ";
}




int main()
{
	int n = 6;
	vector<vector<int>> G = { 
			{ 0,   1,  INF, 4   ,4  ,INF },
			{ INF, 0,  INF, 2   ,INF,INF },
			{ INF,INF, 0  , INF ,INF, 1  },
			{ INF,INF, 2  , 0   ,3  ,INF },
			{ INF,INF, INF, INF ,0  , 3  },
			{ INF,INF, INF, INF ,INF, 0  } 
	};
	vector<bool> vis(n);
	vector<int> d(n);         //存储源点s到达其它顶点的最短距离
	vector<int> pre(n);

	//n 参数个数；0表示起点；G 表示图
	Dijkstra(n, 0, G, vis, d, pre);

	//输出起点0到各个点的最短路径距离
	for (auto x : d)
		cout << x << " ";
	cout << endl;

	//输出从起点0到顶点5的最短路径是怎么走的
	DFSPrint(0, 5, pre);

	system("pause");
	return 0;
}