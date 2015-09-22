#include <iostream>
#include <random>
#include <time.h>
#include "Problem12.h";
using namespace std;

void testProblem12() {
	//生成随机序列
	int nums[SIZE];
	srand((int)time(NULL));
	cout << "待处理的数组为：" << endl;
	for (int i = 0; i < SIZE; i++) {
		nums[i] = rand() % 100-50;
		cout << nums[i] << " ";
	}
	
	cout << endl;
	cout << "最大子序列和：" << getMaxSumSubSequence(nums)<<endl;
	cout << "最小子序列和:" << getMinSumSubSequence(nums) << endl;
	cout << "最小正整数序列和:" << getPositiveMinSumSubSequence(nums) << endl;
	cout << "最小正整数序列和:" << getPositiveMinSumSubSequence2(nums) << endl;
	cout << "最大子序列乘机：" << getMaxMultiSubSequence(nums) << endl;
}
int main() {
	testProblem12();
	system("pause");
}