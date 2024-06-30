#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct node
{   int info;
    struct node *next;
} *top;


void display()
{   struct node *temp;
    temp = top;
    
    while(temp != NULL)
    {   printf("%d\t", temp->info);
        temp = temp -> next;
    }
}

void PUSH(int ele)
{   struct node *New;
    New = (struct node*) malloc(sizeof(struct node));

    if(New == NULL)
        printf("Stack Overflow");
    
    else
    {   New -> info = ele;
        New -> next = top;
        top = New;
    }
    display();
}

void POP()
{   struct node *temp;

    if(top == NULL)
        printf("Stack Underflow");
    
    else
    {   printf("Popped element : %d\n", top -> info);
        temp = top;
        top = top -> next;
        free(temp);
        display();
    }
}

int main()
{   int op, ele;
    top = NULL;

    while(1)
    {   printf("\n1. PUSH\n2. POP\n");
        scanf("%d", &op);

        if(op == 1)
        {   printf("Enter element : ");
            scanf("%d", &ele);
            PUSH(ele);
        }

        else if(op == 2)
            POP();
        
        else
            break;
    }
}