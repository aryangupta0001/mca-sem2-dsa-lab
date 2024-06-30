#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{   int info;
    struct node *next;
} *front, *rear;

void display()
{   struct node *temp;
    temp = front;

    while(temp != NULL)
    {   printf("%d\t", temp -> info);
        temp = temp -> next;
    }
}

void enqueue(int ele)
{   struct node *New;
    New = (struct node*) malloc(sizeof(struct node));

    if(New == NULL)
        printf("Overflow\n");
    
    else
    {   New -> info = ele;
        New -> next = NULL;

        if(rear == NULL)
        {   rear = New;
            front = New;
        }

        else
        {   rear -> next = New;
            rear = New;
        }
    }

    display();
}

void dequeue()
{   struct node *temp;

    if(front == NULL)
        printf("Underflow\n");
    
    else
    {   printf("Dequeued element : %d", front -> info);
        
        temp = front;
        front = front -> next;
        free(temp);

        if(front == NULL)
            rear = NULL;
    }
    display();
}

int main()
{   int op, ele;
    front = NULL;
    rear = NULL;

    while(1)
    {   printf("\n1. Enqueue\n2. Dequeue\nEnter the operation : ");
        scanf("%d", &op);

        if(op == 1)
        {   printf("Enter the element : ");
            scanf("%d", &ele);
            enqueue(ele);
        }

        else if(op == 2)
            dequeue();
        
        else
            break;
    }
}