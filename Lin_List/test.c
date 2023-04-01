#define _CRT_SECURE_NO_WARNINGS
#include "test.h"
//增容
List* SListAdd(SLDataType x)
{
	List* newlist = (List*)malloc(sizeof(List));
	if (newlist == NULL)
	{
		//增容失败直接返回
		return;
	}
	newlist->data = x;
	newlist->next = NULL;
	return newlist;
}
//打印
void SLPrintf(List* plist)
{
	List* LSfirst = plist;
	while (LSfirst!=NULL)
	{
		printf("%d", LSfirst->data);
		LSfirst = LSfirst->next;
	}
	printf("\n");
}
//尾插
void SListPushBack(List** pplist, SLDataType x)
{
	//增加可以模块化
	/*List* newlist = (List*)malloc(sizeof(List));
	newlist->data = x;
	newlist->next = NULL;*/
	List* newlist = SListAdd(x);//创建一个新的节点
	if (*pplist==NULL)//判断是否有节点
	{
		//没有就把newlist给pplist
		*pplist = newlist;
	}
	else
	{
		//有，就找尾(null)
		List* tali = *pplist;//把pplist的地址给tali
		while (tali->next!=NULL)
		{
			tali = tali->next;
		}
		//把newlist的地址给尾巴
		tali->next = newlist;
	}
}
//头插
void SLPoshFront(List** pplist, SLDataType x)
{
	List* newList = SListAdd(x);
	newList->next = *pplist;
	*pplist = newList;
}
//尾删
void SLPopback(List** pplist)
{
	if (*pplist == NULL)
	{
		return;
	}
	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		List* Front = *pplist;//保存倒数第2个的
		List* hate = *pplist;//不断增加的
		//List* Prev = *pplist;//保存倒数第2个的
		//List* tail = *pplist;//不断增加的
		while (hate->next != NULL)
		{
			hate = hate->next;
			if (hate->next == NULL)
			{
				Front->next = NULL;
				break;
			}
			if (hate->next != NULL)
			{
				Front = hate;
			}
			/*Prev = tail;
			tail = tail->next;*/
		}
		free(hate);
		hate = NULL;
		//Prev->next = NULL;
		//*pplist = newlist;
	}
}
//头删
void SLPopFront(List** pplist)
{
	
	if (*pplist == NULL)
	{
		return;
	}
	else
	{
		List* newlist = *pplist;
		*pplist = newlist->next;
		free(newlist);
		newlist = NULL;
	}
}
//查找
List* SLFind(List* plist,SLDataType x)
{
	List* find = plist;
	while (find->next != NULL)
	{
		if (find->data == x)
		{
			return find;
		}
		else
		{
			find = find->next;
		}
	}
	if (find==NULL)
	{
		printf("找不到\n");
	}
	
}
//修改
void SLAmend(List* plist, SLDataType x,SLDataType y)
{
	List* amend = SLFind(plist, x);
	if (amend)
	{
		amend->data = y;
	}
}
//查找多个
void SLFinds(List* plist, SLDataType x)
{
	List* Finds = SLFind(plist, x);
	int i = 1;
	while (Finds)
	{
		if (Finds->data == x) 
		{
			printf("第%d个%d\n", i++, Finds->data);
		}
		Finds = Finds->next;
	}
}
//插入
void SLInsertPos(List** pplist, List* pos, SLDataType x)
{
	List* newlist = SListAdd(x);
	if (*pplist == pos)
	{
		newlist->next = *pplist;
		*pplist = newlist;
	}
	else
	{
		List* find = *pplist;
		while (find->next != pos)
		{
			find = find->next;
		}
		find->next = newlist;
		newlist->next = pos;
	}
}