#include <stdio.h>
#include <stdlib.h>
void read(int m, int n, int a[m][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void disp(int m, int n, int a[m][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int determinant(int m, int n, int a[m][n])
{
    int i, det = 0, j;
    int b[m][n], c[m][n];

    for (i = 0; i < m; i++)
    {
        det = det + (a[0][i] * (a[1][(i + 1) % 3] * a[2][(i + 2) % 3] - a[1][(i + 2) % 3] * a[2][(i + 1) % 3]));
    }
    printf("%d\n", det);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            b[i][j] = (a[(i + 1) % 3][(j + 1) % 3] * a[(i + 2) % 3][(j + 2) % 3] - a[(i + 2) % 3][(j + 1) % 3] * a[(i + 1) % 3][(j + 2) % 3]);
        }
        printf("\n");
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[j][i] = b[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%0.2f ", (float)c[i][j] / (float)det);
        }
        printf("\n");
    }
}

void main()
{
    int m, n;
    printf("Enter m n ");
    scanf("%d%d", &m, &n);
    int a[m][n];
    read(m, n, a);
    disp(m, n, a);
    determinant(m, n, a);
}