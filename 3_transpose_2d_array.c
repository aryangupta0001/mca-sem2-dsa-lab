#include<stdio.h>
#include<conio.h>

int main()
{
    int A[5][5], B[5][5], i, j, R, C;

    printf("Enter no. of rows : ");
    scanf("%d", &R);

    printf("Enter no. of columns : ");
    scanf("%d", &C);

    printf("Enter the elements :\n");

    for(i = 0; i<R; i++)
        for(j = 0; j<C; j++)
        {   scanf("%d", &A[i][j]);
            B[j][i] = A[i][j];
        }
    
    printf("Matrix :-\n");
    
    for(i = 0; i<R; i++)
    {   for(j = 0; j<C; j++)
            printf("%d\t", A[i][j]);
        
        printf("\n");
    }
    
    printf("Transpose of Matrix :-\n");

    for(i = 0; i<C; i++)
    {   for(j = 0; j<R; j++)
            printf("%d\t", B[i][j]);
        
        printf("\n");
    }
}