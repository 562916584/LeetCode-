#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
// 尾插法
void creatListA(int n, ListNode* head) {
	int tp;
	ListNode* s;
	ListNode* r = head;
	for (int i = 0; i < n; i++) {
		cin >> tp;
		s = new ListNode(tp);
		r->next = s;
		r = s;
	}
}
// 头插法
void creatListB(int n, ListNode* head) {
	ListNode* s;
	head->next = NULL;
	int tp;
	for (int i = 0; i < n; i++) {
		cin >> tp;
		s = new ListNode(tp);
		s->next = head->next;
		head->next = s;
	}
}
void DisPlay(ListNode *L)
{
	ListNode *p=L;
	while (p != NULL)
	{
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	// 头部
	ListNode* head = new ListNode(NULL);
	ListNode* l = head;
	ListNode* s;
	ListNode* list1=l1;
	ListNode* list2=l2;
	int m, n;
	int count = 0;
	int res = 0;
	while (list1 != NULL && list2 != NULL) {
		m = list1->val;
		n = list2->val;
		res = count + m + n;
		if (res >= 10) {
			count = res / 10;
			res = res % 10;
		}
		else {
			count = 0;
		}
		s = new ListNode(res);
		l->next = s;
		l = s;
		list1 = list1->next;
		list2 = list2->next;
	}
	while (list1 != NULL) {
		m = list1->val;
		res = m + count;
		if (res >= 10) {
			count = res / 10;
			res = res % 10;
		}
		else
		{
			count = 0;
		}
		s = new ListNode(res);
		l->next = s;
		l = s;
		list1 = list1->next;
	}
	while (list2 != NULL) {
		m = list2->val;
		res = m + count;
		if (res >= 10) {
			count = res / 10;
			res = res % 10;
		}
		else
		{
			count = 0;
		}
		s = new ListNode(res);
		l->next = s;
		l = s;
		list2 = list2->next;
	}
	if (list1 == NULL && list2 == NULL) {
		if (count != 0) {
			s = new ListNode(count);
			l->next = s;
			l = s;
		}
		return head->next;
	}
	return head->next;
}


int main() {
	ListNode* head1 = new ListNode(NULL);
	ListNode* head2 = new ListNode(NULL);
	ListNode* res;
	int m, n;
	cin >> m;
	creatListA(m,head1);
	cin >> n;
	creatListA(n,head2);
	//DisPlay(head1);
	//DisPlay(head2);
	res = addTwoNumbers(head1->next, head2->next);
	DisPlay(res);
	return 0;
}
