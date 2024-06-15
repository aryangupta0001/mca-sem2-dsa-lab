#include<stdio.h>

void merge(int A[], int first, int mid, int last)
{
    int B[100];
    int i = first, j = mid + 1, k = first;

    while(i<=mid && j<=last)
        if(A[i]<=A[j])
            B[k++] = A[i++];
        
        else
            B[k++] = A[j++];
    
    if(i>mid)
        while(j<=last)
            B[k++] = A[j++];
    
    else
        while (i<=mid)
            B[k++] = A[i++];
    
    for (i = first; i <= last; i++)
        A[i] = B[i];
}

void mergeSort(int A[], int first, int last)
{
    int mid;

    if(first<last)
    {
        mid = (first + last) / 2;
        mergeSort(A, first, mid);
        mergeSort(A, mid+1, last);
        merge(A, first, mid, last);
    }
}

int main()
{
    int N, A[100], i;

    printf("Enter the size of Array : ");
    scanf("%d", &N);

    printf("Enter array elements :\n");

    for(i = 0; i<N; i++)
        scanf("%d", &A[i]);
    
    mergeSort(A, 0, N-1);

    for(i = 0; i<N; i++)
        printf("%d\t", A[i]);
}