#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
typedef int HPDataType;
typedef struct ListHeap
{
	HPDataType* a;
	HPDataType size;
	HPDataType capacity;
}Heap;
void HeapInit(Heap* hp);
void HeapDestroy(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
//向上查找
//n是这个数组有多大，child为起始位置
void AdjustUp(int *a,int n,int child);
//向下查找
void AdjustDown(int* a, int n, int child);
void HeadPrintf(Heap* hp);
void swap(HPDataType* px, HPDataType* py);

bool HeapEmpty(Heap* hp);
int Heapsize(Heap* hp);