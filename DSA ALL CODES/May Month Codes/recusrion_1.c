#include <stdio.h>

void rec(int n) // T(n)
{
    if (n > 0)
    {
        printf("%d ", n); // n
        rec(n - 1);       // T(n-1)
        printf("\n");
        rec(n - 1); // T(n-1)
    }
}

int main()
{
    int n = 5;
    rec(n);
}