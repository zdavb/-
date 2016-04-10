#include "Problem12.h"
#include <math.h>
#include <limits>
#include <stdlib.h>
#include <algorithm>

struct Node {
	int val;
	int index;
};
int cmp(const void* node1,const void* node2){
	struct Node inNode1 = *(struct Node*)node1;
	struct Node inNode2 = *(struct Node*)node2;
	return inNode1.val - inNode2.val;
}
//求最大子序列和
int getMaxSumSubSequence(int *nums) {
	int maxSum = 0;
	int tmpSum = 0;
	for (int i = 0; i < SIZE; i++) {
		tmpSum += nums[i];
		if (tmpSum > maxSum)
			maxSum = tmpSum;
		if (tmpSum < 0)
			tmpSum = 0;
	}
	return maxSum;
}
//求最小子序列和
int getMinSumSubSequence(int *nums) {
	int minSum = nums[0];
	int tmpSum = 0;
	for (int i = 0; i < SIZE; i++) {
		tmpSum += nums[i];
		if (tmpSum < minSum)
			minSum = tmpSum;
		if (tmpSum > 0)
			tmpSum = 0;
	}
	return minSum;
}
//求最小正子序列和
int getPositiveMinSumSubSequence(int *nums) {
	int minSum = INT_MAX;
	int tmpSum = 0;
	for (int i = 0; i < SIZE; i++) {
		tmpSum = 0;
		for (int j = i; j < SIZE; j++) {
			tmpSum += nums[j];
			if (tmpSum < 0)
				continue;
			else if (tmpSum < minSum)
				minSum = tmpSum;
		}
	}
	return minSum;
}
int getPositiveMinSumSubSequence2(int* nums) {
	struct Node nodes[SIZE+1];
	int total = 0;
	int minsum = INT_MAX;

	nodes[0].val = 0;
	nodes[0].index = -1;

	for (int i = 0; i < SIZE; i++) {
		total += nums[i];
		nodes[i+1].val = total;
		nodes[i+1].index = i;
	}
	qsort(nodes, SIZE+1, sizeof(struct Node), cmp);
	for (int i = 0; i < SIZE; i++) {
		struct Node now = nodes[i];
		struct Node next = nodes[i + 1];
		if (now.index < next.index) {//只有当前节点的下标小于下一个节点的下标才有意义
			int val = next.val - now.val;
			if (val < minsum)
				minsum = val;
		}
	}
	return minsum;
}
//求最大子序列乘积
int getMaxMultiSubSequence(int *nums) {
	int result = 0;
	int tmpMax = nums[0];
	int tmpMin = nums[0];

	for (int i = 1; i < SIZE; i++) {
		int now1 = tmpMax*nums[i];
		int now2 = tmpMin*nums[i];

		tmpMax = std::max(std::max(now1, now2), nums[i]);
		tmpMin = std::min(std::min(now1, now2), nums[i]);
		if (tmpMax > result)
			result = tmpMax;
	}
	return result;
}
//求最大子序列乘机
int getMaxMultiSubSequence2(int *nums) {
	int tmpMax = 1;
	int tmpMin = 1;

	int max = 0;
	for (int i = 0; i < SIZE; i++) {
		tmpMax = std::max(std::max(tmpMax*nums[i], tmpMin*nums[i]), nums[i]);
		tmpMin = std::min(std::min(tmpMax*nums[i], tmpMin*nums[i]), nums[i]);

		if (tmpMax > max)
			max = tmpMax;
	}
	return max;
}