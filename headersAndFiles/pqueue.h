#ifndef PQUEUE_H
#define PQUEUE_H

#include <stddef.h>
#include <stdbool.h>

typedef int (*PQueueCompareFn)(const void *, const void *);

typedef struct PQueue PQueue;

PQueue *pqueue_create(size_t element_size, PQueueCompareFn compare_fn);
void pqueue_destroy(PQueue *queue);
bool pqueue_enqueue(PQueue *queue, const void *element);
bool pqueue_dequeue(PQueue *queue);
bool pqueue_peek(const PQueue *queue, void *element);
bool pqueue_is_empty(const PQueue *queue);

#endif /* PQUEUE_H */
