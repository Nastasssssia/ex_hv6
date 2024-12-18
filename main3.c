#include <stdio.h>
#include <stdlib.h>

/*
Напишите программу, которая находит разницу между максимальным и минимальным элементом в дереве.
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

int findMin(Node *root)
{
    if (root == NULL)
    {
        printf("Ошибка: дерево пустое\n");
        return -1;
    }
    while (root->left != NULL)
    {
        root = root->left; // Минимум находится в самом левом узле
    }
    return root->data;
}

int findMax(Node *root)
{
    if (root == NULL)
    {
        printf("Ошибка: дерево пустое\n");
        return -1;
    }
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
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

    int min = findMin(root);
    int max = findMax(root);

    int difference = max - min;

    printf("Минимальный элемент: %d\n", min);
    printf("Максимальный элемент: %d\n", max);
    printf("Разница между максимальным и минимальным элементами: %d\n", difference);

    freeTree(root);

    return 0;
}
