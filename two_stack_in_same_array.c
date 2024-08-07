#include<stdio.h>
#include<conio.h>

#define MAX 20

int main()
{   int A[MAX], top1 = -1, top2 = MAX, ele, op, stack, i;
    char ch = 'Y';

    while(ch == 'Y' || ch == 'y')
    {   printf("\nEnter operation to perform : ");
        scanf("%d", &op);

        if(op == 1)
            if(top1 == top2-1)
                printf("Overflow");
            
            else
            {   printf("Enter Stack no. : ");
                scanf("%d", &stack);
                
                printf("Enter element : ");
                scanf("%d", &ele);

                if(stack == 1)
                    A[++top1] = ele;
                
                else if(stack == 2)
                    A[--top2] = ele;
                
                else
                    printf("Invalid Stack\n");
            }

        else if (op == 2)
        {   printf("Enter the stack no. : ");
            scanf("%d", &stack);

            if(stack == 1)
                if(top1 == -1)
                    printf("Underflow");
                else
                    printf("Popped element : %d\n", A[top1--]);
            
            else if(stack == 2)
                if(top2 == MAX)
                    printf("Underflow");
                else
                    printf("Popped element : %d\n", A[top2++]);
            
            else
                printf("Invalid Stack\n");
        }

        for(i = 0; i<=top1; i++)
            printf("%d\t", A[i]);
        
        printf("<--- Stack 1\t\tStack2 --->");

        for(i = top2; i<MAX; i++)
            printf("\t%d", A[i]);
        
        printf("\nPerform More operations (Y / N) ? ");
        ch = getche();
    }
}