#include <stdio.h>
#include <stdlib.h>

typedef int Tobj;

typedef struct Telmt {
    Tobj obj;
    struct Telmt *suiv;
} Telmt;

typedef struct Tfile{
    Telmt *first;
    Telmt *last;
} Tfile;

void init(Tfile * file){
    file->first = NULL ;
    file->last = NULL ;
}

int filevide(Tfile * file) {
    return (file->first == NULL) ;
}

void ajouter(Tfile * file, Tobj A) {
    Telmt * new =(Telmt*) malloc(sizeof(Telmt));
    if (new == NULL) {
        printf("error\n");
        return ;
    }
    new->obj = A;
    new->suiv = NULL;
    if (filevide(file)) {
        file->first = new;
        file->last = new;
    }else {
        file->last->suiv = new;
        file->last = new;
    }
}

void retirer(Tfile * file, Tobj *A) {

    Telmt *p;
    if (filevide(file)) {
        printf("File est vide");
        return;
    }
    p = file->first;
    *A = p->obj;
    file->first = p->suiv;
    if (file->first == NULL)
        file->last = NULL;
    free(p);

}

void afficher(Tfile * file) {
    Telmt *c = file->first;
    printf("Le file est : \n");
    if (filevide(file)) {
        printf("Vide \n");
        return;
    }
    printf("\n");
    while (c != NULL) {
        printf("| %d |: ", c->obj);
        c = c->suiv;
    }
}

int main(){
 Tfile * file = (Tfile *) malloc(sizeof(Tfile));
    Tobj x;
    int n;
    init(file);
    printf("le nombre initiale : \n");
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        printf("entrer la valeur : \n");
        scanf("%d",&x);
        ajouter(file,x);
    }
    afficher(file);
    retirer(file, &x);
    printf("la valeur retirer est : %d \n",&x);
    return 0;
}

