#include<stdio.h>
#include<conio.h>


void display(int A[], int front, int rear)
{
    if(front>=0)
        while(front<=rear)
        {
            printf("%d\t", A[front]);
            front++;
        } 
        
    printf("\n");
}

void enqueue(int *A, int N, int *front, int *rear, int n)
{
    int F = *front, R = *rear;

    if(F == -1)
        F = 0;

    if(R < N-1)
    {   R++;
    
        A[R] = n;
        
        *front = F;
        *rear = R;

        display(A, F, R);
    }

    else
        printf("Overflow\n\n");
}

void dequeue(int A[], int *front, int *rear)
{
    int F = *front, R = *rear;

    if(F == -1)
        printf("Underflow\n\n");
    
    else
    {
        printf("Dequeued element : %d\n", A[F]);

        if(F == R)
        {   F = -1;
            R = -1;
        }

        else
            F++;

        *front = F;
        *rear = R;
        display(A, F, R);
    }
}

int main()
{
    int A[20],front = -1, rear = -1, N, n;
    char ch = 'y', o_ch;

    printf("Enter size of queue : ");
    scanf("%d", &N);

    while(ch == 'y' || ch == 'Y')
    {
        printf("Enter the operation to perform Enqueue (E) or Dequeue (D) or Exit (X) : \n");
        o_ch = getche();

        if(o_ch == 'e' || o_ch == 'E')
        {
            printf("\n\nEnter the element : ");
            scanf("%d", &n);

            enqueue(A, N, &front, &rear, n);
        }

        else if (o_ch == 'd' || o_ch == 'D')
            dequeue(A, &front, &rear);
        
        else if (o_ch == 'x' || o_ch == 'X')
            break;
        else
            printf("Invalid choice !!!\n\n");
    }
}