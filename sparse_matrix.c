#include<stdio.h>

int main()
{
    int A[5][5], B[3][25], i, j, k = 0, R, C;

    printf("Enter no of Rows : ");
    scanf("%d", &R);
    
    printf("Enter no of Columns : ");
    scanf("%d", &C);

    for(i = 0; i<R; i++)
        for(j = 0; j<C; j++)
            scanf("%d", &A[i][j]);
    
    for(i = 0; i<R; i++)
        for(j = 0; j<C; j++)
            if(A[i][j] != 0)
            {   B[0][k] = i;
                B[1][k] = j;
                B[2][k++] = A[i][j];                
            }
    
    printf("\nRow\t|");
    for(i = 0; i<k; i++)
        printf("\t%d\t|", B[0][i]);
    
    printf("\nColumn\t|");
    for(i = 0; i<k; i++)
        printf("\t%d\t|", B[1][i]);
    
    printf("\nElement\t|");
    for(i = 0; i<k; i++)
        printf("\t%d\t|", B[2][i]);
    

}