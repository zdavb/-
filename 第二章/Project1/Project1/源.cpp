#include <iostream>
#include <random>
#include <time.h>
#include "Problem12.h";
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
int main() {
	testProblem12();
	system("pause");
}