#include<iostream>
#include<vector>
using namespace std;

// Ħ��ͶƱ�㷨
// ǰ��������ȷ�������� ����һ������
// �����һ������Ϊ������ѡ�ߣ�ÿ����һ����ѡ�߼�������1�������������ּ�������1  ��Ϊ0��ʱ��ѡ��ǰ����Ϊ��ѡ��
// ��Ϊ������ָ�������������֣� ��ô���ĺ�ѡ�߾�������
int majorityElement(vector<int>& nums) {
	int res = 0, count = 0;
	for (auto num : nums) {
		if (count == 0) {
			res = num;
			count++;
		}
		else {
			res == num ? count++ : count--;
		}
	}
	return res;
}
// �ڶ��ַ��� ��ϣ��������--GOȥд
int main() {
	vector<int> res;
	int tp;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tp;
		res.push_back(tp);
	}
	cout << majorityElement(res);
	return 0;
}