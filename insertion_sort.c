#include <stdio.h>

int main()
{
    int A[20], N, i, j, temp;

    printf("Enter the length of Array : ");
    scanf("%d", &N);

    printf("Enter the array elements : \n");

    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);

    for (i = 1; i < N; i++)
    {
        temp = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > temp)
        {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = temp;
    }

    for (i = 0; i < N; i++)
        printf("%d\t", A[i]);
}