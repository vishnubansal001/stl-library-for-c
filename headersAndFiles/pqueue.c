#include <stdlib.h>
#include <string.h>
#include "pqueue.h"

#define INITIAL_CAPACITY 10

struct PQueue {
    size_t element_size;
    size_t capacity;
    size_t size;
    PQueueCompareFn compare_fn;
    void *data;
};

PQueue *pqueue_create(size_t element_size, PQueueCompareFn compare_fn) {
    PQueue *queue = (PQueue *)malloc(sizeof(PQueue));
    if (queue) {
        queue->element_size = element_size;
        queue->capacity = INITIAL_CAPACITY;
        queue->size = 0;
        queue->compare_fn = compare_fn;
        queue->data = malloc(element_size * queue->capacity);

        if (!queue->data) {
            free(queue);
            queue = NULL;
        }
    }
    return queue;
}

void pqueue_destroy(PQueue *queue) {
    if (queue) {
        free(queue->data);
        free(queue);
    }
}

bool pqueue_resize(PQueue *queue, size_t new_capacity) {
    void *new_data = malloc(queue->element_size * new_capacity);
    if (new_data) {
        memcpy(new_data, queue->data, queue->element_size * queue->size);
        free(queue->data);
        queue->data = new_data;
        queue->capacity = new_capacity;
        return true;
    }
    return false;
}

bool pqueue_enqueue(PQueue *queue, const void *element) {
    if (!queue) return false;

    if (queue->size >= queue->capacity - 1) {
        if (!pqueue_resize(queue, queue->capacity * 2)) {
            return false;
        }
    }

    size_t i = queue->size;
    while (i > 0 && queue->compare_fn(element, (char *)queue->data + queue->element_size * ((i - 1) / 2)) > 0) {
        void *parent = (char *)queue->data + queue->element_size * ((i - 1) / 2);
        memcpy((char *)queue->data + queue->element_size * i, parent, queue->element_size);
        i = (i - 1) / 2;
    }

    memcpy((char *)queue->data + queue->element_size * i, element, queue->element_size);
    queue->size++;
    return true;
}

bool pqueue_dequeue(PQueue *queue) {
    if (!queue || queue->size == 0) return false;

    queue->size--;
    if (queue->size > 0) {
        void *last = (char *)queue->data + queue->element_size * queue->size;
        void *root = queue->data;
        size_t i = 0;

        while (i * 2 + 1 < queue->size) {
            size_t child = i * 2 + 1;
            if (child + 1 < queue->size && queue->compare_fn((char *)queue->data + queue->element_size * child,
                (char *)queue->data + queue->element_size * (child + 1)) < 0) {
                child++;
            }

            if (queue->compare_fn(last, (char *)queue->data + queue->element_size * child) >= 0) {
                break;
            }

            memcpy((char *)queue->data + queue->element_size * i,
                (char *)queue->data + queue->element_size * child, queue->element_size);
            i = child;
        }

        memcpy((char *)queue->data + queue->element_size * i, last, queue->element_size);
    }

    if (queue->size < queue->capacity / 2 && queue->capacity > INITIAL_CAPACITY) {
        pqueue_resize(queue, queue->capacity / 2);
    }

    return true;
}

bool pqueue_peek(const PQueue *queue, void *element) {
    if (!queue || queue->size == 0) return false;

    memcpy(element, queue->data, queue->element_size);

    return true;
}

bool pqueue_is_empty(const PQueue *queue) {
    return queue ? queue->size == 0 : true;
}
