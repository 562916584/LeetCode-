#include<iostream>
#include<vector>
using namespace std;

// 摩尔投票算法
// 前提条件是确定数组中 存在一个众数
// 假设第一个数字为众数候选者，每遇到一个候选者计数器加1，遇到其他数字计数器减1  减为0的时候选择当前数字为候选者
// 因为众数是指超过半数的数字， 那么最后的候选者就是众数
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
// 第二种方法 哈希表求众数--GO去写
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