#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int id;
    char nom[50];
    float note;
} Student;

typedef struct Node {
    Student data;
    struct Node* suiv;
    struct Node* prec;
} Node;

typedef struct {
    Node *debut;
    Node *fin;
} List;

void init(List* l) {
    l->debut = NULL;
    l->fin = NULL;
}

Node* creatNode(int id, char nom[], float note) {
    Node* nv = (Node*)malloc(sizeof(Node));
    nv->data.id = id;
    nv->data.note = note;
    strcpy(nv->data.nom, nom);
    nv->suiv = NULL;
    nv->prec = NULL;
    return nv;
}

void inserFin(List* l, int id, char nom[], float note) {
    Node* nv = creatNode(id, nom, note);
    if (l->debut == NULL) {
        l->debut = nv;
        l->fin = nv;
    } else {
        nv->prec = l->fin;
        l->fin->suiv = nv;
        l->fin = nv;
    }
}

void afficher(List* l) {
    Node* tmp = l->debut;
    while (tmp != NULL) {
        printf("Student: %d \t %s \t %.2f\n",
               tmp->data.id, tmp->data.nom, tmp->data.note);
        tmp = tmp->suiv;
    }
}

void concatenate(List* l1, List* l2) {
    if (l2->debut == NULL) return;

    if (l1->debut == NULL) {
        l1->debut = l2->debut;
        l1->fin = l2->fin;
    } else {
        l1->fin->suiv = l2->debut;
        l2->debut->prec = l1->fin;
        l1->fin = l2->fin;
    }
}

int main() {
    List l1, l2;
    int id, choix;
    float note;
    char nom[50];

    init(&l1);
    init(&l2);


    do {
        printf("Insertion liste 1\n");
        printf("ID: ");
        scanf("%d", &id);
        printf("Nom: ");
        scanf("%s", nom);
        printf("Note: ");
        scanf("%f", &note);

        inserFin(&l1, id, nom, note);

        printf("Ajouter encore ? (1=Oui, 0=Non): ");
        scanf("%d", &choix);

    } while (choix == 1);

    
    do {
        printf("Insertion liste 2\n");
        printf("ID: ");
        scanf("%d", &id);
        printf("Nom: ");
        scanf("%s", nom);
        printf("Note: ");
        scanf("%f", &note);

        inserFin(&l2, id, nom, note);

        printf("Ajouter encore ? (1=Oui, 0=Non): ");
        scanf("%d", &choix);

    } while (choix == 1);

    printf("\nListe 1:\n");
    afficher(&l1);

    printf("\nListe 2:\n");
    afficher(&l2);

    concatenate(&l1, &l2);

    printf("\nListe concatenee:\n");
    afficher(&l1);

    return 0;
}