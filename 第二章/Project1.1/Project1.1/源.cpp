#include <iostream>
#include <algorithm>
using namespace std;
//最小正子序列和(minimun subsequences sum)
const int MAXINT = 999999;
struct Node
{
	int sum;
	int xiabiao;

};
int cmp(const Node& t1, const Node& t2)
{
	return t1.sum < t2.sum;
}

//nlogn
int minPositiveSubsequenceSum(int data[], int len)
{
	Node* temp = new Node[len+1];
	temp[0].sum = 0;
	temp[0].xiabiao = -1;
	
	int total = 0;
	for (int i = 0; i<len; i++)
	{
		total += data[i];
		temp[i + 1].sum = total;
		temp[i+1].xiabiao = i;
	}
	//对temp.sum[]进行从小到大排序，sum[]中只有相邻的两个数才有可能 得到 最小正子序列和
	sort(temp, temp + len+1, cmp);
	int sum = MAXINT;
	for (int i = 0; i<len ; i++)
	{
		if (temp[i].xiabiao < temp[i + 1].xiabiao)
		{
			if (temp[i + 1].sum - temp[i].sum < sum)
				sum = temp[i + 1].sum - temp[i].sum;
		}
	}
	delete temp;
	temp = 0;
	return sum;
}

//最小子序列和(minimun subsequences sum),logn
int minSubsequenceSum(int data[], int len)
{
	int curMinSum = data[0];
	int minSum = data[0];
	for (int i = 1; i<len; i++)
	{
		if (curMinSum >= 0)
			curMinSum = data[i];
		else
			curMinSum = curMinSum + data[i];

		if (curMinSum < minSum)
			minSum = curMinSum;
	}
	return minSum;
}
int main()
{
	int data[] = { -18,20,-41,-1,7,32,-9,-41 };
	int len = sizeof(data) / sizeof(data[0]);
	cout << minPositiveSubsequenceSum(data, len) << endl;
	cout << minSubsequenceSum(data, len) << endl;
	system("pause");
	return 0;
}
