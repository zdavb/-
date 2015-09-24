#pragma once
#include <iostream>
#include <time.h>
#include <random>
//问题描述：编写将两个多项式相加的函数
struct QuanticNode {
	struct content {//存储节点的内容
		int val;
		int index;
	} content;
	struct QuanticNode* next;
};
const int VALUERANGE = 100;
const int INDEXRANGE = 10;

QuanticNode* createQuanticList(int size);
void sortDSC(QuanticNode* head,int size);//按照index（指数）降序排列
QuanticNode* addQuanticList(QuanticNode* leftList, QuanticNode* rightList);
void multiQuanticList1(QuanticNode* leftList, QuanticNode* rightList);
void printQuanticList(QuanticNode* head);