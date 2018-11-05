#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int>& nums) {
	int n = nums.size();
	int tp;
	tp = 0 ^ nums[0];
	for (int i = 1; i < n; i++) {
		tp = tp ^ nums[i];
	}
	return tp;
}
int main() {
	int n,tp;
	vector<int> nums;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> tp;
		nums.push_back(tp);
	}
	cout << singleNumber(nums);
	return 0;
}