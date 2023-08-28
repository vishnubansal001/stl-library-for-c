#include <stdlib.h>
#include <string.h>
#include "queue.h"

#define INITIAL_CAPACITY 10

struct Queue {
    size_t element_size;
    size_t capacity;
    size_t size;
    size_t front;
    size_t rear;
    void *data;
};

Queue *queue_create(size_t element_size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (queue) {
        queue->element_size = element_size;
        queue->capacity = INITIAL_CAPACITY;
        queue->size = 0;
        queue->front = 0;
        queue->rear = 0;
        queue->data = malloc(element_size * queue->capacity);

        if (!queue->data) {
            free(queue);
            queue = NULL;
        }
    }
    return queue;
}

void queue_destroy(Queue *queue) {
    if (queue) {
        free(queue->data);
        free(queue);
    }
}

bool queue_resize(Queue *queue, size_t new_capacity) {
    void *new_data = malloc(queue->element_size * new_capacity);
    if (new_data) {
        size_t i = 0;
        for (size_t j = queue->front; i < queue->size; ++i, j = (j + 1) % queue->capacity) {
            void *src = (char *)queue->data + queue->element_size * j;
            void *dest = (char *)new_data + queue->element_size * i;
            memcpy(dest, src, queue->element_size);
        }
        free(queue->data);
        queue->data = new_data;
        queue->capacity = new_capacity;
        queue->front = 0;
        queue->rear = i % new_capacity;
        return true;
    }
    return false;
}

bool queue_enqueue(Queue *queue, const void *element) {
    if (!queue) return false;

    if (queue->size >= queue->capacity - 1) {
        if (!queue_resize(queue, queue->capacity * 2)) {
            return false;
        }
    }

    void *dest = (char *)queue->data + queue->element_size * queue->rear;
    memcpy(dest, element, queue->element_size);
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->size++;
    return true;
}

bool queue_dequeue(Queue *queue) {
    if (!queue || queue->size == 0) return false;

    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;

    if (queue->size < queue->capacity / 2 && queue->capacity > INITIAL_CAPACITY) {
        queue_resize(queue, queue->capacity / 2);
    }

    return true;
}

bool queue_peek(const Queue *queue, void *element) {
    if (!queue || queue->size == 0) return false;

    void *src = (char *)queue->data + queue->element_size * queue->front;
    memcpy(element, src, queue->element_size);

    return true;
}

bool queue_is_empty(const Queue *queue) {
    return queue ? queue->size == 0 : true;
}
