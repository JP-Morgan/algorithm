#include <stdio.h>
int main()
{
	char str[10] = { 0 };
	char str1[10] = { 0 };
	scanf("%s", str);
	scanf("%s", &str1);
	printf("%s", str);
	printf("%s", &str1);
	return 0;
}