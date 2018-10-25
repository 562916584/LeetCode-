#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};
bool compare(pair<int ,int> p1, pair<int, int>p2) {
	return p1.first < p2.first;
}
ListNode* rotateRight(ListNode* head, int k) {
	ListNode* l=head;
	vector<pair<int, int>> list;
	int count = 0;
	int tp=0;
	while (l != NULL) {
		list.push_back(pair<int, int>(count, l->val));
		count++;
	}
	vector<pair<int, int>>::iterator ite = list.begin();
	// ����ÿ���ڵ��λ��
	for (; ite != list.end();ite++) {
		tp = (*ite).first;
		tp = (tp + k) % count;
		(*ite).first = tp;
		tp = 0;
	}
	sort(list.begin(), list.end(), compare);
	l = head;
	ite = list.begin();
	while (l != NULL) {
		l->val = (*ite).second;
		l = l->next;
		ite++;
	}
	return	head;
}
ListNode* rotateRight(ListNode* head, int k) {
	if (head == nullptr || head->next == nullptr) return head;
	int len = 1;
	ListNode *p = head;
	while (p->next) {//��������
		p = p->next;
		++len;
	}
	p->next = head;//��������β������һ����    
	k %= len;
	for (int i = 0; i<len - k; ++i) {//�ҵ���ת�㴦
		p = p->next;
	}
	head = p->next;//�Ͽ���������ͷ��㣬����β�ڵ�
	p->next = nullptr;
	return head;
}

int mian() {
	return 0;
}