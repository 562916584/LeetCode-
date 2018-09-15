#include<iostream>
using namespace std;
class ba {
public:
	ba(int temp) :ta(temp) {
	};
	ba() {
	};
	~ba() {
	};

	ba& operator=(const ba& tp) {
		ta = tp.ta;
		return *this;
	};

	void show();
private:
	int ta;
};
void ba::show() {
	cout << ta << endl;
}
/*
int main() {
	ba case1(10);

	ba *temp = &case1;
	cout << sizeof(temp) << endl;

	temp->show();
	(*temp).show();

	cout << temp << endl;
	ba case2;
	case2 = case1;
	case2.show();

	int a = 10;
	int *b = &a;
	cout << b << endl;
	return 0;
}
*/