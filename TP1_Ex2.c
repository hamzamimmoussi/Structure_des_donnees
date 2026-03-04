#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nom[50];
    float prix;
    int nombre;
} Mobile;

typedef struct TypeCellule {
    Mobile data;
    struct TypeCellule* suivant;
} TypeCellule;
typedef TypeCellule* Liste;
Liste initialiserListe() {
    return NULL;
}Liste insererEnTete(Liste L, char nom[], float prix, int nombre) {
    Liste nouveau = (Liste)malloc(sizeof(TypeCellule));

    strcpy(nouveau->data.nom, nom);
    nouveau->data.prix = prix;
    nouveau->data.nombre = nombre;
    nouveau->suivant = L;
    return nouveau;
}
Liste construireListe() {
    Liste L = NULL;

    L = insererEnTete(L, "Iphone", 5000, 20);
    L = insererEnTete(L, "Samsung", 1500, 75);
    L = insererEnTete(L, "Nokia", 2000, 10);

    return L;
}
void afficherListe(Liste L) {
    while (L != NULL) {
        printf("Nom: %s\n", L->data.nom);
        printf("Prix: %.2f\n", L->data.prix);
        printf("Quantité vendue: %d\n", L->data.nombre);
        printf("------------------------\n");
        L = L->suivant;
    }
}
int totalMobilesVendus(Liste L) {
    int total = 0;
    while (L != NULL) {
        total += L->data.nombre;
        L = L->suivant;
    }
    return total;
}
Liste concatener(Liste L1, Liste L2) {
    if (L1 == NULL)
        return L2;

    Liste temp = L1;
    while (temp->suivant != NULL) {
        temp = temp->suivant;
    }

    temp->suivant = L2;
    return L1;
}
int main() {

    Liste L1 = construireListe();

    printf("Liste 1:\n");
    afficherListe(L1);

    printf("Total mobiles vendus: %d\n", totalMobilesVendus(L1));

    Liste L2 = NULL;
    L2 = insererEnTete(L2, "Huawei", 3000, 15);
    L2 = insererEnTete(L2, "Xiaomi", 2500, 30);

    printf("\nListe 2:\n");
    afficherListe(L2);

    L1 = concatener(L1, L2);

    printf("\nAprès concaténation:\n");
    afficherListe(L1);

    return 0;
}
