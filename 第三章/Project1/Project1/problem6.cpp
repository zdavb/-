#include "problem6.h"

QuanticNode* createQuanticList(int size) {
	srand((int)time(NULL)+rand());
	
	QuanticNode* head = NULL;
	QuanticNode* cur = NULL;
	for (int i = 0; i < size; i++) {
		int val = rand() % 100 + 1;
		int index = rand() % 10 + 1;

		QuanticNode* newNode = new QuanticNode;
		newNode->content.val = val;
		newNode->content.index = index;
		newNode->next = NULL;

		if (cur)
			cur->next = newNode;
		else {
			head = newNode;
		}
		cur = newNode;
	}
	return head;
}
void freeQuanticList(QuanticNode* head) {
	QuanticNode* next = NULL;
	while (head) {
		next = head->next;
		free(head);
		head = next;
	}
}

void bubbleSort(QuanticNode* head,int size) {
	QuanticNode* cur = head;
	QuanticNode* next;
	int index = 0;
	while (size > 0) {
		for (cur = head,index=0; index < size-1; cur=cur->next,index++) {
			next = cur->next;
			if (cur->content.index < next->content.index) {
				//swap content
				int tmpIndex = cur->content.index;
				int tmpVal = cur->content.val;
				cur->content = next->content;
				next->content.index = tmpIndex;
				next->content.val = tmpVal;
			}
		}
		size--;
	}
}
//按照index顺序进行排序，如果相同就合并
void sortDSC(QuanticNode* head,int size) {//添加size引用
	bubbleSort(head,size);

	QuanticNode* prev = head;
	QuanticNode* cur = prev->next;
	QuanticNode* tmp;
	while (cur) {
		if (prev->content.index == cur->content.index) {
			prev->content.val += cur->content.val;
			prev->next = cur->next;
			tmp = cur;
			cur = cur->next;
			delete tmp;
		}
		else {
			prev = prev->next;
			cur = cur->next;
		}
	}
}
//将两个多项式相加
QuanticNode* addQuanticList(QuanticNode* leftList, QuanticNode* rightList) {
	QuanticNode* head = new QuanticNode;
	QuanticNode* cur = head;
	QuanticNode* prev = NULL;
	while (leftList && rightList) {
		int leftIndex = leftList->content.index;
		int rightIndex = rightList->content.index;

		if (leftIndex > rightIndex) {
			cur->content = leftList->content;
			cur->next = NULL;
			leftList = leftList->next;
		}
		else if (leftIndex == rightIndex) {
			cur->content.val = leftList->content.val + rightList->content.val;
			cur->content.index = leftIndex;
			cur->next = NULL;

			leftList = leftList->next;
			rightList = rightList->next;
		}
		else {
			cur->content = rightList->content;
			cur->next = NULL;
			rightList = rightList->next;
		}
		prev = cur;
		cur = new QuanticNode;
		prev->next = cur;
	}
	while (leftList) {
		cur->content = leftList->content;
		prev = cur;
		cur = new QuanticNode;
		prev->next = cur;
	}
	while (rightList) {
		cur->content = rightList->content;
		prev = cur;
		cur = new QuanticNode;
		prev->next = cur;
	}
	prev->next = NULL;
	return head;
}

//打印list数据
void printQuanticList(QuanticNode* head) {
	while (head) {
		int index = head->content.index;
		int val = head->content.val;
		std::cout << "(" << val << "," << index << ") ";
		head = head->next;
	}
}
