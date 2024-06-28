#include <stdio.h>
#include <conio.h>
#include<stdlib.h>

struct dnode
{	int info;
	struct dnode *prev, *next;
} *head;

void ins_beg(int value)
{	struct dnode *New;

	New = (struct dnode*) malloc(sizeof(struct dnode));

	if (New == NULL)
		printf("Overflow");

	else
	{
		New->info = value;
		New->next = head;
		head = New;
	}
	
}

void ins_pos(int value, int pos)
{	struct dnode *New, *temp;
	int i;

	New = (struct dnode*) malloc(sizeof(struct dnode));

	if (New == NULL)
	{	printf("Overflow");
		return;
	}

	if (pos == 1)
	{	free(New);
		ins_beg(value);
	}

	else
	{	temp = head;

		if (head == NULL)
		{	printf("Position not found");
			free(New);
		}
		else
			for (i = 1; i < pos-1; i++)
				if (temp->next != NULL)
					temp = temp->next;
				
				else
				{	printf("Position not found");
					free(New);
					return;
				}
		
		New->info = value;
		New -> next = temp -> next;
		New -> prev = temp;

		if(temp -> next != NULL)
			temp->next->prev = New;
		
		temp -> next = New;
	}	
}

void ins_end(int value)
{
	struct dnode *New, *temp;

	if(head == NULL)
		ins_beg(value);

	else
	{	New = (struct dnode*) malloc(sizeof(struct dnode));

		if(New == NULL)
		{	free(New);
			printf("Overflow");
		}

		else
		{	temp = head;

			while(temp -> next != NULL)
				temp = temp -> next;
			
			New -> info = value;
			New -> next = NULL;
			New -> prev = temp;
			temp -> next = New;
		}
	}
}


void del_beg()
{	struct dnode *temp;

	if(head == NULL)
		printf("Underflow");
	
	else
	{	temp = head;
		head = head -> next;
		free(temp);	
	}
}


void del_pos(int pos)
{	struct dnode *temp;
	int i;

	if(pos == 1)
		del_beg();
	
	else
	{	temp = head;

		for(i = 1; i<pos; i++)
			if(temp -> next != NULL)
				temp = temp -> next;
			else
				break;

		if(i!=pos)
			printf("Underflow");
		
		else
		{	temp -> prev -> next = temp -> next;
			if (temp -> next != NULL)
				temp -> next -> prev = temp -> prev;
			
			free(temp);
		}
	}
}

void del_end()
{	struct dnode *temp;

	if(head == NULL)
		printf("Underflow");
	
	else
	{	temp = head;

		while(temp -> next != NULL)
			temp = temp -> next;
		
		temp -> prev -> next = NULL;

		free(temp);
	}
}

void display()
{
	struct dnode *temp;
	temp = head;

	printf("\n");
	while (temp != NULL)
	{	printf("%d\t", temp->info);
		temp = temp->next;
	}

	printf("\n\n");

}
void main()
{
	int value, pos, op;
	char pos_ch;

	head = NULL;

	while (1)
	{
		printf("Press 1 to Add Node\nPress 2 to Delete Node\nPress 3 to exit\n");
		printf("\nEnter choice : ");
		scanf("%d", &op);

		if (op == 1) 
		{
			printf("\n\nEnter value of node : ");
			scanf("%d", &value);

			printf("Enter position (B, E, S) : ");
			pos_ch = getche();

			printf("\n");

			if (pos_ch == 'B' || pos_ch == 'b')
				ins_beg(value);

			else if (pos_ch == 'E' || pos_ch == 'e')
				ins_end(value);

			else if (pos_ch == 'S' || pos_ch == 's')
			{
				printf("Enter position no. : ");
				scanf("%d", &pos);
				ins_pos(value, pos);
			}

			display();
		}

		else if (op == 2)
		{	printf("\n\nEnter the node position (B, E, S) : ");
			pos_ch = getche();

			if (pos_ch == 'b' || pos_ch == 'B')
				del_beg();

			else if (pos_ch == 'e' || pos_ch == 'E')
				del_end();

			else if (pos_ch == 's' || pos_ch == 'S')
			{
				printf("\nEnter the node no. : ");
				scanf("%d", &pos);
				del_pos(pos);
			}

			display();
		}

		else
			exit(0);
	}
}