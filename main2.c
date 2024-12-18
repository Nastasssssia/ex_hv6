#include <stdio.h>
#include <stdlib.h>

/*
Напишите программу, которая возвращает сумму всех элементов в дереве.
*/

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int sumTree(Node *root)
{
    if (root == NULL)
        return 0;
    return root->data + sumTree(root->left) + sumTree(root->right);
}

void freeTree(Node *root)
{
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main()
{

    Node *root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->left->left->left = createNode(1);
    root->left->right->right = createNode(6);
    root->right->left = createNode(13);
    root->right->right = createNode(18);

    int totalSum = sumTree(root);
    printf("Сумма всех элементов в дереве: %d\n", totalSum);

    freeTree(root);

    return 0;
}
