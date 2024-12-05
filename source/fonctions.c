//
// Created by Aymeric_ONFRAY on 27/11/2024.
//
#include "../head/head.h"
void ouverture(char* pann){
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
            CLIENT tab_clients_dix[10];
            break;
        case(2):
            fic = fopen(CINQUANTE,"r+");
            if (fic == NULL){
                printf("Echec ouverture fichier\n");
                perror("fopen");
                exit(EXIT_FAILURE);
            }
            CLIENT tab_clients_cinquante[50];
            break;
        case(3):
            printf("");
            fic = fopen(CENT,"r+");
            if (fic == NULL){
                printf("Echec ouverture fichier\n");
                perror("fopen");
                exit(EXIT_FAILURE);
            }
            CLIENT tab_clients_cent[100];
            break;
        case(4):
            fic = fopen(CINQ_CENTS,"r+");
            if (fic == NULL){
                printf("Echec ouverture fichier\n");
                perror("fopen");
                exit(EXIT_FAILURE);
            }
            CLIENT tab_clients_cinq_cent[500];
            break;
        case(5):
            fic = fopen(MILLE,"r+");
            if (fic == NULL){
                printf("Echec ouverture fichier\n");
                perror("fopen");
                exit(EXIT_FAILURE);
            }
            CLIENT tab_clients_mille[1000];
            break;
        case(6):
            printf("");
            fic = fopen(CINQ_MILLES,"r+");
            if (fic == NULL){
                printf("Echec ouverture fichier\n");
                perror("fopen");
                exit(EXIT_FAILURE);
            }
            CLIENT tab_clients_cinq_mille[5000];
            break;
    }
    fclose(fic);
    printf("Le fichier à bien été fermé");
}
void ajout(FILE* fic){


}