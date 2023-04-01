#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
typedef int STDataType;
typedef struct stack
{
	int* a;
	int top;
	int capacity;
}ST;
void Init(ST* ps);
void Destroy(ST* ps);

void Push(ST* ps,STDataType x);
void Pop(ST* ps);
int Size(ST* ps);
bool Empty(ST* ps);
void Destroy(ST* ps);
STDataType Top(ST* PS);