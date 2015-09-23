#include "Problem16.h"
int getSize(int y) {
	int size = 0;
	while (y) {
		y = y >> 1;
		size++;
	}
	return size;
}
int calculateMi(int x, int y) {
	int size = getSize(y);//求y的位数
	int *nums = new int[size];

	nums[0] = x;
	for (int i = 1; i < size; i++) {
		nums[i] = nums[i - 1] * nums[i - 1];
	}

	int res = 1;
	int index = 0;
	while (y) {
		int tail = y % 2;
		y = y / 2;
		if (tail)
			res = res*nums[index];
		index++;
	}
	return res;
}