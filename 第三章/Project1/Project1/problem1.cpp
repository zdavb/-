#include "problem1.h"

struct Node* createList(int size) {
	srand((int)time(NULL));
	struct Node* head = NULL;
	struct Node* prev = head;
	struct Node* cur;
	int count = 0;
	while (count < size) {
		count++;
		cur = (struct Node*)malloc(sizeof(Node));
		cur->val = rand() % size;
		cur->next = NULL;
		if (prev == NULL) {
			head = cur;
			prev = cur;
		}
		else {
			prev->next = cur;
			prev = cur;
		}
	}
	return head;
}
void printList(struct Node* head) {
	struct Node* cur = head;
	while (cur) {
		std::cout << cur->val << " ";
		cur = cur->next;
	}
	std::cout << std::endl;
}
void freeList(struct Node* head) {
	struct Node* cur = head;
	while (cur) {
		struct Node *tmp = cur->next;
		free(cur);
		cur = tmp;
	}
}