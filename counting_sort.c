#include<stdio.h>

int main()
{
    int A[20], B[100], C[20], i, N, M = 0;

    printf("Enter the size of array : ");
    scanf("%d", &N);

    for(i = 0; i<N; i++)
    {   scanf("%d", &A[i]);
        if(M < A[i])
            M = A[i];
    }
    
    for(i = 0; i<100; i++)
        B[i] = 0;

    for(i = 0; i<N; i++)
        B[A[i]]++;

    for(i = 1; i<=M; i++)
        B[i] += B[i-1];

    for(i = N-1; i>=0; i--)
        C[--B[A[i]]] = A[i];

    for(i = 0; i<N; i++)
        A[i] = C[i];
    
    printf("Sorted Array :\n");
    for(i = 0; i<N; i++)
        printf("%d\t", A[i]);
    
}