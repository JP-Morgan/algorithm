#define _CRT_SECURE_NO_WARNINGS
#include "test.h"
void SLTest()
{
	List* str=NULL;
	SListPushBack(&str, 1);
	SListPushBack(&str, 2);
	SListPushBack(&str, 3);
	SListPushBack(&str, 4);
	SListPushBack(&str, 5);
	SListPushBack(&str, 6);
	SLPrintf(str);
	SLPopback(&str);
	SLPopback(&str);
	SLPrintf(str);

}
int main()
{

	SLTest();
	return 0;
}