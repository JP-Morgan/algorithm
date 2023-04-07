#pragma once
#include <stdio.h>
#include <stdlib.h>
//算法测试接口
void TestOP();
void Print(int* a, int n);
void Swap(int* a,int* b);
// 插入排序
void InsertSort(int* a,int n);


// 希尔排序
// 1.预排序目的：数组接近有序--->分组插排
// 分组排序：间隔为GAP分为
// 2.直接插入排序
//
void ShellSort(int* a,int n);
//选择排序
void SelectSort(int* a, int n);
//

//

//