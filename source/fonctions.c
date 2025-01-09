//
// Created by Aymeric_ONFRAY on 27/11/2024.
//
#include "../head/head.h"
void ouverture(char chemin[]){
    char possible[8][50]={"Consulter","Ajouter","Consulter les Client avec données manquantes","Consulter un tableau trié","Suppresion","Modifier","Sauvegarder","Revenir en arrière"};
    int ligne;
    char choix[2];
    int option;
    FILE* fic = NULL;//ouverture du fichier
    fic = fopen(chemin,"r+");
    if (fic == NULL){
        printf("Echec ouverture fichier\n");
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    int nb_ligne= total_lignes(fic);
    CLIENT tab[nb_ligne];//creation du tableau
    mot_par_mot(fic,nb_ligne,tab);
    fclose(fic);
    do{

        printf("\n\nQue voulez-faire parmi les actions suivantes ? \n");//affichage des option
        for (int i = 0; i < 8; i++) {
            printf("%d) %s\n", i + 1, possible[i]);
        }
        printf("\nEntrez le chiffre correspondant à l'action que vous souhaitez réaliser : ");// Entrer utilisateur sécuriser
        choix[0] = fgetc(stdin);
        option = atoi(choix);
        while (choix[0] < '1' || choix[0] > '8') {
            vider_buffer();
            printf("Sasie hors plage\nRéessayez : ");
            choix[0] = fgetc(stdin);
        }
        option = atoi(choix);
        vider_buffer();
        switch (option) {//differents options
            case (1)://affichage
                system("cls");
                afficher(nb_ligne,tab);
                printf("\nVoulez afficher une ligne en particulier\n1) 0ui\n2) Non\n");
                choix[0] = fgetc(stdin);
                while (choix[0] < '1' || choix[0] > '2') {
                    printf("Sasie hors plage\nRéessayez : ");
                    choix[0] = fgetc(stdin);
                }
                ligne =  atoi(choix);
                if(ligne == 1){
                    printf("Quelle ligne voulez vous afficher");
                    scanf("%d",&ligne);
                    while(ligne < 1 || ligne > nb_ligne-1){
                        printf("Hors plage veuillez ressayer\n");
                        scanf("%d",&ligne);
                    }
                    afficher_ligne(nb_ligne,tab,ligne);
                }
                break;
            case (2)://ajout d'utilisateur
                system("cls");
                fic= fopen(chemin,"a");
                ajout(fic);
                fclose(fic);
                break;

            case (3)://
                system("cls");
                afficher_manq(nb_ligne,tab);
                break;
            case(4):// tri du tableau
                system("cls");
                tri_tableau(nb_ligne,tab);
                break;
            case (5):// suppression de ligne
                system("cls");
                suppression(&nb_ligne,tab);
                //list_to_file(chemin,nb_ligne,tab);
                break;
            case (6)://modification du fichier
                system("cls");
                modif(nb_ligne,tab);
                break;
            case (7)://enregistrement des modifications
                system("cls");
                fic= fopen(chemin,"w");
                list_to_file(fic,nb_ligne,tab);
                fclose(fic);
                break;
            case (8):
                system("cls");
                break;
            default:
                printf("Valeur erronée");
                break;
        }
        system("cls");
        //vider_buffer();
    }while(option != 8);

}
void afficher(int nb_l,CLIENT tab[nb_l]) {
    char suite;
    //printf("prenom | nom | ville | téléphone | adresse mail | profession | âge\n");
    printf(" %-5s|%-20s|%-25s|%-20s|%-11s|%-14s|%-35s|%-15s|%-10s\n\n","id","prenom","nom","ville","Code postal","téléphone","adresse mail", "profession", "âge");// afficher l'entête
    for(int i = 0; i< nb_l;i++){// pour chaque client
        printf(" %-5d|%-20s|%-25s|%-20s|%-11s|%-14s|%-40s|%-15s|",tab[i].id,tab[i].prenom,tab[i].nom,tab[i].ville,tab[i].codep,tab[i].tel,tab[i].adrmail,tab[i].profession);// afficher toute les information
        calcul_age(tab[i].date_naissance);//sauf pour 'lage qui est caculer à l'affichage
        printf("\n");
    }
    printf("Appuyer sur Entrer pour continuer");// permet d'attendre un saisie utilisateur pour changer de page
    scanf("%c",&suite);
}
void afficher_manq(int nb_l,CLIENT tab[nb_l]) {
    char suite;
    int p=0;
    printf(" %-5s|%-15s|%-25s|%-15s|%-15s|%-15s|%-35s|%-25s|%-10s\n\n","id","prenom","nom","ville","Code postal","téléphone","adresse mail", "profession", "âge");// afficher l'entête
    for(int i = 0; i< nb_l;i++){// pour chaque client
        if( strcmp(tab[i].prenom,"") == 0 || strcmp(tab[i].nom,"") == 0 || strcmp(tab[i].ville,"") == 0 || strcmp(tab[i].codep,"") == 0||strcmp(tab[i].tel,"") == 0 || strcmp(tab[i].adrmail,"") == 0 || strcmp(tab[i].profession,"") == 0 || strcmp(tab[i].date_naissance,"") == 0){// si il y a une donné vide
            printf(" %-5d|%-15s|%-25s|%-15s|%-15s|%-15s|%-35s|%-25s|",tab[i].id,tab[i].prenom,tab[i].nom,tab[i].ville,tab[i].codep,tab[i].tel,tab[i].adrmail,tab[i].profession);// afficher toute les information
            calcul_age(tab[i].date_naissance);
            printf("\n");
            p++;
        }
    }
    printf(" Nombre de ligne avec attribut manquant : %d\n",p);
    printf("Appuyer sur Entrer pour continuer");// permet d'attendre un saisie utilisateur pour changer de page
    scanf("%c",&suite);
}
void ajout(FILE* fic){
    vider_buffer();
    fseek(fic,SEEK_END,1);
    CLIENT cli;// création d'une occurence de la structure
    printf("Rentrez les information du client a rajouter");
    printf("\nLe prenom du client : ");// saisie utilisateur de toute les information
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
    retirer_chariot(cli.date_naissance);
    fprintf(fic,"%s,%s,%s %s,%s,%s,%s,%s\n",cli.prenom,cli.nom,cli.ville,cli.codep,cli.tel,cli.adrmail,cli.profession,cli.date_naissance);// on print la structure a la fin du fichier
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
void vider_buffer(){// permet de vider le buffer pour eviter les bug de scanf
    char trash = fgetc(stdin);
    while(trash != '\n')// permet de vider le
        trash = fgetc(stdin);
}
void sep_cdp_ville(int nb_lignes,CLIENT tab[nb_lignes]) {
    char tab_carac[100];
    int c1 =0 ;
    int c2 =0;
    for (int i = 0; i < nb_lignes; i++) {// pour chaque client
        strcpy(tab_carac, tab[i].ville);
        if(*(tab_carac) != '\0') {//si la ville est renseigner
            while ((*(tab_carac + c1 + 1) < '0' || *(tab_carac + c1 + 1) > '9') && *(tab_carac + c1 + 1) != '\0') {// regarder si le caracter suivant est un chiffre
                c1++;
            }
            tab[i].ville[c1] = '\0';// finir la chaine ville au moment ou on passe dans le code postal
            c1++;
            while (*(tab_carac + c1) != '\0' || c2<6) {// jusqu'a la fin du code postal
                tab[i].codep[c2] = *(tab_carac + c1);// on met le caractere dans le codep
                tab[i].ville[c1] = '\0';//on suprrime la suite de la chaine ville
                c1++;
                c2++;
            }
            c1 = 0;
            c2 = 0;//on recommence
        }
    }
}

void afficher_ligne(int nb_l,CLIENT tab[nb_l],int ligne){
    char suite;
    int choix = ligne -1;
    printf(" %-5d|%-15s|%-25s|%-15s|%-15s|%-15s|%-35s|%-25s|",tab[choix].id,tab[choix].prenom,tab[choix].nom,tab[choix].ville,tab[choix].codep,tab[choix].tel,tab[choix].adrmail,tab[choix].profession,tab[choix].date_naissance );// print le client demander
    calcul_age(tab[choix].date_naissance);
    vider_buffer();
    printf("\nAppuyer sur Entrer pour continuer");// attendre la saisie utilisateur
    scanf("%c",&suite);
}

void fusion(CLIENT tab[],int debut ,int milieu,int fin,char option[]){
    int tailleG = milieu - debut +1;// calcule de la taille du sous tableau gauche
    int tailleD = fin - milieu;// calcule de la taille du sous tableau droit
    CLIENT gauche[tailleG];// creation du sous tableau gauche
    CLIENT droite[tailleD];// creation du sous tableau droit
    for(int i = 0 ; i < tailleG;i++){// on rempli le sous tableau gauche
        gauche[i]=tab[debut+i];
    }
    for(int j = 0; j < tailleD;j++){// on rempli le sous tableau droit
        droite[j] = tab[milieu+1+j];
    }
    int k = 0,l = 0,m= debut;
    if (stricmp(option, "nom") == 0) {//en fonction de l'option séléctionné
        while (k < tailleG && l < tailleD) {// tant qu'un tableau n'est pas vide
            if (stricmp(gauche[k].nom, droite[l].nom) <=0) { // si l'element du sous tableau gauche est inferieru a l'élament du sous tableau droit
                tab[m] = gauche[k];//on met l'élement du sous tableau gauche
                k++;// on avance d'un élément dans le sous tableau gauche
            } else { //sinon
                tab[m] = droite[l];//on met l'élement du sous tableau droit
                l++;// on avance d'un élément dans le sous tableau droit
            }
            m++;//on avnace de 1 dan le tableau final
        }
    }
    else if (stricmp(option, "codep") == 0) {
        while (k < tailleG && l < tailleD) {
            if (stricmp(gauche[k].codep, droite[l].codep) <=0) {
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
            if (stricmp(gauche[k].profession, droite[l].profession) <=0) {
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
            if (stricmp(gauche[k].date_naissance, droite[l].date_naissance) <=0) {
                tab[m] = gauche[k];
                k++;
            } else {
                tab[m] = droite[l];
                l++;

            }
            m++;

        }

    }
    while(k<tailleG){// si le tableau gauche n'est pas fini
        tab[m] = gauche[k];// on rempli  le tableau par les élément restant du tableau gauche
        k++;
        m++;

    }

    while(l<tailleD){// si le tableau droit n'est pas fini
        tab[m]=droite[l];// on rempli  le tableau par les élément restant du tableau droit
        l++;
        m++;

    }

}
void triFusion(CLIENT tableau[], int debut, int fin, char option[]) {
    if (debut < fin) {// si le tableau a au moin deux élement
        int milieu = debut + (fin - debut) / 2;
        // Diviser le tableau en deux moitiés
        triFusion(tableau, debut, milieu,option);

        triFusion(tableau, milieu + 1, fin,option);

        // Fusionner les deux moitiés triées
        fusion(tableau, debut, milieu, fin,option);


    }
}
void tri_tableau(int nb_l,CLIENT tab[nb_l]){
    char choix[2];
    int option;
    char info[4][30] = {"nom","code postal","profession","âge"};
    printf("Selon quel critère voulez vous triez l'annuaire\n");
    for(int i=0;i<4;i++){// affichage des options
        printf("%d) %s\n",i+1,info[i]);
    }
    printf("\nEntrez le chiffre correspondant au critère par lequel vous voulez trié le tableau: ");
    choix[0] = fgetc(stdin);// demande saisie utilisateur
    while (choix[0] < '1' || choix[0] > '4') {
        printf("Sasie hors plage\nRéessayez : ");
        choix[0] = fgetc(stdin);
    }
    option = atoi(choix);
    vider_buffer();
    switch(option){// tri en fonction de l'option séléctionner
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
    afficher(nb_l,tab);// afficher le tableau trié

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



