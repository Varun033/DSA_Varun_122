#include <stdio.h>

int count(char str[100])
{
    int n = 0, i = 0;
    while (str[i] != '\0')
    {
        n++;
        i++;
    }
    return n;
}

void read(int n)
{
    int n1, n2, i;
    char str1[100], str2[100] = {0};
    for (i = 0; i < n; i++)
    {
        gets(str1);
        n1 = count(str1);
        n2 = count(str2);

        if (n2 < n1)
        {
            int i = 0;
            while (str1[i] != '\0')
            {
                str2[i] = str1[i];
                i++;
            }
        }
    }
    printf("%s", str2);
}

int main()
{
    char str[100];
    int n;
    printf("Enter no of lines\n");
    scanf("%d ", &n);
    read(n);
}
