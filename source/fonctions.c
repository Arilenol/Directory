//
// Created by Aymeric_ONFRAY on 27/11/2024.
//
#include "../head/head.h"
void afficher_tab(int nb_l,CLIENT tab[nb_l]);
void calcul_age(char mot[]);
void ouverture(char chemin[]){
    char possible[8][50]={"Consulter","Ajouter","Consulter les Client avec données manquantes","Consulter un tableau trié","Suppresion","Modifier","Terminer","Sauvegarder"};
    int choix,ligne;
    FILE* fic = NULL;
    FILE* fic2;
    fic = fopen(chemin,"r+");
    if (fic == NULL){
        printf("Echec ouverture fichier\n");
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    int nb_ligne= total_lignes(fic);
    CLIENT tab[nb_ligne];
    mot_par_mot(fic,nb_ligne,tab);
    do{


        printf("\n\nQue voulez-faire parmi les actions suivantes ? \n");
        for (int i = 0; i < 8; i++) {
            printf("%d) %s\n", i + 1, possible[i]);
        }
        printf("\nEntrez le chiffre correspondant à l'action que vous souhaitez réaliser : ");
        scanf("%d", &choix);
        while (choix < 1 || choix > 8) {
            printf("Sasie hors plage\nRéessayez : ");
            scanf("%d", &choix);
        }
        switch (choix) {
            case (1):
                system("cls");
                afficher(nb_ligne,tab);
                printf("\nVoulez afficher une ligne en particulier\n1) 0ui\n2) Non\n");
                scanf("%d",&choix);
                while (choix < 1 || choix > 2) {
                    printf("Sasie hors plage\nRéessayez : ");
                    scanf("%d", &choix);
                }
                if(choix == 1){
                    printf("Quelle ligne voulez vous afficher");
                    scanf("%d",&ligne);
                    while(ligne < 1 || ligne > nb_ligne-1){
                        printf("Hors plage veuillez ressayer\n");
                        scanf("%d",&ligne);
                    }
                    afficher_ligne(nb_ligne,tab,ligne);
                }
                break;

            case (2):
                system("cls");
                ajout(fic);
                break;

            case (3):
                system("cls");
                afficher_manq(nb_ligne,tab);
                break;
            case(4):
                system("cls");
                tri_tableau(fic);
                break;
            case (5):
                system("cls");
                suppression(&nb_ligne,tab);
                break;
            case (6):
                system("cls");
                modif(nb_ligne,tab);
                break;
            case (7):
                system("cls");
                return;
            case (8):
                fclose(fic);
                fic2 = fopen(chemin,"w");
                printf("%s",tab[5].prenom);
                list_to_file(fic2,nb_ligne,tab);
                break;
            default:
                printf("Valeur erronée");
                break;
        }
        if (choix!=8){
        //system("cls");
        fclose(fic);
        }
        else{
        //system("cls");
        fclose(fic2);  
        }

    }while(choix != 9);
}
void afficher(int nb_l,CLIENT tab[nb_l]) {
    char suite;
    //printf("prenom | nom | ville | téléphone | adresse mail | profession | âge\n");
    printf(" %-5s|%-15s|%-25s|%-15s|%-15s|%-15s|%-35s|%-25s|%-10s\n\n","id","prenom","nom","ville","Code postal","téléphone","adresse mail", "profession", "âge");
    for(int i = 0; i< nb_l;i++){
    printf(" %-5d|%-15s|%-25s|%-15s|%-15s|%-15s|%-35s|%-25s|",tab[i].id,tab[i].prenom,tab[i].nom,tab[i].ville,tab[i].codep,tab[i].tel,tab[i].adrmail,tab[i].profession,tab[i].date_naissance );
        calcul_age(tab[i].date_naissance);
        printf("\n");
    }
    vider_buffer();
    printf("Appuyer sur Entrer pour continuer");
    scanf("%c",&suite);
}
void afficher_manq(int nb_l,CLIENT tab[nb_l]) {
    char suite;
    int p=0;
    printf(" %-5s|%-15s|%-25s|%-15s|%-15s|%-15s|%-35s|%-25s|%-10s\n\n","id","prenom","nom","ville","Code postal","téléphone","adresse mail", "profession", "âge");
    for(int i = 0; i< nb_l;i++){
        if( strcmp(tab[i].prenom,"") == 0 || strcmp(tab[i].nom,"") == 0 || strcmp(tab[i].ville,"") == 0 || strcmp(tab[i].codep,"") == 0||strcmp(tab[i].tel,"") == 0 || strcmp(tab[i].adrmail,"") == 0 || strcmp(tab[i].profession,"") == 0 || strcmp(tab[i].date_naissance,"") == 0){
            printf(" %-5d|%-15s|%-25s|%-15s|%-15s|%-15s|%-35s|%-25s|",tab[i].id,tab[i].prenom,tab[i].nom,tab[i].ville,tab[i].codep,tab[i].tel,tab[i].adrmail,tab[i].profession,tab[i].date_naissance );
            calcul_age(tab[i].date_naissance);
            printf("\n");
            p++;
        }
    }
    printf(" Nombre de ligne avec attribut manquant : %d\n",p);
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

void afficher_ligne(int nb_l,CLIENT tab[nb_l],int ligne){
    char suite;
    int choix = ligne -1;
    printf(" %-5d|%-15s|%-25s|%-15s|%-15s|%-15s|%-35s|%-25s|",tab[choix].id,tab[choix].prenom,tab[choix].nom,tab[choix].ville,tab[choix].codep,tab[choix].tel,tab[choix].adrmail,tab[choix].profession,tab[choix].date_naissance );
    calcul_age(tab[choix].date_naissance);
    vider_buffer();
    printf("\nAppuyer sur Entrer pour continuer");
    scanf("%c",&suite);
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

     if (stricmp(option, "nom") == 0) {
        while (k < tailleG && l < tailleD) {
            if (stricmp(gauche[k].nom, droite[l].nom) <=0) { // Comparaison lexicographique
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
            if (stricmp(gauche[k].codep, droite[l].codep) <=0) { // Comparaison lexicographique
                tab[m] = gauche[k];
                k++;
            } else {
                tab[m] = droite[l];
                l++;
            }
            m++;
        }
    }
    else if (stricmp(option, "profession") <= 0) {
        while (k < tailleG && l < tailleD) {
            if (stricmp(gauche[k].profession, droite[l].profession) <=0) { // Comparaison lexicographique
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
             if (stricmp(gauche[k].date_naissance, droite[l].date_naissance) <=0) { // Comparaison lexicographique
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
    char info[4][30] = {"nom","code postal","profession","âge"};
    printf("Selon quel critère voulez vous triez l'annuaire\n");
    for(int i=0;i<4;i++){
        printf("%d) %s\n",i+1,info[i]);
    }
    printf("\nEntrez le chiffre correspondant au critère par lequel vous voulez trié le tableau: ");
    scanf("%d", &choix);
    while (choix < 1 || choix > 4) {
        printf("Sasie hors plage\nRéessayez : ");
        scanf("%d", &choix);
    }
    switch(choix){
        case(1):
            triFusion(tab,0,nb_l-1,"nom");
            break;
        case(2):
            triFusion(tab,0,nb_l-1,"codep");
            break;
        case(3):
            triFusion(tab,0,nb_l-1,"profession");
            break;
        case(4):
            triFusion(tab,0,nb_l-1,"date_naissance");
            break;
        default:
            printf("Erreur de menu");
    }
    afficher(nb_l,tab);

}

void calcul_age(char mot[]){
    int jour,mois,annee,jour1,mois1,annee1;
    char j[3],m[3],a[5];
    if(mot[0] != '\0'){
        time_t t = time(NULL);
        struct tm *date_actuelle = localtime(&t);
        // Extraire les informations de la date
        jour = date_actuelle->tm_mday;
        mois = date_actuelle->tm_mon + 1;    // Les mois commencent à 0
        annee = date_actuelle->tm_year + 1900; // L'année commence à 1900
        // recupere les element de la date de naissance
        j[0]=mot[0];
        j[1]=mot[1];
        m[0]=mot[3];
        m[1]=mot[4];
        a[0]=mot[6];
        a[1]=mot[7];
        a[2]=mot[8];
        a[3]=mot[9];
        // convertir en nombre
        jour1 = strtol(j,NULL,10);
        mois1 = strtol(m,NULL,10);
        annee1= strtol(a,NULL,10);
        if(mois<mois1 && jour1 > jour || (mois==mois1 && jour1 > jour)){// si le mois de naissance n'est pas encore passer ou si le jour de naissance est pas encore passer
            printf("%d",annee-annee1);// print l'age
        }
        else{
            printf("%d",annee-annee1-1);
        }

    }
}





