#include "Sort.h"

// ������������ܶԱ�
void test()
{
	int a[] = { 6,1,2,7,9,3,4,5,10,8 };
	Print(a, sizeof(a) / sizeof(a[0]));
	QuickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	Print(a, sizeof(a) / sizeof(a[0]));
}
int main()
{
	TestOP();
	//test();
	return 0;
}