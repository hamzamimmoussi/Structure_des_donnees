#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void triselection(char **T, int taille){
    int min;
    char *temp;

    for(int i = 0; i < taille - 1; i++){
        min = i;
        for(int j = i+1; j < taille; j++){
            if(strcmp(T[j], T[min]) < 0){
                min = j;
            }
        }
        if(min != i){
            temp = T[i];
            T[i] = T[min];
            T[min] = temp;
        }
    }
}

int main(){
    int n;
    char b[100];
    char **T;

    printf("Combien de chaînes voulez-vous trier ? \n");
    scanf("%d", &n);

    T = (char**) malloc(n * sizeof(char *));
    if(T == NULL){
        printf("erreur d'allocation");
        return 1;
    }

    for (int i = 0; i < n; i++){
        printf("chaine %d: \n", i + 1);
        scanf(" %[^\n]s", b);

        T[i] = (char*)malloc((strlen(b)+1)*sizeof(char));
        strcpy(T[i], b);
    }

    triselection(T, n);

    for(int i = 0; i < n; i++){
        printf("|%s|\n", T[i]);
    }

    for(int i = 0; i < n; i++){
        free(T[i]);
    }

    free(T);
    return 0;
}