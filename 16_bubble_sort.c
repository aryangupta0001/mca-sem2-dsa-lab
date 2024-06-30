#include <stdio.h>
#include<conio.h>

int main()
{	int A[20], N, i, j, t;

	printf("Enter no. of elements in Array (Max. 20) : ");
	scanf("%d", &N);

	printf("Enter the elements of Array : ");

	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);

	for (i = 0; i < N; i++)
		for (j = 0; j < N - i - 1; j++)
			if (A[j] > A[j + 1])
			{	t = A[j];
				A[j] = A[j + 1];
				A[j + 1] = t;
			}

	printf("Sorted Array :-\n");

	for (i = 0; i < 10; i++)
		printf("%d\t", A[i]);
}