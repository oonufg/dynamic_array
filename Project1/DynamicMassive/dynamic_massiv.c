#include "dynamic_massiv.h"
#include "stdlib.h"
#include "stdio.h"

struct dArray
{
	int* data;
	int capacity;
	int size;
};

void* arrayConstructor(int typeSize) 
{
	struct dArray* arrPtr = malloc(sizeof(struct dArray));
	if (arrPtr != NULL)
	{
		arrPtr->data = malloc(typeSize * 2);
		if (arrPtr->data != NULL)
		{
			arrPtr->size = 0;
			arrPtr->capacity = 2;
		}
	}
	return arrPtr;
}

void arrayDestructor(struct dArray* arrPtr)
{
	if (arrPtr != NULL)
	{
		if (arrPtr->data != NULL)
		{
			free(arrPtr->data);
		}
		free(arrPtr);
	}
}

void arrayExtend(struct dArray* arrPtr)
{
	int* newData = malloc(sizeof(arrPtr->data[0]) * (arrPtr->capacity * 2));
	if (newData != NULL)
	{
		for (int i = 0; i < arrPtr->size; i++)
		{
			newData[i] = arrPtr->data[i];
		}
		free(arrPtr->data);
		arrPtr->data = newData;
		arrPtr->capacity = arrPtr->capacity * 2;
	}
	else
	{
		printf("Memory allocate error");
	}
}

void arrayWrite(struct dArray* arrayPtr, int index, int value)
{
	if (arrayPtr != NULL)
	{
		if(index >= 0 && index < arrayPtr->size + 1)
		{
			if (arrayPtr->data != NULL)
			{
				if (arrayPtr->size == arrayPtr->capacity)
				{
					arrayExtend(arrayPtr);
				}
				arrayPtr->data[index] = value;
				if (index == arrayPtr->size)
				{
					arrayPtr->size++;
				}
			}
		}
		else
		{
			printf("Out of range");
		}
	}
	else
	{
		printf("Memmory error");
	}
}

int arrayRead(struct dArray* arrayPtr, int index)
{
	if (arrayPtr != NULL)
	{
		if (index >= 0 && index < arrayPtr->size)
		{
			if (arrayPtr->data != NULL)
			{
				return arrayPtr->data[index];
			}
		}
		else
		{
			printf("Out of range");
		}
	}
	else
	{
		printf("Memmory error");
	}
	return 0;
}
int getSize(struct dArray* arrayPtr)
{
	if (arrayPtr != NULL)
	{
		return arrayPtr->size;
	}
	return 0;
}
int _getCapacity(struct dArray* arrayPtr)
{
	if (arrayPtr != NULL)
	{
		return arrayPtr->capacity;
	}
	return 0;
}
