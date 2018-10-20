#include<iostream>
#include<vector>
#include<list>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
	list<int> res;
	for (int i = 0; i < lists.size(); i++) {
		while (lists[i]!=NULL)
		{
			res.push_back(lists[i]->val);
			lists[i] = lists[i]->next;
		}
	}
	res.sort();
	ListNode* head = new ListNode(NULL);
	ListNode* tp = head;
	ListNode* s;
	for (auto i : res) {
		s = new ListNode(i);
		tp->next = s;
		tp = tp->next;
	}
	return head->next;
}
int main() {
	return 0;
}