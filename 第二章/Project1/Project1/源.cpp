#include <iostream>
#include <random>
#include <time.h>
#include "Problem12.h"
#include "Problem16.h"
#include "Problem19.h"

using namespace std;

void testProblem12() {
	//�����������
	int nums[SIZE];
	srand((int)time(NULL));
	cout << "�����������Ϊ��" << endl;
	for (int i = 0; i < SIZE; i++) {
		nums[i] = rand() % 100-50;
		cout << nums[i] << " ";
	}
	
	cout << endl;
	cout << "��������кͣ�" << getMaxSumSubSequence(nums)<<endl;
	cout << "��С�����к�:" << getMinSumSubSequence(nums) << endl;
	cout << "��С���������к�:" << getPositiveMinSumSubSequence(nums) << endl;
	cout << "��С���������к�:" << getPositiveMinSumSubSequence2(nums) << endl;
	cout << "��������г˻���" << getMaxMultiSubSequence(nums) << endl;
}
void test16() {
	int x,y;
	cout << "������x��y���Կո�Ϊ��β��:" << endl;
	scanf_s("%d %d", &x, &y);

	cout << calculateMi(x, y) << endl;
}
void test19() {
	//���������
	const int SIZE = 6;
	srand((int)time(NULL));
	int nums[SIZE];
	while (getchar() != 'q') {
		cout << "��19�����ɵ�ԭʼ����";
		for (int i = 0; i < SIZE; i++) {
			nums[i] = rand() % SIZE;
			cout << nums[i] << " ";
		}
		cout << endl;
		cout << "��ҪԪ��Ϊ��" << getMainData(nums, SIZE) << endl;
	}
}
int main() {
	//testProblem12();
	//test16();
	test19();
	system("pause");
}