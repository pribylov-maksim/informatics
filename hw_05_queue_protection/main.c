#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
multiplicity(struct queue* queue, int p)
{
	int i, l, k;
	l = length(queue);
	for (i = 0; i < l; i++)
	{
		k = dequeue(queue);
		if (k % p == 0)
		{
			printf("%d ", k);
		}
		else
		{
			enqueue(queue, k);
		}
	}
	printf("\n");
	if (queue->head == NULL)
	{
        printf("Empty");
		return 0;
	}
	else
	{
		dequeue(queue);
		struct node* q = queue->head;
		while (q != NULL)
		{
			printf("%d ", q->value);
			q = q->next;
		}
		return 0;
	}
}
int main()
{
	int a, p, n = -1;
	queue q;
	q.head = NULL;
	q.tail = NULL;
	printf("Enter p: ");
	scanf("%d", &p);
	while (n != 0)
	{
        scanf("%d", &a);
        enqueue(&q, a);
		n = a;
	}
	multiplicity(&q, p);
	while (getchar() != '\n');
	getchar();
}