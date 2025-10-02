#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct personne {
    char nom[50];
    char prenom[50];
    char telephone[50];
    char email[50];
    struct personne *suivant;
};

typedef struct personne personne;

