#include "stack.h"
bool a(int c)
{
	return c == 0;
}
int main()
{
	int c = 1;//���ؼ�
	int b = 0;//������
	int as1=a(c);//����0
	int as2=a(b);//����1
	printf("%d\n", as1);
	printf("%d\n", as2);
	//����˭Ϊ��˭����
	assert(as1);
	assert(as2);

	//˭Ϊ��˭����
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