#include <stdio.h>

int main()
{
	int num, reversed = 0, remainder,   original;
	printf("Enter  numbers : ");
	scanf("%d", &num);

	original = num;
	while (num != 0)
{
	remainder = num % 10;
	reversed = reversed * 10 + remainder;
	num /= 10;
}
printf("The reversed number is: %d",reversed);
		return 0;
	}
