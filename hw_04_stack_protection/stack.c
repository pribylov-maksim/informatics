#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
#include <string.h>
input(stack** head, const char str)
{
	stack* s = (stack*)malloc(sizeof(stack));
	s->value = str;
	s->next = *head;
	*head = s;
}
empty(stack** head)
{
	if (*head == NULL)
		return 1;
	else
		return 0;
}
char pop(stack** head)
{
	if (*head == NULL)
		return 0;
	else
	{
		stack* s = NULL;
		stack* p = NULL;
		p = *head;
		char result = p->value;
		*head = p->next;
		free(p);
		s = *head;
		return result;
	}
}
int count(stack** head)
{
	int count=0;
	if (*head == NULL)
		return 0;
	else
	{
		stack* s = NULL;
		s = *head;
		while (s->next)
		{
			count++;
			s = s->next;
		}
		count++;
	}
	return (count);
}