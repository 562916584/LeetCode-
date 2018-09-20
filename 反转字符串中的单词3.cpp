#include<iostream>
#include<string>
using namespace std;

string reverseWords(string s) {
	int n = s.size();
	string res;
	if (s.size() == 0) {
		return "";
	}
	int temp=0;//标记每个单词开始的下标位置
	for (int i = 0; i <= n; i++) {
		if (s[i] == ' '|| i==n) {
			for (int j =i-1 ; j >= temp; j--) {
				if (s[j] == ' ') {
					break;
				}
				res.push_back(s[j]);
			}
			//将空格放入
			res.push_back(s[i]);
			temp = i;
		}
	}
	return res;
}
int main() {
string str;
//读入一行数据
getline(cin, str);
cout << reverseWords(str) << endl;
return 0;
}
