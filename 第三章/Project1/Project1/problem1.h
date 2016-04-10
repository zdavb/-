#pragma once
#include <time.h>
#include <random>
#include <iostream>
struct Node {
	int val;
	struct Node* next;
};
struct Node* createList(int size);
void printList(struct Node* head);
void freeList(struct Node* head);