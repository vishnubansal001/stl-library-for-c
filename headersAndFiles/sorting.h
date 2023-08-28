#ifndef SORTING_H
#define SORTING_H
#define SWAP(x, y, T) do { T temp = x; x = y; y = temp; } while (0)

#include <stddef.h>

void sort(void *arr,size_t n,size_t elemSize,int(*cmp)(const void* x,const void * y));
void bubble_sort(void * arr, size_t n, size_t elemSize, int(*cmp)(const void * x,const void * y));
void insertion_sort(void *arr, size_t n, size_t elemSize, int (*cmp)(const void *, const void *));
void merge_sort(void *arr, size_t n, size_t elemSize, int (*cmp)(const void *, const void *));
void quick_sort(void *arr, size_t n, size_t elemSize, int (*cmp)(const void *, const void *));

#endif
