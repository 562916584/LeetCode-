#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int reverse(int x) {
	vector<int> res;
	bool isFu = false;
	if (x == 0) {
		return 0;
	}
	if (x < 0) {
		isFu = true;
	}
	long tp = fabs(x);
	int t;
	while (tp != 0) {
		t = tp % 10;
		tp = tp / 10;
		res.push_back(t);
	}
	
	vector<int>::iterator ite = res.end();
	ite--;
	t = res.size();
	tp = 0;
	while (ite != res.begin()) {
		if (*ite == 0) {
			ite--;
			t--;
		}
		else
		{
			break;
		}
	}
	for (ite = res.begin(); ite != res.end(); ite++) {
		if (t < 0) {
			break;
		}
		tp += *ite*pow(10, t - 1);
		if (tp >= INT_MAX||tp<=INT_MIN) {
			return 0;
		}
		t--;
	}
	if (isFu) {
		return tp*-1;
	}
	else
	{
		return tp;
	}
}
int main() {
	int n;
	cin >> n;
	cout<<reverse(n);
	return 0;
}