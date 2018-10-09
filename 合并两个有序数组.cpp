#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	vector<int> res;
	int i = 0, j = 0, k = 0;
	while (i<m && j<n) {
		if (nums1[i] < nums2[j]) {
			res.push_back(nums1[i++]);
		}
		else if (nums1[i] > nums2[j]) {
			res.push_back(nums2[j++]);
		}
		else if (nums1[i] == nums2[j]) {
			res.push_back(nums1[i++]);
			res.push_back(nums2[j++]);
		}
	}
	while (i < m) {
		res.push_back(nums1[i++]);
	}
	while (j < n) {
		res.push_back(nums2[j++]);
	}
	nums1.swap(res);
	for (auto i : nums1) {
		cout << i;
	}
}
int main() {
	vector<int> num1, num2;
	int m, n;
	int tp;
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		cin >> tp;
		num1.push_back(tp);
	}
	for (int i = 0; i < n; i++) {
		cin >> tp;
		num2.push_back(tp);
	}
	merge(num1, m, num2, n);
	return 0;
}