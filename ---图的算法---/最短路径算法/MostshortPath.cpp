#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

void print_graph(int graph[][6], int n) {
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << graph[i][j] << "   ";
		}
		cout << endl;
	}
}

void init_graph(int graph[][6], int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			graph[i][j] = -1;
		}
	}
}

vector<int> getnext(int graph[][6],int n,int node) {
	vector<int> nodenext;
	for (int i = 0; i < n; i++) {
		if (graph[node][i] > 0) {
			nodenext.push_back(i);
		}
	}
	return nodenext;
}

void print_mostshortpath(int * shortpath, int n) {
	for (int i = 0; i < n; i++) {
		cout << shortpath[i] << "   ";
	}
	cout << endl;
}

//接口是一个二维的n*n的图，begin是出发的结点
int *  get_mostshortpath(int graph[][6],int n,int begin){
	//保存的begin接到到其他各个结点的最短路径
	int * cur_shortpath = new int[n];
	for (int i = 0; i < n; i++) {
		cur_shortpath[i] = INT_MAX;
	}

	//表示已经加入S的集合的结点
	int * finalnode = new int[n];
	for (int i = 0; i < n; i++) {
		finalnode[i] = 0;
	}

	//将begin结点加入S ,并且是的begin到自己的最短路径为0
	finalnode[begin] = 1;
	cur_shortpath[begin] = 0;

	//完成一个初始化
	vector<int> nodenext = getnext(graph,n,begin);
	for (int i = 0; i < nodenext.size(); i++) {
		int nnode = nodenext[i];
		cur_shortpath[nnode] = graph[begin][nnode];
	}

	//times表示要迭代n-1次
	for (int times = 1; times < n; times++) {

		// #1 > 寻找cur_shortpath里面的最小值,并且这个结点没有加入到S集合里面
		int min_node = begin;
		int min_value = INT_MAX;
		for (int i = 0; i < n; i++) {
			if (min_value > cur_shortpath[i] && finalnode[i]==0 ) {
				min_value = cur_shortpath[i];
				min_node = i;
			}
		}

		// #2 > 将这个结点加入S
		finalnode[min_node] = 1;

		// #3 > 更新最短路径
		vector<int> newnodenext = getnext(graph, n, min_node);
		for (int i = 0; i < newnodenext.size(); i++) {
			int newnnode = newnodenext[i];
			if ( (cur_shortpath[newnnode] > cur_shortpath[min_node] + graph[min_node][newnnode])) {
				cur_shortpath[newnnode] = cur_shortpath[min_node] + graph[min_node][newnnode];
			}
		}
	}


	return cur_shortpath;

}

int main() {
	//初始化为都不可达
	const int n = 6;
	int begin = 0;
	int graph[n][n];
	init_graph(graph, 6);
	
	//设置可达路径
	graph[0][2] = 10;
	graph[0][4] = 30;
	graph[0][5] = 100;
	graph[1][2] = 5;
	graph[2][3] = 50;
	graph[3][5] = 10;
	graph[4][3] = 20;
	graph[4][5] = 60;


	int * shortpath=get_mostshortpath(graph, n, begin);

	//print_graph(graph, 6);
	print_mostshortpath(shortpath,n);

	return 0;
}