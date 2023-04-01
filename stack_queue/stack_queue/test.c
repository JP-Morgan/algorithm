#include "stack.h"
bool a(int c)
{
	return c == 0;
}
int main()
{
	int c = 1;//返回假
	int b = 0;//返回真
	int as1=a(c);//返回0
	int as2=a(b);//返回1
	printf("%d\n", as1);
	printf("%d\n", as2);
	//断言谁为假谁报错
	assert(as1);
	assert(as2);

	//谁为真谁报错
	assert(!as1);
	assert(!as2);
}
//int main()
//{
//	ST st;
//	Init(&st);
//	Push(&st, 1);
//	Push(&st, 2);
//	Push(&st, 3);
//	while (!Empty(&st))
//	{
//		printf("%d\n", Top(&st));
//		Pop(&st);
//	}
//	Destroy(&st);
//	return 0;
//}