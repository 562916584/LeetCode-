#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};
ListNode* MerageDList(ListNode* left, ListNode* right);
// �ⷨһ ����mutimap���ײ����������ڵ����map
// Ȼ��ȡ���ڵ㣬 �������������
/*
ListNode* sortList(ListNode* head) {
	multimap<int, ListNode*> mul;
	while (head) {
		mul.insert(make_pair(head->val, head));
		head = head->next;
	}
	ListNode dummy(-1);
	head = &dummy;
	for (auto it = mul.begin(); it != mul.end(); it++) {
		head->next = it->second;
		head = head->next;
	}
	head->next = NULL;
	return dummy.next;
}
*/

// �ⷨ�����ϲ�����
// ���ҵ��м������һ��Ϊ����left��right
// Ȼ������ϲ�
ListNode* sortList(ListNode* head) {
	// �ݹ���� ���ص�ǰ�ڵ�
	if (head == NULL || head->next == NULL) {
		return head;
	}
	// �ȶ����ҵ��м�� p2��p1������λ�á���ôÿ��p1����p2��˵���Ǵ����м�λ�õ�
	ListNode* p1 = head;
	ListNode* p2 = p1->next;
	while (p2 != NULL)
	{
		p2 = p2->next;
		if (p2 == NULL) {
			break;
		}
		p2 = p2->next;
		p1 = p1->next;
	}
	// ������ֳ����Σ�p2--p1
	p2 = p1->next;
	p1->next = NULL;
	p1 = head;
	// �ݹ���ȥ��������
	sortList(p1);
	sortList(p2);
	p1=MerageDList(p1, p2);
	return p1;
}

ListNode* MerageDList(ListNode* left, ListNode* right) {
	if (left == NULL) {
		return right;
	}
	if (right == NULL) {
		return left;
	}
	// �Ƚϴ�С
	if (left->val <= right->val) {
		left->next = MerageDList(left->next, right);
		return left;
	}
	else {
		right->next = MerageDList(left, right->next);
		return right;
	}
}
void createList(ListNode *head) {
	ListNode *s;
	ListNode *l = head;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tp;
		cin >> tp;
		s = new ListNode(tp);
		l->next = s;
		l = s;
	}
}
void splay(ListNode* head) {
	ListNode* l = head;
	while (l != NULL) {
		cout << l->val << ' ';
		l = l->next;
	}
	cout << endl;
}
int main() {
	ListNode *head=new ListNode(NULL);
	createList(head);
	head=sortList(head->next);
	splay(head);
	return 0;
}