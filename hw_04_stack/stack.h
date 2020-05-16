#ifndef STACK_H
#define STACK_H
struct stack 
{
	char value;
	struct stack* next;
};
typedef struct stack stack;
input(stack** head, const char str);
char pop(stack** head);
empty(stack** head);
#endif