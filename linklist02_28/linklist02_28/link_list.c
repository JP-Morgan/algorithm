#include "link_list.h"
//ע�⣺ʲôʱ��ö���ʲôʱ�򲻶���
//��Ҫ���߳��� "һ������Ϊ�վ�Ҫ����"
// void add(**phead);
//���磺assert(phead);//��ֹ��������(��Ҫ�ж�)//Ϊ��ʱ�����Ҳ�������.
//	   assert(*phead);//��ֹnull����//���������Ҳ�������������.

//��ӡ
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
//β��
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
//����
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
//ͷ��
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
//βɾ
void ListPopBack(LS** pback)
{
	
	assert(pback);//Ϊ��ʱ�����Ҳ�������.
	assert(*pback);//���������Ҳ�������������.
	//void test1(int* p)
	//{
	//	assert(p != NULL);//��null��ΪnullΪ��
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
//ͷɾ
void ListPopFront(LS** phand)
{
	assert(phand);//��Ϊ
	assert(*phand);
	LS* ListDelete = *phand;
	LS* Newlist = *phand;
	Newlist = ListDelete->next;
	ListDelete->next = NULL;
	free(ListDelete);
	*phand = Newlist;
}
//����
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
//posλ�ò���
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
//posλ��ɾ��
void ListErase(LS** pphead, LS* pos)
{
	assert(pphead);//��û������
	assert(pos);//
	assert(*pphead);//�����Ƿ�Ϊnull
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