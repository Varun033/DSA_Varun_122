#include <stdio.h>
#include <stdlib.h>

void linear_search(int key, FILE *fp)
{
    int x;
    while (!feof(fp))
    {
        fscanf(fp, "%d", &x);
        if (key == x)
        {
            printf("Success\n");
            exit(1);
        }
    }
    printf("NOT success\n");
}
int main()
{
    int key;
    FILE *fp = fopen("list.txt", "r");
    printf("Enter number u want to search:\n");
    scanf("%d", &key);
    linear_search(key, fp);
    fclose(fp);
}