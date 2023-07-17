#include <stdio.h>
#include <stdlib.h>
#define SI 100
struct queue
{
    int data[SI], front, rear;
};
void enqueue(struct queue *qptr, int num)
{
    if (qptr->rear == SI - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        qptr->rear++;
        qptr->data[qptr->rear] = num;
    }
}

int dequeue(struct queue *qptr)
{
    int num = -999;
    if (qptr->front == qptr->rear)
    {
        return num;
    }
    else
    {
        qptr->front++;
        num = qptr->data[qptr->front];
        return num;
    }
}
void display(struct queue *qptr)
{
    if (qptr->front == qptr->rear)
    {
        printf("Queue Empty\n");
    }
    else
    {
        for (int i = qptr->front + 1; i <= qptr->rear; i++)
        {
            printf("%d->", qptr->data[i]);
        }
        printf("\n");
    }
}
int main()

{
    struct queue *qptr;
    struct queue q;
    qptr = &q;
    qptr->front = qptr->rear = -1;
    int num, ch;
    while (1)
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.getfront\n5.Exit\n");
        printf("Enter choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data\n");
            scanf("%d", &num);
            p_enqueue(qptr, num);
            break;
        case 2:
            num = dequeue(qptr);
            if (num == -999)
            {
                printf("Stack Underflow\n");
            }
            else
            {
                printf("Deleted %d\n", num);
            }
            break;
        case 3:
            display(qptr);
            break;
        case 4:
            num = getfront(qptr);
            if (num == -999)
            {
                printf("Stack Empty\n");
            }
            else
            {
                printf("%d\n", num);
            }
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Enter valid choice\n");
            break;
        }
    }
    return 0;
}
