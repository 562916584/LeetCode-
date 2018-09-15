#include<iostream>
#include<array>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int ASIZE=4;//C++11推荐这样设置，不推荐define
bool compare(int a, int b)
{
	return a > b;
}
/*

int main()
{
	array<int, ASIZE>c;
	vector<int> v;
	int temp;
	int target=3;
	for (int i = 0; i < ASIZE; i++)
	{
		cin >> c[i];
		//cin >> temp;
		//v.push_back(temp);
	}
	sort(c.begin(), c.end(),compare);
	auto ipthm=find(c.begin(), c.end(), target);
	//bsearch(&target, c.data(), ASIZE, sizeof(int), compare);//c继承的bsearch和qsort暂时不会用，选用sort和find
	//qsort(c.data(), ASIZE, sizeof(int), compare);
	for (int i = 0; i < 4; i++)
	{
		cout << c[i]<<' ';
	}
	cout << endl << *ipthm << endl;
	return 0;
}
*/