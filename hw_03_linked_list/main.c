#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include "linkedlist.h"
#include <stdlib.h>
int main()
{
	int a, menu=-1;
	list* l = NULL;
	printf("Enter first number: ");
	scanf("%d", &a);
	init_head(&l, a);
	while (menu != 0)
	{
		printf("1 - print list\n");
		printf("2 - add number to the beginning\n");
		printf("3 - add to the end\n");
		printf("4 - add to the place N\n");
		printf("5 - delete first\n");
		printf("6 - delete last\n");
		printf("0 - Exit\n");
		scanf("%d", &menu);
		if (menu == 1)
		{
			printf("Numbers in list: ");
			print(&l);
			printf("\n");	
		}
		else if (menu == 2)
		{
			int b;
			printf("Enter your number: ");
			scanf("%d", &b);
			add_first(&l,b);
			printf("First number was added\n");
		}
		else if (menu == 3)
		{
			int c;
			printf("Enter your number: ");
			scanf("%d", &c);
			add_last(&l, c);
			printf("Last number was added\n");
		}
		else if (menu == 4)
		{
			int d, n;
			printf("Enter position and your number: ");
			scanf("%d %d",&n, &d);
			add_N(&l,n,d);
			printf("N number was added\n");
		}
		else if (menu == 5)
		{
			delete_first(&l);
			printf("First number was deleted\n");
		}
		else if (menu == 6)
		{
			delete_last(&l);
			printf("Last number was deleted\n");
		}
		else if (menu == 0)
		{
			printf("Stopping programm\n");
		}
		else
		{
			printf("Wrong number\n");
		}
	}
	return 0;
}