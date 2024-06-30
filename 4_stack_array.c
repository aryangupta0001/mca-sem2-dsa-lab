#include<stdio.h>
#include<conio.h>
#define N 20

void display(int A[], int top)
{   int i;
    for(i = 0; i<=top; i++)
        printf("%d\t", A[i]);
}
int main()
{   int A[N], top = -1, op;

    while(1)
    {   display(A, top);
    
        printf("\n1. Push\n2. Pop\n3. Exit\nEnter operation : ");
        scanf("%d", &op);

        if(op == 1)
            if(top == N-1)
                printf("Stack Overflow\n");
            else
            {   printf("Enter the element : ");
                scanf("%d", &A[++top]);
            }

        else if(op == 2)
            if(top == -1)
                printf("Stack Underflow\n");
            
            else
                printf("Element popped : %d\n", A[top--]);

        else if(op == 3)
            break;
        
        else
            printf("Wrong choice");
    }
}