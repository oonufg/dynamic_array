#include "DynamicArray.h"
#include "stdlib.h"
#include "stdio.h"

struct dArray
{
	void* data;
	int capacity;
	int size;
	int typeSize;
};

void* arrayConstructor(int typeSize) 
{
	struct dArray* arrPtr = malloc(sizeof(struct dArray));
	if (arrPtr != NULL && typeSize > 0)
	{
		arrPtr->data = malloc(typeSize * 2);
		if (arrPtr->data != NULL)
		{
			arrPtr->size = 0;
			arrPtr->capacity = 2;
			arrPtr->typeSize = typeSize;
		}
	}
	else
	{
		printf("Memmory allocate error");
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
	void* newData = malloc(sizeof(arrPtr->typeSize) * (arrPtr->capacity * 2));
	if (newData != NULL)
	{
		for (int i = 0; i < (arrPtr->size * arrPtr->typeSize); i++)
		{
			((char*)newData)[i] = ((char*)arrPtr->data)[i];
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

void arrayWrite(struct dArray* arrayPtr, int index, void* value)
{
	if (arrayPtr != NULL)
	{
		if (index >= 0 && index <= arrayPtr->size);
		{
			if (arrayPtr->size == arrayPtr->capacity)
			{
				arrayExtend(arrayPtr);
			}
			for (int i = 0 ; i < arrayPtr->typeSize;i++)
			{
				((unsigned char*)arrayPtr->data)[(index * arrayPtr->typeSize) + i] = ((unsigned char*)value)[i];
			}

			if (index == arrayPtr->size)
			{
				arrayPtr->size++;
			}
		}
	}
	else
	{
		printf("Memmory allocate error");
	}
}

void* arrayRead(struct dArray* arrayPtr, int index)
{
	if (arrayPtr != NULL)
	{
		if (index >= 0 && index < arrayPtr->size)
		{
			return (((char*)arrayPtr->data) + index * arrayPtr->typeSize);
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
	return NULL;
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
