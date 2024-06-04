#include <stdio.h>

void main()
{
	int A[10], i, j, t;

	printf("Enter the values of Array : ");

	for (i = 0; i < 10; i++)
	{
		scanf("%d", &A[i]);
	}

	for (i = 0; i < 10; i++)
		for (j = 0; j < 10 - i - 1; j++)
			if (A[j] > A[j + 1])
			{
				t = A[j];
				A[j] = A[j + 1];
				A[j + 1] = t;
			}

	printf("Sorted Array :-\n");

	for (i = 0; i < 10; i++)
		printf("%d\t", A[i]);
}