#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int threeSumClosest(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	int n = nums.size();     
	int res = 0;// �����ֵ
	int temp=0;
	int cha = 0;// ��Ŀ��Ĳ�ֵ
	int min = INT_MAX-1; //����һ��Ƚ� ������С�Ĳ�ֵ
	for (int i = 0; i < n-2; i++) {
		int low = i + 1;
		int high = n - 1;
		while (low < high) {
			temp= nums[i] + nums[low] + nums[high];
			cha = abs(temp - target);
			if (cha < min) { //����һ�θ��� �����res��cha
				res = temp;
				min = cha;
			}
			if (cha == 0) {
				//��ȫƥ��
				return res;
			}
			if (temp > target) {
				//��Ҫ��С
				high--;
				continue;
			}
			if (temp < target) {
				low++;
				continue;
			}
		}
	}
	return res;
}
/*
int main() {
	vector<int> nums;
	int n,target;
	while (cin >> n >> target) { 
	for (int i = 0; i < n; i++) {
		int tp;
		cin >> tp;
		nums.push_back(tp);
	}
	cout << threeSumClosest(nums, target);
	}
	return 0;
}
*/