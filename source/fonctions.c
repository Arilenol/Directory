//
// Created by Aymeric_ONFRAY on 27/11/2024.
//
#include "../head/head.h"
FILE* ouverture(int x,int y,char annuaires[x][y],FILE* fic){
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
    switch(choix){
        case(1):
            fic = fopen(DIX,"r");
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
        default:
            printf("erreur");
    }
    return fic;
}
void fermeture(FILE* fic){
    fclose(fic);
    printf("\n1Le fichier à bien été fermé");
}
void afficher(FILE* fic){
    rewind(fic);
    char ligne[464];
    int i =1;
    while (fgets(ligne, sizeof(ligne), fic) != NULL) {
        printf("%d: %s", i++, ligne); // Afficher la ligne
    }
}
void ajout(FILE* fic){
    vider_buffer();
    fseek(fic,SEEK_END,0);
    CLIENT cli = {"Antoine","Dupont","TOULOUSE","31000","0600000000","a","rugbyman","15/11/1996"};
    printf("Rentrez les information du client a rajouter");
    /*printf("\nLe prenom du client : ");
    fgets(cli.prenom,sizeof(cli.prenom),stdin);
    retirer_chariot(cli.prenom);
    printf("\nLe nom du client :");
    fgets(cli.nom,sizeof(cli.nom),stdin);
    retirer_chariot(cli.nom);
    printf("\nLa ville du client : ");
    fgets(cli.ville,sizeof(cli.ville),stdin);
    retirer_chariot(cli.ville);
    printf("\nLe code postal du client :");
    fgets(cli.codep,sizeof(cli.codep),stdin);
    retirer_chariot(cli.codep);
    printf("\nLe numero de téléphone du client :");
    vider_buffer();
    fgets(cli.tel,sizeof(cli.tel),stdin);
    retirer_chariot(cli.tel);
    printf("\nL'adresse mail du client :");
    fgets(cli.adrmail,sizeof(cli.adrmail),stdin);
    retirer_chariot(cli.adrmail);
    printf("\nLa profession du client :");
    fgets(cli.profession,sizeof(cli.profession),stdin);
    retirer_chariot(cli.profession);
    printf("\nLa date de naissance du client :");
    fgets(cli.date_naissance,sizeof(cli.date_naissance),stdin);
    retirer_chariot(cli.date_naissance);*/
    if(fprintf(fic,"%s,%s,%s %s,%s,%s,%s,%s\n",cli.prenom,cli.nom,cli.ville,cli.codep,cli.tel,cli.adrmail,cli.profession,cli.date_naissance) <= 0)
        printf("erreur de copy");
}
void retirer_chariot(char mot[]){
    int i = 0;
    if(mot[0] == '\n')
        mot[0] = '\0';
    while(mot[i] != '\n' && mot[i] != '\0') {
        i++;
    }
    mot[i] = '\0';
}
void vider_buffer(){
    char trash = fgetc(stdin);
    while(trash != '\n')
        trash = fgetc(stdin);
}