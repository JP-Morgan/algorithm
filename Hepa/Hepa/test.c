#include "Heap.h"
int main()
{
	HP hp;
	HeapInit(&hp);
	HeapPush(&hp, 31);
	HeapPush(&hp, 23);
	HeapPush(&hp, 22);
	HeapPush(&hp, 11);
	HeapPush(&hp, 9);
	HeapPush(&hp, 6);
	HeapPush(&hp, 3);
	HeapPush(&hp, 1);

	return 0;
}