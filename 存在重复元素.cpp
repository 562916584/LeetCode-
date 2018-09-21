#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
	int tp = 0;
	int n = nums.size();
	if (n == 0) {
		return false;
	}
	sort(nums.begin(), nums.end());
	nums.push_back(INT_MAX);
	for (int i = 0; i < n; i++ ) {
		if (nums[i] == nums[i + 1]) {
			return true;
		}
	}
	return false;
}

int main() {
	vector<int> nums;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tp;
		cin >> tp;
		nums.push_back(tp);
	}
	cout << containsDuplicate(nums) << endl;
	return 0;
}