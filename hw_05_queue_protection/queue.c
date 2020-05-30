#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
enqueue(struct queue* queue, int value)
{
	struct node* q = (struct node*)malloc(sizeof(struct node));
	q->value = value;
	q->prev = queue->tail;
	q->next = NULL;
	if (queue->tail == NULL)
		queue->head = q;
	else
		queue->tail->next = q;
	queue->tail = q;
}
int dequeue(struct queue* queue)
{
	int value;
	value = queue->head->value;
	struct node* q = queue->head;
	queue->head = queue->head->next;
	free(q);
	if (queue->head == NULL)
		queue->tail = NULL;
	else
		queue->head->prev = NULL;
	return (value);
}
int length(struct queue* queue)
{
	int len=0;
	struct node* q = queue->head;
	while (q != NULL)
	{
		q = q->next;
		len++;
	}
	len--;
	return (len);
}