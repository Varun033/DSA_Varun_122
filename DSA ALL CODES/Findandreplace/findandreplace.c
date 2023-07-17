#include <stdio.h>

int length(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

void copy(char temp[], char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        temp[i] = str[i];
        i++;
    }
    temp[i] = '\0';
}

void replace(int x, int l3, int l2, char temp[], char rep[])
{
    char str[1000];
    int i, j;
    for (int i = 0; i < x; i++)
    {
        str[i] = temp[i];
    }
    for (i = x, j = 0; j < l3; i++, j++)
    {
        str[i] = rep[j];
    }
    int k = x + l2;
    i = x + l3;
    while (temp[i] != '\0')
    {
        str[i] = temp[k];
        k++;
        i++;
    }
    str[i] = '\0';
    copy(temp, str);
}

void compare(FILE *fp1, FILE *fp2, char fin[], char rep[])
{
    char temp[1000];
    int status = 1, p = 1, j;
    while (!feof(fp1))
    {
        fgets(temp, 1000, fp1);
        int l1 = length(temp);
        int l2 = length(fin);
        int l3 = length(rep);
        for (int i = 0; i < l1 - l2; i++)
        {
            for (j = 0; j < l2; j++)
            {
                if (temp[i + j] != fin[j])
                {
                    status = 0;
                    break;
                }
            }
            if (j == l2 && status == 1)
            {
                replace(i, l3, l2, temp, rep);
            }
            status = 1;
        }
        fputs(temp, fp2);
    }
}

int main()
{
    FILE *fp1, *fp2;
    fp1 = fopen("Text.txt", "r+");
    fp2 = fopen("Write.txt", "w+");
    char fin[100], rep[100];
    printf("Enter what word u want to find:\n");
    gets(fin);
    printf("Enter replace word:\n");
    gets(rep);
    compare(fp1, fp2, fin, rep);
}