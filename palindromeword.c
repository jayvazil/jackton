#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char str[])
{
	int start = 0;
	int end = strlen(str ) - 1;
	while(start < end)
	{
		if(tolower(str[start]) != tolower(str[end]))
		{
			return 0;
		}
		start++;
		end--;
	}
	return 1;
}
int main()
{
	char str[100];
	printf("Type a word : ");
	scanf("%s", str);

	if(isPalindrome(str))
	{
		printf("%s is a palindrome .\n", str);
	}

	else
	{
		printf("%s is  not apalindrome .\n", str);
	}
	return 0;
}
