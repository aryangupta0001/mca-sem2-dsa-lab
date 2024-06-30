#include<stdio.h>
#include<conio.h>
#define N 20

void display(int A[], int front, int rear)
{   while(front<=rear)
        printf("%d\t", A[front++]);
}

void main()
{   int A[N], front = -1, rear = -1, op;

    while(1)
    {   if(front>=0)
            display(A, front, rear);
        
        printf("\n1. Push\n2. Pop\n3. Exit\nEnter operation : ");
        scanf("%d", &op);

        if(op == 1)
            if(rear == N-1)
                printf("Overflow\n");
            
            else
            {   printf("Enter the element : ");
                scanf("%d", &A[++rear]);

                if(front == -1)
                    front = 0;
            }

        else if(op == 2)
            if(front == -1)
                printf("Underflow\n");
            
            else
            {   printf("Dequeued element : %d\n", A[front++]);
                if(front>rear)
                    front = rear = -1;
            }
        
        else
            break;
    }
}