#include "link_list.h"
void test()
{
	LS* list = NULL;
	ListPushBack(&list, 1);
	ListPushBack(&list, 2);
	ListPushBack(&list, 3);
	ListPushBack(&list, 4);
	ListPushBack(&list, 5);

	ListPrintf(list);
	LS* find=ListFind(list, 2);
	find->Data *= 2;
	ListPrintf(list);
}
void test1()
{
	LS* list = NULL;
	ListPushBack(&list, 1);
	ListPushBack(&list, 2);
	ListPushBack(&list, 3);
	ListPushBack(&list, 4);
	ListPushBack(&list, 5);
	ListPrintf(list);
	ListPopBack(&list);
	ListPopBack(&list);
	ListPopBack(&list);
	ListPopBack(&list);
	ListPopBack(&list);
	ListPopBack(&list);
	ListPopBack(&list);
	ListPrintf(list);
}
int main()
{
	test1();

	return 0;
}
