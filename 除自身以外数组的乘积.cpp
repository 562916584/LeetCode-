#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
			int len = nums.size();
			int *left = new int[len], *right = new int[len];
			left[0] = nums[0]; right[len - 1] = nums[len - 1];
			for (int i = 1; i < len - 1; i++) {
				left[i] = left[i - 1] * nums[i];
				right[len - i - 1] = right[len - i] * nums[len - i - 1];
			}
			vector<int> ans;
			ans.push_back(right[1]);
			for (int i = 1; i < len - 1; i++) ans.push_back(left[i - 1] * right[i + 1]);
			ans.push_back(left[len - 2]);
			return ans;
}

int main() {
	vector<int> nums;
	vector<int> res;
	int n,tp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tp;
		nums.push_back(tp);
	}
	res = productExceptSelf(nums);
	for (auto i : res) {
		cout << i << ' ';
	}
	return 0;
}