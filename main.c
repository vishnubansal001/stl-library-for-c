#include <stdio.h>
#include "headersAndFiles/stack.h"
#include "headersAndFiles/queue.h"
#include "headersAndFiles/pqueue.h"
#include "headersAndFiles/trie.h"
#include "headersAndFiles/searching.h"
#include "headersAndFiles/sorting.h"

int cmp(const void *a,const void *b){
    return (*(int*)a - *(int*)b);
}

int compare_int(const void * x,const void * y){
    int * value1 = (int*)x;
    int * value2 = (int*)y;
    return *value1 > *value2 ? 1 : -1;
}

int compare_char(const void * x,const void * y){
    char * p1 = (char*)x;
    char * p2 = (char*)y;
    return *p1 > *p2 ? 1 : -1;
}

int cmpchar(const void * x,const void * y){
    char * p1 = (char*)x;
    char * p2 = (char*)y;
    return *p1 > *p2 ? 1 : -1;
}


int main() {
    // ---------------------------- stack ------------------------------
    Stack *stack = stack_create(sizeof(int));

    if (!stack) {
        printf("Failed to create stack.\n");
        return 1;
    }

    int values[] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; ++i) {
        if (!stack_push(stack, &values[i])) {
            printf("Failed to push element onto the stack.\n");
            stack_destroy(stack);
            return 1;
        }
    }

    printf("Stack contents: ");
    while (!stack_is_empty(stack)) {
        int value;
        if (stack_peek(stack, &value)) {
            printf("%d ", value);
        }
        stack_pop(stack);
    }
    printf("\n");
    
    stack_destroy(stack);
    
    //---------------------------------- queue ---------------------------
    
    Queue *queue = queue_create(sizeof(int));
    
    if(!queue){
        printf("Failed to create queue.\n");
        return 1;
    }
    
    char value[] = {'a','b','c','d','e','f'};
    
    for(int i=0;i<6;i++){
    	if(!queue_enqueue(queue,&value[i])){
    	    printf("Failed to push element onto the queue.\n");
    	    queue_destroy(queue);
    	    return 1;
    	}
    }
    
    printf("queue contains: ");
    
    while(!queue_is_empty(queue)){
    	char val;
    	if(queue_peek(queue,&val)){
    	    printf("%c ",val);
    	}
    	queue_dequeue(queue);
    }
    
    printf("\n");
    
    queue_destroy(queue);
    
    // -------------------------------- PQueue ------------------------------
    
    PQueue *pq = pqueue_create(sizeof(int),cmp);
    
    if(!pq){
    	printf("Failed to create Priority Queue\n");
    	return 1;
    }
    
    int vals[] = {10,2,30,12,8,1};
    
    for(int i=0;i<6;i++){
    	if(!pqueue_enqueue(pq,&vals[i])){
    	    printf("Failed to push element onto the priority queue.\n");
    	    pqueue_destroy(pq);
    	    return 1;
    	}
    }
    
    printf("Priority queue contains: ");
    while(!pqueue_is_empty(pq)){
    	int val;
    	if(pqueue_peek(pq,&val)){
    	    printf("%d ",val);
    	}
    	pqueue_dequeue(pq);
    }
    
    printf("\n");
    
    pqueue_destroy(pq);
    
    //--------------------------------- Trie -------------------------------
    
    Trie *trie = trie_create();
    if (!trie) {
        printf("Failed to create trie.\n");
        return 1;
    }

    trie_insert(trie, "apple", "A sweet fruit");
    trie_insert(trie, "banana", "A tropical fruit");
    trie_insert(trie, "grape", "A small round fruit");

    void *valu;
    if (trie_search(trie, "apple", &valu)) {
        printf("Value for 'apple': %s\n", (char *)valu);
    } else {
        printf("'apple' not found in the trie.\n");
    }

    if (trie_search(trie, "cherry", &valu)) {
        printf("Value for 'cherry': %s\n", (char *)valu);
    } else {
        printf("'cherry' not found in the trie.\n");
    }

    trie_remove(trie, "banana");
    
    //printf("\n");
    
    trie_destroy(trie);
    
    // ------------------------------ searching ----------------------------
    
    char arr1[] = {'a','b','c','g'};
    
    char target1 = 'h';
    
    int index1 = linear_search(arr1,&target1,4,sizeof(arr1[0]));
    
    if(index1 == -1){
    	printf("Element don't exists!!\n");
    }else{
    	printf("Element exists at %d\n",index1);
    }
    
    int arr2[] = {1,2,4,3453,123,122};
    
    int target2 = 123;
    
    int index2 = linear_search(arr2,&target2,6,sizeof(arr2[0]));
    
    if(index2 == -1){
    	printf("Element don't exists!!\n");
    }else{
    	printf("Element exists at %d\n",index2);
    }
    
    int arr3[] = {1,2,3,4,5};
    
    int tar = 3;
    
    int ind1 = binary_search(arr3,&tar,5,sizeof(arr3[0]));
    
    if(ind1 == -1){
    	printf("Element don't exists!!\n");
    }else{
    	printf("Element exists at %d\n",ind1);
    }
    
    //-------------------------------- sorting ----------------------------
    
    int arrr[] = {12,32,4,1,0,8};
    
    bubble_sort(arrr,6,sizeof(int),compare_int);
    
    for(int i=0;i<6;i++){
    	printf("%d ",arrr[i]);
    }
    printf("\n");
    
    int arrr2[] = {1,23,3,45,67,0};
    insertion_sort(arrr2, 6, sizeof(arrr2[0]), cmp);
    for(int i=0;i<6;i++){
    	printf("%d ",arrr2[i]);
    }
    printf("\n");
    
    int arrr3[] = {1,23,4,56,88,0,10};
    merge_sort(arrr3, 7, sizeof(arrr3[0]), cmp);
    for(int i=0;i<7;i++){
    	printf("%d ",arrr3[i]);
    }
    printf("\n");
    
    char arrr4[] = {'d','a','b','e','h','g'};
    
    quick_sort(arrr4, 6, sizeof(arrr4[0]), cmpchar);
    
    for(int i=0;i<6;i++){
    	printf("%c ",arrr4[i]);
    }
    printf("\n");
    
    int arer[] = {13,1,2,45,0,23,9,15,18,98,67};
    sort(arer,11,sizeof(arer[0]),compare_int);
    for(int i=0;i<11;i++){
    	printf("%d ",arer[i]);
    }
    printf("\n");
    return 0;
}
