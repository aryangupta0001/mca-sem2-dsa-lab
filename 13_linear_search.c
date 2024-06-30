#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{   int A[20], N, ele, i, found = 0;

    printf("Enter the no. of elements (Max. 20) : ");
    scanf("%d", &N);

    for(i = 0; i<N; i++)
        scanf("%d", &A[i]);
    
    printf("Enter the element to search : ");
    scanf("%d", &ele);

    for(i = 0; i<N; i++)
        if(A[i] == ele)
        {   printf("%d found at position %d", ele, i+1);
            exit(0);
        }
    
    printf("Element not found");
}