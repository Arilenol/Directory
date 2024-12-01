//
// Created by Aymeric_ONFRAY on 27/11/2024.
//
#include "../head/head.h"
void consulter(char* pann){
    int choix;
    printf("Quel fichier voulez vous consulter\n");
    printf("\nEntrez le chiffre correspondant au fichier que vous souhaitez ouvrir : ");
    scanf("%d",&choix);
    while (choix<1 || choix >NB_FICH){
        printf("Sasie hors plage\nRéessayez : ");
        scanf("%d",&choix);
    }
    FILE* fic = NULL;
    switch(choix){
        case(1):
            fic = fopen(DIX,"r+");
            if (fic == NULL){
                printf("Echec ouverture fichier\n");
                perror("fopen");
                exit(EXIT_FAILURE);
            }
            else{
                fclose(fic);
                printf("Le fichier à bien été fermé");
            }
            break;
        case(2):
            fic = fopen(CINQUANTE,"r+");
            if (fic == NULL){
                printf("Echec ouverture fichier\n");
                perror("fopen");
                exit(EXIT_FAILURE);
            }
            else{
                fclose(fic);
                printf("Le fichier  à bien été fermé");
            }
            break;
        case(3):
            printf("");
            fic = fopen(CENT,"r+");
            if (fic == NULL){
                printf("Echec ouverture fichier\n");
                perror("fopen");
                exit(EXIT_FAILURE);
            }
            else{
                fclose(fic);
                printf("Le fichier à bien été fermé");
            }
            break;
        case(4):
            fic = fopen(CINQ_CENTS,"r+");
            if (fic == NULL){
                printf("Echec ouverture fichier\n");
                perror("fopen");
                exit(EXIT_FAILURE);
            }
            else{
                fclose(fic);
                printf("Le fichier à bien été fermé",);
            }
            break;
        case(5):
            fic = fopen(MILLE,"r+");
            if (fic == NULL){
                printf("Echec ouverture fichier\n");
                perror("fopen");
                exit(EXIT_FAILURE);
            }
            else{
                fclose(fic);
                printf("Le fichier à bien été fermé");
            }
            break;
        case(6):
            printf("");
            fic = fopen(CINQ_MILLES,"r+");
            if (fic == NULL){
                printf("Echec ouverture fichier\n");
                perror("fopen");
                exit(EXIT_FAILURE);
            }
            else{
                fclose(fic);
                printf("Le fichier à bien été fermé");
            }
            break;
    }
}