#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct contact
{
    char nom[50];
    char prenom[50];
    char telephone[15];
    char email[50];
    struct contact *suivant;
};

typedef struct contact contact;

// Fomction pour créer un nouveau contact
contact *creercontact()
{
    contact *nouveau;                             // déclaration du pointeur
    nouveau = (contact *)malloc(sizeof(contact)); // allocation mémoire
    if (!nouveau)
    {
        printf("Erreur d'allocation de memoire\n");
        return NULL;
    }
    printf("Entrez le nom: ");
    scanf("%49[^\n]", nouveau->nom);
    printf("Entrez le prenom: ");
    scanf("%49[^\n]", nouveau->prenom);
    printf("Entrez le numero de telephone: ");
    scanf("%15[^\n]", nouveau->telephone);
    printf("Entrez l'email: ");
    scanf("%49[^\n]", nouveau->email);
    nouveau->suivant = NULL;
    return nouveau;
}

// Fonction pour ajouter un contact à la liste (à la fin)
void ajoutContact(contact *tete)
{
    contact *nouveau = creercontact();
    if (!nouveau)
        return;
    if (*tete == NULL)
    {
        *tete = nouveau;
    }
    else
    {
        contact *temp = *tete;
        while (temp->suivant != NULL)
        {
            temp = temp->suivant;
        }
        temp->suivant = nouveau;
    }
    printf("Contact ajoute avec succes!\n");
}

// Fonction pour ajouter un contact à la liste (au début)
Contact *ajouterContact(Contact *tete)
{
    Contact *nouveau = creerContact();
    if (!nouveau)
        return tete;
    nouveau->suivant = tete;
    return nouveau;
}

// Fonction pour ajouter un contact à la liste (en ordre alphabétique)

Contact *ajouterContactTrie(Contact *tete, Contact *nouveau)
{
    if (!nouveau)
        return tete;

    // Cas : liste vide ou nouveau nom avant la tête
    if (!tete || strcmp(nouveau->nom, tete->nom) < 0)
    {
        nouveau->suivant = tete;
        return nouveau;
    }

    // Parcours pour trouver la position
    Contact *courant = tete;
    while (courant->suivant && strcmp(nouveau->nom, courant->suivant->nom) > 0)
    {
        courant = courant->suivant;
    }

    // Insertion
    nouveau->suivant = courant->suivant;
    courant->suivant = nouveau;

    return tete;
}
