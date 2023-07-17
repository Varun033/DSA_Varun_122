// C program to demonstrate insert
// operation in binary
// search tree.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int key;
    struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct node *root, FILE *fp)
{
    if (root != NULL)
    {
        inorder(root->left, fp);
        fprintf(fp, "%d ", root->key);
        printf("%d ", root->key);
        inorder(root->right, fp);
    }
}
void preorder(struct node *root, FILE *fp)
{
    if (root != NULL)
    {
        fprintf(fp, "%d ", root->key);
        printf("%d ", root->key);
        preorder(root->left, fp);
        preorder(root->right, fp);
    }
}
void postorder(struct node *root, FILE *fp)
{
    if (root != NULL)
    {
        postorder(root->right, fp);
        postorder(root->left, fp);
        printf("%d ", root->key);
        fprintf(fp, "%d ", root->key);
    }
}

// A utility function to insert
// a new node with given key in BST
struct node *insert(struct node *node, int key)
{
    // If the tree is empty, return a new node
    if (node == NULL)
        return newNode(key);

    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    // Return the (unchanged) node pointer
    return node;
}
void random(FILE *fp, int n)
{
    int r;
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        r = rand() % 10000;
        fprintf(fp, "%d ", r);
    }
    rewind(fp);
}

// Driver Code
int main()
{
    int n;
    struct node *root = NULL;
    clock_t start, stop;
    FILE *fp = fopen("random.txt", "w+");
    printf("Enter how many random numbers:\n");
    scanf("%d", &n);
    random(fp, n);
    for (int i = 0; i < n; i++)
    {
        int key;
        fscanf(fp, "%d", &key);
        if (root == NULL)
        {
            root = insert(root, key);
        }
        insert(root, key);
    }
    fclose(fp);
    FILE *log = fopen("log.txt", "w+");
    // Print inorder traversal of the BST
    printf("Inorder\n");
    FILE *fp1 = fopen("inorder.txt", "w");
    start = clock();
    inorder(root, fp1);
    stop = clock();
    float time_l = (float)(stop - start) / CLOCKS_PER_SEC;
    fprintf(log, "Time taken for inorder %fsec\n", time_l);
    fclose(fp1);

    printf("\npreorder\n");
    FILE *fp2 = fopen("preorder.txt", "w");
    start = clock();
    preorder(root, fp2);
    stop = clock();
    time_l = (float)(stop - start) / CLOCKS_PER_SEC;
    fprintf(log, "Time taken for preorder %fsec\n", time_l);
    fclose(fp1);

    printf("\npostorder\n");
    FILE *fp3 = fopen("postorder.txt", "w");
    start = clock();
    postorder(root, fp3);
    stop = clock();
    time_l = (float)(stop - start) / CLOCKS_PER_SEC;
    fprintf(log, "Time taken for postorder %fsec\n", time_l);
    fclose(fp1);

    return 0;
}