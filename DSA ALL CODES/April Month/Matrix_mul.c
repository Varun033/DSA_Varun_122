#include <stdio.h>
#include <stdlib.h>
void read(int arr[10][10], int m1, int m2)
{
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}
void disp(int arr[10][10], int m1, int m2)
{
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void mux(int a[10][10], int b[10][10], int m1, int m2, int n1, int n2)
{
    int c[10][10], sum = 0;
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            sum = 0;
            for (int k = 0; k < n1; k++)
            {
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
        }
    }
    disp(c, m1, n2);
}
int main()
{
    int m1, m2, n1, n2;
    printf("Enter row and col of 1st matrix\n");
    scanf("%d %d", &m1, &m2);
    printf("Enter row and col of 2st matrix\n");
    scanf("%d %d", &n1, &n2);
    int a[m1][m2], b[n1][n2];
    read(a, m1, m2);
    read(b, n1, n2);
    disp(a, m1, m2);
    disp(b, n1, n2);
    mux(a, b, m1, m2, n1, n2);
}
