#include <stdio.h>
#include <time.h>
struct node
{
    int data;
    struct node *link;
};
struct node *cur1, *prev;
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

void selection(struct node *head, int n)
{
    cur1 = head;
    struct node *cur2;
    struct node *minptr = NULL;
    int min = __INT_MAX__;
    while (cur1 != NULL)
    {
        cur2 = cur1;
        while (cur2 != NULL)
        {
            if (cur2->data < min)
            {
                min = cur2->data;
                minptr = cur2;
            }
            cur2 = cur2->link;
        }
        int temp = minptr->data;
        minptr->data = cur1->data;
        cur1->data = temp;
        cur1 = cur1->link;
        min = __INT_MAX__;
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
    FILE *fp = fopen("List.txt", "r+");
    printf("Enter how many numbers:\n");
    scanf("%d", &n);
    printf("Enter range l,H\n");
    scanf("%d %d", &l, &h);
    random(fp, n, l, h);
    head = list_make(fp, n, head);
    display(head);
    selection(head, n);
    printf("\n");
    display(head);
}
