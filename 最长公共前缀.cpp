#include<iostream>
#include<vector>
#include<string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
	if (strs.size() == 0) {
		return "";
	}
	int n = strs[0].length();
	int m = strs.size();
	int j = 0;
	string ans="";
	while (j < n) {
		char t = strs[0][j];//第一个string里的第一个字符
		for (int i = 0; i < m-1; i++) {
			if (strs[i][j] != strs[i + 1][j]) {
				return ans;
			}
			if (t != strs[i][j]) {
				return ans;
			}
		}
		ans.push_back(strs[0][j]);
		j++;
	}
	return ans;
}

/*
int main() {
	vector<string> strs;
	int n;
	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		strs.push_back(str);
	}
	cout<<longestCommonPrefix(strs);
	return 0;
}
*/