#include<unordered_map>
#include<vector>
#include<iostream>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> a;
	vector<int> res;
	for (int i = 0; i < nums.size(); i++) {
		a.insert(pair<int, int >(nums[i], i));
	}
	for (int i = 1; i < nums.size() ; i++) {
		auto p=a.find(target - nums[i]);
		if (p!=a.end()&&(*p).second!=i) {
			if (i > (*p).second) {
				res.push_back((*p).second);
				res.push_back(i);
			}
			else {
				res.push_back(i);
				res.push_back((*p).second);
			}
			return res;
		}
	}
	return res;
}
/*
int main() {
	vector<int> a;
	vector<int> b;
	int temp;
	for (int i = 0; i<4; i++) {
		cin >> temp;
		a.push_back(temp);
	}
	int target;
	cin >> target;
	b=twoSum(a, target);
	vector<int>::iterator ute = b.begin();
	while (ute != b.end()) {
		cout << (*ute) << ' ' << endl;
		ute++;
	}
	return 0;
}
*/