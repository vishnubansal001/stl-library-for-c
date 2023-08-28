#include <stdlib.h>
#include <string.h>
#include "searching.h"

int linear_search(const void* array,const void* target,int size,size_t elementSize){
    for(int i=0;i<size;i++){
    	if(memcmp((char*)array+i*elementSize,target,elementSize) == 0){
    	    return i;
    	}
    }
    return -1;
}

int binary_search(const void* array,const void* target,int size,size_t elementSize){
    int left = 0;
    int right = size-1;
    while(left <= right){
    	int mid = left + (right - left)/2;
    	const void* midEle = (char*)array + mid*elementSize;
    	if(*(int*)target == *(int*)midEle){
    	    return mid;
    	}
    	else if(*(int*)midEle < *(int*)target){
    	    left = mid + 1;
    	}
    	else{
    	    right = mid - 1;
    	}
    }
    return -1;
}
