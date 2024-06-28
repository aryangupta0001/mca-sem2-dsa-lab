#include<stdio.h>
#include<conio.h>
#define N 20

int A[20], front = -1, rear = -1;


void display()
{
    int i;

    printf("\n");
    
    for(i = front; i<=rear; i++)
        printf("%d\t", A[i]);
    
    printf("\n");
}


void enqueue_beg(int n)
{
    if(front == 0)
        printf("Overflow");

    else
    {
        if(front == -1)
            front = rear = 0;
        
        else
            front--;

        A[front] = n;
    }
    
    display();
}


void enqueue_end(int  n)
{
    if(rear == N-1)
        printf("Overflow");
    
    else
    {
        if(front == -1)
            front = 0;
        
        A[++rear] = n;
    }
    
    display();
}


void del_beg()
{
    if(front == -1)
        printf("Underflow");
    
    else
    {
        printf("Dequeued element : %d", A[front]);

        if(front == rear)
            front = rear = -1;

        else
            front++;    
    }

    display();

}


void del_end()
{
    if(front == -1)
        printf("Underflow");
    
    else
    {
        printf("Dequeued element : %d", A[rear]);

        if(front == rear)
            front = rear = -1;

        else
            rear--;    
    }

    display();
}







int main()
{   char o_ch, pos;
    int n;

    while(1)
    {   printf("Enter the operation to perform, Enqueue (E), Dequeue (D) or Exit (X) : ");
        o_ch = getche();

        if(o_ch == 'E' || o_ch == 'e')
        {   printf("\nEnter the element : ");
            scanf("%d", &n);

            printf("Enter the position Beginning (B) or End (E) : ");
            pos = getche();

            if(pos == 'B' || pos == 'b')
                enqueue_beg(n);
            
            else if(pos == 'E' || pos == 'e')
                enqueue_end(n);
            
            else
                printf("Wrong position entered");
        }

        else if(o_ch == 'D' || o_ch == 'd')
        {   printf("Enter the position Beginning (B) or End (E) : ");
            pos = getche();

            if(pos == 'B' || pos == 'b')
                del_beg();
            
            else if(pos == 'E' || pos == 'e')
                del_end();
            
            else
                printf("Wrong position entered");
        }

        else
            printf("Wrong choice of operation");
    }
}