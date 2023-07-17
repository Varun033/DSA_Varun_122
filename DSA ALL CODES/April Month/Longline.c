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

void read()
{
    FILE *fp;
    int n1, n2;
    fp = fopen("text.txt", "r");
    char str1[100], str2[100] = {0};
    while (!feof(fp))
    {
        fgets(str1, 100, fp);
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
    fclose(fp);
}

int main()
{
    char str[100];
    read();
}
