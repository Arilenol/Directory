//
// Created by Aymeric_ONFRAY on 27/11/2024.
//
#include "../head/head.h"
void ouverture(int x,int y,char annuaires[x][y]){
    int choix;
    printf("Quel fichier voulez vous consulter\n");
    for (int i = 0; i<NB_FICH; i++){
        printf("%d) %s\n",i+1,annuaires[i]);
    }
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
            break;
        case(2):
            fic = fopen(CINQUANTE,"r+");
            if (fic == NULL){
                printf("Echec ouverture fichier\n");
                perror("fopen");
                exit(EXIT_FAILURE);
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
            break;
        case(4):
            fic = fopen(CINQ_CENTS,"r+");
            if (fic == NULL){
                printf("Echec ouverture fichier\n");
                perror("fopen");
                exit(EXIT_FAILURE);
            }
            break;
        case(5):
            fic = fopen(MILLE,"r+");
            if (fic == NULL){
                printf("Echec ouverture fichier\n");
                perror("fopen");
                exit(EXIT_FAILURE);
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

            break;
    }
    fclose(fic);
    printf("Le fichier à bien été fermé");
}
void ajout(FILE* fic){
    fseek(fic,SEEK_END,0);
    CLIENT cli;
    printf("Rentrez les inofrmation du client a rajouter\n");
    printf("Le nom du client : \n");
    scanf("%s",cli.nom);
    printf("Le prenom du client : \n");
    scanf("%s",cli.prenom);
    printf("La ville du client : \n");
    scanf("%s",cli.ville);
    printf("Le code postal du client : \n");
    scanf("%s",cli.codep);
    printf("Le numero de téléphone du client : \n");
    scanf("%s",cli.tel);
    printf("L'adresse mail du client : \n");
    scanf("%s",cli.adrmail);
    printf("La profession du client : \n");
    scanf("%s",cli.profession);
    printf("La date de naissance du client : \n");
    scanf("%s",cli.date_naissance);
    fprintf(fic,"%s,%s;%s %s,%s,%s,%s,%s",cli.nom,cli.prenom,cli.ville,cli.codep,cli.tel,cli.adrmail,cli.profession,cli.date_naissance);
}