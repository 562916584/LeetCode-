#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> res(1);
	for (int i = 0; i < nums.size(); i++) {
		int length = res.size();
		for (int j = 0; j < length; j++) {
			res.push_back(res[j]);
			res.back().push_back(nums[i]);
		}
	}
	return res;
}

int main() {
	vector<int> res;
	vector<vector<int>> ans;
	for (int i = 1; i <= 4; i++) {
		int tp;
		cin >> tp;
		res.push_back(tp);
	}
	ans = subsets(res);
	for (auto i : ans) {
		for (auto k : i) {
			cout << k << ' ';
		}
		cout << endl;
	}
	return 0;
}