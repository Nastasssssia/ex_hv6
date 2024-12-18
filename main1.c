#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Используя код задачи 1, написать программу поиска первого и последнего слова в строке.*/

#define STR_SIZE 2000

typedef struct list
{
    char *word;
    struct list *next;
} list;

list *insert2(char *value, list *head);
void print_list(list *head);
void choose_sort_array_list(list *head);
void swap_elements(list *e1, list *e2);
void delete_list(list *head);
void find_first_and_last(list *head);

int main(int argc, char **argv)
{
    list *w_list = NULL;
    char word[STR_SIZE] = "";
    int ch = ' ';
    int i = 0;

    while (EOF != (ch = getchar()))
    {
        switch (ch)
        {
        case '.':
        case ' ':
            if (i > 0)
            { // Добавляем слово только если оно не пустое
                word[i] = '\0';
                w_list = insert2(word, w_list);
                i = 0;
            }
            break;
        default:
            word[i++] = ch;
            if (i >= STR_SIZE)
                i = 0; // Защита от переполнения строки
        }
        if ('.' == ch)
            break;
    }

    find_first_and_last(w_list);

    delete_list(w_list);
    return 0;
}

void delete_list(list *l)
{
    list *c = l;
    list *n;
    while (c != NULL)
    {
        n = c->next;
        free(c->word);
        free(c);
        c = n;
    }
}

void find_first_and_last(list *head)
{
    if (!head)
    {
        printf("Список пуст\n");
        return;
    }

    list *first = head;
    list *last = head;

    while (last->next != NULL)
    {
        last = last->next;
    }

    printf("Первое слово: %s\n", first->word);
    printf("Последнее слово: %s\n", last->word);
}

void choose_sort_array_list(list *head)
{
    for (list *i = head; i->next != NULL; i = i->next)
    {
        list *min = i;
        for (list *j = i->next; j != NULL; j = j->next)
            if (strcmp(j->word, min->word) < 0)
                min = j;
        if (min != i)
            swap_elements(i, min);
    }
}

list *insert2(char *value, list *head)
{
    list *res = (list *)calloc(1, sizeof(list));
    int len = strlen(value);
    res->word = malloc(len + 1);
    strcpy(res->word, value);
    res->next = head;
    return res;
}

void swap_elements(list *e1, list *e2)
{
    char *tmp = e1->word;
    e1->word = e2->word;
    e2->word = tmp;
}

void print_list(list *head)
{
    for (list *i = head; i != NULL; i = i->next)
        printf("%s ", i->word);
    putchar('\n');
}
