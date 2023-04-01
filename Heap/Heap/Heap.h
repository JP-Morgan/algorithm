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
//���ϲ���
//n����������ж��childΪ��ʼλ��
void AdjustUp(int *a,int n,int child);
//���²���
void AdjustDown(int* a, int n, int child);
void HeadPrintf(Heap* hp);
void swap(HPDataType* px, HPDataType* py);

bool HeapEmpty(Heap* hp);
int Heapsize(Heap* hp);