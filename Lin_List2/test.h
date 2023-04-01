#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef int SLDataType;//SLDataType
typedef struct Link_List
{
	SLDataType data;
	struct List* next;
}List;
//¥Ú”°
void SLPrintf(List* plist);
//‘ˆ»›
List* SListAdd(SLDataType x);
//Œ≤≤Â
void SListPushBack(List** pplist, SLDataType x);
//Õ∑≤Â
void SLPoshFront(List** pplist, SLDataType x);
//Õ∑…æ
void SLPopback(List** pplist);
//Œ≤…æ
void SLPopFront(List** pplist);