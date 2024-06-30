#include<stdio.h>
#include<conio.h>

int main()
{   int N, A[20], i, j, temp;
    printf("Enter the Size of array : ");
    scanf("%d", &N);

    printf("Enter the array elements :\n");
    for(i = 0; i<N; i++)
        scanf("%d", &A[i]);
    
    for(i = 0; i<N-1; i++)
        for(j = i+1; j<N; j++)
            if(A[i] > A[j])
            {   temp = A[i];;
                A[i] = A[j];
                A[j] = temp;
            }
    
    for(i = 0; i<N; i++)
        printf("%d\t", A[i]);
}