#include <stdio.h>

void rec(int n) // T(n)
{
    if (n > 0)
    {
        for (int i = 1; i < n; i = i * 2) // n+1
        {
            printf("%d ", n); // n
        }
        rec(n - 1); // T(n-1)
    }
}

int main()
{
    int n = 10;
    rec(n);
}