#include<iostream>
#include<string>
using namespace std;

string reverseWords(string s) {
	int n = s.size();
	string res;
	if (s.size() == 0) {
		return "";
	}
	int temp=0;//���ÿ�����ʿ�ʼ���±�λ��
	for (int i = 0; i <= n; i++) {
		if (s[i] == ' '|| i==n) {
			for (int j =i-1 ; j >= temp; j--) {
				if (s[j] == ' ') {
					break;
				}
				res.push_back(s[j]);
			}
			//���ո����
			res.push_back(s[i]);
			temp = i;
		}
	}
	return res;
}
int main() {
string str;
//����һ������
getline(cin, str);
cout << reverseWords(str) << endl;
return 0;
}
