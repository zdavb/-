#include "problem2.h"
struct Node* printLots(struct Node* l, struct Node* p) {
	int lbase = 1;
	int pValue = 0;
	struct Node* head = NULL;
	struct Node* cur = NULL;
	while (p) {
		int val = p->val;
		p = p->next;
		while (lbase < val) {
			struct Node* next = l->next;
			free(l);
			lbase++;
			l = next;
		}
		if (cur) 
			cur->next = l;
		else
			head = l;

		cur = l;
		l = l->next;lbase++;
	}
	//当P为空的时候，如果L后面还有其他元素，全部free、
	cur->next = NULL;
	while (l) {
		struct Node* next = l->next;
		free(l);
		l = next;
	}
	return head;
}