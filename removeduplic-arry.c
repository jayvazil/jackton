#include <stdio.h>

int removeDuplicates(int nums[], int n)
{
	int i, j, k;
	for(i = 0; i < n; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			if(nums[i] == nums[j])
			{
				for (k = j; k < n - 1; k++)
				{
					nums[k] = nums[k + 1];
				}
				n--;
				j--;
			}
		}
	}
	printf("Array after removing duplicates: ");
	for (i = 0; i < n; i++)
	{
		printf("%d", nums[i]);
	}
	printf("\n");
}
int main()
{
	int nums[] = {1, 2, 2, 3, 4, 4, 5, 5, 6};
	int n = sizeof(nums) / sizeof(nums[0]);
	printf("Original array: ");
	for(int i = 0; i < n; i++)
	{
		printf("%d", nums[i]);
	}
	printf("\n");
	removeDuplicates(nums, n);
	return 0;
}
