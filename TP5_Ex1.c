#include<stdio.h>
#include<stdlib.h>

typedef struct arbre {
    int data;
    struct arbre *right, *left;
}arbre;

arbre* creeNode(int val){
    arbre* new_node =  (arbre*)malloc(sizeof(arbre));
    new_node->data = val;
    new_node->right = new_node->left = NULL;
    return new_node;

}


arbre* inserer(arbre* racine, int val){
    if(racine == NULL)
        return creeNode(val);

    if(val < racine->data)
        racine->left = inserer(racine->left, val);
    else if(val > racine->data)
        racine->right = inserer(racine->right, val);

    return racine;
}


arbre* rechercher(arbre* racine, int val) {
    if (racine == NULL || racine->data == val)
        return racine;

    if (val < racine->data)
        return rechercher(racine->left, val);
    else if (val > racine->data)
    return rechercher(racine->right, val);
    return racine;
}


void prefixe(arbre* racine){
    if(racine!=NULL){
        printf("%d ", racine->data);
        prefixe(racine->left);
        prefixe(racine->right);
    }
}


void infixe(arbre* racine){
    if(racine){
        infixe(racine->left);
        printf("%d ", racine->data);
        infixe(racine->right);
    }
}


void postfixe(arbre* racine){
    if(racine){
        postfixe(racine->left);
        postfixe(racine->right);
        printf("%d ", racine->data);
    }
}


arbre* minValueNode(arbre* racine){         //voir la methode de la fct recurssive (photo)!
    while(racine && racine->left != NULL)
        racine = racine->left;
    return racine;
}


arbre* maxValueNode(arbre* racine){
    while(racine && racine->right != NULL)
        racine = racine->right;
    return racine;
}


arbre* supprimer(arbre* racine, int val){
    if(racine == NULL) return racine;

    if(val < racine->data)
        racine->left = supprimer(racine->left, val);
    else if(val > racine->data)
        racine->right = supprimer(racine->right, val);
    else{

        if(racine->left == NULL && racine->right == NULL) {
            free(racine);
            racine = NULL;
        }

        else if(racine->left == NULL){
            arbre* temp = racine->right;
            free(racine);
            return temp;
        }
        else if(racine->right == NULL){
            arbre* temp = racine->left;
            free(racine);
            return temp;
        }


        arbre* temp = minValueNode(racine->right);
        racine->data = temp->data;
        racine->right = supprimer(racine->right, temp->data);
    }

    return racine;
}



int main(){
    arbre* racine = NULL;

    int tab[] = {7,4,9,2,5,8,11};
    int n = 7;

    for(int i=0; i<n; i++)
        racine = inserer(racine, tab[i]);

    printf("Prefixe  : ");
    prefixe(racine);
    infixe(racine);

    printf("\nInfixe : ");
    infixe(racine);

    printf("\nPostfixe : ");
    postfixe(racine);

    printf("\n\nRecherche 5 : ");
    if(rechercher(racine,5))
        printf("Trouve");
    else
        printf("Non trouve");

    racine = supprimer(racine, 4);

    printf("\nApres suppression de 4 (infixe) : ");
    infixe(racine);

    return 0;
}