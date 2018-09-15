#include<iostream>
#include<string>
#include<vector>
using namespace std;
class StockSpanner {
public:
	StockSpanner() {
	}

	int next(int price) {
		if (price == NULL) {
			return NULL;
		}
		if (prices.empty() && price >= 0) {
			this->prices.push_back(price);
			return 1;
		}
		//比较以前数字的大小
		prices.push_back(price);
		prices.push_back(-1);
		//递归求连续
		ite = prices.begin();
		time = 0;
		int t = cnm(price);
		prices.pop_back();
		return t;
	}
	int cnm(int price) {
		//递归出口
		if (ite == prices.end()||*ite==-1) {
			if (time == 0) {
				return 1;
			}
			return time + 1;
		}
		if (*ite <= price&&*(++ite) <= price) {
			if (*(ite) != -1) {
				time++;
			}
		}
		else {
			if (*ite > price) {
				time = 0;
			}
			ite++;
		}
		return cnm(price);
	}
private:
	vector<int> prices;
	vector<int>::iterator ite = prices.begin();
	int time = 0;
};
/*
int main() {
	int price;
	StockSpanner *stoc = new StockSpanner();
	while (cin >> price) {
		cout << stoc->next(price) << endl;
	}
}
*/