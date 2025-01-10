#include "../head/head.h"

int total_lignes(FILE * fichier){
    rewind(fichier);
    char c;
    int res = 0;
    c = fgetc(fichier);
    while (c!=EOF)
    {   
        if(c=='\n'){
            res++;
        }
        c = fgetc(fichier);
    }
    return res;
}

// " Bonjour"

void enlever_espace_debut(char mot[]) {
    int indice = 0; // Trouver le premier caractère non-espace
    int length = strlen(mot);

    // Parcours pour trouver le premier caractère alphabétique ou autre non-espace
    while (indice < length && mot[indice] == ' ') {
        indice++;
    }

    // Décaler la chaîne si des espaces ont été trouvés
    if (indice > 0) {
        for (int i = 0; i <= length - indice; i++) {
            mot[i] = mot[i + indice];
        }
    }
}


void enlever_espace_fin(char mot[]) {
    int length = strlen(mot) - 1;

    // Parcourir la chaîne à l'envers pour trouver le dernier caractère non espace
    while (length >= 0 && mot[length] == ' ') {
        length--;
    }

    // Ajouter le terminateur de chaîne après le dernier caractère non espace
    mot[length + 1] = '\0';
}

void affecter_struct(CLIENT *c1, char option[], char mot[]) {
    if (stricmp(option, "prenom") == 0) {
        strcpy(c1->prenom, mot);
    }
    else if (stricmp(option, "nom") == 0) {
        strcpy(c1->nom, mot);
    }
    else if (stricmp(option, "ville") == 0) {
        strcpy(c1->ville, mot);
    }

    else if (stricmp(option, "codep") == 0) {
        strcpy(c1->codep, mot);
    }
    else if (stricmp(option, "tel") == 0) {
        strcpy(c1->tel, mot);
    }
     else if (stricmp(option, "adrmail") == 0) {
        strcpy(c1->adrmail, mot);
    }
    else if (stricmp(option, "profession") == 0) {
        strcpy(c1->profession, mot);
    }
    else if (stricmp(option, "date_naissance") == 0) {
        strcpy(c1->date_naissance, mot);

    } else {
        printf("Option inconnue: %s\n", option);
    }
}


void mot_par_mot(FILE* fichier,int nb_ligne, CLIENT tableau[nb_ligne]){
    rewind(fichier);
    char info[7][30] = {"prenom","nom","ville","tel","adrmail","profession","date_naissance"};
    CLIENT c1;
    char c;
    int indice = 0;
    int ligne = 0;
    int nb_champ = 0;
    char mot[50];
    c = fgetc(fichier);
    while(c!=EOF && ligne<nb_ligne){
        if (c=='\n'){
            mot[indice] = '\0';
            affecter_struct(&c1,info[nb_champ],mot);
            tableau[ligne] = c1;
            nb_champ = 0 ;
            mot[0] = '\0';
            indice = 0;
            ligne++;
            CLIENT c1;
        }
        else if (c==','){
            mot[indice] = '\0';
            //printf("info : %s et mot : ",info[nb_champ],mot);
            affecter_struct(&c1,info[nb_champ],mot);
            nb_champ++;
            char mot[50];
            indice = 0 ;
            }
        else {
            mot[indice] = c;
            indice++;

            }
            c=fgetc(fichier);
            c1.id=ligne+1;
        }
        sep_cdp_ville(nb_ligne,tableau);
    }

void retirerchariot(char mot[]){
    int i = 0;
    while (mot[i]!='\n' && mot[i]!='\0'){
        i++;
        }

    mot[i]='\0';
}

int stristr(char mot[],  char motif[]) {
    // Si le motif est vide, on considère que la recherche est toujours réussie
    if (motif[0] == '\0') {
        return 0;  // Retourne 0 car une chaîne vide est toujours trouvée en début de la chaîne principale
    }

    // Longueur du motif
    int motif_len = strlen(motif);

    // Parcours de la chaîne principale (mot)
    for (int i = 0; mot[i] != '\0'; i++) {
        // Comparaison caractère par caractère, en ignorant la casse
        if (tolower(mot[i]) == tolower(motif[0])) {
            // Si le premier caractère correspond, on vérifie le reste de la chaîne
            int j = 0;
            while (mot[i + j] != '\0' && motif[j] != '\0' && tolower(mot[i + j]) == tolower(motif[j])) {
                j++;
            }

            // Si on a trouvé toute la sous-chaîne (fin de motif)
            if (motif[j] == '\0') {
                return 1;  // Retourne l'indice où la sous-chaîne a été trouvée
            }
        }
    }

    // Si le motif n'a pas été trouvé
    return -1;  // Retourne -1 pour indiquer que le motif n'a pas été trouvé
}


/*
int filtre(const char motif[], int taille, CLIENT tab[taille] ){
    int choix;
    //char motif[40];
    CLIENT tableau[70];
    printf("Comment voulez-vous filtrer l'annuaire ?\n");
    printf("1) Son prénom ?\n");

    printf("2) Son nom ?\n");
    printf("3) Son numero de telephone ?\n");
    printf("4) Son mail ?\n");
    printf("Entrez votre choix ici : ");
    scanf("%d", &choix);
    getchar();
    switch (choix)
    {
    case 1:
        printf("Entrez un motif : ");
        fgets(motif,41,stdin);

        break;
    
    default:
        break;
    }
}
*/
//FONCTION terminée, en attente d'un point ensemble pour rectfier 2-3 choses
int recherche(int nb_ligne, CLIENT tableau[nb_ligne]) {
    int indice[100];
    int indice2 = 0;
    int select = -1; //initialisation par défaut
    int option,nb_l;
    char choix[2];
    int verification = nb_ligne;
    char prenom[40], nom[40], ville[40], code[40], mail[40], numero[40], metier[40], date[20];
    int value;
    CLIENT tab[100];
    printf("Par quel moyen voulez-vous retrouver la personne\n");
    printf("1) Son prénom ?\n");
    printf("2) Son nom ?\n");
    printf("3) Son numero de telephone ?\n");
    printf("4) Son mail ?\n");
    printf("5) Par cumul d'info ?\n");
    printf("Entrez votre choix ici : ");
    //vider_buffer(); //avale le \n laissé par scanf
    choix[0] = fgetc(stdin);
    option = atoi(choix);
    while (choix[0] < '1' || choix[0] > '5') {
        printf("Sasie hors plage\nRéessayez : ");
        choix[0] = fgetc(stdin);
    }
    option = atoi(choix);
    vider_buffer();
    switch (option) {
        case 1:
            printf("Entrez le prénom de la personne : ");
            fgets(prenom, 41, stdin);
            retirerchariot(prenom);
            enlever_espace_fin(prenom);
            enlever_espace_debut(prenom);
            for (int i = 0; i < nb_ligne; i++) {
                if (stricmp(prenom, tableau[i].prenom) == 0) {
                    indice[indice2] = i;
                    tab[indice2] = tableau[i];
                    indice2++;

                }
            }
            // Si aucun résultat n'a été trouvé, select reste à -1
            if (indice2 == 0) {
                printf("Aucun client trouvé avec ce prénom.\n");
                return select; // Retourne -1
            }
            break;

        case 2:
            printf("Entrez le nom de la personne : ");
            fgets(nom, 41, stdin);
            retirerchariot(nom);
            enlever_espace_fin(nom);
            enlever_espace_debut(nom);
            for (int i = 0; i < nb_ligne; i++) {
                if (stricmp(nom, tableau[i].nom) == 0) {
                    indice[indice2] = i;
                    tab[indice2] = tableau[i];
                    indice2++;

                }
            }
            // Si aucun résultat n'a été trouvé, select reste à -1
            if (indice2 == 0) {
                printf("Aucun client trouvé avec ce prénom.\n");
                return select; // Retourne -1
            }
            break;

        case 3:
            value = 1;
            printf("Entrez le numero de telephone de la personne : ");
            fgets(numero, 41, stdin);
            retirerchariot(numero);
            enlever_espace_fin(numero);
            enlever_espace_debut(numero);
            for (int i = 0; i < nb_ligne && value; i++) {
                if (stricmp(numero, tableau[i].tel) == 0) {
                    value = 0;
                    indice[indice2] = i;
                    tab[indice2] = tableau[i];
                    indice2++;

                }
            }
                
            // Si aucun résultat n'a été trouvé, select reste à -1
            if (indice2 == 0) {
                printf("Aucun client trouvé avec ce prénom.\n");
                return select; // Retourne -1
            }
            select = indice[0];
            break;
        case 4:
            printf("Entrez le mail de la personne : ");
            fgets(mail, 41, stdin);
            retirerchariot(mail);
            enlever_espace_fin(mail);
            enlever_espace_debut(mail);
            for (int i = 0; i < nb_ligne; i++) {
                if (stricmp(mail, tableau[i].adrmail) == 0) {
                    indice[indice2] = i;
                    tab[indice2] = tableau[i];
                    indice2++;

                }
            }
            // Si aucun résultat n'a été trouvé, select reste à -1
            if (indice2 == 0) {
                printf("Aucun client trouvé avec ce prénom.\n");
                return select; // Retourne -1
            }
            break;
        case 5:

            printf("Entrez le prénom de la personne : ");
            fgets(prenom, 41, stdin);
            retirerchariot(prenom);
            enlever_espace_fin(prenom);
            enlever_espace_debut(prenom);
            if (prenom[0]!='\0'){
                for (int i = 0; i < nb_ligne; i++) {
                    if (stricmp(prenom, tableau[i].prenom) == 0) {
                        tab[indice2] = tableau[i];
                        indice[indice2] = i;
                        indice2++;
                    }
                    verification = indice2;
                }
            }

            printf("Entrez le nom de la personne : ");
            fgets(nom, 41, stdin);
            retirerchariot(nom);
            enlever_espace_fin(nom);
            enlever_espace_debut(nom);
            if (nom[0]!='\0' && verification==nb_ligne){
                for (int i = 0; i < nb_ligne; i++) {
                    if (stricmp(nom, tableau[i].nom) == 0) {
                        tab[indice2] = tableau[i];
                        indice[indice2] = i;
                        indice2++;
                    }
                    verification = indice2;
                }
            }
            else if (nom[0]!='\0' && verification!=nb_ligne){
                for (int i = 0; i < verification; ) { // pas de i++ car bug avec le décalage
                    if (stricmp(nom, tab[i].nom) != 0) {
                        // Décaler les éléments suivants pour supprimer l'élément courant
                        for (int j = i; j < verification - 1; j++) {
                            tab[j] = tab[j + 1];
                            indice[j] = indice[j+1];

                        }
                        verification--; // Réduire la taille logique
                        // Ne pas incrémenter i pour revérifier l'élément décalé
                    } else {
                        i++;
                    }
                }

            }
            printf("Entrez la ville de la personne : ");
            fgets(ville, 41, stdin);
            retirerchariot(ville);
            enlever_espace_fin(ville);
            enlever_espace_debut(ville);
            if (ville[0]!='\0' && verification==nb_ligne){
                for (int i = 0; i < nb_ligne; i++) {
                    if (stricmp(ville, tableau[i].ville) == 0) {
                        tab[indice2] = tableau[i];
                        indice[indice2] = i;
                        indice2++;
                    }
                    verification = indice2;
                }
            }
            else if (ville[0]!='\0' && verification!=nb_ligne){
                for (int i = 0; i < verification; ) { // pas de i++ car bug avec le décalage
                    if (stricmp(ville, tab[i].ville) != 0) {
                        // Décaler les éléments suivants pour supprimer l'élément courant
                        for (int j = i; j < verification - 1; j++) {
                            tab[j] = tab[j + 1];
                            indice[j] = indice[j+1];

                        }
                        verification--; // Réduire la taille logique
                        // Ne pas incrémenter i pour revérifier l'élément décalé
                    } else {
                        i++;
                    }
                }

            }
            printf("Entrez le code postal de la personne : ");
            fgets(code, 41, stdin);
            retirerchariot(code);
            enlever_espace_fin(code);
            enlever_espace_debut(code);
            if (code[0]!='\0' && verification==nb_ligne){
                for (int i = 0; i < nb_ligne; i++) {
                    if (stricmp(code, tableau[i].codep) == 0) {
                        tab[indice2] = tableau[i];
                        indice[indice2] = i;
                        indice2++;
                    }
                    verification = indice2;
                }
            }
            else if (code[0]!='\0' && verification!=nb_ligne){
                for (int i = 0; i < verification; ) { // pas de i++ car bug avec le décalage
                    if (stricmp(code, tab[i].codep) != 0) {
                        // Décaler les éléments suivants pour supprimer l'élément courant
                        for (int j = i; j < verification - 1; j++) {
                            tab[j] = tab[j + 1];
                            indice[j] = indice[j+1];
                        }
                        verification--; // Réduire la taille logique
                        // Ne pas incrémenter i pour revérifier l'élément décalé
                    } else {
                        i++;
                    }
                }

            }
            printf("Entrez le numéro de téléphone : ");
            fgets(numero, 41, stdin);
            retirerchariot(numero);
            enlever_espace_fin(numero);
            enlever_espace_debut(numero);
            if (numero[0]!='\0' && verification==nb_ligne){
                for (int i = 0; i < nb_ligne; i++) {
                    if (stricmp(numero, tableau[i].tel) == 0) {
                        tab[indice2] = tableau[i];
                        indice[indice2] = i;
                        indice2++;
                    }
                    verification = indice2;
                }
            }
            else if (numero[0]!='\0' && verification!=nb_ligne){
                for (int i = 0; i < verification; ) { // pas de i++ car bug avec le décalage
                    if (stricmp(numero, tab[i].tel) != 0) {
                        // Décaler les éléments suivants pour supprimer l'élément courant
                        for (int j = i; j < verification - 1; j++) {
                            tab[j] = tab[j + 1];
                            indice[j] = indice[j+1];
                        }
                        verification--; // Réduire la taille logique
                        // Ne pas incrémenter i pour revérifier l'élément décalé
                    } else {
                        i++;
                    }
                }

            }
            printf("Entrez l'adresse mail : ");
            fgets(mail, 41, stdin);
            retirerchariot(mail);
            enlever_espace_fin(mail);
            enlever_espace_debut(mail);
            if (mail[0]!='\0' && verification==nb_ligne){
                for (int i = 0; i < nb_ligne; i++) {
                    if (stricmp(mail, tableau[i].adrmail) == 0) {
                        tab[indice2] = tableau[i];
                        indice[indice2] = i;
                        indice2++;
                    }
                    verification = indice2;
                }
            }
            else if (mail[0]!='\0' && verification!=nb_ligne){
                for (int i = 0; i < verification; ) { // pas de i++ car bug avec le décalage
                    if (stricmp(mail, tab[i].adrmail) != 0) {
                        // Décaler les éléments suivants pour supprimer l'élément courant
                        for (int j = i; j < verification - 1; j++) {
                            tab[j] = tab[j + 1];
                            indice[j] = indice[j+1];
                        }
                        verification--; // Réduire la taille logique
                        // Ne pas incrémenter i pour revérifier l'élément décalé
                    } else {
                        i++;
                    }
                }

            }
            printf("Entrez le métier : ");
            fgets(metier, 21, stdin);
            retirerchariot(metier);
            enlever_espace_fin(metier);
            enlever_espace_debut(metier);
            if (metier[0]!='\0' && verification==nb_ligne){
                for (int i = 0; i < nb_ligne; i++) {
                    if (stricmp(metier, tableau[i].profession) == 0) {
                        tab[indice2] = tableau[i];
                        indice[indice2] = i;
                        indice2++;
                    }
                    verification = indice2;
                }
            }
            else if (metier[0]!='\0' && verification!=nb_ligne){
                for (int i = 0; i < verification; ) { // pas de i++ car bug avec le décalage
                    if (stricmp(metier, tab[i].profession) != 0) {
                        // Décaler les éléments suivants pour supprimer l'élément courant
                        for (int j = i; j < verification - 1; j++) {
                            tab[j] = tab[j + 1];
                            indice[j] = indice[j+1];
                        }
                        verification--; // Réduire la taille logique
                        // Ne pas incrémenter i pour revérifier l'élément décalé
                    } else {
                        i++;
                    }
                }

            }
            printf("Entrez la date de naissance : ");
            fgets(date, 21, stdin);
            retirerchariot(date);
            enlever_espace_fin(date);
            enlever_espace_debut(date);
            if (date[0]!='\0' && verification==nb_ligne){
                for (int i = 0; i < nb_ligne; i++) {
                    if (stricmp(date, tableau[i].date_naissance) == 0) {
                        tab[indice2] = tableau[i];
                        indice[indice2] = i;
                        indice2++;
                    }
                    verification = indice2;
                }
            }
            else if (date[0]!='\0' && verification!=nb_ligne){
                for (int i = 0; i < verification; ) { // pas de i++ car bug avec le décalage
                    if (stricmp(date, tab[i].date_naissance) != 0) {
                        // Décaler les éléments suivants pour supprimer l'élément courant
                        for (int j = i; j < verification - 1; j++) {
                            tab[j] = tab[j + 1];
                            indice[j] = indice[j+1];
                        }
                        verification--; // Réduire la taille logique
                        // Ne pas incrémenter i pour revérifier l'élément décalé
                    } else {
                        i++;
                    }
                }

            }

            if (numero[0]!='\0'){
                return indice[0];
            }
            else{
                afficher(verification,tab);
            }
            
            break;
        default:
            printf("Choix incorrect\n");
            break;
    }
    if (option!=5)
    afficher(indice2,tab);
    if (option!=3){
        printf("Entrez le numéro de la ligne sur laquelle vous voulez modifier un élément sinon tapez 0 : ");
        int ligne;
        choix[0] = fgetc(stdin);
        ligne = atoi(choix);
        while (choix[0] < '0' || choix[0] > '5') {
            printf("Sasie hors plage\nRéessayez : ");
            choix[0] = fgetc(stdin);
        }
        if (choix[0] = '0'){
            return select;
        }
        ligne = atoi(choix);
        vider_buffer();
        if (ligne!=0){
        select = indice[ligne - 1];
        }}
        
    return select;
}

void suppression(int* nb_ligne, CLIENT tableau[*nb_ligne]){
    int select = recherche(*nb_ligne,tableau);
    if (select == -1) {
        printf("Aucune sélection valide effectuée.\n");
        return ;
    }
    for (int i = select; i<((*nb_ligne)-1);i++){
        tableau[i] = tableau[i+1];
    }
    *nb_ligne = *nb_ligne - 1;
}


void modif(int nb_ligne, CLIENT tableau[nb_ligne]){
    int select = recherche(nb_ligne, tableau);

    if (select == -1) {
        printf("Aucune sélection valide effectuée.\n");
        return;
    }

    
    printf("Que voulez-vous modifier parmi ses champs ?\n");
    printf("1) Son prénom\n");
    printf("2) Son nom\n");
    printf("3) Sa ville\n");
    printf("4) Le code postal\n");
    printf("5) Num de tel\n");
    printf("6) Adresse mail\n");
    printf("7) Métier\n");
    printf("8) Date de naissance\n");
    printf("Entrez le numéro correspondant : ");
    int option;
    scanf("%d", &option);
    vider_buffer(); // Pour consommer le caractère '\n' laissé par scanf
    char nouveau[50];
    switch (option)
    {
    case 1:
        printf("Entrez le nouveau prénom : ");
        fgets(nouveau, 51, stdin);
        retirerchariot(nouveau);
        strcpy(tableau[select].prenom, nouveau);
        break;
    case 2:
        printf("Entrez le nouveau nom : ");
        fgets(nouveau, 51, stdin);
        retirerchariot(nouveau);
        strcpy(tableau[select].nom, nouveau);
        break;
    case 3:
        printf("Entrez la nouvelle ville : ");
        fgets(nouveau, 51, stdin);
        retirerchariot(nouveau);
        strcpy(tableau[select].ville, nouveau);
        break;
    case 4:
        printf("Entrez le nouveau code postal : ");
        fgets(nouveau, 51, stdin);
        retirerchariot(nouveau);
        strcpy(tableau[select].codep, nouveau);
        break;
    case 5:
        printf("Entrez le nouveau numéro de téléphone : ");
        fgets(nouveau, 51, stdin);
        retirerchariot(nouveau);
        strcpy(tableau[select].tel, nouveau);
        break;
    case 6:
        printf("Entrez la nouvelle adresse mail : ");
        fgets(nouveau, 51, stdin);
        retirerchariot(nouveau);
        strcpy(tableau[select].adrmail, nouveau);
        break;
    case 7:
        printf("Entrez la nouvelle profession : ");
        fgets(nouveau, 51, stdin);
        retirerchariot(nouveau);
        strcpy(tableau[select].profession, nouveau);
        break;
    case 8:
        printf("Entrez la nouvelle date de naissance : ");
        fgets(nouveau, 51, stdin);
        retirerchariot(nouveau);
        strcpy(tableau[select].date_naissance, nouveau);
        break;
    default:
        printf("Erreur dans la saisie\n");
        break;
    }
}


void list_to_file(FILE* file,int taille, CLIENT c[taille]){
    for (int i = 0; i<taille;i++){
        if (strlen(c[i].ville)<=0){
            fprintf(file, "%s,%s,,%s,%s,%s,%s\n",
                    c[i].prenom, c[i].nom,
                    c[i].tel,
                    c[i].adrmail, c[i].profession,
                    c[i].date_naissance);
            }
        else{
            fprintf(file, "%s,%s,%s %s,%s,%s,%s,%s\n",
                    c[i].prenom, c[i].nom,
                    c[i].ville,c[i].codep, c[i].tel,
                    c[i].adrmail, c[i].profession,
                    c[i].date_naissance);
        }
                
    }
}

