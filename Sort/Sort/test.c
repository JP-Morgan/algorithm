#include "Sort.h"

// 测试排序的性能对比
void test()
{
	int a[] = { 5,3,7,8,10,2,4,1,6,9 };
	Print(a, sizeof(a) / sizeof(a[0]));
	SelectSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}
int main()
{
	TestOP();
	//test();
	return 0;
}