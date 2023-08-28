#ifndef SEARCHING_H
#define SEARCHING_H

#include<stddef.h>


int linear_search(const void* array,const void* target,int size,size_t elementSize);
int binary_search(const void* array,const void* target,int size,size_t elementSize);

#endif
