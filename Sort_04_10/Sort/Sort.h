#pragma once
#include <stdio.h>
#include <stdlib.h>
//�㷨���Խӿ�
void TestOP();
void Print(int* a, int n);
void Swap(int* a,int* b);
// ��������
void InsertSort(int* a,int n);


// ϣ������
// 1.Ԥ����Ŀ�ģ�����ӽ�����--->�������
// �������򣺼��ΪGAP��Ϊ
// 2.ֱ�Ӳ�������
//
void ShellSort(int* a,int n);
//ѡ������
void SelectSort(int* a, int n);
//������
void HeapSort(int* a, int n);
void AdjustDown(int* a, int n/*�ܴ�С(Ҳ����β��)*/, int parent/*ͷ����*/);
//ð������
void BubbleSort(int* a, int n);
//����
void QuickSort(int* a, int left,int right);