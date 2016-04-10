#include <iostream>
#include "problem1.h"
#include "problem2.h"
#include "problem4.h"
#include "problem6.h"
using namespace std;

void test1() {
	const int SIZE = 10;
	struct Node *head = createList(SIZE);
	cout << "打印list：";
	printList(head);
	freeList(head);
}
void test2() {
	const int SIZE = 10;
	struct Node* lHead = createList(SIZE);
	cout << "打印list：";
	printList(lHead);

	struct Node nodes[5];
	nodes[0].val = 1;
	nodes[0].next = &nodes[1];
	nodes[1].val = 3;
	nodes[1].next = &nodes[2];
	nodes[2].val = 4;
	nodes[2].next = &nodes[3];
	nodes[3].val = 6;
	nodes[3].next = &nodes[4];
	nodes[4].val = 8;
	nodes[4].next = NULL;
	cout << "P的list：";
	printList(&nodes[0]);
	struct Node *newList = printLots(lHead, &nodes[0]);
	cout << "新的list：";
	printList(newList);
	freeList(lHead);
}
void test44(struct Node* (*func)(struct Node*,struct Node*)) {
	struct Node lefts[5];
	struct Node rights[5];
	lefts[0].val = 1; lefts[0].next = &lefts[1];
	lefts[1].val = 3; lefts[1].next = &lefts[2];
	lefts[2].val = 4; lefts[2].next = &lefts[3];
	lefts[3].val = 5; lefts[3].next = &lefts[4];
	lefts[4].val = 6; lefts[4].next = NULL;

	rights[0].val = 3; rights[0].next = &rights[1];
	rights[1].val = 6; rights[1].next = &rights[2];
	rights[2].val = 8; rights[2].next = &rights[3];
	rights[3].val = 9; rights[3].next = &rights[4];
	rights[4].val = 10; rights[4].next = NULL;

	cout << "第一个list是：";
	printList(&lefts[0]);
	cout << "第二个list是：";
	printList(&rights[0]);

	cout << "两个list的交是：";
	struct Node* head = func(&lefts[0], &rights[0]);
	printList(head);
}
void test4(void) {
	test44(getIntersect);
	test44(getUnion);
}

void test5(void) {
	const int size = 10;
	//生成两个随机的序列
	QuanticNode* left = createQuanticList(10);
	QuanticNode* right = createQuanticList(5);

	cout << "第一个list的原始数据";
	printQuanticList(left);
	cout << endl <<"第二个list的原始数据";
	printQuanticList(right);

	//return;
	sortDSC(left,10);
	sortDSC(right,5);

	cout <<endl<< "第一个list加工后的数据";
	printQuanticList(left);
	cout <<endl<< "第二个list加工后的数据";
	printQuanticList(right);

	cout <<endl<< "两个list相加后的数据";
	QuanticNode* head = addQuanticList(left, right);
	printQuanticList(head);
	cout << endl;
}
int main() {
	//test1();
	//test2();
	//test4();
	test5();
	system("pause");
} 