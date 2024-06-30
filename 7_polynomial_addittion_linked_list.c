#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{   int coeff, power;
    struct node *next;
} *head1, *head2, *head3;

void insert(int coeff, int power, int poly)
{   struct node *head, *New, *temp;

    if(poly == 1)
        temp = head1;
    
    else if(poly == 2)
        temp = head2;
    
    else if(poly == 3)
        temp = head3;

    New = (struct node*) malloc(sizeof(struct node));

    if(New == NULL)
        printf("Overflow");
    
    else
    {   New -> coeff = coeff;
        New -> power = power;
        New -> next = NULL;

        if(temp == NULL)
        {   if(poly == 1)
                head1 = New;
            
            else if(poly == 2)
                head2 = New;
            
            else if(poly = 3)
                head3 = New;
        }
        
        else
        {   while(temp -> next != NULL)
                temp = temp -> next;
            
            temp -> next = New;
        }
    }
}

void add()
{   struct node *temp1, *temp2;

    temp1 = head1;
    temp2 = head2;

    while(temp1 != NULL && temp2 != NULL)
    {   if(temp1 -> power > temp2 -> power)
        {   insert(temp1 -> coeff, temp1 -> power, 3);
            temp1 = temp1 -> next;
        }
        
        else if(temp2 -> power > temp1 -> power)
        {   insert(temp2 -> coeff, temp2 -> power, 3);
            temp2 = temp2 -> next;
        }

        else
        {   insert(temp1 -> coeff + temp2 -> coeff, temp1 -> power, 3);
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
    }

    while (temp1 != NULL)
    {   insert(temp1 -> coeff, temp1 -> power, 3);
        temp1 = temp1 -> next;
    }

    while (temp2 != NULL)
    {   insert(temp2 -> coeff, temp2 -> power, 3);
        temp2 = temp2 -> next;
    }
}

void substract()
{   struct node *temp1, *temp2;

    temp1 = head1;
    temp2 = head2;

    while (temp1 != NULL && temp2 != NULL)
        if(temp1 -> power > temp2 -> power)
        {   insert(temp1 -> coeff, temp1 -> power, 3);
            temp1 = temp1 -> next;
        }
        
        else if(temp2 -> power > temp1 -> power)
        {   insert(-1 * temp2 -> coeff, temp2 -> power, 3);
            temp2 = temp2 -> next;
        }

        else
        {   insert(temp1 -> coeff - temp2 -> coeff, temp1 -> power, 3);
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
    
    while (temp1 != NULL)
    {   insert(temp1 -> coeff, temp1 -> power, 3);
        temp1 = temp1 -> next;
    }

    while (temp2 != NULL)
    {   insert(-1 * temp2 -> coeff, temp2 -> power, 3);
        temp2 = temp2 -> next;
    }
}

void display(int poly)
{   struct node *temp;
    
    if(poly == 3)
        temp = head3;
    
    while(temp != NULL)
    {   printf("%dx^%d\t", temp -> coeff, temp -> power);
        temp = temp -> next;

        if(temp != NULL)
            printf("+\t");
    }
}

int main()
{   int power, coeff, i = 0, op;
    char ch;

    head1 = NULL;
    head2 = NULL;
    head3 = NULL;

    while (i<2)
    {   printf("Enter polynomial %d\n", ++i);

        while(1)
        {   printf("Enter power : ");
            scanf("%d", &power);

            printf("Enter coeff : ");
            scanf("%d", &coeff);

            insert(coeff, power, i);

            printf("Press E to exit\nPress any key to continue\n");
            ch = getche();

            if(ch == 'E' || ch == 'e')
                break;
        }
    }

    printf("\nEnter operation:\n1. Addittion\n2. Substraction");
    scanf("%d", &op);

    if(op == 1)
    {   add();
        printf("P1 + P2 :\n");
    }

    else if (op == 2)
    {   substract();
        printf("P1 - P2 :\n");
    }

    else
        printf("Wrong choice\n");
    
    display(3);
}