#include<stdio.h>
#include<conio.h>
#define N 20

int A[N], front = -1, rear = -1;

void display()
{	int i;
	for(i = front; i!=rear; i = (i+1)%N)
		printf("%d\t", A[i]);
	printf("%d\t", A[i]);
	printf("\n\n");
}

void enqueue(int n)
{	if((rear+1)%N == front)
		printf("Overflow\n");

	else
	{	if(front == -1)
			front = 0;

		rear = (rear+1)%N;
		A[rear] = n;
	}

	display();
}

void dequeue()
{	if(front == -1)
		printf("Underflow");

	else
	{	printf("Dequeued element : %d\n\n", A[front]);

		if(front == rear)
		{	front = -1;
			rear = -1;
		}

		else
			front = (front+1)%N;
	}
	display();
}

int main()
{	int n;
	char ch = 'y', o_ch;

	while(ch == 'y' || ch == 'Y')
    {	printf("Enter the operation to perform Enqueue (E) or Dequeue (D) or Exit (X) : ");
        o_ch = getche();

        if(o_ch == 'e' || o_ch == 'E')
        {	printf("\n\nEnter the element : ");
            scanf("%d", &n);

            enqueue(n);
        }

        else if (o_ch == 'd' || o_ch == 'D')
            dequeue();
        
        else if (o_ch == 'x' || o_ch == 'X')
            break;
		
        else
            printf("Invalid choice !!!\n\n");
    }

	getch();
}