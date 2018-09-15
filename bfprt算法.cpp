#include<iostream>
#include<algorithm> 
#include<string.h>
using namespace std;
int a[2];
int medianOfMedians(int root[], int start, int finish);
//表示再root数组上begin位置到end位置找到第K小的元素 
int bfprt(int root[], int begin, int end, int k);
//表示求root数组上beginI到endI上的中位数，其实求是5个数一个组中的中位数 
int getmedian(int root[], int beginI, int endI) {
	sort(root + beginI, root + endI + 1);
	int sum = beginI + endI;
	int mid = (sum / 2) + (sum % 2);//这个地方加上sum%2目的是为了确保偶数个数的时候我们中位数是后面哪一个数
	return root[mid];
}
//表示将数组root从startdaofinish分成五个组，并求出每个数组的中位数 
int medianOfMedians(int root[], int start, int finish) {
	int num = finish - start + 1;//求出数组长度
	int offset = num % 5 == 0 ? 0 : 1;//如果剩余的个数不足5个，我们也将其分成一个小组，和前面同等对待
	int range = num / 5 + offset;//总共分成几个组
	int *median = new int[range];//这个数组保存每个小组的中位数
	for (int i = 0; i<range; i++) {
		int beginI = start + i * 5;
		int endI = beginI + 4;//算出美分小组开始下标，结束小标
		median[i] = getmedian(root, beginI, min(endI, finish));//如果最后一组不足5个，那么结束地址就会使finish  
	}
	return bfprt(median, 0, range - 1, range / 2);
	//求出生成好的median数组的中位数，作为partataion函数划分的基准 
	delete[] median;
}

void swap(int root[], int a, int b)
{
	int temp = root[a];
	root[a] = root[b];
	root[b] = temp;
}
//求的使等于number的范围; 
void partation(int root[], int beginJ, int endJ, int number) {
	int less = beginJ - 1;
	int more = endJ + 1;
	int cur = beginJ;
	while (cur<more) {
		if (root[cur]<number) {
			less++;
			swap(root, cur, less);
			cur++;
		}
		else if (root[cur] == number) {
			cur++;
		}
		else {
			more--;
			swap(root, cur, more);
		}
	}
	a[0] = less + 1;
	a[1] = more - 1;
}
int bfprt(int root[], int begin, int end, int k) {
	if (begin == end) {//如果数组只有一个数，直接返回 
		return root[begin];
	}
	int divide = medianOfMedians(root, begin, end);//求出以那个数作为划分值
	partation(root, begin, end, divide);//注意，进行完partation函数后，root数组已经不是无序的了，
	if (k >= a[0] && k <= a[1]) {//如果需要的数正好再等于区域，直接返回root[k] 
		return root[k];
	}
	else if (k<a[0]) {
		return bfprt(root, begin, a[0] - 1, k);
	}
	else if (k>a[1]) {
		return bfprt(root, a[1] + 1, end, k);
	}
}
/*
int main() {
	int n, k;
	int root[100000];
	while (cin >> n)
	{
		cin >> k;
		for (int i = 0; i<n; i++)
			cin >> root[i];
		cout << bfprt(root, 0, n - 1, k - 1) << endl;
		memset(root, 0, sizeof(root));
		memset(a, 0, sizeof(a));
	}

	return 0;
}
*/