#include<iostream>
#include<string>
using namespace std;
/*
本程序是使用Dijkstra算法实现求解最短路径的问题
采用的邻接矩阵来存储图
*/
//记录起点到每个顶点的最短路径的信息
struct Dis {
	string path;
	int value;
	bool visit;
	Dis() {
		visit = false;
		value = 0;
		path = "";
	}
};

class Graph_DG {
private:
	int vexnum;   //图的顶点个数
	int edge;     //图的边数
	int **arc;   //邻接矩阵
	Dis * dis;   //记录各个顶点最短路径的信息;
public:
	//构造函数
	Graph_DG(int vexnum, int edge);
	~Graph_DG();
	//判断我们每次输入的边的信息是否合法
	//顶点从1开始编号
	bool check_edge_value(int start, int end, int weight);
	//创建图
	void creatGraph();
	//打印邻接矩阵
	void show();
	//求最短路径
	void Dijkstra(int begin);
	void Graph_DG::print_path(int begin);
};

Graph_DG::Graph_DG(int vexnum, int edge) {
	//初化始顶点数和边数
	this->vexnum = vexnum;
	this->edge = edge;
	//为邻接矩阵开辟空间和赋初值
	arc = new int*[this->vexnum];
	dis = new Dis[this->vexnum];
	for (int i = 0; i<this->vexnum; i++) {
		arc[i] = new int[this->vexnum];
		for (int k = 0; k<this->vexnum; k++) {
			//邻接矩阵初始化为无穷大
			arc[i][k] = INT_MAX;
		}
	}
}
//析构函数
Graph_DG::~Graph_DG() {
	delete[] dis;
	for (int i = 0; i<this->vexnum; i++) {
		delete this->arc[i];
	}
	delete[] arc;
}
//判断我们每次输入的边的信息是否是合法的
//顶点从1 开始编号
bool Graph_DG::check_edge_value(int start, int end, int weight) {
	if (start<1 || end<1 || start>vexnum || end>vexnum || weight < 0) {
		return false;
	}
	return true;
}
void Graph_DG::creatGraph() {
	cout << "请输入每条边的起点和终点（顶点编号从1开始）以及其权重" << endl;
	int start;
	int end;
	int weight;
	int count = 0;
	int edge = this->edge;
	while (count != this->edge) {
		cin >> start >> end >> weight;
		//首先判断信息是否合法
		while (!this->check_edge_value(start, end, weight)) {
			cout << "输入的边的信息不合法，请重新输入" << endl;
			cin >> start >> end >> weight;
		}
		//堆邻接矩阵对应的点上赋值
		arc[start - 1][end - 1] = weight;
		//无向图添加上这行代码
		//arc[end-1][start-1]=weight;
		count++;
	}
}
void Graph_DG::show() {
	cout << "图的邻接矩阵为：" << endl;
	int count_row = 0; //打印行的标签
	int count_col = 0; //打印列的标签
					   //开始打印
	while (count_row != this->vexnum) {
		count_col = 0;
		while (count_col != this->vexnum) {
			if (arc[count_row][count_col] == INT_MAX)
				cout << "∞" << " ";
			else
				cout << arc[count_row][count_col] << " ";
			++count_col;
		}
		cout << endl;
		++count_row;
	}
}
void Graph_DG::Dijkstra(int begin) {
	//首先初化始dis数组
	int i;
	for (i = 0; i<this->vexnum; i++) {
		//设置当前的路径  C++11支持to_string()转换，低版本不支持
		dis[i].path = "v" + to_string(begin) + "-->v" + to_string(i + 1);
		dis[i].value = arc[begin - 1][i];
	}
	//设置起点到起点的路径为0
	dis[begin - 1].value = 0;
	dis[begin - 1].visit = true;
	int count = 1;
	//计算剩余的顶点的最短距离
	while (count != this->vexnum) {
		//temp用于保存当前dis数组中最小的那个下标
		//min记录当前的最小值
		int temp = 0;
		int min = INT_MAX;
		for (i = 0; i<this->vexnum; i++) {
			if (!dis[i].visit&&dis[i].value<min) {
				min = dis[i].value;
				temp = i;
			}
		}
		cout<<temp+1<<" "<<min<<endl;
		//把temp对应的顶点加入到已经周到的最短路径中
		dis[temp].visit = true;
		++count;
		for (i = 0; i<this->vexnum; i++) {
			//注意这里的条件是arc【temp】【i】！=INT_MAX，不然会出现溢出，出现异常
			if (!dis[i].visit&&arc[temp][i] != INT_MAX &&
				(dis[temp].value + arc[temp][i]) < dis[i].value) {
				// 如果新的到的边可以影响到其他访问的顶点，那么就更新他的最短路径和长度
				dis[i].value = dis[temp].value + arc[temp][i];
				dis[i].path = dis[temp].path + "-->v" + to_string(i + 1);
			}
		}
	}
}
void Graph_DG::print_path(int begin) {
    string str;
    str = "v" + to_string(begin);
    cout << "以"<<str<<"为起点的图的最短路径为：" << endl;
    for (int i = 0; i != this->vexnum; i++) {
        if(dis[i].value!=INT_MAX)
        cout << dis[i].path << "=" << dis[i].value << endl;
        else {
            cout << dis[i].path << "是无最短路径的" << endl;
        }
    }
}
//检验输入边数和顶点数的值是否有效，可以自己推算为啥：
//顶点数和边数的关系是：((Vexnum*(Vexnum - 1)) / 2) < edge
bool check(int Vexnum, int edge) {
	if (Vexnum <= 0 || edge <= 0 || ((Vexnum*(Vexnum - 1)) / 2) < edge)
		return false;
	return true;
}
/*
int main() {
	int vexnum; int edge;

	cout << "输入图的顶点个数和边的条数：" << endl;
	cin >> vexnum >> edge;
	while (!check(vexnum, edge)) {
		cout << "输入的数值不合法，请重新输入" << endl;
		cin >> vexnum >> edge;
	}
	Graph_DG graph(vexnum, edge);
	graph.creatGraph();
	graph.show();
	graph.Dijkstra(1);
	graph.print_path(1);
	return 0;
}
*/