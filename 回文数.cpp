#include<iostream>
#include<vector>
using namespace std;
bool isPalindrome(int x) {
	if (x < 0 || x % 10 == 0) {
		if (x == 0) {
			return true;
		}
		return false;
	}
	vector<int> res;
	int tp=0;
	while (x != 0) {
		tp = x % 10;
		x = x / 10;
		res.push_back(tp);
	}
	int length = res.size();
	int k = length-1;
	for (int i = 0; i < length; i++) {
		if (res[i] != res[k]) {
			return false;
		}
		k--;
	}
	return true;
}
int main() {
	int n;
	cin >> n;
	cout<<isPalindrome(n);
	return 0;
}