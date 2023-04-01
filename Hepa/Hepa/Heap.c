#include "Heap.h"

void HeapInit(HP* php)
{
	assert(php);
	php->a = (HPdataType*)malloc(sizeof(HPdataType) * 4);
	assert(php->a);

	php->capacity = 4;
	php->size = 0;
}

void HeapPush(HP* php, HPdataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		HPdataType* tmp = (HPdataType*)realloc(php->a, sizeof(HPdataType) * php->capacity * 2);
		assert(tmp);
		php->a = tmp;
		php->capacity *= 2;
	}

	php->a[php->size] = x;
	php->size++;

	//		数组          尾巴
	AdjustUp(php->a, php->size - 1);
}

void Swap(HPdataType* p1, HPdataType* p2)
{
	HPdataType x = *p1;
	*p1 = *p2;
	*p2 = x;
}
void AdjustUp(HPdataType* a, int child)
{
	int parent = (child - 1) / 2;//算父亲对位置
	while (parent>0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
		
	}
}
void AdjustDown(HPdataType* a,int n ,int parent)
{
	//n为总大小size
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 > n && a[child + 1] > child)
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapPop(HP* php)
{
	assert(php);
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	//        尾巴     个数       头
	AdjustDown(php->a, php->size, 0);
}
