#include<stdio.h>
#include<conio.h>

int main()
{   int A[20], N, i, ele, beg, end, mid;

    printf("Enter no. of elements : ");
    scanf("%d", &N);

    printf("Enter elements in sorted form :\n");

    for(i = 0; i<N; i++)
        scanf("%d", &A[i]);
    
    printf("Enter element to search : ");
    scanf("%d", &ele);

    beg = 0;
    end = N;

    while(beg<=end)
    {   mid = (beg + end) / 2;

        if(A[mid] == ele)
            break;
        
        if(ele>A[mid])
            beg = mid + 1;
        else
            end = mid - 1;
    }

    if(A[mid] == ele)
        printf("%d found at position : %d", ele, mid + 1);
    else
        printf("%d not found in array", ele);
}