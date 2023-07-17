#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display(int a[100][100], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void transpose(int a[100][100], int r, int c)
{
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            printf("%d ", a[j][i]);
            if (j == r - 1)
                printf("\n");
        }
    }
}

void read(FILE *fp, int a[100][100], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            fscanf(fp, "%d", &a[i][j]);
        }
    }
}

void add_value(FILE *fp, int r, int c)
{
    int x;
    srand(time(NULL));
    for (int i = 0; i < r * c; i++)
    {
        x = rand() % 100;
        fprintf(fp, "%d ", x);
    }
}

int main()
{
    FILE *fp;
    int r, c;
    printf("Enter no of rows and column required:\n");
    scanf("%d %d", &r, &c);
    fp = fopen("matrix_data.txt", "w");
    add_value(fp, r, c);
    fclose(fp);
    fp = fopen("matrix_data.txt", "r");
    int a[100][100];
    read(fp, a, r, c);
    display(a, r, c);
    printf("\nOutput:\n");
    transpose(a, r, c);
}