#include<iostream>
#include<vector>
using namespace std;

void show(vector<int>& a);
double findMedianSortArrays(vector<int>& nums1, vector<int>& nums2) {
	int n;
	int j, k;
	vector<int> nums3;
	j = nums1.size();
	k = nums2.size();
	if (j == 0) {
		if (k % 2 == 0) {
			return (double)(nums2[k / 2] + nums2[k / 2 - 1]) / 2;
		}
		return nums2[k / 2] * 1.0;
	}
	if (k == 0) {
		if (j % 2 == 0) {
			return (double)(nums1[(j / 2)] + nums1[(j / 2) - 1]) / 2;
		}
		return nums1[j / 2] * 1.0;
	}

	n = j + k;
	int up=0;
	int i = 0;
	while (i+up<n ) {
		if (up >= j&&i<=k) {
			nums3.push_back(nums2[i]);
			i++;
			continue;
		}
		if (i >= k&&up <= j) {
			nums3.push_back(nums1[up]);
			up++;
			continue;
		}
		if (nums1[up] > nums2[i]) {
			nums3.push_back(nums2[i]);
			i++;
			continue;
		}
		if (nums1[up] < nums2[i]) {
			nums3.push_back(nums1[up]);
			up++;
			continue;
		}
		if (nums1[up] == nums2[i]) {
			nums3.push_back(nums1[up]);
			up++;
			nums3.push_back(nums2[i]);
			i++;
			continue;
		}
	}
	int c = nums3.size();
	if (c % 2 == 0) {
		return (double)(nums3[c / 2] + nums3[c / 2 - 1]) / 2;
	}
	return (double)nums3[c / 2];
}
/*
void show(vector<int>& a) {
	vector<int>::iterator ite = a.begin();
	for (; ite != a.end(); ite++) {
		cout << *ite << ' ';
	}
}

int main() {
	vector<int> a;
	vector<int> b;
	int m, n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		a.push_back(temp);
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		b.push_back(temp);
	}
	cout<<findMedianSortArrays(a, b);
	return 0;
}
*/