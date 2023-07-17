#include <stdio.h>

void read(int a[], int n, FILE *fp)
{
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &a[i]);
    }
}

void disp(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubble_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    FILE *fp;
    fp = fopen("array.txt", "r");
    int n;
    fscanf(fp, "%d", &n);
    int a[n];
    read(a, n, fp);
    disp(a, n);
    bubble_sort(a, n);
    disp(a, n);
}