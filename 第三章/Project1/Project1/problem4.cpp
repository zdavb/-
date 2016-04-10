#include "problem4.h"
//获取两个list的交
struct Node *getIntersect(struct Node* left, struct Node* right) {
	struct Node* head = NULL;
	struct Node* cur = NULL;
	struct Node* next;
	while (left && right) {
		int lval = left->val;
		int rval = right->val;
		if (lval == rval) {
			if (cur)
				cur->next = left;
			else
				head = left;
			cur = left;
			left = left->next;
			right = right->next;
		}
		else if (lval < rval) {
			left = left->next;
		}
		else {
			right = right->next;
		}
	}
	return head;
}
//获取两个list的并
struct Node* getUnion(struct Node* left, struct Node* right) {
	struct Node* head = NULL;
	struct Node* cur = NULL;
	int lval, rval;

	lval = left->val;
	rval = right->val;
	if (lval == rval) {
		head = left;
		left = left->next;
		right = right->next;
	}
	else if (lval < rval) {
		head = left;
		left = left->next;
	}
	else {
		head = right;
		right = right->next;
	}
	cur = head;
	while (left && right) {
		lval = left->val;
		rval = right->val;

		if (lval == rval) {
			cur->next = left;
			cur = left;
			left = left->next;
			right = right->next;
		}
		else if (lval > rval) {
			cur->next = right;
			cur = right;
			right = right->next;
		}
		else {
			cur->next = left;
			cur = left;
			left = left->next;
		}
	}
	if (left)
		cur->next = left;
	if (right)
		cur->next = right;
	return head;
}