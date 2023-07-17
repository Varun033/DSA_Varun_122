#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 100

struct stack
{
    int data[size];
    int top;
};

void stack_maintain(FILE *fp, struct stack *sptr)
{
    for (int i = sptr->top; i >= 0; i--)
    {
        fprintf(fp, "%d ", sptr->data[i]);
    }
}
void push(struct stack *sptr, FILE *fp1, FILE *fp)
{
    if (sptr->top == size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        int x;
        fscanf(fp1, "%d", &x);
        sptr->top++;
        sptr->data[sptr->top] = x;
        fprintf(fp, "%d ", x);
    }
}
void pop(struct stack *sptr, FILE *fp)
{
    int num;
    if (sptr->top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        num = sptr->data[sptr->top];
        sptr->top--;
        fprintf(fp, "%d\n", num);
    }
}
void display(struct stack *sptr)
{
    int i;
    if (sptr->top == -1)
    {
        printf("Stack empty\n");
    }
    else
    {

        for (i = sptr->top; i >= 0; i--)
        {
            printf("%d\n", sptr->data[i]);
        }
    }
}
void random(FILE *fp, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d ", rand() % 100);
    }
}

int main()
{
    FILE *fp1 = fopen("inputstack.txt", "w+");
    int n, c;
    struct stack *sptr;
    struct stack s;
    sptr = &s;
    sptr->top = -1;
    printf("Enter how many numbers:\n");
    scanf("%d", &n);
    random(fp1, n);
    rewind(fp1);
    while (1)
    {
        FILE *fptr1 = fopen("push_log.txt", "a");
        FILE *fptr2 = fopen("pop_log.txt", "a");
        FILE *fptr3 = fopen("stackk.txt", "w");
        stack_maintain(fptr3, sptr);
        fclose(fptr3);
        printf("Enter choice\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            push(sptr, fp1, fptr1);
            break;
        case 2:
            pop(sptr, fptr2);
            break;
        case 3:
            display(sptr);
            break;
        case 4:
            exit(0);
        default:
            printf("Enter correct choice\n");
            break;
        }
        fclose(fptr1);
        fclose(fptr2);
    }
}