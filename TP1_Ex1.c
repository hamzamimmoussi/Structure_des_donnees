#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//q1

typedef struct Cellule {
    char nom[50];
    float superficie;
    int habitants;
    struct Cellule* suivant;
} Cellule;

typedef Cellule* Liste;

/*typedef struct {
    char nom[50];
    float superficie;
    int habitants;
} Ville;

typedef struct Cellule {
    Ville data;
    struct Cellule* suivant;
} Cellule;

typedef Cellule* Liste;*/
//q2
int compterVilles(Liste L) {
    int count = 0;
    while (L != NULL) {
        count++;
        L = L->suivant;
    }
    return count;
}
//q3
Liste ajouterTete(Liste L, char nom[], float sup, int hab) {
    Liste nouv = (Liste)malloc(sizeof(Cellule));

    strcpy(nouv->nom, nom);
    nouv->superficie = sup;
    nouv->habitants = hab;

    nouv->suivant = L;
    return nouv;
}
//q4
Liste construireListe() {
    Liste L = NULL;

    L = ajouterTete(L, "Rabat", 118.5, 580000);
    L = ajouterTete(L, "Casablanca", 220.0, 3400000);
    L = ajouterTete(L, "Marrakech", 230.0, 950000);

    return L;
}
//q5
void afficherVille(Cellule v) {
    printf("Nom: %s | Superficie: %.2f | Habitants: %d\n",v.nom, v.superficie, v.habitants);
}
//q6
void afficherPlus10000(Liste L) {
    while (L != NULL) {
        if (L->habitants > 10000) {
            afficherVille(*L);
        }
        L = L->suivant;
    }
}
//q7
int main() {
    Liste L = construireListe();

    printf("Nombre de villes: %d\n", compterVilles(L));

    printf("\nVilles avec plus de 10000 habitants:\n");
    afficherPlus10000(L);

    return 0;
}
