#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int n;
int q[N];
void quick_sort(int q[], int l, int r)
{
	if (l >= r) 
		return;//判断是否为一个数
	int x = q[l], i = l - 1, j = r + 1;//i为最左边边线-1，而j为最右边边线+1
	while (i<j)
	{
		do
		{
			i++;
		}while (q[i]<x);
		do
		{
			j--;
		} while (q[j]>x);
		if (i<j)
		{
			swap(q[i], q[j]);
		}
		quick_sort(q,l,j);
		quick_sort(q, j + 1, r);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &q[i]);
	}
	//第一个数据为“数组”，为“最左边”，为“最右边”
	quick_sort(q, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		printf("%d", q[i]);
	}
	return 0;
}