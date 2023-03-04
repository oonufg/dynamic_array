#include "DynamicArray.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct _dArray
{
	void* data;
	int capacity;
	int size;
	int typeSize;
};

void* arrayConstructor(int typeSize) 
{
	dArray* arrayPtr = malloc(sizeof(dArray));
	if (arrayPtr != NULL && typeSize > 0)
	{
		arrayPtr->data = malloc(typeSize * 2);
		if (arrayPtr->data != NULL)
		{
			arrayPtr->size = 0;
			arrayPtr->capacity = 2;
			arrayPtr->typeSize = typeSize;
		}
	}
	else
	{
		printf("Memmory allocate error");
	}
	return arrayPtr;
}

void arrayDestructor(dArray* arrayPtr)
{
	if (arrayPtr != NULL)
	{
		if (arrayPtr->data != NULL)
		{
			free(arrayPtr->data);
		}
		free(arrayPtr);
	}
}

void arrayExtend(dArray* arrayPtr)
{
	void* newData = malloc(sizeof(arrayPtr->typeSize) * (arrayPtr->capacity * 2));
	if (newData != NULL)
	{
		for (int i = 0; i < (arrayPtr->size * arrayPtr->typeSize); i++)
		{
			((char*)newData)[i] = ((char*)arrayPtr->data)[i];
		}
		free(arrayPtr->data);
		arrayPtr->data = newData;
		arrayPtr->capacity = arrayPtr->capacity * 2;
	}
	else
	{
		printf("Memory allocate error");
	}
}

void arrayWrite(dArray* arrayPtr, int index, void* value)
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

void* arrayRead(dArray* arrayPtr, int index)
{
	if (arrayPtr != NULL)
	{
		if (index >= 0 && index < arrayPtr->size)
		{
			return (((unsigned char*)arrayPtr->data) + index * arrayPtr->typeSize);
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

int getSize(dArray* arrayPtr)
{
	if (arrayPtr != NULL)
	{
		return arrayPtr->size;
	}
	return 0;
}
int _getCapacity(dArray* arrayPtr)
{
	if (arrayPtr != NULL)
	{
		return arrayPtr->capacity;
	}
	return 0;
}
