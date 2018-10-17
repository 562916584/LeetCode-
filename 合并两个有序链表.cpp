#include<iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int n) :val(n), next(NULL) {};
};
void creatList(ListNode* head) {
	int n;
	int tp;
	ListNode* s;
	ListNode* l=head;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tp;
		s = new ListNode(tp);
		l->next = s;
		l = s;
	}
}
void Display(ListNode* head) {
	ListNode* l = head->next;
	while (l != NULL) {
		cout << l->val << ' ';
		l = l->next;
	}
	cout << endl;
}
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* res = new ListNode(NULL);
	ListNode* l = res;
	ListNode* list1 = l1;
	ListNode* list2 = l2;
	while (list1 != NULL && list2 != NULL) {
		if (list1->val > list2->val) {
			l->next = new ListNode(list2->val);
			l = l->next;
			list2 = list2->next;
			continue;
		}
		else if (list1->val < list2->val) {
			l->next = new ListNode(list1->val);
			l = l->next;
			list1 = list1->next;
			continue;
		}
		else {
			l->next = new ListNode(list1->val);
			l = l->next;
			l->next = new ListNode(list2->val);
			l = l->next;
			list1 = list1->next;
			list2 = list2->next;
		}
	}
	while (list1 != NULL) {
		l->next = new ListNode(list1->val);
		l = l->next;
		list1 = list1->next;
	}
	while (list2 != NULL) {
		l->next = new ListNode(list2->val);
		l = l->next;
		list2 = list2->next;
	}
	return res;
}
int main() {
	ListNode* head1 = new ListNode(NULL);
	ListNode* head2 = new ListNode(NULL);
	ListNode* res;
	creatList(head1);
	creatList(head2);
	res = mergeTwoLists(head1->next, head2->next);
	Display(res);
	return 0;
}