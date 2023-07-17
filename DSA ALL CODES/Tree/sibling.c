// C program to demonstrate insert
// operation in binary
// search tree.

#include <stdio.h>
#include <stdlib.h>
#define COUNT 10
struct tree
{
    int key;
    int level;
    struct tree *left, *right;
};

// A utility function to create a new BST node
struct tree *newNode(int item, int i)
{
    struct tree *temp = (struct tree *)malloc(sizeof(struct tree));
    temp->key = item;
    temp->left = temp->right = NULL;
    temp->level = i - 1;
    return temp;
}

int preorder(struct tree *root, int a[])
{
    if (root != NULL)
    {
        a[root->level] = a[root->level] + 1;
        printf("%d ", root->key);
        preorder(root->left, a);
        preorder(root->right, a);
    }
}

// A utility function to insert
// a new node with given key in BST
struct tree *insert(struct tree *node, int key, int i)
{
    i++;
    // If the tree is empty, return a new node
    if (node == NULL)
        return newNode(key, i);
    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key, i);
    else if (key > node->key)
        node->right = insert(node->right, key, i);

    // Return the (unchanged) node pointer
    return node;
}

void random(FILE *fp, int n)
{
    int r;
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        r = rand() % 1000;
        fprintf(fp, "%d ", r);
    }
    rewind(fp);
}

void print2DUtil(struct tree *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(struct tree *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

// Driver Code
int main()
{
    int a[100] = {0};
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct tree *root = NULL;
    int n;
    FILE *fp = fopen("random.txt", "w+");
    printf("Enter how many random numbers:\n");
    scanf("%d", &n);
    random(fp, n);
    for (int i = 0; i < n; i++)
    {
        int key;
        fscanf(fp, "%d", &key);
        root = insert(root, key, 0);
    }
    fclose(fp);

    printf("\npreorder\n");
    preorder(root, a);
    printf("\n");
    for (int i = 0; i < 100; i++)
    {
        if (a[i] != 0)
        {
            printf("Siblings in level %d is %d\n", i, a[i]);
        }
    }
    print2D(root);
    return 0;
}