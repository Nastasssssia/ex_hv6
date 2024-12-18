#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Напишите программу, которая удаляет из списка все элементы с нечетным порядковым номером.
 */

typedef struct Node
{
    char data[100];
    struct Node *next;
} Node;

void append(Node **head, const char *data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->data, data);
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Функция для удаления элементов с нечетными индексами
void remove_odd_positions(Node **head)
{
    if (*head == NULL)
        return;

    Node *current = *head;
    Node *prev = NULL;
    int index = 0;

    while (current != NULL)
    {
        if (index % 2 != 0)
        { // Удаляем узел, если индекс нечетный
            if (prev != NULL)
            {
                prev->next = current->next;
            }
            else
            {
                *head = current->next; // Если нужно удалить первый элемент
            }
            Node *temp = current;
            current = current->next;
            free(temp);
        }
        else
        {
            prev = current;
            current = current->next;
        }
        index++;
    }
}

void print_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;

    // Добавляем элементы в первый список
    append(&head1, "aa");
    append(&head1, "ss");
    append(&head1, "dd");
    append(&head1, "ff");
    append(&head1, "gg");
    append(&head1, "hh");
    append(&head1, "jj");
    append(&head1, "kk");
    append(&head1, "ll");

    // Добавляем элементы во второй список
    append(&head2, "aa");
    append(&head2, "ss");
    append(&head2, "dd");
    append(&head2, "ff");
    append(&head2, "gg");
    append(&head2, "hh");
    append(&head2, "jj");
    append(&head2, "kk");
    append(&head2, "ll");
    append(&head2, "tt");

    printf("Before removal (list 1): ");
    print_list(head1);
    printf("Before removal (list 2): ");
    print_list(head2);

    // Удаляем элементы с нечетными индексами
    remove_odd_positions(&head1);
    remove_odd_positions(&head2);

    printf("After removal (list 1): ");
    print_list(head1);
    printf("After removal (list 2): ");
    print_list(head2);

    return 0;
}
