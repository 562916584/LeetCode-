#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
using namespace std;
void show(int** dis, int n);
string Init(string s);
/*
string longestPalindrom(string& s) {
	
	//���η���
	int n = s.length();
	int m = n;
	string b=s;

	for (int i = 0; i < s.length(); i++) {
		b[i] = s[n-1];
		n--;
	}
	cout << b<<endl;
	//��̬��������
	int **dis;
	dis = new int*[m];
	for (int i = 0; i < m; i++) {
		dis[i] = new int[m];
	}
	//����ʼ����
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			dis[i][j] = 0;
		}
	}
	//���� ��̬�滮��������
	int key_x=0, key_y=0, max = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i] == b[j]) {
				dis[i][j] = 1;
				if ( (i - 1) >= 0 && (j -1) >= 0) {
					if (dis[i - 1][j - 1] != 0) {
						dis[i][j] += dis[i - 1][j - 1];
					}
				}
				//�ҳ������ַ�������
				if (dis[i][j] > max) {
					max = dis[i][j];
					key_x = i;
					key_y = j;
				}
			}
		}
	}
	//�𰸷��� 
	string res="";
	for (int i = 0; i < max; i ++ ) {
		if (max == 0) {
			return res;
		}
		res += s[key_x];
		--key_x;
	}
	//�Ӷ�ά������ �����

	show(dis, m);
	return res;
	
}
*/
string abc(string s) {
	//��ʼ��s
	string ns;
	ns=Init(s);
	int len = ns.length();
	//manachar�㷨����
	int id=0;//�����ַ�������
	int mx = 0;//���ұ߽߱�
	int p[4000];//��po��i��Ϊ���ģ��뾶ΪLen��i���Ļ����ַ���
	memset(p, 0, sizeof(int) * 4000);
	p[0] = 0;
	int max_len=-1;//�����ĳ���
	int max_id=0;//�����ĳ��ȵ�����
	for (int i = 1; i < len; i++) {
		//���߽�,������İ뾶
		if (i < mx) {
			 p[i]= min(p[2 * id - 1], mx - i);
		}
		else {
			p[i] = 1;
		}
		//������,���ӻ��İ뾶
		while (ns[i - p[i]] == ns[i + p[i]]) {
			p[i]++;
		}
		//����max�߽�ͻ�������
		if (i + p[i] > mx) {
			id = i;
			mx = i + p[i];
		}
		max_len = max(p[i] - 1, max_len);
		if (max_len == p[i] - 1) {
			max_id = i;
		}
	}
	for (int i = 0; i<len; i++) {
		cout << p[i]<< ' ';
	}
	cout << max_len << endl;
	s.clear();
	//�����������ַ���
	for (int i = max_id - max_len; i < max_id + max_len; i++) {
		if (ns[i] != '#') {
			s.push_back(ns[i]);
		}
	}
	cout << s << endl;
	return s;
}
string Init(string s) {
	string new_s;
	new_s.push_back('@');
	new_s.push_back('#');
	int p = 2;
	for (int i = 0; i < s.length(); i++) {
		new_s.push_back(s[i]);
		new_s.push_back('#');
	}
	new_s.push_back('$');
	cout << new_s << endl;
	return new_s;
}



/**
void show(int** dis, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dis[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	string a;
	cin >> a;
	cout << abc(a) << endl;
	return 0;
}
*/