#include <stdio.h>

void rec(int n) // T(n)
{
    if (n > 0)
    {
        printf("%d\n", n); // 1
        rec(n - 1);        // T(n-1)
    }
}

int main()
{
    int n = 4;
    rec(n);
}