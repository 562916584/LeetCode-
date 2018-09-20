#include<iostream>
#include<string>
using namespace std;

string revertseString(string s) {
	int n = s.size();
	string res;
	for (int i = n-1; i >=0; i--) {
		res.push_back(s[i]) ;
	}
	return res;
}
/*
int main() {
	string str;
	cin >> str;
	cout << revertseString(str) << endl;
	return 0;
}
*/