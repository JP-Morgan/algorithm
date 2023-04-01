#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int HPdataType;
typedef struct Heap
{
	HPdataType* a;
	int size;
	int capacity;
}HP;
void HeapInit(HP* php);
void HeapPush(HP* php,HPdataType x);
void AdjustUp(HPdataType* a, int child);
void AdjustDown(HPdataType* a,int n ,int child);
void HeapPop(HP* php);