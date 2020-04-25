#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <malloc.h>
int main()
{
	int* M = NULL;
	int* N = NULL;
	int* A = NULL;
	int n, m, i;
	int p, j = 0;

	printf("n=");
	scanf("%d", &n);
	printf("m=");
	scanf("%d", &m);

	p = n + m;
	M = (int*)malloc(m * sizeof(int));
	N = (int*)malloc(n * sizeof(int));
	A = (int*)malloc(p * sizeof(int));



	for (int i = 0; i < n; i++)
	{
		scanf("%d", &N[i]);
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%d", &M[i]);
	}
	if (n < m)
	{
		for (int i = 0; i < n; i++)
		{
			A[i] = N[i];
		}
		for (int i = n; i < p; i++)
		{
			A[i] = M[j];
			j++;
		}
	}
	if (m < n)
	{
		for (int i = 0; i < m; i++)
		{
			A[i] = M[i];
		}
		for (int i = m; i < p; i++)
		{
			A[i] = N[j];
			j++;
		}
	}

	for (i = 0; i < p - 1; i++)
	{
       for (j = 0; j < p - i - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				int tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
			}
		}
	}


	for (i = 0; i < p - 1; i++)
		if (A[i] == A[i + 1])
		{
			for (j = i; j < p - 1; j++)
				A[j] = A[j + 1];
			p -= 1;
		}

	for (i = 0; i < p; i++)
	{
		printf("%d ", A[i]);
	}

	while (getchar() != '\n');
	getchar();


	free(M);
	free(N);

	return 0;
}