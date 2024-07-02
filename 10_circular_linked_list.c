#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{   int info;
    struct node *next;
} *head, *rear;


void ins_beg(int value)
{   struct node *New;
    New = (struct node*) malloc(sizeof(struct node));

    if(New == NULL)
        printf("Overflow");
    
    else
    {   New -> info = value;
        New -> next = head;
        head = New;

        if(rear == NULL)
        {   rear = head;
            New -> next = rear;
        }

        rear -> next = head;
    }
}


void ins_pos(int value,  int pos)
{   int i;
    struct node *New, *temp;

    if(pos <= 1)
        ins_beg(value);
    else
    {   New = (struct node*) malloc(sizeof(struct node));

        if(New == NULL)
            printf("Overflow");
        
        else
        {   temp = head;
            
            for(i = 1; i<pos-1; i++)
                if(temp -> next != head)
                    temp = temp -> next;

                else
                {	printf("Position not found\n");
                    free(New);
                    return;
                }
            
            New -> info = value;
            New -> next = temp -> next;
            temp -> next = New;
            
            if(New -> next == head)
                rear = New;
        }
    }
}

void ins_end(int value)
{   struct node *New, *temp;

    if(head ==  NULL)
        ins_beg(value);
    
    else
    {   New = (struct node*) malloc(sizeof(struct node));

        if(New == NULL)
            printf("Overflow");
        
        else
        {   New -> info = value;
            rear -> next = New;
            rear = New;
            rear -> next = head;
        }
    }
}

void del_beg()
{   struct node *temp;

    if(head == NULL)
        printf("Underflow");
    
    else
    {   temp = head;
        head = temp -> next;
        rear -> next = head;
        
        free(temp);
    }
}

void del_pos(int pos)
{   struct node *temp1, *temp2;
	int i;

	temp1 = head;

	if(head == NULL)
		printf("\nUnderflow");

	else
	{	if(pos == 1)
            del_beg();

		else
		{	for(i = 1; i<pos; i++)
			{	if(temp1 -> next == head)
				{	printf("Node not found, Underflow");
					return;
				}
				else
				{   temp2 = temp1;
					temp1 = temp1 -> next;
				}
			}
            
            temp2 -> next = temp1 -> next;
            free(temp1);

            if(temp2 -> next == head)
                rear = temp2;
		}
	}
}

void del_end()
{   struct node *temp;
    temp = head;
    
    if(head == NULL)
        printf("Underflow");

    else if(head == rear)
    {   free(temp);
        head = NULL;
        rear = NULL;
    }
    
    else
    {   while(temp -> next != rear)
            temp = temp -> next;
        
        rear = temp;

        temp = temp -> next;
        free(temp);
        
        rear -> next = head;
    }

}

void display()
{   struct node *temp;
    temp = head;

    printf("\n%d\t", temp->info);
    
    while(temp != rear)
    {   temp = temp -> next;
        printf("%d\t", temp -> info);
    }
    
    printf("\n\n");
}

int main()
{   int op, pos, value;
    char pos_ch;

    head = NULL;
    rear = NULL;

    while(1)
    {   printf("1. Add Node\n");
        printf("2. Delete Node\n");
        printf("3. Exit\n");
        printf("Enter choice : ");

        scanf("%d", &op);

        if(op == 3)
            exit(0);
        
        if(op == 1)
        {   printf("Enter value of Node : ");
            scanf("%d", &value);
        }

        printf("Enter the Node position (B / E / S) : ");
        pos_ch = getche();

        if(pos_ch == 'B' || pos_ch == 'b')
            if(op == 1)
                ins_beg(value);
            else
                del_beg();
        
        else if(pos_ch == 'E' || pos_ch == 'e')
            if(op == 1)
                ins_end(value);
            else
                del_end();
        
        else if(pos_ch == 'S' || pos_ch == 's')
        {   printf("\nEnter position : ");
            scanf("%d", &pos);

            if(op == 1)
                ins_pos(value, pos);
            
            else
                del_pos(pos);
        }
        
        display();
    }
    return  0;
}