#include<vector>
#include<iostream>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> res;
	if (matrix.empty() || matrix[0].empty()) return res;
	int m = matrix.size(), n = matrix[0].size();
	int c = m > n ? (n + 1) / 2 : (m + 1) / 2;
	int p = m, q = n;
	for (int i = 0; i < c; ++i, p -= 2, q -= 2) {
		for (int col = i; col < i + q; ++col)
			res.push_back(matrix[i][col]);
		for (int row = i + 1; row < i + p; ++row)
			res.push_back(matrix[row][i + q - 1]);
		if (p == 1 || q == 1) break;
		for (int col = i + q - 2; col >= i; --col)
			res.push_back(matrix[i + p - 1][col]);
		for (int row = i + p - 2; row > i; --row)
			res.push_back(matrix[row][i]);
	}
	return res;
}

int main() {
	vector<vector<int>> nums;
	vector<int> num;
	int m, n;//mÐÐ nÁÐ
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int tp;
			cin >> tp;
			num.push_back(tp);
		}
		nums.push_back(num);
	}
	num.clear();
	num=spiralOrder(nums);
	for (auto i : num) {
		cout << i << ' ';
	}
	cout << endl;
	return 0;
}