//
// Created by Aymeric_ONFRAY on 27/11/2024.
//
#include "../head/head.h"
int ouverture(int x,int y,char annuaires[x][y],FILE* fic){
    int choix;
    printf("Quel fichier voulez vous consulter\n");
    for (int i = 0; i<x; i++){
        printf("%d) %s\n",i+1,annuaires[i]);
    }
    printf("\nEntrez le chiffre correspondant au fichier que vous souhaitez ouvrir : ");
    scanf("%d",&choix);
    while (choix<1 || choix >NB_FICH){
        printf("Sasie hors plage\nRéessayez : ");
        scanf("%d",&choix);
    }
    int nb_ligne;
    switch(choix){
        case(1):
            fic = fopen(DIX,"r+");
            if (fic == NULL){
                printf("Echec ouverture fichier\n");
                perror("fopen");
                exit(EXIT_FAILURE);
            }
            nb_ligne = total_lignes(fic);
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
}
void fermeture(FILE* fic){
    fclose(fic);
    printf("Le fichier à bien été fermé");
}
void ajout(FILE* fic){
    fseek(fic,SEEK_END,0);
    CLIENT cli = {"","","","","","","",""};
    printf("Rentrez les inofrmation du client a rajouter");
    printf("\nLe prenom du client :");
    fgets(cli.prenom,75,stdin);
    /*printf("\nLe nom du client :");
    fgets(cli.nom,85,stdin);
    printf("\nLa ville du client : ");
    fgets(cli.ville,85,stdin);
    printf("\nLe code postal du client :");
    fgets(cli.codep,6,stdin);
    printf("\nLe numero de téléphone du client :");
    fgets(cli.tel,16,stdin);
    printf("\nL'adresse mail du client :");
    fgets(cli.adrmail,100,stdin);
    printf("\nLa profession du client :");
    fgets(cli.profession,85,stdin);
    printf("\nLa date de naissance du client :");
    fgets(cli.date_naissance,11,stdin);*/
    fprintf(fic,"%s,%s;%s %s,%s,%s,%s,%s",cli.prenom,cli.nom,cli.ville,cli.codep,cli.tel,cli.adrmail,cli.profession,cli.date_naissance);
}