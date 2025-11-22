#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void ImprovedSelectionSort(int A[], int n)
{
    int left = 0, right = n - 1;

    while (left < right)
    {
        int minIndex = left;
        int maxIndex = left;

        // scan the unsorted portion
        for (int i = left; i <= right; i++)
        {
            if (A[i] < A[minIndex])
                minIndex = i;

            if (A[i] > A[maxIndex])
                maxIndex = i;
        }

        // place minimum at the beginning (left)
        swap(&A[left], &A[minIndex]);

        
        if (maxIndex == left)
            maxIndex = minIndex;

        // place maximum at the end (right)
        swap(&A[right], &A[maxIndex]);

        left++;
        right--;
    }
}

int main()
{
    int A[] = {11,13,7,12,16,9,24,5,10,3};
    int n = 10;

    ImprovedSelectionSort(A, n);

    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    printf("\n");
    return 0;
}
