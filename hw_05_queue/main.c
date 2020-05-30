#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

avg(float* arr, int n, int k)
{
	int i = 0;
	float sum = 0;
	int len = 0;
	float value;
	struct queue queue;
	queue.head = NULL;
	queue.tail = NULL;
	struct node* q = NULL;
	enqueue(&queue, arr[i]);
	q = queue.head;
	sum += q->value;
	len++;
	printf("%.2f ", sum / len);
	for (i = 1; i < k; i++)
	{
		enqueue(&queue, arr[i]);
		q = q->next;
		sum += q->value;
		len++;
		printf("%.2f ", sum / len);
	}
	for (i = k; i < n; i++)
	{
		q = queue.head;
		sum -= q->value;
		dequeue(&queue);
		enqueue(&queue, arr[i]);
		q = queue.tail;
		sum += q->value;
		printf("%.2f ", sum / len);
	}
	printf("\n");
}
int main()
{
	int n, k, i;
	printf("Enter n and k:");
	scanf("%d %d", &n, &k);
	float* arr = (float*)malloc(n * sizeof(float));
	for (i = 0; i < n; i++)
		scanf("%f", &arr[i]);
	avg(arr, n, k);
	while (getchar() != '\n');
	getchar();
}