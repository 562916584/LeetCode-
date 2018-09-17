#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxArea(vector<int>& nums) {
	int n = nums.size();
	int low, high;//组成容器的左右两壁
	int capcity = 0;
	int max = 0;
	for (int i = 0; i < n; i++) {
		// i为容器下标 nums【i】为高度 
		low = i; //左壁
		for (int j = i+1; j < n; j++) {
			high = j;
			capcity = (high - low)*min(nums[low], nums[high]);
			if (capcity > max) {
				max = capcity;
			}
		}
	}
	return max;
}
int maxArea_better(vector<int>& height) {
	int length = height.size();
	int start = 0; int end = length - 1;
	int i = start, j = end;
	int result = min(height[start], height[end]) * (end - start);
	while (i < j) {
		if (height[i] < height[j]) i++;
		else j--;
		int temp_result = min(height[i], height[j]) * (j - i);
		if (temp_result > result) {
			start = i;
			end = j;
			result = temp_result;
		}
	}
	return result;
}
int main() {
	vector<int> data;
	int n;
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			int tp;
			cin >> tp;
			data.push_back(tp);
		}
		cout << maxArea(data) << endl;
	}
	return 0;
}