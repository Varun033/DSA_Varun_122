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

void selection_sort(int a[], int n)
{
    int min = 999, temp, temp2;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (min > a[j])
            {
                min = a[j];
                temp = j;
            }
        }
        temp2 = a[temp];
        a[temp] = a[i];
        a[i] = temp2;
        min = 999;
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
    selection_sort(a, n);
    disp(a, n);
}