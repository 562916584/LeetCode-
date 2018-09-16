#include<iostream>
#include<algorithm> 
#include<string.h>
using namespace std;
int a[2];
int medianOfMedians(int root[], int start, int finish);
//��ʾ��root������beginλ�õ�endλ���ҵ���KС��Ԫ�� 
int bfprt(int root[], int begin, int end, int k);
//��ʾ��root������beginI��endI�ϵ���λ������ʵ����5����һ�����е���λ�� 
int getmedian(int root[], int beginI, int endI) {
	sort(root + beginI, root + endI + 1);
	int sum = beginI + endI;
	int mid = (sum / 2) + (sum % 2);//����ط�����sum%2Ŀ����Ϊ��ȷ��ż��������ʱ��������λ���Ǻ�����һ����
	return root[mid];
}
//��ʾ������root��startdaofinish�ֳ�����飬�����ÿ���������λ�� 
int medianOfMedians(int root[], int start, int finish) {
	int num = finish - start + 1;//������鳤��
	int offset = num % 5 == 0 ? 0 : 1;//���ʣ��ĸ�������5��������Ҳ����ֳ�һ��С�飬��ǰ��ͬ�ȶԴ�
	int range = num / 5 + offset;//�ܹ��ֳɼ�����
	int *median = new int[range];//������鱣��ÿ��С�����λ��
	for (int i = 0; i<range; i++) {
		int beginI = start + i * 5;
		int endI = beginI + 4;//�������С�鿪ʼ�±꣬����С��
		median[i] = getmedian(root, beginI, min(endI, finish));//������һ�鲻��5������ô������ַ�ͻ�ʹfinish  
	}
	return bfprt(median, 0, range - 1, range / 2);
	//������ɺõ�median�������λ������Ϊpartataion�������ֵĻ�׼ 
	delete[] median;
}

void swap(int root[], int a, int b)
{
	int temp = root[a];
	root[a] = root[b];
	root[b] = temp;
}
//���ʹ����number�ķ�Χ; 
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
	if (begin == end) {//�������ֻ��һ������ֱ�ӷ��� 
		return root[begin];
	}
	int divide = medianOfMedians(root, begin, end);//������Ǹ�����Ϊ����ֵ
	partation(root, begin, end, divide);//ע�⣬������partation������root�����Ѿ�����������ˣ�
	if (k >= a[0] && k <= a[1]) {//�����Ҫ���������ٵ�������ֱ�ӷ���root[k] 
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