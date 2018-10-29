#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};
// 快 慢指针解决问题
// 如果链表存在环 那么慢指针总会追上快指针 
bool hasCycle(ListNode *head) {
	if (head == NULL || head->next == NULL) {
		return false;
	}
	ListNode* quick = head->next;
	ListNode* slow = head;
	while (quick != NULL) {
		if (quick == slow) {
			return true;
		}
		else {
			quick = quick->next;
			if (quick == NULL) {
				return false;
			}
			else
			{
				quick = quick->next;
				slow = slow->next;
			}
		}
	}
	return false;
}
void creatListA1(int n, ListNode* head) {
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
int main() {
	ListNode *head = new ListNode(NULL);
	int n;
	cin >> n;
	creatListA1(n, head);
	cout << hasCycle(head);
	return 0;
}