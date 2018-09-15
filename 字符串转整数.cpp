#include<iostream>
#include<string>
#include<deque>
#include<math.h>
using namespace std;

/*
int show(string& data) {
	//cout << data;
	int pt=0;//储存上一个res
	int n = data.length();
	int count = n;//记录位数
	bool is_fu = false;
	int res = 0;
	bool is_zero = true;
	bool is_yuejie = false;
	for (int i = 0; i < n; i++) {
		if (data[i] == '-') {
			is_fu = true;
			continue;
		}
		//把字符串转换出来
		if (data[i] >= '0' && data[i] <= '9') {
			pt = res;
			res = res + (data[i] - '0')*pow(10, n - 1 - i);
			if (pt > res) {//int越界了
				is_yuejie = true;
				break;
			}
			if (res == 0&&is_zero) {//前面的零
				count--;
			}
			else if (res > 0) {
				is_zero = false;//后面的零
			}
		}
	}
	if (is_yuejie) {
		if (is_fu) {
			return INT_MIN;
		}
		else {
			return INT_MAX;
		}
	}
	else {
		if (is_fu) {
			return res*-1;
		}
		else {
			return res;
		}
	}
}
int myAtoi(string str) {
	deque<char> data;
	int is_first = 0; //还没开始识别数字
	for (int i = 0; i < (int)str.length(); i++) {
		data.push_back(str[i]);
	}
	str.clear();
	data.push_back('#');
	deque<char>::iterator ite = data.begin();
	while (*ite!='#') {

		//判断非法字符的时候直接退出
		if (*ite != ' ' && *ite != '-') {
			if (*ite != '+') {
				if (*ite<'0' || *ite>'9') {
					return 0;
					break;
				}
			}
		}
		if (*ite == ' ') {
			ite++;
			continue;
		}

		if (*ite == '+' || *ite == '-') {
			if (is_first == 1) {//只能读取数字  读取其他东西退出
				return show(str);
			}
			str.push_back(*ite);
			is_first = 1;//开始识别数字了
			ite++;
			continue;
		}
		if (*ite <= '9'&&*ite >= '0') {
			while (*ite <= '9'&&*ite >= '0') {
				is_first = 1;
				str.push_back(*ite);
				ite++;
			}
			if (*ite > '0' || *ite < '9') {
				return show(str);
			}
		}
	}
	return show(str);
}
*/
int myAtoi(string str) {
	int n = str.size();
	int i;
	int flag = 0;
	long ans = 0;
	for (i = 0; i < n; i++) {
		if (flag == 0) {
			if (str[i] == '+') flag = 1;
			else if (str[i] == '-') flag = -1;
			else if (str[i] == ' ')   continue;
			else if (str[i] >= '0' && str[i] <= '9') {
				ans = str[i] - '0';
				flag = 1;
			}
			else return 0;
		}
		else {
			if (str[i] >= '0' && str[i] <= '9') {
				ans = ans * 10 + (str[i] - '0');
				if (ans * flag < INT_MIN) return INT_MIN;
				if (ans * flag > INT_MAX) return INT_MAX;
			}
			else if (ans != 0)    break;
			else return 0;
		}
	}
	return ans * flag;
}

/*
int main() {
	string a;
	while (cin >> a) {
		cout << myAtoi(a) << endl;
	}
	return 0;
}
*/