#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//ǰ�巨 ��������
ListNode *headList = new ListNode(NULL);
ListNode *p = headList;
void creatList(int tp) {
	ListNode *s;
	s = new ListNode(tp);
	p->next = s;
	p = p->next;
}
//�ݹ� ���巨
ListNode* reverseList(ListNode* head) {
	ListNode* pReversedHead = NULL;
	ListNode* pNode = head;
	ListNode* pPrev = NULL;
	while (pNode != NULL)
	{
		ListNode* pNext = pNode->next;

		if (pNext == NULL)
			pReversedHead = pNode;

		pNode->next = pPrev;

		pPrev = pNode;
		pNode = pNext;
	}

	return pReversedHead;
}
int main() {
	int n,tp;
	//ǰ����պ�
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tp;
		creatList(tp);
	}
	headList =reverseList(headList);
	while (headList != NULL) {
		cout << headList->val << ' ';
		headList = headList->next;
	}
	return 0;
}