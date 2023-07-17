#include <stdio.h>

void bubble_sort(int a[], int n)
{
    if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            bubble_sort(a, n - 1);
            if (a[n] < a[n - 1])
            {
                int temp = a[n - 1];
                a[n - 1] = a[n];
                a[n] = temp;
            }
        }
    }
}

void read(int a[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int main()
{
    int a[100];
    int n;
    scanf("%d", &n);
    read(a, n);
    bubble_sort(a, n);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}