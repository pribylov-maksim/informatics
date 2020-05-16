#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stack.h"
#include <string.h>
int check(const char* str)
{
	struct stack* s = NULL;
	int len = strlen(str), i, counter=0, counter1;

	if (str[0] == '(')
		input(&s, str[0]);
	else if (str[0] == ')')
		counter++;

	for (i = 1; i < len; i++)
	{
		if (str[i] == '(')
			input(&s, str[i]);
		else if (str[i] == ')')
		{
			if (empty(&s))
				counter++;
			else
			{
				if (s->value == '(')
					pop(&s);
				else
					counter++;
			}
		}
	}

	if (empty(&s))
		return (counter);
	else
	{
		counter1 = count(&s);
		counter = counter + counter1;
	}
	return(counter);
}
int main()
{
	char str[100];
	int result;
	while (1)
	{
		printf("Enter the string:");
		gets_s(str, 100);
		result = check(str);
		printf("%d\n", result);
	}
	while (getchar() != '\n');
}