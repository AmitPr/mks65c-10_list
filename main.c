#include "animal.h"
#include "animal.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(NULL));
    char animal_name[12] = "Hippopotamus";
    struct Animal *hippo=new_animal(animal_name, rand() % 100, 5);
    struct Animal *walrus=new_animal("Walrus", rand() % 100, 0);
    hippo->next=walrus;
    struct Animal *seal=new_animal("Seal", rand() % 100, 0);
    walrus->next=seal;
    struct Animal *yoda=new_animal("Yoda", 900, 2);
    seal->next=yoda;
    print_animal(hippo);
    mutate(hippo);
    print_animal(hippo);

    printf("\n\n");
    print_list(hippo);
    struct Animal *giraffe = insert_front(hippo,"Giraffe",rand() % 100,4);
    printf("\n\n");
    print_list(giraffe);

    printf("\n\nRemove \"Walrus\"\n");
    giraffe=remove_node(giraffe,"Walrus");
    print_list(giraffe);
    printf("\n\nRemove \"Giraffe\"\n");
    giraffe=remove_node(giraffe,"Giraffe");
    print_list(giraffe);

    printf("\n\nFreeing list...");
    free_list(giraffe);
    printf("...done.\n");
    return 0;
}