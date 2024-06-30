#include<stdio.h>
#include<conio.h>

void display(int A[], int front, int rear, int N)
{   printf("%d\t", A[front]);
    while (front != rear)
        printf("%d\t", A[(++front) % N]);
}

int main()
{   int A[20], N = 20, op, front = -1, rear = -1;

    while(1)
    {   if(front>=0)
            display(A, front, rear, N);
        
        printf("\n1. Enqueue\n2. Dequeue\n3. Exit\nEnter the operation : ");
        scanf("%d", &op);

        if(op == 1)
            if((rear+1) % N == front)
                printf("Overflow\n");
            
            else
            {   printf("Enter the element : ");
                scanf("%d", &A[(++rear) % N]);

                if(front == -1)
                    front = 0;
            }

        else if(op == 2)
            if(front == -1)
                printf("Underflow\n");
            
            else
            {
                printf("Dequeued elemennt : %d\n", A[front]);

                if(front == rear)
                    front = rear = -1;
                else
                    front = (front+1) % N;
            }

        else
            break;
    }
}