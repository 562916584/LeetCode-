#include<iostream>
#include<string>
using namespace std;

//����֮�����Ϊ������2  ������ǰһ������֮��ļ�����  j-2*i+num
string convert(string s, int numRows) {
	int len = s.length();
	string res;
	int num = 2*numRows - 2;//�Ȳ����е�d
	if (numRows == 1|| len==0|| numRows == 0) {
		return s;
	}
	for (int i = 0; i < numRows; i++) {
		for (int j = i; j < len; j+=num) {
			res.push_back(s[j]);
			if (i != 0 && i != numRows - 1 && j - 2 * i + num < len) {
				res.push_back(s[j - (2 * i) + num]);
			}
		}
	}
	return res;
}/*
int main() {
	string str;
	int rows;
	cin >> str>>rows;
	cout << convert(str,rows) << endl;
	return 0;
}
*/