#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stack.h"
#include <string.h>
check(const char* str)
{
	struct stack* s = NULL;
	int len = strlen(str), i;

	if (str[0] == '(')
		input(&s, str[0]);
	else if (str[0] == ')')
		return 0;

	if (str[0] == '{')
		input(&s, str[0]);
	else if (str[0] == '}')
		return 0;

	if (str[0] == '[')
		input(&s, str[0]);
	else if (str[0] == ']')
		return 0;

	for (i = 1; i < len; i++)
	{
		if (str[i] == '(')
			input(&s, str[i]);
		else if (str[i] == ')')
		{
			if (empty(&s))
				return 0;
			else
			{
				if (s->value == '(')
					pop(&s);
				else return 0;
			}
		}

		if (str[i] == '{')
			input(&s, str[i]);
		else if (str[i] == '}')
		{
			if (empty(&s))
				return 0;
			else
			{
				if (s->value == '{')
					pop(&s);
				else return 0;
			}

		}

		if (str[i] == '[')
			input(&s, str[i]);
		else if (str[i] == ']')
		{
			if (empty(&s))
				return 0;
			else
			{
				if (s->value == '[')
					pop(&s);
				else return 0;
			}
		}

	}

	if (empty(&s))
		return 1;
	else return 0;
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
		if (result)
			printf("It is right\n");
		else printf("It is not right\n");
	}
	while (getchar() != '\n');
}