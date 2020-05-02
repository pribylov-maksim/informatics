#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include "linkedlist.h"
#include <stdlib.h>
print(list** head)
{
	list* l = *head;
	while (l != NULL)
	{
		printf("%d ", l->value);
		l = l->next;
	}
}
init_head(list** head, int a)
{
	list* l = (list*)malloc(sizeof(list));
	l->value = a;
	l->next = NULL;
	*head = l;
}
add_first(list** head, int a)
{
	list* l = (list*)malloc(sizeof(list));
	l->value = a;
	l->next = *head;
	*head = l;
}
add_last(list** head, int a)
{
	list* l = get_last(head);
	list* l1 = (list*)malloc(sizeof(list));
	l1->value = a;
	l1->next = NULL;
	l->next = l1;
}
add_N(list** head, int n, int a)
{
	int k;
	int counter = 0;
	list* l1 = *head;
	list* next = *head;
	list* prev = *head;
	while (l1 != NULL)
	{
		l1 = l1->next;
		counter++;
	}
	if (counter == 0)
	{
		list* l = (list*)malloc(sizeof(list));
		l->value = a;
		l->next = *head;
		*head = l;
	}
	else if (counter < n)
	{
		printf("Your number is bigger than the number of elements\n");
	}
	else
	{
		n--;
		k = n;
		k--;
        while (n != 0)
		{
			next = next->next;
			n--;
		}
        while (k != 0)
		{
			prev = prev->next;
			k--;
		}
        list* l = (list*)malloc(sizeof(list));
		l->value = a;
		l->next = next;
		prev->next = l;
	}
}
delete_first(list** head)
{
	list* prev = NULL;
	int val;
	prev = (*head);
	val = prev->value;
	(*head) = (*head)->next;
	free(prev);
}
delete_last(list** head)
{
	list* last = NULL;
	last = get_before_last(*head);
	if (last == NULL)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		free(last->next);
		last->next = NULL;
	}
}
list* get_last(list** head)
{
	list* l = *head;
	while (l->next)
	{
		l = l->next;
	}
	return (l);
}
list* get_before_last(list* head)
{
	while (head->next->next)
		head = head->next;
	return (head);
}