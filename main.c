#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headersAndFiles/stack.h"
#include "headersAndFiles/queue.h"
#include "headersAndFiles/pqueue.h"
#include "headersAndFiles/trie.h"
#include "headersAndFiles/searching.h"
#include "headersAndFiles/sorting.h"

#define MAX_WORD_LENGTH 100

int (*CompareFn)(const void *, const void *);

int compare_int(const void *a, const void *b) {
    int int_a = *((int *)a);
    int int_b = *((int *)b);
    
    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
    return 0;
}

// Generic comparison function for doubles
int compare_double(const void *a, const void *b) {
    double double_a = *((double *)a);
    double double_b = *((double *)b);
    
    if (double_a < double_b) return -1;
    if (double_a > double_b) return 1;
    return 0;
}

// Generic comparison function for characters
int compare_char(const void *a, const void *b) {
    char char_a = *((char *)a);
    char char_b = *((char *)b);
    
    if (char_a < char_b) return -1;
    if (char_a > char_b) return 1;
    return 0;
}


int main() {
    // ---------------------------- stack ------------------------------
    // Stack *stack = stack_create(sizeof(int));

    // if (!stack) {
    //     printf("Failed to create stack.\n");
    //     return 1;
    // }

    // int values[] = {10, 20, 30, 40, 50};

    // for (int i = 0; i < 5; ++i) {
    //     if (!stack_push(stack, &values[i])) {
    //         printf("Failed to push element onto the stack.\n");
    //         stack_destroy(stack);
    //         return 1;
    //     }
    // }

    // printf("Stack contents: ");
    // while (!stack_is_empty(stack)) {
    //     int value;
    //     if (stack_peek(stack, &value)) {
    //         printf("%d ", value);
    //     }
    //     stack_pop(stack);
    // }
    // printf("\n");
    
    // stack_destroy(stack);
    
    // //---------------------------------- queue ---------------------------
    
    // Queue *queue = queue_create(sizeof(int));
    
    // if(!queue){
    //     printf("Failed to create queue.\n");
    //     return 1;
    // }
    
    // char value[] = {'a','b','c','d','e','f'};
    
    // for(int i=0;i<6;i++){
    // 	if(!queue_enqueue(queue,&value[i])){
    // 	    printf("Failed to push element onto the queue.\n");
    // 	    queue_destroy(queue);
    // 	    return 1;
    // 	}
    // }
    
    // printf("queue contains: ");
    
    // while(!queue_is_empty(queue)){
    // 	char val;
    // 	if(queue_peek(queue,&val)){
    // 	    printf("%c ",val);
    // 	}
    // 	queue_dequeue(queue);
    // }
    
    // printf("\n");
    
    // queue_destroy(queue);
    
    // // -------------------------------- PQueue ------------------------------
    
    // PQueue *pq = pqueue_create(sizeof(int),compare_int);
    
    // if(!pq){
    // 	printf("Failed to create Priority Queue\n");
    // 	return 1;
    // }
    
    // int vals[] = {10,2,30,12,8,1};
    
    // for(int i=0;i<6;i++){
    // 	if(!pqueue_enqueue(pq,&vals[i])){
    // 	    printf("Failed to push element onto the priority queue.\n");
    // 	    pqueue_destroy(pq);
    // 	    return 1;
    // 	}
    // }
    
    //printf("Priority queue contains: ");
    // while(!pqueue_is_empty(pq)){
    // 	int val;
    // 	if(pqueue_peek(pq,&val)){
    // 	    printf("%d ",val);
    // 	}
    // 	pqueue_dequeue(pq);
    // }
    
    // printf("\n");
    
    // pqueue_destroy(pq);
    
    // //--------------------------------- Trie -------------------------------
    
    // Trie *trie = trie_create();
    // if (!trie) {
    //     printf("Failed to create trie.\n");
    //     return 1;
    // }

    // trie_insert(trie, "apple", "A sweet fruit");
    // trie_insert(trie, "banana", "A tropical fruit");
    // trie_insert(trie, "grape", "A small round fruit");

    // void *valu;
    // if (trie_search(trie, "apple", &valu)) {
    //     printf("Value for 'apple': %s\n", (char *)valu);
    // } else {
    //     printf("'apple' not found in the trie.\n");
    // }

    // if (trie_search(trie, "cherry", &valu)) {
    //     printf("Value for 'cherry': %s\n", (char *)valu);
    // } else {
    //     printf("'cherry' not found in the trie.\n");
    // }

    // trie_remove(trie, "banana");
    
    // //printf("\n");
    
    // trie_destroy(trie);
    
    // // ------------------------------ searching ----------------------------
    
    // char arr1[] = {'a','b','c','g'};
    
    // char target1 = 'h';
    
    // int index1 = linear_search(arr1,&target1,4,sizeof(arr1[0]));
    
    // if(index1 == -1){
    // 	printf("Element don't exists!!\n");
    // }else{
    // 	printf("Element exists at %d\n",index1);
    // }
    
    // int arr2[] = {1,2,4,3453,123,122};
    
    // int target2 = 123;
    
    // int index2 = linear_search(arr2,&target2,6,sizeof(arr2[0]));
    
    // if(index2 == -1){
    // 	printf("Element don't exists!!\n");
    // }else{
    // 	printf("Element exists at %d\n",index2);
    // }
    
    // int arr3[] = {1,2,3,4,5};
    
    // int tar = 3;
    
    // int ind1 = binary_search(arr3,&tar,5,sizeof(arr3[0]));
    
    // if(ind1 == -1){
    // 	printf("Element don't exists!!\n");
    // }else{
    // 	printf("Element exists at %d\n",ind1);
    // }
    
    // //-------------------------------- sorting ----------------------------
    
    // int arrr[] = {12,32,4,1,0,8};
    
    // bubble_sort(arrr,6,sizeof(int),compare_int);
    
    // for(int i=0;i<6;i++){
    // 	printf("%d ",arrr[i]);
    // }
    // printf("\n");
    
    // int arrr2[] = {1,23,3,45,67,0};
    // insertion_sort(arrr2, 6, sizeof(arrr2[0]), cmp);
    // for(int i=0;i<6;i++){
    // 	printf("%d ",arrr2[i]);
    // }
    // printf("\n");
    
    // int arrr3[] = {1,23,4,56,88,0,10};
    // merge_sort(arrr3, 7, sizeof(arrr3[0]), cmp);
    // for(int i=0;i<7;i++){
    // 	printf("%d ",arrr3[i]);
    // }
    // printf("\n");
    
    // char arrr4[] = {'d','a','b','e','h','g'};
    
    // quick_sort(arrr4, 6, sizeof(arrr4[0]), cmpchar);
    
    // for(int i=0;i<6;i++){
    // 	printf("%c ",arrr4[i]);
    // }
    // printf("\n");
    
    // int arer[] = {13,1,2,45,0,23,9,15,18,98,67};
    // sort(arer,11,sizeof(arer[0]),compare_int);
    // for(int i=0;i<11;i++){
    // 	printf("%d ",arer[i]);
    // }
    // printf("\n");

    int choice;
    do {
    	printf("--------start--------\n");
        printf("\nSelect an option:\n");
        printf("1. Stack\n");
        printf("2. Queue\n");
        printf("3. Priority Queue\n");
        printf("4. Trie\n");
        printf("5. Search in Array\n");
        printf("6. Sorting\n");
        printf("7. Exit\n");
        printf("---------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                int elementDataType;
                size_t element_size;
                printf("---------------------\n");
                printf("Select element data type:\n");
                printf("1. int\n");
                printf("2. double\n");
                printf("3. char\n");
                printf("---------------------\n");
                printf("Enter your choice: ");
                scanf("%d", &elementDataType);

                switch (elementDataType) {
                    case 1:
                        element_size = sizeof(int);
                        break;
                    case 2:
                        element_size = sizeof(double);
                        break;
                    case 3:
                        element_size = sizeof(char);
                        break;
                    default:
                        printf("Invalid choice.\n");
                        return 1;
                }

                Stack *stack = stack_create(element_size);
                if (!stack) {
                    printf("Failed to create stack.\n");
                    return 1;
                }
                int choice1;
                do {
                    printf("---------------------\n");
                    printf("\n1. Push an element\n");
                    printf("2. Pop an element\n");
                    printf("3. Peek at the top element\n");
                    printf("4. Check if stack is empty\n");
                    printf("5. Print all elements of stack\n");
                    printf("6. Exit\n");
                    printf("---------------------\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice1);

                    switch (choice1) {
                        case 1: {
                            void *newElement = malloc(element_size);
                            if (!newElement) {
                                printf("Memory allocation failed.\n");
                                break;
                            }
                            printf("Enter an element: ");
                            if (element_size == sizeof(int)) {
                                int intValue;
                                scanf("%d", &intValue);
                                memcpy(newElement, &intValue, sizeof(int));
                            } else if (element_size == sizeof(double)) {
                                double doubleValue;
                                scanf("%lf", &doubleValue);
                                memcpy(newElement, &doubleValue, sizeof(double));
                            } else if (element_size == sizeof(char)) {
                                char charValue;
                                scanf(" %c", &charValue);
                                memcpy(newElement, &charValue, sizeof(char));
                            } else {
                                printf("Unsupported element size.\n");
                                free(newElement);
                                break;
                            }
                            
                            if (stack_push(stack, newElement)) {
                                printf("Element pushed onto the stack.\n");
                            } else {
                                printf("Failed to push element onto the stack.\n");
                            }
                            
                            free(newElement);
                            break;
                        }
                        case 2: {
                            // Pop an element from the stack
                            if (stack_pop(stack)) {
                                printf("Element popped.\n");
                            } else {
                                printf("Stack is empty.\n");
                            }
                            break;
                        }
                        case 3: {
                            // Peek at the top element
                            if (!stack_is_empty(stack)) {
                                // Allocate memory for the element to be peeked
                                void *peekedElement = malloc(element_size);
                                if (!peekedElement) {
                                    printf("Memory allocation failed.\n");
                                    break;
                                }

                                if (stack_peek(stack, peekedElement)) {
                                    printf("Peeked element: ");
                                    // Print the peeked element based on its data type
                                    if (element_size == sizeof(int)) {
                                        printf("%d\n", *(int *)peekedElement);
                                    } else if (element_size == sizeof(double)) {
                                        printf("%lf\n", *(double *)peekedElement);
                                    } else if (element_size == sizeof(char)) {
                                        printf("%c\n", *(char *)peekedElement);
                                    } else {
                                        printf("Unsupported element size.\n");
                                    }
                                } else {
                                    printf("Failed to peek at element.\n");
                                }
                                
                                free(peekedElement);
                            } else {
                                printf("Stack is empty.\n");
                            }
                            break;
                        }
                        case 4: {
                            // Check if stack is empty
                            if (stack_is_empty(stack)) {
                                printf("Stack is empty.\n");
                            } else {
                                printf("Stack is not empty.\n");
                            }
                            break;
                        }
                        case 5: {
                            // Print all elements of the stack by popping
                            if (stack_is_empty(stack)) {
                                printf("Stack is empty.\n");
                            } else {
                                printf("Elements in the stack:\n");
                                while (!stack_is_empty(stack)) {
				    void *element = malloc(element_size);
				    if (!element) {
					printf("Memory allocation failed.\n");
					break;
				    }
				    if (stack_peek(stack, element)) {
					// Print the element based on its data type
					if (element_size == sizeof(int)) {
					    printf("%d ", *(int *)element);
					} else if (element_size == sizeof(double)) {
					    printf("%lf ", *(double *)element);
					} else if (element_size == sizeof(char)) {
					    printf("%c ", *(char *)element);
					} else {
					    printf("Unsupported element size.\n");
					    free(element);
					    break;
					}
				    }

			            // Pop from the original stack and push into the temporary stack
				    if (!stack_pop(stack)) {
					printf("Some Error Occurred!!\n");
					break;
				    }

				    free(element);
				}
				printf("\n");
                            }
                            break;
                        }
                        case 6: {
                            // Exit the program
                            stack_destroy(stack);
                            printf("Exiting...\n");
                            break;
                        }
                        default:
                            printf("Invalid choice.\n");
                    }
                } while (choice1 != 6);
                break;
            case 2:
                int elementDataType1;
                size_t element_size1;
                printf("---------------------\n");
                printf("Select element data type:\n");
                printf("1. int\n");
                printf("2. double\n");
                printf("3. char\n");
                printf("---------------------\n");
                printf("Enter your choice: ");
                scanf("%d", &elementDataType1);

                switch (elementDataType1) {
                    case 1:
                        element_size1 = sizeof(int);
                        
                        break;
                    case 2:
                        element_size1 = sizeof(double);
                        break;
                    case 3:
                        element_size1 = sizeof(char);
                        break;
                    default:
                        printf("Invalid choice.\n");
                        return 1;
                }
                Queue *queue = queue_create(element_size1);
                if (!queue) {
                    printf("Failed to create queue.\n");
                    return 1;
                }
                int choice2;
                do {
                    printf("---------------------\n");
                    printf("\nQueue Menu:\n");
                    printf("1. Enqueue an element\n");
                    printf("2. Dequeue an element\n");
                    printf("3. Peek at the front element\n");
                    printf("4. Check if queue is empty\n");
                    printf("5. Print all elements of queue\n");
                    printf("6. Exit\n");
                    printf("---------------------\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice2);

                    switch (choice2) {
                        case 1: {
                            // Enqueue an element into the queue
                            void *newElement = malloc(element_size1);
                            if (!newElement) {
                                printf("Memory allocation failed.\n");
                                break;
                            }

                            printf("Enter an element: ");
                            
                            // Read the element based on its data type
                            if (element_size1 == sizeof(int)) {
                                int intValue;
                                scanf("%d", &intValue);
                                memcpy(newElement, &intValue, sizeof(int));
                            } else if (element_size1 == sizeof(double)) {
                                double doubleValue;
                                scanf("%lf", &doubleValue);
                                memcpy(newElement, &doubleValue, sizeof(double));
                            } else if (element_size1 == sizeof(char)) {
                                char charValue;
                                scanf(" %c", &charValue);
                                memcpy(newElement, &charValue, sizeof(char));
                            } else {
                                printf("Unsupported element size.\n");
                                free(newElement);
                                break;
                            }

                            if (queue_enqueue(queue, newElement)) {
                                printf("Element enqueued into the queue.\n");
                            } else {
                                printf("Failed to enqueue element into the queue.\n");
                            }

                            free(newElement);
                            break;
                        }
                        case 2: {
                            // Dequeue an element from the queue
                            if (queue_dequeue(queue)) {
                                printf("Element dequeued.\n");
                            } else {
                                printf("Queue is empty.\n");
                            }
                            break;
                        }
                        case 3: {
                            // Peek at the front element
                            if (!queue_is_empty(queue)) {
                                // Allocate memory for the element to be peeked
                                void *peekedElement = malloc(element_size1);
                                if (!peekedElement) {
                                    printf("Memory allocation failed.\n");
                                    break;
                                }

                                if (queue_peek(queue, peekedElement)) {
                                    printf("Peeked element: ");
                                    // Print the peeked element based on its data type
                                    if (element_size1 == sizeof(int)) {
                                        printf("%d\n", *(int *)peekedElement);
                                    } else if (element_size1 == sizeof(double)) {
                                        printf("%lf\n", *(double *)peekedElement);
                                    } else if (element_size1 == sizeof(char)) {
                                        printf("%c\n", *(char *)peekedElement);
                                    } else {
                                        printf("Unsupported element size.\n");
                                    }
                                } else {
                                    printf("Failed to peek at element.\n");
                                }
                                
                                free(peekedElement);
                            } else {
                                printf("Queue is empty.\n");
                            }
                            break;
                        }
                        case 4: {
                            // Check if queue is empty
                            if (queue_is_empty(queue)) {
                                printf("Queue is empty.\n");
                            } else {
                                printf("Queue is not empty.\n");
                            }
                            break;
                        }
                        case 5: {
                            // Print all elements of the queue using dequeue
                            if (queue_is_empty(queue)) {
                                printf("Queue is empty.\n");
                            } else {
                                printf("Elements in the queue:\n");
                                while (!queue_is_empty(queue)) {
				    void *element = malloc(element_size1);
				    if (!element) {
					printf("Memory allocation failed.\n");
					break;
				    }
				    if (queue_peek(queue, element)) {
					// Print the element based on its data type
					if (element_size1 == sizeof(int)) {
					    printf("%d ", *(int *)element);
					} else if (element_size1 == sizeof(double)) {
					    printf("%lf ", *(double *)element);
					} else if (element_size1 == sizeof(char)) {
					    printf("%c ", *(char *)element);
					} else {
					    printf("Unsupported element size.\n");
					    free(element);
					    break;
					}
				    }
				    // Dequeue from the original queue and enqueue into the temporary queue
				    queue_dequeue(queue);
				    free(element);
				}
				printf("\n");
                            }
                            break;
                        }
                        case 6: {
                            // Exit the program
                            queue_destroy(queue);
                            printf("Exiting...\n");
                            break;
                        }
                        default:
                            printf("Invalid choice1.\n");
                    }
                } while (choice2 != 6);
                break;
            case 3:
            	int elementDataType2;
                size_t element_size2;
                printf("---------------------\n");
                printf("Select element data type:\n");
                printf("1. int\n");
                printf("2. double\n");
                printf("3. char\n");
                printf("---------------------\n");
                printf("Enter your choice: ");
                scanf("%d", &elementDataType2);

                switch (elementDataType2) {
                    case 1:
                        element_size2 = sizeof(int);
                        CompareFn = compare_int;
                        break;
                    case 2:
                        element_size2 = sizeof(double);
                        CompareFn = compare_double;
                        break;
                    case 3:
                        element_size2 = sizeof(char);
                        CompareFn = compare_char;
                        break;
                    default:
                        printf("Invalid choice.\n");
                        return 1;
                }
                PQueue *pq = pqueue_create(element_size, compare_int);
                if (!pq) {
                    printf("Failed to create priority queue.\n");
                    return 1;
                }

                int choice3;
                do {
                    printf("---------------------\n");
                    printf("\n1. Enqueue an element\n");
                    printf("2. Dequeue an element\n");
                    printf("3. Peek at the front element\n");
                    printf("4. Check if priority queue is empty\n");
                    printf("5. Exit\n");
                    printf("---------------------\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice3);
                    switch (choice3) {
                        case 1: {
                            // Enqueue an element into the priority queue
                            void *newElement; // Declare a pointer without allocating memory
                            printf("please enter the element: ");
			if (element_size2 == sizeof(int)) {
			    int intValue;
			    scanf("%d", &intValue);
			    newElement = malloc(sizeof(int)); // Allocate memory for the data
			    if (newElement) {
				memcpy(newElement, &intValue, sizeof(int));
			    }
			} else if (element_size2 == sizeof(double)) {
			    double doubleValue;
			    scanf("%lf", &doubleValue);
			    newElement = malloc(sizeof(double)); // Allocate memory for the data
			    if (newElement) {
				memcpy(newElement, &doubleValue, sizeof(double));
			    }
			} else if (element_size2 == sizeof(char)) {
			    char charValue;
			    scanf(" %c", &charValue);
			    newElement = malloc(sizeof(char)); // Allocate memory for the data
			    if (newElement) {
				memcpy(newElement, &charValue, sizeof(char));
			    }
			} else {
			    printf("Unsupported element size.\n");
			    break;
			}

			if (newElement) {
			    if (pqueue_enqueue(pq, newElement)) {
				printf("Element enqueued.\n");
			    } else {
				printf("Failed to enqueue element.\n");
				free(newElement); // Free memory in case of failure
			    }
			} else {
			    printf("Memory allocation failed.\n");
			}
			break;
                        }
                        case 2: {
                            // Dequeue an element from the priority queue
                            if (pqueue_dequeue(pq)) {
                                printf("Element dequeued.\n");
                            } else {
                                printf("Priority queue is empty.\n");
                            }
                            break;
                        }
                        case 3: {
                            // Peek at the front element
                            if (!pqueue_is_empty(pq)) {
                                // Allocate memory for the element to be peeked
                                // void *peekedElement = malloc(element_size2);
                               // if (!peekedElement) {
                                  //  printf("Memory allocation failed.\n");
                                 //   break;
                               // }

                              //  if (pqueue_peek(pq, peekedElement)) {
                                   // printf("Peeked element: ");
                                   // // Print the peeked element based on its data type
                                   // if (element_size2 == sizeof(int)) {
                                    //    printf("%d\n", *(int *)peekedElement);
                                   // } else if (element_size2 == sizeof(double)) {
                                    //    printf("%lf\n", *(double *)peekedElement);
                                   // } else if (element_size2 == sizeof(char)) {
                                   //     printf("%c\n", *(char *)peekedElement);
                                  //  } else {
                                 //       printf("Unsupported element size.\n");
                                //    }
                                //} else {
                                //    printf("Failed to peek at element.\n");
                                //}
                                
                                printf("Peeked Element: ");
                                if(elementDataType2 == 1){
                                    int intValue;
                                    if(pqueue_peek(pq,&intValue)){
				        printf("%d\n",intValue);
				    }
                                }
                                else if(elementDataType2 == 2){
                                     double doubleValue;
                                     if(pqueue_peek(pq,&doubleValue)){
				        printf("%lf\n",doubleValue);
				     }
                                }
                                else if(elementDataType2 == 3){
                                     char charValue;
                                     if(pqueue_peek(pq,&charValue)){
				        printf("%c\n",charValue);
				     }
                                }
                                //free(peekedElement);
                            } else {
                                printf("Priority queue is empty.\n");
                            }
                            break;
                        }
                        case 4: {
                            // Check if priority queue is empty
                            if (pqueue_is_empty(pq)) {
                                printf("Priority queue is empty.\n");
                            } else {
                                printf("Priority queue is not empty.\n");
                            }
                            break;
                        }
                        case 5: {
                            // Exit the program
                            pqueue_destroy(pq);
                            printf("Exiting...\n");
                            break;
                        }
                        default:
                            printf("Invalid choice.\n");
                    }
                } while (choice3 != 5);
                break;
            case 4:
                struct TrieNode* root = createNode();
	        if (!root) {
		    printf("Failed to create Trie.\n");
		    return 1;
	    	}

	        int choice;
	        do {
		    printf("---------------------\n");
		    printf("\n1. Insert a word into the Trie\n");
		    printf("2. Search for a word\n");
		    printf("3. Autocomplete words with a prefix\n");
		    printf("4. Destroy the Trie and Exit\n");
		    printf("---------------------\n");
		    printf("Enter your choice: ");
		    scanf("%d", &choice);
		    
		    switch (choice) {
		        case 1: {
		            // Insert a word into the Trie
		            char word[MAX_WORD_LENGTH];
		            printf("Enter a word (string): ");
		            scanf("%s", word);
		            
		            insert(root, word);
		            printf("Word inserted.\n");
		            break;
		        }
		        case 2: {
		            // Search for a word in the Trie
		            char word[MAX_WORD_LENGTH];
		            printf("Enter a word to search (string): ");
		            scanf("%s", word);
		            
		            if (search(root, word)) {
		                printf("%s found in the Trie.\n", word);
		            } else {
		                printf("%s not found in the Trie.\n", word);
		            }
		            break;
		        }
		        case 3: {
		            // Autocomplete words with a prefix
		            char prefix[MAX_WORD_LENGTH];
		            printf("Enter a prefix (string): ");
		            scanf("%s", prefix);

		            char** autocompleteResults = autocomplete(root, prefix);

		            if (autocompleteResults) {
		                printf("Words starting with '%s':\n", prefix);
		                for (int i = 0; autocompleteResults[i] != NULL; i++) {
		                    printf("%s\n", autocompleteResults[i]);
		                }
		                freeAutocompleteResults(autocompleteResults);
		            } else {
		                printf("No words found with prefix '%s'.\n", prefix);
		            }
		            break;
		        }
		        case 4: {
		            // Destroy the Trie and exit
		            destroy(root);
		            printf("Trie destroyed. Exiting...\n");
		            break;
		        }
		        default:
		            printf("Invalid choice.\n");
		    }
	        } while (choice != 4);
	        
	        break;
            case 5:
                int choice4;
                int size;
                size_t elementSize;
                printf("Enter the size of the array: ");
                scanf("%d", &size);
                printf("---------------------\n");
                printf("Choose a data type:\n");
                printf("1. Integer\n");
                printf("2. Double\n");
                printf("3. Character\n");
                printf("---------------------\n");
                printf("Enter your choice: ");
                scanf("%d", &choice4);

                // Determine elementSize based on the chosen data type
                switch (choice4) {
                    case 1:
                        elementSize = sizeof(int);
                        break;
                    case 2:
                        elementSize = sizeof(double);
                        break;
                    case 3:
                        elementSize = sizeof(char);
                        break;
                    default:
                        printf("Invalid choice.\n");
                        return 1;
                }

                // Create an array of the desired data type and size
                void* array = malloc(elementSize * size);
                if (!array) {
                    printf("Memory allocation failed.\n");
                    return 1;
                }

                // Populate the array with elements of the desired data type
                printf("Enter %d elements of the array:\n", size);
                for (int i = 0; i < size; i++) {
                    if (choice4 == 1) {
                        scanf("%d", (int*)(array + i * elementSize));
                    } else if (choice4 == 2) {
                        scanf("%lf", (double*)(array + i * elementSize));
                    } else if (choice4 == 3) {
                        scanf(" %c", (char*)(array + i * elementSize));
                    }
                }

                // Prompt the user for the target element based on the chosen data type
                printf("Enter the element to search for: ");
                void* target = malloc(elementSize);
                if (!target) {
                    printf("Memory allocation failed.\n");
                    free(array);
                    return 1;
                }

                if (choice4 == 1) {
                    scanf("%d", (int*)target);
                } else if (choice4 == 2) {
                    scanf("%lf", (double*)target);
                } else if (choice4 == 3) {
                    scanf(" %c", (char*)target);
                }

                // Perform the search based on the chosen data type
                int result = -1;
                if (choice4 == 1) {
                    result = linear_search(array, target, size, elementSize);
                } else if (choice4 == 2) {
                    result = linear_search(array, target, size, elementSize);
                } else if (choice4 == 3) {
                    result = linear_search(array, target, size, elementSize);
                }

                if (result != -1) {
                    printf("Element found at index %d.\n", result);
                } else {
                    printf("Element not found.\n");
                }

                // Clean up
                free(array);
                free(target);
                break;
            case 6:
                int choice5;
                int size1;
                size_t elemSize1;
                printf("Enter the size of the array: ");
                scanf("%d", &size1);
                printf("---------------------\n");
                printf("Choose a data type:\n");
                printf("1. Integer\n");
                printf("2. Double\n");
                printf("3. Character\n");
                printf("---------------------\n");
                printf("Enter your choice: ");
                scanf("%d", &choice5);

                // Determine elementSize based on the chosen data type
                switch (choice5){
                    case 1:
                        elemSize1 = sizeof(int);
                        break;
                    case 2:
                        elemSize1 = sizeof(double);
                        break;
                    case 3:
                        elemSize1 = sizeof(char);
                        break;
                    default:
                        printf("Invalid choice.\n");
                        return 1;
                }

                // Create an array of the desired data type and size
                void *array1 = malloc(elemSize1 * size1);
                if (!array1) {
                    printf("Memory allocation failed.\n");
                    return 1;
                }

                // Populate the array with elements of the desired data type
                printf("Enter %d elements of the array:\n", size1);
                for (int i = 0; i < size1; i++) {
                    if (choice5 == 1) {
                        scanf("%d", (int *)(array1 + i * elemSize1));
                    } else if (choice5 == 2) {
                        scanf("%lf", (double *)(array1 + i * elemSize1));
                    } else if (choice5 == 3) {
                        scanf(" %c", (char *)(array1 + i * elemSize1));
                    }
                }

                // Choose a sorting algorithm
                printf("---------------------\n");
                printf("Choose a sorting algorithm:\n");
                printf("1. Bubble Sort\n");
                printf("2. Insertion Sort\n");
                printf("3. Merge Sort\n");
                printf("4. Quick Sort\n");
                printf("5. sort\n");
                printf("---------------------\n");
                printf("Enter your choice: ");
                int sortingChoice;
                scanf("%d", &sortingChoice);

                // Define a compare function based on the chosen data type
                int (*compare)(const void *, const void *);
                switch (choice5) {
                    case 1:
                        compare = compare_int;
                        break;
                    case 2:
                        compare = compare_double;
                        break;
                    case 3:
                        compare = compare_char;
                        break;
                }

                // Sort the array using the chosen sorting algorithm
                switch (sortingChoice) {
                    case 1:
                        bubble_sort(array1, size1, elemSize1, compare);
                        break;
                    case 2:
                        insertion_sort(array1, size1, elemSize1, compare);
                        break;
                    case 3:
                        merge_sort(array1, size1, elemSize1, compare);
                        break;
                    case 4:
                        quick_sort(array1, size1, elemSize1, compare);
                        break;
                    case 5:
                        sort(array1,size1,elemSize1,compare);
                        break;
                    default:
                        printf("Invalid sorting choice.\n");
                        free(array1);
                        return 1;
                }

                // Print the sorted array
                printf("Sorted array:\n");
                for (int i = 0; i < size1; i++) {
                    if (choice5 == 1) {
                        printf("%d ", *((int *)(array1 + i * elemSize1)));
                    } else if (choice5 == 2) {
                        printf("%lf ", *((double *)(array1 + i * elemSize1)));
                    } else if (choice5 == 3) {
                        printf("%c ", *((char *)(array1 + i * elemSize1)));
                    }
                }
                printf("\n");

                // Clean up
                free(array1);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 7);
    return 0;
}
