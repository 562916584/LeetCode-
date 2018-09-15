#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isValid(string s) {
	stack<char> cc;
	if (s.size() == 0) {
		return true;
	}
	int n = s.size();
	int subscript = 0;
	while (subscript < n) {
		if (s[subscript] == ')' || s[subscript] == '}' || s[subscript] == ']') {
			if (cc.empty()) {
				return false;
			}
		}
		if (s[subscript] == '(' || s[subscript] == '{' || s[subscript] == '[') {
			cc.push(s[subscript]);
			subscript++;
			continue;
		}
		else {//因为字符串只含有括号  所以直接匹配
			char tp;
			if (!cc.empty()) {
				tp = cc.top();
				switch (s[subscript]) {
				case ')':tp == '(' ? cc.pop() : cc.push(')'); break;
				case '}':tp == '{' ? cc.pop() : cc.push('}'); break;
				case ']':tp == '[' ? cc.pop() : cc.push(']'); break;
				}
			}
		}
		subscript++;
	}
	if (cc.empty()) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	string str;
	while (cin >> str) {
		bool res;
		res=isValid(str);
		cout << res << endl;
	}
	return 0;
}