#include "stdio.h"
#include "stdlib.h"
#include "dynamic_massiv.h"
int main()
{
	struct dArray* arr = arrayConstructor(sizeof(int));
	for (int i = 0; i < 100; i++)
	{
		arrayWrite(arr, i, i * 2);
	}
	printf("%d", arr);
	printf("\n");

	arrayDestructor(arr);
	printf("%d", arr);

}