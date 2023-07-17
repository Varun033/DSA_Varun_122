#include <stdio.h>
#include <stdlib.h>

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

void check(FILE *fptr, char pat[100])
{
    char lin[100];
    int i = 0, j = 0, p1 = 0, status = 1;
    while (!feof(fptr))
    {
        fgets(lin, 50, fptr);
        printf("%s", lin);
        int n1 = count(lin);
        int n2 = count(pat);
        for (i = 0; i < n1 - n2; i++)
        {
            for (j = 0; j < n2; j++)
            {
                if (pat[j] != lin[i + j])
                {
                    status = 0;
                    break;
                }
            }
            if (j == n2 + 1 && status == 1)
            {
                p1 = 1;
                break;
            }
            status = 1;
        }
        if (p1 == 1)
        {
            printf("%s\n", lin);
            break;
        }
        p1 = 0;
    }
}
int main()
{
    FILE *fptr;
    char pat[100];
    fptr = fopen("text.txt", "r");
    fgets(pat, 100, fptr);
    check(fptr, pat);
    fclose(fptr);
}