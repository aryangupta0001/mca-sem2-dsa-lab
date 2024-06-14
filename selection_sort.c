#include<stdio.h>
int main()
{
    int n, A[20], i, j, temp;
    
    printf("Enter the Size of array : ");
    scanf("%d", &n);

    for(i = 0; i<n; i++)
        scanf("%d", &A[i]);
    
    for(i = 0; i<n-1; i++)
        for(j = i+1; j<n; j++)
            if(A[i] > A[j])
            {
                temp = A[i];;
                A[i] = A[j];
                A[j] = temp;
            }
    
    for(i = 0; i<n; i++)
        printf("%d", A[i]);
}