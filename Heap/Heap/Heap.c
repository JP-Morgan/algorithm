#include "Heap.h"
//初始化
void HeapInit(Heap* hp)
{
	assert(hp);
	hp->a = NULL;
	hp->capacity = hp->size = NULL;
}
//销毁
void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->a);
	hp->capacity = hp->size = 0;
}
//树(堆)向上查找算法
void AdjustUp(int* a, int n, int child)
{
	//child为下标
	int parent = (child - 1) / 2;
	//直到child为父为至
	while (child > 0)
	{
		if (a[parent] < a[child])
		{
			swap(&a[parent], &a[child]);
			//找下一个parent
			//把父给儿 主要原因为大堆
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
//树(堆)向下查找算法
//parent为父
void AdjustDown(int* a, int n/*总大小(也就是尾部)*/, int parent/*头，父*/)
{
	//查找值
	int chlid = parent * 2 + 1;//儿子
	while (chlid<n)
	{
		//选出左右孩子中小的那一个；
		if (chlid < n && a[chlid + 1] < a[chlid])
		{
			//满足为左，不满足为右
			++chlid;
		}
		//如果为小的孩子，则交换，并继续往下调整
		if (a[chlid]<a[parent])
		{
			swap(&a[chlid], &a[parent]);
			//把儿子给父 主要原因小堆
			parent = chlid;
			//找下一个儿子
			chlid = parent * 2 + 1;
		}
		else
		{
			break;
		}

	}
}
//打印
void HeadPrintf(Heap* hp)
{
	for (int i = 0; i < hp->size; i++)
	{
		printf(" %d ", hp->a[i]);
	}
}
//插入数据
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		//扩容
		size_t newHeap = hp->capacity == 0 ? 4 : hp->capacity * 2;
		HPDataType* tmp = realloc(hp->a, sizeof(HPDataType) * newHeap);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		hp->a = tmp;
		hp->capacity = newHeap;
	}
	//插入数值
	hp->a[hp->size] = x;
	hp->size++;
	//树(堆)向上查找算法
	AdjustUp(hp->a, hp->size, hp->size - 1);
}
void swap(HPDataType* px, HPDataType* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}
bool HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->size == 0;

}
int Heapsize(Heap* hp)
{
	assert(hp);
	return hp->size;
}
//删除
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	//第一步头与最后一个就交换
	swap(hp->a[0], hp->a[hp->size - 1]);
	hp->size--;
	//开始向下
	AdjustDown(hp->a,hp->size,0);
}