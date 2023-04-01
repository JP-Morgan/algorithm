#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLTDataType;
typedef struct List
{
	SLTDataType Data;
	struct LIST* next;
}LS;

//¥Ú”°¡¥±Ì
void ListPrintf(LS* phead);
//Œ≤≤Â
void ListPushBack(LS** pback, SLTDataType x);
//Õ∑≤Â
void ListPushFront(LS** phand, SLTDataType X);
//¿©»›
LS* BuySLTNode(SLTDataType x);
//Œ≤…æ
void ListPopBack(LS** pback);
//Õ∑…æ
void ListPopFront(LS** phand);
//≤È’“
LS* ListFind(LS* sfind,SLTDataType x);
//pos≤Â»Î
void Listinsert(LS** pphead ,LS* pos,SLTDataType x);
//posŒª÷√…æ≥˝
void ListErase(LS** pphead, LS* pos);