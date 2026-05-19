#include "QUEUE.h"

void init_queue(EventQueue *q){
 q->front =0;
 q->rear =0;
 q->count =0;
}

int is_queue_empty(EventQueue *q){

if(q->count==0){

  return 1;
}
return 0;

}


int enqueue(EventQueue *q, SystemEvent event){

if(q->count==QUEUE_SIZE){

	return 0;
}

q->events[q->rear]=event;

q->rear=(q->rear+1)%QUEUE_SIZE;

q->count++;

return 1;

}


SystemEvent dequeue(EventQueue *q)
{
    if(is_queue_empty(q))
    {
        return EVENT_NONE;
    }

    SystemEvent event = q->events[q->front];

    q->front = (q->front + 1) % QUEUE_SIZE;

    q->count--;

    return event;
}
