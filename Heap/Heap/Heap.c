#include "Heap.h"
//��ʼ��
void HeapInit(Heap* hp)
{
	assert(hp);
	hp->a = NULL;
	hp->capacity = hp->size = NULL;
}
//����
void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->a);
	hp->capacity = hp->size = 0;
}
//��(��)���ϲ����㷨
void AdjustUp(int* a, int n, int child)
{
	//childΪ�±�
	int parent = (child - 1) / 2;
	//ֱ��childΪ��Ϊ��
	while (child > 0)
	{
		if (a[parent] < a[child])
		{
			swap(&a[parent], &a[child]);
			//����һ��parent
			//�Ѹ����� ��Ҫԭ��Ϊ���
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
//��(��)���²����㷨
//parentΪ��
void AdjustDown(int* a, int n/*�ܴ�С(Ҳ����β��)*/, int parent/*ͷ����*/)
{
	//����ֵ
	int chlid = parent * 2 + 1;//����
	while (chlid<n)
	{
		//ѡ�����Һ�����С����һ����
		if (chlid < n && a[chlid + 1] < a[chlid])
		{
			//����Ϊ�󣬲�����Ϊ��
			++chlid;
		}
		//���ΪС�ĺ��ӣ��򽻻������������µ���
		if (a[chlid]<a[parent])
		{
			swap(&a[chlid], &a[parent]);
			//�Ѷ��Ӹ��� ��Ҫԭ��С��
			parent = chlid;
			//����һ������
			chlid = parent * 2 + 1;
		}
		else
		{
			break;
		}

	}
}
//��ӡ
void HeadPrintf(Heap* hp)
{
	for (int i = 0; i < hp->size; i++)
	{
		printf(" %d ", hp->a[i]);
	}
}
//��������
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		//����
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
	//������ֵ
	hp->a[hp->size] = x;
	hp->size++;
	//��(��)���ϲ����㷨
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
//ɾ��
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	//��һ��ͷ�����һ���ͽ���
	swap(hp->a[0], hp->a[hp->size - 1]);
	hp->size--;
	//��ʼ����
	AdjustDown(hp->a,hp->size,0);
}