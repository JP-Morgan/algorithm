#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLTDataType;
typedef struct List
{
	SLTDataType Data;
	struct LIST* next;
}LS;

//��ӡ����
void ListPrintf(LS* phead);
//β��
void ListPushBack(LS** pback, SLTDataType x);
//ͷ��
void ListPushFront(LS** phand, SLTDataType X);
//����
LS* BuySLTNode(SLTDataType x);
//βɾ
void ListPopBack(LS** pback);
//ͷɾ
void ListPopFront(LS** phand);
//����
LS* ListFind(LS* sfind,SLTDataType x);
//pos����
void Listinsert(LS** pphead ,LS* pos,SLTDataType x);
//posλ��ɾ��
void ListErase(LS** pphead, LS* pos);