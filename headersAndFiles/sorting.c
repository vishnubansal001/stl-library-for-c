#include <stdlib.h>
#include <string.h>
#include "sorting.h"

//Bubble Sort Code
void bubble_sort(void * arr, size_t n, size_t elemSize, int(*cmp)(const void * x,const void * y)){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n-1; j++){
            if(cmp(arr + elemSize*j, arr + elemSize * (j+1)) > 0){
                char temp[elemSize];
                memcpy(temp,arr + elemSize*j,elemSize);
                memcpy(arr + elemSize*j,arr + elemSize * (j+1), elemSize);
                memcpy(arr + elemSize * (j+1),temp, elemSize);
            };
        }

    }
}

//Insertion Sort Code
void insertion_sort(void *arr, size_t n, size_t elemSize, int (*cmp)(const void *, const void *)) {
    char *array = arr;
    
    for (size_t i = 1; i < n; i++) {
        size_t j = i;
        while (j > 0 && cmp(array + (j - 1) * elemSize, array + j * elemSize) > 0) {
            SWAP(array[j * elemSize], array[(j - 1) * elemSize], char);
            j--;
        }
    }
}

//Merge Sort Code
static void merge(void *arr, size_t left, size_t mid, size_t right, size_t elemSize, int (*cmp)(const void *, const void *)) {
    char *array = arr;
    size_t leftSize = mid - left + 1;
    size_t rightSize = right - mid;

    void *leftArr = malloc(leftSize * elemSize);
    void *rightArr = malloc(rightSize * elemSize);
    if (!leftArr || !rightArr) {
        free(leftArr);
        free(rightArr);
        return;
    }

    memcpy(leftArr, array + left * elemSize, leftSize * elemSize);
    memcpy(rightArr, array + (mid + 1) * elemSize, rightSize * elemSize);

    size_t i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (cmp(leftArr + i * elemSize, rightArr + j * elemSize) <= 0) {
            memcpy(array + k * elemSize, leftArr + i * elemSize, elemSize);
            i++;
        } else {
            memcpy(array + k * elemSize, rightArr + j * elemSize, elemSize);
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        memcpy(array + k * elemSize, leftArr + i * elemSize, elemSize);
        i++;
        k++;
    }

    while (j < rightSize) {
        memcpy(array + k * elemSize, rightArr + j * elemSize, elemSize);
        j++;
        k++;
    }

    free(leftArr);
    free(rightArr);
}

// Define a generic merge sort function
void merge_sort(void *arr, size_t n, size_t elemSize, int (*cmp)(const void *, const void *)) {
    if (n <= 1) {
        return;
    }

    size_t mid = n / 2;
    merge_sort(arr, mid, elemSize, cmp);
    merge_sort(arr + mid * elemSize, n - mid, elemSize, cmp);

    merge(arr, 0, mid - 1, n - 1, elemSize, cmp);
}

//Quick Sort Code
static size_t partition(void *arr, size_t low, size_t high, size_t elemSize, int (*cmp)(const void *, const void *)) {
    char *array = arr;
    void *pivot = array + high * elemSize;
    size_t i = low - 1;

    for (size_t j = low; j < high; j++) {
        if (cmp(array + j * elemSize, pivot) < 0) {
            i++;
            char *temp = malloc(elemSize);
            if (!temp) {
                return i;
            }
            memcpy(temp, array + i * elemSize, elemSize);
            memcpy(array + i * elemSize, array + j * elemSize, elemSize);
            memcpy(array + j * elemSize, temp, elemSize);
            free(temp);
        }
    }

    char *temp = malloc(elemSize);
    if (!temp) {
        return i + 1;
    }
    memcpy(temp, array + (i + 1) * elemSize, elemSize);
    memcpy(array + (i + 1) * elemSize, array + high * elemSize, elemSize);
    memcpy(array + high * elemSize, temp, elemSize);
    free(temp);

    return i + 1;
}

// Define a generic quick sort function
void quickSort(void *arr, size_t low, size_t high, size_t elemSize, int (*cmp)(const void *, const void *)) {
    if (low < high) {
        size_t pivotIndex = partition(arr, low, high, elemSize, cmp);
        quickSort(arr, low, pivotIndex - 1, elemSize, cmp);
        quickSort(arr, pivotIndex + 1, high, elemSize, cmp);
    }
}

void quick_sort(void *arr,size_t n,size_t elemSize,int (*cmp)(const void* ,const void*)){
   quickSort(arr,0,n-1,elemSize,cmp);
}

void (*sorting)(void*,size_t,size_t,int (*)(const void*,const void*));
void sort(void *arr,size_t n,size_t elemSize,int (*cmp)(const void* ,const void*)){
    if(n<=20){
        sorting = bubble_sort;
    }
    else if(n<=100){
    	sorting = insertion_sort;
    }
    else if(n<=5000){
    	sorting = merge_sort;
    }
    else{
    	sorting = quick_sort;
    }
    sorting(arr,n,elemSize,cmp);
}
