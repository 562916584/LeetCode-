#include<iostream>
#include<string>
#include<deque>
#include<math.h>
using namespace std;

/*
int show(string& data) {
	//cout << data;
	int pt=0;//������һ��res
	int n = data.length();
	int count = n;//��¼λ��
	bool is_fu = false;
	int res = 0;
	bool is_zero = true;
	bool is_yuejie = false;
	for (int i = 0; i < n; i++) {
		if (data[i] == '-') {
			is_fu = true;
			continue;
		}
		//���ַ���ת������
		if (data[i] >= '0' && data[i] <= '9') {
			pt = res;
			res = res + (data[i] - '0')*pow(10, n - 1 - i);
			if (pt > res) {//intԽ����
				is_yuejie = true;
				break;
			}
			if (res == 0&&is_zero) {//ǰ�����
				count--;
			}
			else if (res > 0) {
				is_zero = false;//�������
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
	int is_first = 0; //��û��ʼʶ������
	for (int i = 0; i < (int)str.length(); i++) {
		data.push_back(str[i]);
	}
	str.clear();
	data.push_back('#');
	deque<char>::iterator ite = data.begin();
	while (*ite!='#') {

		//�жϷǷ��ַ���ʱ��ֱ���˳�
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
			if (is_first == 1) {//ֻ�ܶ�ȡ����  ��ȡ���������˳�
				return show(str);
			}
			str.push_back(*ite);
			is_first = 1;//��ʼʶ��������
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