#include "stdio.h"
#include "stdlib.h"
#include "DynamicArray/DynamicArray.h"
int main()
{
	struct dArray* arr = arrayConstructor(sizeof(int));
	int wannaAdd = 214124;
	arrayWrite(arr, 0, &wannaAdd);

	int* res = arrayRead(arr,0);
	printf("%d", *res);
}