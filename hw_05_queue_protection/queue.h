#ifndef _QUEUE_H
#define _QUEUE_H

struct node
{
	int value;
	struct node* next;
	struct node* prev;
};
typedef struct node node;
struct queue
{
	int data;
	struct node* head;
	struct node* tail;
};
typedef struct queue queue;
enqueue(struct queue* queue, int value);
int dequeue(struct queue* queue);
int length(struct queue* queue);
#endif 