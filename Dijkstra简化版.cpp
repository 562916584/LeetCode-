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
	//���ȳ�ʼ�����ǵ�dis����
	int i;
	for (i = 0; i < vexnum; i++) {
		//���õ�ǰ��·��
		dis[i].value = graph[begin - 1][i];
	}
	//�������ĵ�����·��Ϊ0
	dis[begin - 1].value = 0;
	dis[begin - 1].visit = true;

	int count = 1;
	//����ʣ��Ķ�������·����ʣ��this->vexnum-1�����㣩
	while (count != vexnum) {
		//temp���ڱ��浱ǰdis��������С���Ǹ��±�
		//min��¼�ĵ�ǰ����Сֵ
		int temp = 0;
		int min = INT_MAX;
		for (i = 0; i < vexnum; i++) {
			if (!dis[i].visit && dis[i].value<min) {
				min = dis[i].value;
				temp = i;
			}
		}
		//cout << temp + 1 << "  "<<min << endl;
		//��temp��Ӧ�Ķ�����뵽�Ѿ��ҵ������·���ļ�����
		dis[temp].visit = true;
		++count;
		for (i = 0; i < vexnum; i++) {
			//ע�����������arc[temp][i]!=INT_MAX����ӣ���Ȼ�����������Ӷ���ɳ����쳣
			if (!dis[i].visit && graph[temp][i] != INT_MAX && (dis[temp].value + graph[temp][i]) < dis[i].value) {
				//����µõ��ı߿���Ӱ������Ϊ���ʵĶ��㣬�Ǿ;͸����������·���ͳ���
				dis[i].value = dis[temp].value + graph[temp][i];
			}
		}
	}

}
void print() {
	cout << "ͼ���ڽӾ���Ϊ��" << endl;
	int count_row = 0; //��ӡ�еı�ǩ
	int count_col = 0; //��ӡ�еı�ǩ
					   //��ʼ��ӡ
	while (count_row != vexnum) {
		count_col = 0;
		while (count_col != vexnum) {
			if (graph[count_row][count_col] == INT_MAX)
				cout << "��" << " ";
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
	//Ϊ�ڽӾ��󿪱ٿռ�͸���ֵ
	graph = new int*[vexnum];
	dis = new Graph[vexnum];
	for (int i = 0; i < vexnum; i++) {
		graph[i] = new int[vexnum];
		for (int k = 0; k < vexnum; k++) {
			//�ڽӾ����ʼ��Ϊ�����
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