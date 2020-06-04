#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"
enqueue(struct queue** head, struct queue** tail, struct node* value)
{
	struct queue* q = (struct queue*)malloc(sizeof(struct queue));
	q->next = NULL;
	q->tree = value;
	if ((*head == NULL) && (*tail == NULL))
		* head = q;
	else
		(*tail)->next = q;
	*tail = q;
}
struct node* dequeue(struct queue** head, struct queue** tail)
{
	struct node* result;
	result = (*head)->tree;
	struct queue* buf;
	buf = *head;
	*head = (*head)->next;
	if (*head == NULL)
		* tail = NULL;
	free(buf);
	return result;
}
add_new(struct node** root, int new_value)
{
	if (*root == NULL)
	{
		*root = (struct node*)malloc(sizeof(struct node));
		(*root)->value = new_value;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else
	{
		if (new_value > (*root)->value)
			add_new(&(*root)->right, new_value);
		else
			add_new(&(*root)->left, new_value);
	}
}
dfs(struct node* root)
{
	if (root == NULL)
	{
		printf("Binary tree is empty!");
		return 0;
	}
	printf("%d ", root->value);
	if (root->left != NULL)
		dfs(root->left);
	if (root->right != NULL)
		dfs(root->right);
	return 0;
}
bfs(struct node* root)
{
	struct queue* head;
	struct queue* tail;
	head = NULL;
	tail = NULL;
	enqueue(&head, &tail, root);
	while (head != NULL)
	{
		struct queue* new_head;
		struct queue* new_tail;
		new_head = NULL;
		new_tail = NULL;
		while (head != NULL)
		{
			struct node* value;
			value = dequeue(&head, &tail);
			if (value == NULL) 
			{
				printf("Binary tree is empty!\n");  
				return 0;
			}
			if (value->left)
				enqueue(&new_head, &new_tail, value->left);
			if (value->right)
				enqueue(&new_head, &new_tail, value->right);
			printf("%d ", value->value);
		}
		printf("\n");
		head = new_head;
		tail = new_tail;
	}
	return 0;
}
search(struct node* root, const int num)
{
	int cout = 0;
	struct queue* head;
	struct queue* tail;
	head = NULL;
	tail = NULL;
	enqueue(&head, &tail, root);
	while (head != NULL)
	{
		struct queue* new_head;
		struct queue* new_tail;
		new_head = NULL;
		new_tail = NULL;
		while (head != NULL)
		{
			struct node* value;
			value = dequeue(&head, &tail);
			if (value == NULL)
			{
				printf("Binary tree is empty!\n");
				return 0;
			}
			if (value->value == num)
			{
				printf("Level = %d\n", cout);
				return 0;
			}
			if (value->left)
				enqueue(&new_head, &new_tail, value->left);
			if (value->right)
				enqueue(&new_head, &new_tail, value->right);
		}
		cout++;
		head = new_head;
		tail = new_tail;
	}
	printf("There is no searched element\n");
	return 0;
}
statistics(struct node* root)
{
	int count = 0, count1 = 0, lvl=0;
	struct queue* head;
	struct queue* tail;
	head = NULL;
	tail = NULL;
	enqueue(&head, &tail, root);
	while (head != NULL)
	{
		struct queue* new_head;
		struct queue* new_tail;
		new_head = NULL;
		new_tail = NULL;
		while (head != NULL)
		{
			struct node* value;
			value = dequeue(&head, &tail);
			if (value == NULL) 
			{
				printf("Binary tree is empty!\n");  
				return 0;
			}
			if ((value->left) || (value->right))
			{
				if (value->left)
				enqueue(&new_head, &new_tail, value->left);
				if (value->right)
					enqueue(&new_head, &new_tail, value->right);
				count++;
			}
			else
			{
				count1++;
			}
		}
        printf("Level - %d    ", lvl);
		printf("Inner treetop - %d    Leaves - %d", count, count1);
		printf("\n");
		lvl++;
		count = 0;
		count1 = 0;
		head = new_head;
		tail = new_tail;
	}
	return 0;
}