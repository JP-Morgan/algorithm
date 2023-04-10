#include "Sort.h"
void TestOP()
{
	srand(time(0));
	const int N = 100000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}
	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();
	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();
	int begin3 = clock();
	//SelectSort(a3, N);
	int end3 = clock();
	int begin4 = clock();
	//HeapSort(a4, N);
	int end4 = clock();
	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();
	int begin6 = clock();
	//MergeSort(a6, N);
	int end6 = clock();
	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}
void Print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}printf("\n");
}
void Swap(int* a, int* p)
{
	int tmp = *a;
	*a = *p;
	*p = tmp;
}
//升序
//最好：O(N)	  逆序
//最坏：O(N^2) 有序
void InsertSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int end = i - 1;
		int tmp = a[i];
		//将tmp插入a[0,end]区间中
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n)
{
	/*int gap = 3;
	for (int j = 0; j< gap; j++)
	{
		for (int i = j; i < n; i += gap)
		{
			int end = i - gap;
			int tmp = a[i]; 
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
				a[end + gap] = tmp;
			}
		}
	}*/
	int gap = n;
	while (gap>1)
	{
		gap /= 2;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[i + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
				a[end + gap] = tmp;
			}
		}
	}
	
}

void SelectSort(int* a, int n)
{
	int left = 0;
	int right = n-1;
	while (left<right)
	{
		int max;
		int mini = max = left;
		for (int i = left + 1; i <= right; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[max])
			{
				max = i;
			}
		}
		Swap(&a[left], &a[mini]);
		if (left == max)
		{
			max = mini;
		}
		Swap(&a[right], &a[max]);
		left++;
		right--;
	}
}
//树(堆)向下查找算法
//parent为父
void AdjustDown(int* a, int n/*总大小(也就是尾部)*/, int parent/*头，父*/)
{
	//查找值
	int chlid = parent * 2 + 1;//儿子
	while (chlid < n)
	{
		//选出左右孩子中小的那一个；
		if (chlid < n && a[chlid + 1] < a[chlid])
		{
			//满足为左，不满足为右
			++chlid;
		}
		//如果为小的孩子，则交换，并继续往下调整
		if (a[chlid] < a[parent])
		{
			Swap(&a[chlid], &a[parent]);
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

void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[end], &a[0]);
		AdjustDown(a, end, 0);
		--end;
	}

}

void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n; j++)
	{
		for (int i = 1; i < n - j; i++)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
			}
		}
	}
	
}
int GetMidNumi(int* a, int left, int right)
{
	int mid = (left >= right) / 2;
	int tmp;
	if (a[left] < a[mid])
	{
		if (a[right] > a[mid])
		{
			return mid;
		}
		else if (a[right] > a[left])
		{
			return right;
		}
		else
		{
			return left;
		}
	}
	else
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	
	}
}
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;
	
	int begin = left, end = right;
	//随机选key
	/*int randi = left + (rand() % (right - left));
	Swap(&a[left], &a[randi]);*/
	int midi = GetMidNumi(a, left, right);
	Swap(&a[left], &a[midi]);
	int key = left;
	while (left < right)
	{
		//右边找小
		while (left < right && a[right] >= a[key])
		{
			right--;
		}
		//左边找大
		while (left < right && a[left] <= a[key])
		{
			left++;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[key], &a[right]);
	key = left;
	QuickSort(a, begin, key - 1);
	QuickSort(a, key + 1, end);
}
 