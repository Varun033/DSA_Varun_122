#include <stdio.h>

void rec(int n) // T(n)
{
    if (n > 0) // 1
    {
        for (int i = 0; i < n; i++) // n+1
        {
            printf("%d ", n); // n
        }
        printf("\n"); // 1
        rec(n - 1);   // T(n-1)
    }
}
// T(n) = T(n-1) + n

int main()
{
    int n = 5;
    rec(n);
}