#ifndef QUEUE_H
#define QUEUE_H

#include "EVENTS.h"

#define QUEUE_SIZE 10

typedef struct {
    SystemEvent events[QUEUE_SIZE];
    int front;
    int rear;
    int count;
} EventQueue;

void init_queue(EventQueue *q);
int enqueue(EventQueue *q, SystemEvent event);
SystemEvent dequeue(EventQueue *q);

#endif
