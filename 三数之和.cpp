#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	//����֮��ת��Ϊ���������� �ö���˼��������ͷ���м���
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	if (nums.size() == 0 ) {
		return res;
	}
	int n = nums.size();
	int target;//����֮��
	int low, high;
	for (int i = 0; i < n; i++) {
		if (nums[i] > 0) {
			break;
		}
		target = 0 - nums[i];
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}
		//����˼��
		low = i + 1;
		high = n - 1;
		int sum = 0;
		while (low < high) {
			sum = nums[low] + nums[high];
			if (sum == target) {
				res.push_back(vector<int>{ nums[i],nums[low],nums[high] });
				//ȥ���ظ���Ԫ��
				while (low < high&&nums[low] == nums[low + 1]) {
					low++;
				}
				while (low < high&&nums[high] == nums[high - 1]) {
					high--;
				}
				low++;
				high--;
			} 
			else if (target > sum) {
				low++;
			}
			else {
				high--;
			}
		}
	}
	return res;
}
/*
int main() {
	vector<int> data;
	int n,tp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tp;
		data.push_back(tp);
	}
	threeSum(data);
	return 0;
}
*/