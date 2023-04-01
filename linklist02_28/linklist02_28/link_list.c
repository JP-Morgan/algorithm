#include "link_list.h"
//注意：什么时候该断言什么时候不断言
//主要看具场景 "一定不能为空就要断言"
// void add(**phead);
//比如：assert(phead);//防止传错数据(都要判断)//为空时所以找不到链表.
//	   assert(*phead);//防止null链表//有链表，但找不到后续的数据.

//打印
void ListPrintf(LS* phead)
{
	LS* cur = phead;
	while (cur!=NULL)
	{
		printf("%d->", cur->Data);
		cur = cur->next;
	}
	printf("NULL\n");
}
//尾插
void ListPushBack(LS** pback, SLTDataType x)
{
	assert(pback);
	LS* NewList=BuySLTNode(x);
	
	if (*pback == NULL)
	{
		*pback=NewList;
	}
	else
	{
		LS* tail = *pback;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = NewList;
	}
	
}
//扩容
LS* BuySLTNode(SLTDataType x)
{
	LS* NewList = (LS*)malloc(sizeof(LS));
	if (NewList == NULL)
	{
		printf("malloc fail");
		return;
	}
	NewList->Data = x;
	NewList->next = NULL;
	return NewList;
}
//头插
void ListPushFront(LS** phand, SLTDataType X)
{
	assert(phand);
	LS* NewList=BuySLTNode(X);
	if (phand==NULL)
	{
		*phand = NewList;
	}
	else
	{
		NewList->next = *phand;
		*phand = NewList;
	}
}
//尾删
void ListPopBack(LS** pback)
{
	
	assert(pback);//为空时所以找不到链表.
	assert(*pback);//有链表，但找不到后续的数据.
	//void test1(int* p)
	//{
	//	assert(p != NULL);//当null不为null为假
	//	printf("%d\n", 123);
	//}
	//int main(void)
	//{
	//	test1(NULL);
	//}
	if ((*pback)->next==NULL)
	{
		free(*pback);
		*pback = NULL;
	}
	else
	{
		LS* cur = *pback;
		LS* slow = *pback;
		while (cur->next)
		{
			slow = cur;
			cur = cur->next;
		}
		slow->next = NULL;
		free(cur);
		cur = NULL;
	}
}
//头删
void ListPopFront(LS** phand)
{
	assert(phand);//因为
	assert(*phand);
	LS* ListDelete = *phand;
	LS* Newlist = *phand;
	Newlist = ListDelete->next;
	ListDelete->next = NULL;
	free(ListDelete);
	*phand = Newlist;
}
//查找
LS* ListFind(LS* sfind, SLTDataType x)
{
	LS* find = sfind;
	while (find)
	{
		if (find->Data == x)
		{
			return find;

		}
		find = find->next;
	}
	return NULL;
}
//pos位置插入
void Listinsert(LS** pphead, LS* pos, SLTDataType x)
{
	assert(pphead);
	assert(pos);
	if (pos == *pphead)
	{
		ListPushFront(pphead, x);
	}
	else
	{
		LS* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		LS* Newlist = BuySLTNode(x);
		Newlist = prev->next;
		Newlist->next = pos;
	}
}
//pos位置删除
void ListErase(LS** pphead, LS* pos)
{
	assert(pphead);//有没有链表
	assert(pos);//
	assert(*pphead);//链表是否为null
	if (*pphead == pos)
	{
		ListPopFront(pphead);
	}
	else
	{
		LS* prev = *pphead;
		while (prev->next!=pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}
}