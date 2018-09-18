#include<iostream>
#include<string>
#include<vector>
using namespace std;

void show(vector<int>& data) {
	for (auto i : data) {
		cout << i << endl;
	}
}
string multiply(string num1, string num2) {
	string res;
	int mark = 0;//除去前面无用的0
	int k = num1.size();
	int m = num2.size();
	int n = k + m-2;//总的字符串长度
	vector<int> tp(k+m , 0);
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < m; j++) {//模拟乘法运算法则
			tp[n - i - j] += (num1[i] - '0')*(num2[j] - '0'); //多次乘法将每一位上的总和算出来
		}
	}
	show(tp);
	//进位运算
	int count = 0;//进位数
	for (int i = 0; i < k+m; i++) { //先加上进位数字再进行进位运算
		tp[i] += count;
		count = tp[i] / 10;//算出进位数
		tp[i] = tp[i] % 10;
	}
	mark = n + 1;
	while (tp[mark] == 0) {
		mark--;
	}
	if (mark < 0) {
		return "0";
	}
	for (; mark >= 0; mark--) {
		res.push_back(tp[mark]+'0');
	}
	return res;
}

int main() {
	string num1, num2;
	cin >> num1 >> num2;
	cout << multiply(num1, num2) << endl;
	return 0;
}