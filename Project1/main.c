#include "stdio.h"
#include "stdlib.h"
#include "DynamicArray/DynamicArray.h"


int main()
{
	dArray* arr = arrayConstructor(sizeof(int));
	
	for (int i = 0; i < 1000; i++)
	{
		arrayWrite(arr, i, &i);
	}
	for (int i = 0; i < getSize(arr); i++)
	{
		int* res = arrayRead(arr, i);
		printf("%d", *res);
		printf("\n");
	}
	printf("%d", _getCapacity(arr));
	return 0;
}