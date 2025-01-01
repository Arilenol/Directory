//
// Created by Aymeric_ONFRAY on 27/11/2024.
//
#include "../head/head.h"
void afficher_tab(int nb_l,CLIENT tab[nb_l]);
FILE* ouverture(int x,int y,char annuaires[x][y],FILE* fic,char mode[]){
    int choix;
    printf("Quel fichier voulez vous consulter\n");
    for (int i = 0; i<x; i++){
        printf("%d) %s\n",i+1,annuaires[i]);
    }
    printf("\nEntrez le chiffre correspondant au fichier que vous souhaitez ouvrir : ");
    scanf("%d",&choix);
    while (choix<1 || choix > 7){
        printf("Sasie hors plage\nRéessayez : ");
        scanf("%d",&choix);
    }
    switch(choix){
        case(1):
            fic = fopen(DIX,mode);
            if (fic == NULL){
                printf("Echec ouverture fichier\n");
                perror("fopen");
                exit(EXIT_FAILURE);
            }
            system("cls");
            break;
        case(2):
            fic = fopen(CINQUANTE,mode);
            if (fic == NULL){
                printf("Echec ouverture fichier\n");
                perror("fopen");
                exit(EXIT_FAILURE);
            }
            system("cls");
            break;
        case(3):
            fic = fopen(CENT,mode);
            if (fic == NULL){
                printf("Echec ouverture fichier\n");
                perror("fopen");
                exit(EXIT_FAILURE);
            }
            system("cls");
            break;
        case(4):
            fic = fopen(CINQ_CENTS,mode);
            if (fic == NULL){
                printf("Echec ouverture fichier\n");
                perror("fopen");
                exit(EXIT_FAILURE);
            }
            system("cls");
            break;
        case(5):
            fic = fopen(MILLE,mode);
            if (fic == NULL){
                printf("Echec ouverture fichier\n");
                perror("fopen");
                exit(EXIT_FAILURE);
            }
            system("cls");
            break;
        case(6):
            fic = fopen(CINQ_MILLES,mode);
            if (fic == NULL){
                printf("Echec ouverture fichier\n");
                perror("fopen");
                exit(EXIT_FAILURE);
            }
            system("cls");
            break;
        case(7):
            system("cls");
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
void afficher(FILE* fic) {
    int nb_l = total_lignes(fic);
    char suite;
    CLIENT tab[nb_l];
    mot_par_mot(fic,nb_l,tab);
    printf("prenom | nom | ville | téléphone | adresse mail | profession | date de naissance\n");
    for(int i = 0; i< nb_l;i++){
    printf(" %d|%s|%s|%s|%s|%s|%s|%s|%s\n",tab[i].id,tab[i].prenom,tab[i].nom,tab[i].ville,tab[i].codep,tab[i].tel,tab[i].adrmail,tab[i].profession,tab[i].date_naissance );
    }
    vider_buffer();
    printf("Appuyer sur Entrer pour continuer");
    scanf("%c",&suite);
}
void afficher_manq(FILE* fic){
    int nb_l = total_lignes(fic),comt = 1;
    char suite;
    CLIENT tab[nb_l];
    mot_par_mot(fic,nb_l,tab);
    printf("num | prenom | nom | ville | téléphone | adresse mail | profession | date de naissance\n");
    for(int i = 0; i< nb_l;i++){
        if( strcmp(tab[i].prenom,"") == 0 || strcmp(tab[i].nom,"") == 0 || strcmp(tab[i].ville,"") == 0 || strcmp(tab[i].codep,"") == 0||strcmp(tab[i].tel,"") == 0 || strcmp(tab[i].adrmail,"") == 0 || strcmp(tab[i].profession,"") == 0 || strcmp(tab[i].date_naissance,"") == 0){
            printf(" %d|%s|%s|%s|%s|%s|%s|%s\n",tab[i].id,tab[i].prenom, tab[i].nom, tab[i].ville,tab[i].tel, tab[i].adrmail, tab[i].profession, tab[i].date_naissance);
            comt++;
        }
    }
    vider_buffer();
    printf("Appuyer sur Entrer pour continuer");
    scanf("%c",&suite);
}
void ajout(FILE* fic){
    vider_buffer();
    fseek(fic,SEEK_END,1);
    CLIENT cli;
    printf("Rentrez les information du client a rajouter");
    printf("\nLe prenom du client : ");
    fgets(cli.prenom,sizeof(cli.prenom),stdin);
    retirer_chariot(cli.prenom);
    printf("\nLe nom du client :");
    fgets(cli.nom,sizeof(cli.nom),stdin);
    retirer_chariot(cli.nom);
    printf("\nLa ville du client : ");
    fgets(cli.ville,sizeof(cli.ville),stdin);
    retirer_chariot(cli.ville);
    upper(cli.ville);
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
    retirer_chariot(cli.date_naissance);
    fprintf(fic,"%s,%s,%s %s,%s,%s,%s,%s\n",cli.prenom,cli.nom,cli.ville,cli.codep,cli.tel,cli.adrmail,cli.profession,cli.date_naissance);
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
void upper(char mot[]){
    int i=0;
    while(mot[i] != '\n' && mot[i] != '\0'){
        if(mot[i]> 96 && mot[i]< 123)
            mot[i]=mot[i]-32;
        i++;
    }
}
void sep_cdp_ville(int nb_lignes,CLIENT tab[nb_lignes]) {
    char tab_carac[100];
    int c1 =0 ;
    int c2 =0;
    for (int i = 0; i < nb_lignes; i++) {
        strcpy(tab_carac, tab[i].ville);
        if(*(tab_carac) != '\0') {
            while ((*(tab_carac + c1 + 1) < '0' || *(tab_carac + c1 + 1) > '9') && *(tab_carac + c1 + 1) != '\0') {
                c1++;
            }
            tab[i].ville[c1] = '\0';
            c1++;
            while (*(tab_carac + c1) != '\0' || c2<6) {
                tab[i].codep[c2] = *(tab_carac + c1);
                tab[i].ville[c1] = '\0';
                c1++;
                c2++;
            }
            c1 = 0;
            c2 = 0;
        }
    }
}
void afficher_tab(int nb_l,CLIENT tab[nb_l]) {
    char suite;
    printf("prenom | nom | ville | téléphone | adresse mail | profession | date de naissance\n");
    for (int i = 0; i < nb_l; i++) {
        printf(" %d|%s|%s|%s|%s|%s|%s|%s|%s\n", tab[i].id, tab[i].prenom, tab[i].nom, tab[i].ville, tab[i].codep,
               tab[i].tel, tab[i].adrmail, tab[i].profession, tab[i].date_naissance);
    }
    vider_buffer();
    printf("Appuyer sur Entrer pour continuer");
    scanf("%c", &suite);
}
void afficher_ligne(FILE* fic){
    int nb_l = total_lignes(fic),choix;
    CLIENT tab[nb_l];
    char suite;
    rewind(fic);
    mot_par_mot(fic,nb_l,tab);
    printf("\nQuelle ligne voulez-vous afficher :");
    scanf("%d",&choix);
    while(choix < 0 || choix > nb_l){
        printf("\nSaisie incorrect veuiller resaisir la ligne : ");
        scanf("%d",&choix);
    }
    for(int i = 0; i< nb_l;i++){
        if(tab[i].id == choix)
            printf(" %d|%s|%s|%s|%s|%s|%s|%s\n",tab[i].id,tab[i].prenom, tab[i].nom, tab[i].ville,tab[i].tel, tab[i].adrmail, tab[i].profession, tab[i].date_naissance);
    }
    vider_buffer();
    printf("\nAppuyer sur Entrer pour continuer");
    scanf("%c",&suite);
}
int ordre_alpha(char mot1[],char mot2[]){
    int i=0;
    while(mot1[i] == mot2[i] && (mot1[i] != '\0' && mot2[i] != '\0')){
        i++;
    }
    if(mot1[i] <= mot2[i])
        return 1;
    else
        return 2;
}

void fusion(CLIENT tab[],int debut ,int milieu,int fin,char option[]){
    int tailleG = milieu - debut +1;
    int tailleD = fin - milieu;
    CLIENT gauche[tailleG];
    CLIENT droite[tailleD];
    for(int i = 0 ; i < tailleG;i++){
        gauche[i]=tab[debut+i];
    }
    for(int j = 0; j < tailleD;j++){
        droite[j] = tab[milieu+1+j];
    }
    int k = 0,l = 0,m= debut;
    if (stricmp(option, "prenom") == 0) {
        while (k < tailleG && l < tailleD) {
            if (strcmp(gauche[k].prenom, droite[l].prenom) < 0) { // Comparaison lexicographique
                tab[m] = gauche[k];
                k++;
            } else {
                tab[m] = droite[l];
                l++;
            }
            m++;
        }
    }
    else if (stricmp(option, "nom") == 0) {
        while (k < tailleG && l < tailleD) {
            if (ordre_alpha(gauche[k].nom, droite[l].nom) == 1) { // Comparaison lexicographique
                tab[m] = gauche[k];
                k++;
            } else {
                tab[m] = droite[l];
                l++;
            }
            m++;
        }

    }
    else if (stricmp(option, "ville") == 0) {
        while (k < tailleG && l < tailleD) {
            if (ordre_alpha(gauche[k].ville, droite[l].ville) == 1) { // Comparaison lexicographique
                tab[m] = gauche[k];
                k++;
            } else {
                tab[m] = droite[l];
                l++;
            }
            m++;
        }

    }

    else if (stricmp(option, "codep") == 0) {
        while (k < tailleG && l < tailleD) {
            if (ordre_alpha(gauche[k].codep, droite[l].codep) == 1) { // Comparaison lexicographique
                tab[m] = gauche[k];
                k++;
            } else {
                tab[m] = droite[l];
                l++;
            }
            m++;
        }
    }
    else if (stricmp(option, "date_naissance") == 0) {
        while (k < tailleG && l < tailleD) {
            if (ordre_alpha(gauche[k].date_naissance, droite[l].date_naissance) == 1) { // Comparaison lexicographique
                tab[m] = gauche[k];
                k++;
            } else {
                tab[m] = droite[l];
                l++;
            }
            m++;
        }
    }
    while(k<tailleG){
        tab[m] = gauche[k];
        k++;
        m++;
    }
    while(l<tailleD){
        tab[m]=droite[l];
        l++;
        m++;
    }
}
void triFusion(CLIENT tableau[], int debut, int fin, char option[]) {
    if (debut < fin) {
        int milieu = debut + (fin - debut) / 2;

        // Diviser le tableau en deux moitiés
        triFusion(tableau, debut, milieu,option);
        triFusion(tableau, milieu + 1, fin,option);

        // Fusionner les deux moitiés triées=
        fusion(tableau, debut, milieu, fin,option);
    }
}
void tri_tableau(FILE* fic){
    int choix;
    int nb_l = total_lignes(fic);
    CLIENT tab[nb_l];
    mot_par_mot(fic,nb_l,tab);
    char info[5][30] = {"prenom","nom","ville","code postal","date de naissance"};
    printf("Selon quel critère voulez vous triez l'annuaire\n");
    for(int i=0;i<5;i++){
        printf("%d) %s\n",i+1,info[i]);
    }
    printf("\nEntrez le chiffre correspondant au critère par lequel vous voulez trié le tableau: ");
    scanf("%d", &choix);
    while (choix < 1 || choix > 5) {
        printf("Sasie hors plage\nRéessayez : ");
        scanf("%d", &choix);
    }
    switch(choix){
        case(1):
            triFusion(tab,0,nb_l-1,"prenom");
            break;
        case(2):
            triFusion(tab,0,nb_l-1,"nom");
            break;
        case(3):
            triFusion(tab,0,nb_l-1,"ville");
            break;
        case(4):
            triFusion(tab,0,nb_l-1,"codep");
            break;
        case(5):
            triFusion(tab,0,nb_l-1,"date_naissance");
            break;
        default:
            printf("Erreur de menu");
    }
    afficher_tab(nb_l,tab);
}




