#include "stdio.h"
#include "stdlib.h"
#include "DynamicMassive/dynamic_massiv.h"
int main()
{
	struct dArray* arr = arrayConstructor(sizeof(int));
	for (int i = 0; i < 100; i++)
	{
		arrayWrite(arr, i, i * 2);
	}
	arrayDestructor(arr);
}