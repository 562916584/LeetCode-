#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};
ListNode* MerageDList(ListNode* left, ListNode* right);
// 解法一 利用mutimap（底层红黑树）将节点存入map
// 然后取出节点， 将有序链表输出
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

// 解法二：合并排序法
// 先找到中间的链表，一分为二，left和right
// 然后排序合并
ListNode* sortList(ListNode* head) {
	// 递归出口 返回当前节点
	if (head == NULL || head->next == NULL) {
		return head;
	}
	// 先二分找到中间点 p2比p1快三个位置。那么每次p1对于p2来说都是处于中间位置的
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
	// 将链表分成两段，p2--p1
	p2 = p1->next;
	p1->next = NULL;
	p1 = head;
	// 递归下去继续二分
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
	// 比较大小
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