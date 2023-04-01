#include "stack.h"
void Init(ST* ps)
{
	assert(ps);

	ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (ps->a == NULL)
	{
		perror("malloc fail");
		return;
	}
	ps->capacity = 4;
	ps->top = 0;//如果-1为顶，eg为0这是顶的下一个;
}
void Destroy(ST* ps)
{
	assert(ps);

	free(ps->a);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}
void Push(ST* ps, STDataType x)
{
	assert(ps);

	if (ps->top == ps->capacity)
	{
		assert(ps);
		STDataType* tmp= (STDataType*)realloc(ps->a,
			sizeof(STDataType) * ps->capacity*2);
		if (ps->a == NULL) 
		{
			perror("realloc fail");
			return;
		}
		ps->a = tmp;
		ps->capacity *= 2;
	}

 	ps->a[ps->top] = x;
	ps->top++;
}
void Pop(ST* ps)
{
	assert(ps);
	assert(!Empty(ps));

	ps->top--;
}
int Size(ST* ps)
{
	assert(ps);

	return ps->top;
}
bool Empty(ST* ps)
{
	assert(ps);

	return ps->top == 0;
}
STDataType Top(ST* PS)
{
	assert(PS);
	assert(!Empty(PS));

	return PS->a[PS->top - 1];
}