#ifndef ANIMAL
#define ANIMAL
struct Animal {
    char name[80];
    int age;
    int number_of_legs;
    struct Animal *next;
};
void print_animal(struct Animal*);
struct Animal* new_animal(char n[], int a, int legs);
void mutate(struct Animal*);
void free_animal(struct Animal*);
void free_list(struct Animal*);
void print_list(struct Animal*);
struct Animal *insert_front(struct Animal* root, char n[],int a, int legs);
struct Animal * remove_node(struct Animal* root, char name[]);
#endif