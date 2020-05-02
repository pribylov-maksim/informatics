//«аданы два массива из N, M  целых чисел. „исла в массивах изначально отсортированны по возрастанию, нет повтор€ющихс€ элементов.
//«адача: слить два массива в один новый, чтобы числа в нем тоже были упор€дочены.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <malloc.h>
int main()
{
	int* a = NULL;
	int* b = NULL;
	int* S = NULL;
	int n, m, i, j, p, k=0, counter=0;
	printf("n=");
	scanf("%d", &n);
	printf("m=");
	scanf("%d", &m);
	p = n + m;
	a = (int*)malloc(n * sizeof(int));
	b = (int*)malloc(m * sizeof(int));
	S = (int*)malloc(p * sizeof(int));
	printf("Enter numbers for array a: \n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &(*(a + i)));
	}
	printf("Enter numbers for array b: \n");
	for (j = 0; j < m; j++)
	{
		scanf("%d", &(*(b + j)));
	}
	i = 0;
	j = 0;
	if (n > m)
	{
		while ((i < n) && (j < m))
		{
			if (*(a + i) < *(b + j))
			{
				*(S + k) = *(a + i);
				i++;
				k++;
				counter++;
			}
			else if (*(a + i) == *(b + j))
			{
				*(S + k) = *(a + i);
				i++;
				j++;
				k++;
				counter++;
			}
			else
			{
				*(S + k) = *(b + j);
				j++;
				k++;
				counter++;
			}
		}
		while (i < n)
		{
			*(S + k) = *(a + i);
			i++;
			k++;
			counter++;
		}
	}
	else if (n < m)
	{
		while ((i < n) && (j < m))
		{
			if (*(a + i) < *(b + j))
			{
				*(S + k) = *(a + i);
				i++;
				k++;
				counter++;
			}
			else if (*(a + i) == *(b + j))
			{
				*(S + k) = *(a + i);
				i++;
				j++;
				k++;
				counter++;
			}
			else
			{
				*(S + k) = *(b + j);
				j++;
				k++;
				counter++;
			}
		}
		while (j < m)
		{
			*(S + k) = *(b + j);
			j++;
			k++;
			counter++;
		}
	}
	else if (n == m)
	{
		while ((i < n) && (j < m))
		{
			if (*(a + i) < *(b + j))
			{
				*(S + k) = *(a + i);
				i++;
				k++;
				counter++;
			}
			else if (*(a + i) == *(b + j))
			{
				*(S + k) = *(a + i);
				i++;
				j++;
				k++;
				counter++;
			}
			else
			{
				*(S + k) = *(b + j);
				j++;
				k++;
				counter++;
			}
		}
	}
	S = (int*)realloc(S,counter * sizeof(int));
	for (k = 0; k < counter; k++)
	{
		printf("%d ", *(S + k));
	}
	getchar();
	free(a);
	free(b);
	free(S);
	return 0;
}