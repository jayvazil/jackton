#include <stdio.h>
int i, t;
float add, av;
int main()
{
	printf("Enter the first number: ");
	scanf("%d", &i);
	printf("Enter the second number: ");
	scanf("%d", &t);
	add = i + t;
	printf("The sum is %f \n", add);
	av = add / 2;
	printf("The average is %f", av);
	return 0;
}
