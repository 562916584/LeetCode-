#include<iostream>
#include<vector>
using namespace std;
int removeDuplicates(vector<int>& nums) {
	
	if (nums.size() == 0) {
		return 0;
	}
	int tp = 0;
	int res = nums.size();
	for (int i = 0; i < nums.size()-1; i++) {
		while (nums[i] == nums[i + 1]) {
			if (i + 2 == nums.size()) {
				break;
			}
			i++;
			tp++;
		}
		if (nums[i] == nums[i + 1]) {
			tp++;
			nums[i - tp + 1] = nums[i + 1];
			break;
		}
		else {
			nums[i - tp + 1] = nums[i + 1];
		}
	}
	return res-tp;
}


int main() {
	vector<int> data;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tp;
		cin >> tp;
		data.push_back(tp);
	}
	cout << removeDuplicates(data)<<endl;
	for (int i = 0; i < data.size(); i++) {
		cout << data[i] << ' ';
	}
	return 0;
}
