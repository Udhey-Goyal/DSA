#include <stdio.h>

void Insert(int A[], int n)
{
    int i = n, temp;
    temp = A[i];

    // Move up the heap
    while (i > 1 && temp > A[i/2])
    {
        A[i] = A[i/2];
        i = i / 2;
    }
    A[i] = temp;
}

int Delete(int A[], int n)
{
    int i, j, x, temp, val;

    val = A[1];     
    x = A[n];       

    A[1] = x;   
    A[n] = val;     

    i = 1;
    j = 2 * i;

    
    while (j < n)
    {
        if (j < n - 1 && A[j + 1] > A[j])
            j = j + 1;

        if (A[i] < A[j])
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;

            i = j;
            j = 2 * i;
        }
        else
            break;
    }

    return val;
}

void Display(int A[], int n)
{
    int i;
    for (i = 1; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int PQ[50];  // priority queue
    int n = 1;   
    int choice, x, deleted;

    while (1)
    {
        printf("\n Priority Queue Using Max Heap \n");
        printf("1. Insert\n2. Delete (Remove Highest Priority)\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter value: ");
            scanf("%d", &x);
            PQ[n] = x;
            Insert(PQ, n);
            n++;
        }
        else if (choice == 2)
        {
            if (n == 1)
            {
                printf("Priority Queue Empty\n");
            }
            else
            {
                deleted = Delete(PQ, n - 1);
                n--;
                printf("Deleted (highest priority): %d\n", deleted);
            }
        }
        else if (choice == 3)
        {
            if (n == 1)
                printf("Priority Queue Empty\n");
            else
                Display(PQ, n);
        }
        else if (choice == 4)
        {
            break;
        }
        else
            printf("Invalid choice\n");
    }

    return 0;
}
