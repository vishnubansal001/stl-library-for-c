#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "queue.h"
#include "trie.h"
#include "pqueue.h"


#define INITIAL_CAPACITY 10

struct Stack {
    size_t element_size;
    size_t capacity;
    size_t size;
    void *data;
};

Stack *stack_create(size_t element_size) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack) {
        stack->element_size = element_size;
        stack->capacity = INITIAL_CAPACITY;
        stack->size = 0;
        stack->data = malloc(element_size * stack->capacity);

        if (!stack->data) {
            free(stack);
            stack = NULL;
        }
    }
    return stack;
}

void stack_destroy(Stack *stack) {
    if (stack) {
        free(stack->data);
        free(stack);
    }
}

bool stack_resize(Stack *stack, size_t new_capacity) {
    void *new_data = realloc(stack->data, stack->element_size * new_capacity);
    if (new_data) {
        stack->data = new_data;
        stack->capacity = new_capacity;
        return true;
    }
    return false;
}

bool stack_push(Stack *stack, const void *element) {
    if (!stack) return false;

    if (stack->size >= stack->capacity) {
        if (!stack_resize(stack, stack->capacity * 2)) {
            return false;
        }
    }

    void *dest = (char *)stack->data + stack->element_size * stack->size;
    memcpy(dest, element, stack->element_size);
    stack->size++;
    return true;
}

bool stack_pop(Stack *stack) {
    if (!stack || stack->size == 0) return false;

    stack->size--;

    if (stack->size < stack->capacity / 2 && stack->capacity > INITIAL_CAPACITY) {
        stack_resize(stack, stack->capacity / 2);
    }

    return true;
}

bool stack_peek(const Stack *stack, void *element) {
    if (!stack || stack->size == 0) return false;

    void *src = (char *)stack->data + stack->element_size * (stack->size - 1);
    memcpy(element, src, stack->element_size);

    return true;
}

bool stack_is_empty(const Stack *stack) {
    return stack ? stack->size == 0 : true;
}
