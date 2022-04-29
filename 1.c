/* 1. Two Sum */
/* Using Radix Sort and Two Pointer, in O(n) time */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int *nums1 =(int*)malloc(sizeof(int) * numsSize); 
	int i = 0, j = numsSize - 1;
	int x, y, k;
	int* result = NULL;
	result = (int*)malloc(sizeof(int) * 2);
	int min = *nums;
	for(k = 0; k < numsSize; k++)
	{
		if(nums[k] < min) min = nums[k];
	}
	for(k = 0; k < numsSize; k++)
	{
		nums1[k] = nums[k] - min;
	}
	radix_sort(nums1, numsSize);
	for(k = 0; k < numsSize; k++)
	{
		nums1[k] += min;
	}
	while(i < j)
	{
		if(nums1[i] + nums1[j] > target) j--;
		else if(nums1[i] + nums1[j] < target) i++;
		else
		{
			x = nums1[i];
			y = nums1[j];
			break;
		}
	}
	k = 0;
	for(i = 0; i < numsSize; i++)
	{
		if(nums[i] == x || nums[i] == y)
		{
			result[k] = i;
			k++;
		}
	}
	if(k == 2) *returnSize = 2;
	else *returnSize = 0;
	return result;
}

int get_max (int *a, int n){
   int max = a[0];
   for (int i = 1; i < n; i++)
      if (a[i] > max)
         max = a[i];
   return max;
}

void radix_sort (int *a, int n){
   int bucket[1000][1000], bucket_cnt[1000];
   int i, j, k, r, NOP = 0, divisor = 1, lar, pass;
   lar = get_max (a, n);
   while (lar > 0){
      NOP++;
      lar /= 10;
   }
   for (pass = 0; pass < NOP; pass++){
      for (i = 0; i < 10; i++){
         bucket_cnt[i] = 0;
      }
      for (i = 0; i < n; i++){
         r = (a[i] / divisor) % 10;
         bucket[r][bucket_cnt[r]] = a[i];
         bucket_cnt[r] += 1;
      }
      i = 0;
      for (k = 0; k < 10; k++){
         for (j = 0; j < bucket_cnt[k]; j++){
            a[i] = bucket[k][j];
            i++;
         }
      }
      divisor *= 10;
   }
}

/* enumeration, in O(n^2) time */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *result = NULL;
    result = (int*)malloc(2 * sizeof(int));
	int i = 0,j;
	while(i < numsSize)
	{
		j = i + 1;
		while(j < numsSize)
		{
			if(nums[i] + nums[j] == target)
			{
				result[0] = i;
				result[1] = j;
				*returnSize = 2;
                return result;
			}	
			j++;
		}	 
		i++;
	}	
    *returnSize = 0;
	return result;
}
