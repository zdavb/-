int getMainData(int *nums,int size) {
	if (size <= 0)
		return -1;
	int base = nums[0];
	int baseCount = 1;
	for (int i = 1; i < size; i++) {
		if (baseCount == 0) {
			base = nums[i];
			baseCount = 1;
		}
		if (nums[i] != base)
			baseCount--;
		else
			baseCount++;	
	}
	//check if the real main data
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (nums[i] == base)
			count++;
	}
	if (count > size / 2)
		return base;
	return -1;
}