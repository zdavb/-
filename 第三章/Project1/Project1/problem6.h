#pragma once
#include <iostream>
#include <time.h>
#include <random>
//������������д����������ʽ��ӵĺ���
struct QuanticNode {
	struct content {//�洢�ڵ������
		int val;
		int index;
	} content;
	struct QuanticNode* next;
};
const int VALUERANGE = 100;
const int INDEXRANGE = 10;

QuanticNode* createQuanticList(int size);
void sortDSC(QuanticNode* head,int size);//����index��ָ������������
QuanticNode* addQuanticList(QuanticNode* leftList, QuanticNode* rightList);
void multiQuanticList1(QuanticNode* leftList, QuanticNode* rightList);
void printQuanticList(QuanticNode* head);