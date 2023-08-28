#include <stdbool.h>

typedef struct Stack Stack;

Stack *stack_create(size_t element_size);
void stack_destroy(Stack *stack);
bool stack_push(Stack *stack, const void *element);
bool stack_pop(Stack *stack);
bool stack_peek(const Stack *stack, void *element);
bool stack_is_empty(const Stack *stack);

