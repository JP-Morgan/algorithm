#define _CRT_SECURE_NO_WARNINGS
#include "test.h"
//����
List* SListAdd(SLDataType x)
{
	List* newlist = (List*)malloc(sizeof(List));
	if (newlist == NULL)
	{
		//����ʧ��ֱ�ӷ���
		return;
	}
	newlist->data = x;
	newlist->next = NULL;
	return newlist;
}
//��ӡ
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
//β��
void SListPushBack(List** pplist, SLDataType x)
{
	//���ӿ���ģ�黯
	/*List* newlist = (List*)malloc(sizeof(List));
	newlist->data = x;
	newlist->next = NULL;*/
	List* newlist = SListAdd(x);//����һ���µĽڵ�
	if (*pplist==NULL)//�ж��Ƿ��нڵ�
	{
		//û�оͰ�newlist��pplist
		*pplist = newlist;
	}
	else
	{
		//�У�����β(null)
		List* tali = *pplist;//��pplist�ĵ�ַ��tali
		while (tali->next!=NULL)
		{
			tali = tali->next;
		}
		//��newlist�ĵ�ַ��β��
		tali->next = newlist;
	}
}
//ͷ��
void SLPoshFront(List** pplist, SLDataType x)
{
	List* newList = SListAdd(x);
	newList->next = *pplist;
	*pplist = newList;
}
//βɾ
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
		List* Front = *pplist;//���浹����2����
		List* hate = *pplist;//�������ӵ�
		//List* Prev = *pplist;//���浹����2����
		//List* tail = *pplist;//�������ӵ�
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
//ͷɾ
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