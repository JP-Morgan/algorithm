#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef int SLDataType;//SLDataType
typedef struct Link_List
{
	SLDataType data;
	struct List* next;
}List;
//��ӡ
void SLPrintf(List* plist);
//����
List* SListAdd(SLDataType x);
//β��
void SListPushBack(List** pplist, SLDataType x);
//ͷ��
void SLPoshFront(List** pplist, SLDataType x);
//ͷɾ
void SLPopback(List** pplist);
//βɾ
void SLPopFront(List** pplist);