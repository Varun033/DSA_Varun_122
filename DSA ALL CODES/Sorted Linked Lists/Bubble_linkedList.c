#include <stdio.h>
#include <time.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *cur, *prev;
struct node *newnode;

struct node *create_node(int n)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("NO memory allocated");
    }
    newnode->data = n;
    newnode->link = NULL;
    return newnode;
}
struct node *insert_end(struct node *head, int n)
{
    struct node *cur;
    newnode = create_node(n);
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        cur = head;
        while (cur->link != NULL)
        {
            cur = cur->link;
        }
        cur->link = newnode;
    }
    return head;
}

void display(struct node *head)
{
    struct node *cur;
    if (head == NULL)
    {
        printf("List empty\n");
    }
    else
    {
        cur = head;
        while (cur != NULL)
        {
            printf("%d->", cur->data);
            cur = cur->link;
        }
    }
}

void bubble(struct node *head, int n)
{
    cur = head;
    prev = NULL;
    for (int i = 0; i < n; i++)
    {
        while (cur->link != NULL)
        {
            prev = cur;
            cur = cur->link;
            if (cur->data < prev->data)
            {
                int temp = prev->data;
                prev->data = cur->data;
                cur->data = temp;
            }
        }
        cur = head;
        prev = NULL;
    }
}

struct node *list_make(FILE *fp, int n, struct node *head)
{
    int x;
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &x);
        head = insert_end(head, x);
    }
    return head;
}

void random(FILE *fp, int n, int l, int h)
{
    int r;
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        r = rand() % (h - l) + l;
        fprintf(fp, "%d ", r);
    }
    rewind(fp);
}

int main()
{
    struct node *head = NULL;
    int n, l, h;
    FILE *fp;
    fp = fopen("List.txt", "w+");
    printf("Enter how many numbers:\n");
    scanf("%d", &n);
    printf("Enter range l,H\n");
    scanf("%d %d", &l, &h);
    random(fp, n, l, h);
    head = list_make(fp, n, head);
    display(head);
    bubble(head, n);
    printf("\n");
    display(head);
}
