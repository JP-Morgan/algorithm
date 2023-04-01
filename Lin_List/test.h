#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef int SLDataType;//SLDataType
typedef struct Link_List
{
	SLDataType data;
	struct List* next;
}List;
//打印
void SLPrintf(List* plist);
//增容
List* SListAdd(SLDataType x);
//尾插
void SListPushBack(List** pplist, SLDataType x);
//头插
void SLPoshFront(List** pplist, SLDataType x);
//头删
void SLPopback(List** pplist);
//尾删
void SLPopFront(List** pplist);
//查找
List* SLFind(List* plist,SLDataType x);
//修改
void SLAmend(List* plist, SLDataType x, SLDataType y);
//查找多个
void SLFinds(List* plist, SLDataType x);
//插入
void SLInsertPos(List** pplist, List* pos, SLDataType x);
