#include<stdio.h>
#include<conio.h>

struct Node
{	int info;
	struct Node *next;
} *New, *head;

void ins_beg(int value)
{	New = (struct Node*) malloc(sizeof(struct Node));

	if(New == NULL)
		printf("Overflow");

	else
	{	New -> info = value;

		if(head == NULL)
			New -> next = NULL;

		else
			New -> next = head;

		head = New;
	}
}

void ins_end(int value)
{       struct Node *temp;
	temp = head;

	New = (struct Node*) malloc(sizeof(struct Node));

	if(New == NULL)
		printf("Overflow");

	else
	{	New -> info = value;
		New -> next = NULL;

		if(head == NULL)
			head = New;

		else
		{	while(temp -> next != NULL)
				temp = temp -> next;

			temp -> next = New;
		}
	}
}

void ins_pos(int value, int pos)
{	struct Node *temp;
	int i;

	temp = head;

	New = (struct Node*) malloc(sizeof(struct Node));

	if(New == NULL)
		printf("Overflow");

	else
	{	New -> info = value;
		if(pos == 1)
		{	if(head == NULL)
				New -> next = NULL;
			else
				New -> next=  head;
			head = New;
		}

		else
		{	if(head == NULL)
			{	printf("Position Not  Found\n");
				free(New);
				getch();
				return;
			}
			else
			{	for(i = 1; i<pos-1; i++)
					if(temp -> next != NULL)
						temp = temp -> next;

					else
					{	printf("Position not found\n");
						free(New);
						getch();
						return;
					}
			}

			New  -> next = temp -> next;
			temp -> next = New;
		}
	}
}

void del_beg()
{	struct Node *temp;

	if(head == NULL)
		printf("Underflow");

	else
	{	temp = head;
		head = head -> next;
	}

	free(temp);
}

void del_end()
{	struct Node *temp1, *temp2;

	if(head == NULL)
		printf("Underflow");

	else
	{      	temp1 = head;

		if(head -> next == NULL)
		{	free(temp1);
			head = NULL;
		}

		else
		{	while(temp1 -> next != NULL)
			{	temp2 = temp1;
				temp1 = temp1 -> next;
			}

			temp2 -> next = NULL;
			free(temp1);
		}
	}
}

void del_pos(int pos)
{	struct Node *temp1, *temp2;
	int i, pos_out = 0;

	temp1 = head;

	if(head == NULL)
		printf("\nUnderflow");

	else
	{	if(pos == 1)
		{	head = head -> next;
			free(temp1);
		}

		else
		{	for(i = 1; i<pos; i++)
			{	if(temp1 -> next == NULL)
				{	printf("Node not found, Underflow");
					return;
				}
				else
				{       temp2 = temp1;
					temp1 = temp1 -> next;
				}

			}

			if(pos_out)
				printf("Node not found, Underflow");
			else
			{	temp2 -> next = temp1 -> next;
				free(temp1);
			}
		}
	}
}



void display()
{	struct Node *temp;
	temp = head;

	printf("\n");

	if(temp == NULL)
		printf("List Empty");

	else
		while(temp != NULL)
		{	printf("%d\t", temp -> info);
			temp = temp -> next;
		}
	printf("\n\n");
}


void main()
{	int value, pos, op;
	char pos_ch;

	clrscr();

	head = NULL;

	while(1)
	{	printf("Press 1 to Add Node\nPress 2 to Delete Node\nPress 3 to exit");
		printf("\nEnter choice : ");
		scanf("%d", &op);

		if(op == 1)
		{      	printf("\n\nEnter value of node : ");
			scanf("%d", &value);

			printf("Enter position (B, E, S) : ");
			pos_ch = getche();

			printf("\n");

			if(pos_ch == 'B' || pos_ch == 'b')
				ins_beg(value);

			else if(pos_ch == 'E' || pos_ch == 'e')
				ins_end(value);

			else if(pos_ch == 's' || pos_ch == 'S')
			{	printf("Enter position no. : ");
				scanf("%d", &pos);
				ins_pos(value, pos);
			}

			display();
		}

		else if(op == 2)
		{	printf("\n\nEnter the node position (B, E, S) : ");
			pos_ch = getche();

			if(pos_ch == 'b' || pos_ch == 'B')
				del_beg();

			else if(pos_ch == 'e' || pos_ch == 'E')
				del_end();

			else if(pos_ch == 's' || pos_ch == 'E')
			{	printf("\nEnter the node no. : ");
				scanf("%d", &pos);
				del_pos(pos);
			}

			display();
		}

		else
			exit(0);
	}
}