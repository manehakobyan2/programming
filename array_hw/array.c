#include "array.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct array* array_create()
{
	struct array* a = (struct array*)malloc(sizeof(struct array));
        assert(0 != a);
        memset(a, 0, sizeof(struct array));
	a->size = 0;
	a->capacity = 2;
	a->start = (element_type*)malloc(a->capacity * sizeof(element_type));
	return a;
}

void array_push_back(struct array* a, element_type e)
{
         if(a->size == a->capacity)
        {
                //double the capacty
                a->capacity *= 2;
                //checking for failure allocating memory
                void* temp =realloc(a->start, a->capacity*sizeof(element_type));
                if (!temp) exit(1);
                a->start =temp;
        }
	//add new element at the end 
	a->start[a->size++] = e;

}

void array_pop_back(struct array* a)
{
	//check if there is element in the array
        if(a->size > 0)
	{
		//reduce size
		a-> size--;
	}
}

void array_insert(struct array* a, size_type index, element_type e)
{
	//check if the given index is inside the array
	if(index > a->size)
	{
		return;
	}

	//check the need to grow the array
	if(a->size == a->capacity)
	{
		//double the capacty
		a->capacity *= 2;
		//checking for failure allocating memory
		void* temp =realloc(a->start, a->capacity*sizeof(element_type));
		if (!temp) exit(1);
		a->start =temp;
	}

	//shift elements to the right till index
	for(size_type i = a->size; i>index; --i)
	{
	         a->start[i] = a->start[i-1];
	}
	//insert index 
	a->start[index] = e;
	//increase the size by one 
	a-> size++;
}

size_type array_size(struct array* a)
{
	assert(0 != a);
	return a->size;
}

size_type array_capacity(struct array* a)
{
	assert(0 != a);
	return a->capacity;
}

void array_print(struct array* a)
{
	assert(0 != a);
	for (size_type i = 0; i < a->size; ++i) {
		printf("%d ", a->start[i]);
	}
	printf("\nsize = %d", a->size);
	printf("\ncapacity = %d\n\n", a->capacity);
}

int array_empty(struct array* a)
{
	assert(0 != a);
	return a->size == 0;
}
