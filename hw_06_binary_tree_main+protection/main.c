#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "binarytree.h"
int main()
{
	struct node* root = NULL;
	int menu = -1, value, i;
	while (menu != 0)
	{
		printf("1 - Add new \n");
		printf("2 - Breadth first search \n");
		printf("3 - Depth first search \n");
		printf("4 - Search number \n");
		printf("5 - Statistics \n");
		printf("0 - Exit \n");
		printf("Enter number: ");
		scanf("%d", &menu);
		if (menu == 1)
		{
			printf("Enter your number: ");
			scanf("%d", &value);
			add_new(&root, value);
		}
		else if (menu == 2)
		{
			bfs(root);
		}
		else if (menu == 3)
		{
			dfs(root);
			printf("\n");
		}
		else if (menu == 4)
		{
			printf("Enter your number: ");
			scanf("%d", &value);
			search(root, value);
		}
		else if (menu == 5)
		{
			statistics(root);
		}
		else if (menu == 0)
		{
			printf("\n");
		}
		else
		{
			printf("Wrong number\n");
		}
	}
	printf("Stopping program\n");
	while (getchar() != '\n');
	getchar();
}