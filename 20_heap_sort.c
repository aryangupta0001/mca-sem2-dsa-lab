#include<stdio.h>

void maxHeapify(int A[], int N, int i)
{   int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if (left<N && A[left] > A[largest])
        largest = left;
    
    if(right < N && A[right] > A[largest])
        largest = right;
    
    if(largest != i)
    {   temp = A[largest];
        A[largest] = A[i];
        A[i] = temp;

        maxHeapify(A, N, largest);
    }
}

void heapSort(int A[], int N)
{   int i, temp;

    for(i = N/2 - 1; i>=0; i--)
        maxHeapify(A, N, i);
    
    for(i = N-1; i>0; i--)
    {   temp = A[i];
        A[i] = A[0];
        A[0] = temp;

        maxHeapify(A, i, 0);
    }
}

int main()
{   int A[100], N, i;

    printf("Enter the size of Array : ");
    scanf("%d", &N);

    printf("Enter Array elements :\n");
    for(i = 0; i<N; i++)
        scanf("%d", &A[i]);

    heapSort(A, N);

    for(i = 0; i<N; i++)
        printf("%d\t", A[i]);   

}