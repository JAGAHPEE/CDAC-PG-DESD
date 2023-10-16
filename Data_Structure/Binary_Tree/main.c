#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
struct node *root = NULL;
struct node *insert(struct node *, int);
struct node *delete_node(struct node *, int);
void travserse(struct node *);
int search(struct node *, int);
int height(struct node *);
int tree_min(struct node *);
int tree_max(struct node *);
int main()
{
    root = insert(root, 10);
    root = insert(root, 12);
    root = insert(root, 13);
    root = insert(root, 9);
    root = insert(root, 8);
    root = insert(root, 7);
    root = insert(root, 5);
    root = insert(root, 15);
    travserse(root);
    printf("\n");
    root = delete_node(root, 10);
    travserse(root);
    if (search(root, 10) > 0)
    {
        printf("\nElement Found");
    }
    else
    {
        printf("\nElement not Found");
    }
    int heightt = height(root);
    if (height > 0)
    {
        printf("\nHeight: %d", heightt);
    }
}
struct node *insert(struct node *root, int num)
{
    if (root == NULL)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->left = NULL;
        temp->right = NULL;
        temp->data = num;
        root = temp;
    }
    else if (root->data > num)
    {
        root->left = insert(root->left, num);
    }
    else if (num > root->data)
    {
        root->right = insert(root->right, num);
    }
    return root;
}
void travserse(struct node *root)
{
    struct node *temp;
    temp = root;
    if (temp != NULL)
    {
        if (temp == NULL)
        {
            return;
        }
        travserse(temp->left);
        printf("%d ", temp->data);
        travserse(temp->right);
    }
    // return root;
}
int search(struct node *root, int num)
{
    int x;
    if (root == NULL)
    {
        x=0;
    }
    else if (root->data == num)
    {
        x=1;
    }
    else if (root->data > num)
    {
        search(root->left, num);
    }
    else
    {
        search(root->right, num);
    }
    return x;
}
int height(struct node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);
    if (lheight > rheight)
    {
        return (lheight + 1);
    }
    else
    {
        return (rheight + 1);
    }
}
int tree_min(struct node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}
int tree_max(struct node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}
struct node *delete_node(struct node *root, int num)
{
    //struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    if (root->data > num)
    {
        root->left = delete_node(root->left, num);
    }
    else if (num > root->data)
    {
        root->right = delete_node(root->right, num);
    }
    else if (root == NULL)
    {
        return NULL;
    }
    else if (root->data == num)
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
            return root;
        }
        else if (root->left != NULL && root->right == NULL)
        {

            temp = root->left;
            free(root);
            root = NULL;
            return temp;
        }
        else if (root->right != NULL && root->left == NULL)
        {

            temp = root->right;
            free(root);
            root = NULL;
            return temp;
        }
        else if (root->left != NULL && root->right != NULL)
        {
            root->data = tree_max(root->left);
            root->left = delete_node(root->left, root->data);
            return root;
        }
    }
}
