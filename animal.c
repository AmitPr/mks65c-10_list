#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "animal.h"
#include "string.h"
void print_animal(struct Animal *x)
{
    printf("Animal{ name: %s, age: %d, number of legs: %d }\n", x->name, x->age, x->number_of_legs);
}

void print_list(struct Animal *root)
{
    printf("Animal List:\n");
    struct Animal *cur = root;
    while (cur)
    {
        print_animal(cur);
        cur = cur->next;
    }
}

struct Animal *insert_front(struct Animal *root, char n[], int a, int legs)
{
    struct Animal *front = new_animal(n, a, legs);
    front->next = root;
    return front;
}

struct Animal *remove_node(struct Animal *root, char name[])
{
    struct Animal *cur = root;
    struct Animal *last = NULL;
    while (cur)
    {
        struct Animal *next = cur->next;
        if (strcmp(name, cur->name) == 0)
        {
            if (last)
                last->next = next;
            if (root == cur)
            {
                free_animal(root);
                return next;
            }
            else
            {
                free_animal(cur);
                return root;
            }
        }
        last = cur;
        cur = next;
    }
}

struct Animal *new_animal(char n[], int a, int legs)
{
    struct Animal *na = malloc(sizeof(struct Animal));
    strncpy(na->name, n, sizeof(na->name) - 1);
    na->age = a;
    na->number_of_legs = legs;
    na->next=NULL;
}
void mutate(struct Animal *x)
{
    x->number_of_legs++;
}
void free_animal(struct Animal *x)
{
    free(x);
}
void free_list(struct Animal *cur)
{
    while (cur)
    {
        struct Animal *tmp = cur->next;
        free_animal(cur);
        cur = tmp;
    }
}