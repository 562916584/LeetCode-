#include<iostream>
using namespace std;
struct Graph {
	int value;
	bool visit;
	Graph() {
		visit = false;
		value = 0;
	}
};
int **graph;
Graph *dis;
int vexnum, edge;
void Djkstra(int begin) {
	//首先初始化我们的dis数组
	int i;
	for (i = 0; i < vexnum; i++) {
		//设置当前的路径
		dis[i].value = graph[begin - 1][i];
	}
	//设置起点的到起点的路径为0
	dis[begin - 1].value = 0;
	dis[begin - 1].visit = true;

	int count = 1;
	//计算剩余的顶点的最短路径（剩余this->vexnum-1个顶点）
	while (count != vexnum) {
		//temp用于保存当前dis数组中最小的那个下标
		//min记录的当前的最小值
		int temp = 0;
		int min = INT_MAX;
		for (i = 0; i < vexnum; i++) {
			if (!dis[i].visit && dis[i].value<min) {
				min = dis[i].value;
				temp = i;
			}
		}
		//cout << temp + 1 << "  "<<min << endl;
		//把temp对应的顶点加入到已经找到的最短路径的集合中
		dis[temp].visit = true;
		++count;
		for (i = 0; i < vexnum; i++) {
			//注意这里的条件arc[temp][i]!=INT_MAX必须加，不然会出现溢出，从而造成程序异常
			if (!dis[i].visit && graph[temp][i] != INT_MAX && (dis[temp].value + graph[temp][i]) < dis[i].value) {
				//如果新得到的边可以影响其他为访问的顶点，那就就更新它的最短路径和长度
				dis[i].value = dis[temp].value + graph[temp][i];
			}
		}
	}

}
void print() {
	cout << "图的邻接矩阵为：" << endl;
	int count_row = 0; //打印行的标签
	int count_col = 0; //打印列的标签
					   //开始打印
	while (count_row != vexnum) {
		count_col = 0;
		while (count_col != vexnum) {
			if (graph[count_row][count_col] == INT_MAX)
				cout << "∞" << " ";
			else
				cout << graph[count_row][count_col] << " ";
			++count_col;
		}
		cout << endl;
		++count_row;
	}
}
/*
int main() {
	int start, end, weight;
	cin >> vexnum >> edge;
	//为邻接矩阵开辟空间和赋初值
	graph = new int*[vexnum];
	dis = new Graph[vexnum];
	for (int i = 0; i < vexnum; i++) {
		graph[i] = new int[vexnum];
		for (int k = 0; k < vexnum; k++) {
			//邻接矩阵初始化为无穷大
			graph[i][k] = INT_MAX;
		}
	}

	for (int i = 0; i<edge; i++) {
		cin >> start >> end >> weight;
		if (graph[start-1][end-1]>weight) {
			graph[start-1][end-1] = weight;
		}
	}
	print();
	Djkstra(1);
	for (int i = 0; i<vexnum; i++) {
		cout << dis[i].value << ' ' << endl;
	}
	for (int i = 0; i<vexnum; i++) {
		delete[] graph[i];
	}
	delete[] graph;
	delete[] dis;
	return 0;
}
*/