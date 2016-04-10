#include <iostream>
#include <random>
#include <time.h>
#include "Problem12.h"
#include "Problem16.h"
#include "Problem19.h"

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
void test16() {
	int x,y;
	cout << "请输入x与y（以空格为结尾）:" << endl;
	scanf_s("%d %d", &x, &y);

	cout << calculateMi(x, y) << endl;
}
void test19() {
	//生成随机数
	const int SIZE = 6;
	srand((int)time(NULL));
	int nums[SIZE];
	while (getchar() != 'q') {
		cout << "第19题生成的原始数组";
		for (int i = 0; i < SIZE; i++) {
			nums[i] = rand() % SIZE;
			cout << nums[i] << " ";
		}
		cout << endl;
		cout << "主要元素为：" << getMainData(nums, SIZE) << endl;
	}
}
int main() {
	//testProblem12();
	//test16();
	test19();
	system("pause");
}