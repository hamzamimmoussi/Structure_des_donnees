#include <stdio.h>
#include <stdlib.h>

typedef int Tobj;

typedef struct Telmt {
    Tobj obj;
    struct Telmt *suiv;
} Telmt;

typedef struct Tpile{
    Telmt *premier;
} Tpile;

void initialiserPile(Tpile *pile) {
    pile->premier = NULL;
}

void empiler(Tpile *pile, Tobj E) {
    Telmt *nouveau = (Telmt*)malloc(sizeof(Telmt));
    nouveau->obj = E;
    nouveau->suiv = pile->premier;
    pile->premier = nouveau;
}

int pilevide(Tpile pile) {
    return (pile.premier == NULL);
}

int depiler(Tpile *pile, Tobj *E) {
    if (pilevide(*pile))
        return 0;

    Telmt *temp = pile->premier;
    *E = temp->obj;
    pile->premier = temp->suiv;
    free(temp);

    return 1;
}

int main(){

    return 0;
}

