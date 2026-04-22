#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *p_next;
    struct node *p_prev;
} typeCellule;

typedef struct {
    int taille;
    typeCellule *p_deb;
    typeCellule *p_fin;
} Dlist;

void initListe(Dlist *l) {
    l->taille = 0;
    l->p_deb = NULL;
    l->p_fin = NULL;
}

void insererListeVide(Dlist *l, int val) {
    typeCellule *n = (typeCellule*)malloc(sizeof(typeCellule));
    if(n == NULL) return;

    n->data = val;
    n->p_next = NULL;
    n->p_prev = NULL;

    l->p_deb = n;
    l->p_fin = n;
    l->taille = 1;
}


void insererDebut(Dlist *l, int val) {
    if(l->p_deb == NULL) {
        insererListeVide(l, val);
        return;
    }

    typeCellule *n = (typeCellule*)malloc(sizeof(typeCellule));
    if(n == NULL) return;

    n->data = val;
    n->p_prev = NULL;
    n->p_next = l->p_deb;

    l->p_deb->p_prev = n;
    l->p_deb = n;

    l->taille++;
}

void insererFin(Dlist *l, int val) {
    if(l->p_fin == NULL) {
        insererListeVide(l, val);
        return;
    }

    typeCellule *n = (typeCellule*)malloc(sizeof(typeCellule));
    if(n == NULL) return;

    n->data = val;
    n->p_next = NULL;
    n->p_prev = l->p_fin;

    l->p_fin->p_next = n;
    l->p_fin = n;

    l->taille++;
}

void afficherListe(Dlist l) {
    typeCellule *tmp = l.p_deb;
    if (l.taille== 0) {
        printf("liste est vide\n");
        return;
    }
    printf("Du debut a la fin");
    while(tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->p_next;
    }
    printf("\n");
}

typeCellule * rechercher(Dlist * l, int val) {
    typeCellule *tmp = l->p_deb;

    while(tmp != NULL) {
        if(tmp->data == val){
            return tmp;
    }
        tmp = tmp->p_next;
    }
    return 0;
}

int sommeListe(Dlist l) {
    int s = 0;
    typeCellule *tmp = l.p_deb;

    while(tmp != NULL) {
        s += tmp->data;
        tmp = tmp->p_next;
    }
    return s;
}


void ins_avant(Dlist * l ,int val, int nval) {
    typeCellule * tmp=l->p_deb;
    while (tmp!=NULL && tmp->data!=val){
        tmp=tmp->p_next;
    }

    if (tmp==l->p_deb) {
        insererDebut(l,nval);
        return;
    }
    if (tmp==NULL) {
        insererFin(l,val);
        printf("there is no : %d",val);
        return;
    }
    typeCellule * n = (typeCellule*)malloc(sizeof(typeCellule));
    n->data=nval;
    n->p_prev=tmp->p_prev;
    n->p_next=tmp;
    tmp->p_prev->p_next=n;
    tmp->p_prev=n;
    l->taille++;
}
void insererMilieu(Dlist *l, int val, int apres) {
    typeCellule *tmp = l->p_deb;

    while(tmp != NULL && tmp->data != apres) {
        tmp = tmp->p_next;
    }

    if(tmp == NULL) {
        insererFin(l, val);
        return;
    }

    if(tmp == l->p_fin) {
        insererFin(l, val);
        return;
    }

    typeCellule *n = (typeCellule*)malloc(sizeof(typeCellule));
    if(n == NULL) return;

    n->data = val;
    n->p_next = tmp->p_next;
    n->p_prev = tmp;

    tmp->p_next->p_prev = n;
    tmp->p_next = n;

    l->taille++;
}

void libererListe(Dlist *l) {
    typeCellule *tmp;

    while(l->p_deb != NULL) {
        tmp = l->p_deb;
        l->p_deb = l->p_deb->p_next;
        free(tmp);
    }

    l->p_fin = NULL;
    l->taille = 0;
}


int main() {
    Dlist l;

    initListe(&l);

    insererDebut(&l, 10);
    insererDebut(&l, 5);
    insererFin(&l, 20);
    insererMilieu(&l, 10, 20);
    afficherListe(l);

    printf("Somme = %d\n", sommeListe(l));

    if(rechercher(&l, 10))
        printf("Element trouve\n");
    else
        printf("Element non trouve\n");

    libererListe(&l);

    return 0;
}