#include<stdio.h>
#include<conio.h>
#define N 20

int A[N], front = -1, rear = -1;

void display()
{	int i;
	for(i = front; i<=rear; i = (i+1)%N)
		printf("%d\t", A[i]);
	printf("\n");
}

void enqueue(int n)
{       if((rear+1)%N == front)
		printf("Overflow");

	else
	{	if(front == -1)
			front = 0;

		rear = (rear+1)%N;
		A[rear] = N;
	}

	display();
}

void dequeue()
{    	if(front == -1)
		printf("Underflow");

	else
	{	printf("Dequeued element : %d", A[front]);

		if(front == rear)
		{	front = -1;
			rear = -1;
		}

		else
			front = (front+1)%N;
	}
	display();
}

void main()
{	int N;
	char ch = 'y';

	clrscr();

	while((ch == 'y') || (ch == 'Y'))
	{	printf("Enter the element : ");
		scanf("%d", &N);

		enqueue(N);

		printf("Want to enter more elements (y/n) ? ");
		ch = getche();
	}

	printf("Want to delete elements (y/n) ? ");
	ch = getche();

	while((ch == 'y') || (ch == 'Y'))
	{	dequeue();
		printf("Delete more elements (y/n) ? ");
		ch = getche();
	}


	getch();
}