#include "../head/head.h"
int nb_op_filtre = 0;
int nb_op_recherche = 0;
int total_lignes(FILE * fichier){
    // Remise à zéro du curseur du fichier pour s'assurer de commencer au début
    rewind(fichier);
    char c;
    int res = 0;
    // Lecture du premier caractère du fichier
    c = fgetc(fichier);
    while (c!=EOF)
    {   // Si un caractère de nouvelle ligne est trouvé, on incrémente le compteur de lignes
        if(c=='\n'){
            res++;
        }
        // Lecture du caractère suivant
        c = fgetc(fichier);
    }
    return res;
}

void enlever_espace_debut(char mot[]) {
    nb_op_recherche = nb_op_recherche + 2 ;
    int indice = 0; // Trouver le premier caractère non-espace
    int length = strlen(mot);

    // Parcours pour trouver le premier caractère alphabétique ou autre non-espace
    nb_op_recherche = nb_op_recherche + 4 ;
    while (indice < length && mot[indice] == ' ') {
        nb_op_recherche = nb_op_recherche + 2 ;
        indice++;
    }

    // Décaler la chaîne si des espaces ont été trouvés
    nb_op_recherche = nb_op_recherche + 1 ;
    if (indice > 0) {
        nb_op_recherche = nb_op_recherche + 3 ;
        for (int i = 0; i <= length - indice; i++) {
            //mot[i] = mot[i + indice]; 1 affectation, 3 calculs
            nb_op_recherche = nb_op_recherche + 4 ;
            mot[i] = mot[i + indice];
            //i++
            nb_op_recherche = nb_op_recherche + 2 ;
        }
    }
}

void enlever_espace_fin(char mot[]) {
    nb_op_recherche = nb_op_recherche + 2 ;
    int length = strlen(mot) - 1;

    // Parcourir la chaîne à l'envers pour trouver le dernier caractère non espace
    nb_op_recherche = nb_op_recherche + 4 ;
    while (length >= 0 && mot[length] == ' ') {
        nb_op_recherche = nb_op_recherche + 2 ;
        length--;
    }

    // Ajouter le terminateur de chaîne après le dernier caractère non espace
    nb_op_recherche = nb_op_recherche + 3 ;
    mot[length + 1] = '\0';
}

void affecter_struct(CLIENT *c1, char option[], char mot[]) {
    // on compare à chaque fois si option est égale à l'autre champ demandé.
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
    // Remise à zéro du curseur du fichier pour s'assurer de commencer au début
    rewind(fichier);
    char info[7][30] = {"prenom","nom","ville","tel","adrmail","profession","date_naissance"};
    CLIENT c1;  // Structure CLIENT qui sera remplie avec les informations lues
    char c;     // Variable pour stocker les caractères lus du fichier
    int indice = 0;  // Indice pour suivre la position dans le mot actuel
    int ligne = 0;   // Compteur pour les lignes lues
    int nb_champ = 0; // Compteur pour suivre quel champ (prénom, nom, etc.) est actuellement rempli
    char mot[50];    // Tableau pour stocker un mot (ou champ) à chaque étape de la lecture
    // Lecture du premier caractère du fichier
    c = fgetc(fichier);
    while(c!=EOF && ligne<nb_ligne){
        // Si un retour à la ligne est rencontré
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
        // Si une virgule est rencontrée (séparateur entre les champs)
        else if (c==','){
            mot[indice] = '\0';
            affecter_struct(&c1,info[nb_champ],mot);
            nb_champ++;
            char mot[50];
            indice = 0 ;
            }
        // Sinon, ajouter le caractère au mot actuel
        else {
            mot[indice] = c;
            indice++;

            }
            // Lecture du caractère suivant
            c=fgetc(fichier);
            c1.id=ligne+1;
        }
        // Séparation des champs 'ville' et 'code postal'
        sep_cdp_ville(nb_ligne,tableau);
    }

void retirerchariot(char mot[]){
    nb_op_recherche = nb_op_recherche + 1 ;
    int i = 0;
    nb_op_recherche = nb_op_recherche + 5 ;
    while (mot[i]!='\n' && mot[i]!='\0'){
        nb_op_recherche = nb_op_recherche + 2 ;
        i++;
        }
    nb_op_recherche = nb_op_recherche + 2 ;
    mot[i]='\0';
}

void nettoyer_char(char mot[]){
    retirerchariot(mot);
    enlever_espace_fin(mot);
    enlever_espace_debut(mot);
}

int stristr(char mot[],  char motif[]) {
    // Si le motif est vide, on considère que la recherche est toujours réussie
    //on calcule motif[0] et on le compare
    nb_op_filtre = nb_op_filtre + 2 ; 
    if (motif[0] == '\0') {
        return 0;  // Retourne 0 car une chaîne vide est toujours trouvée en début de la chaîne principale
    }

    // Longueur du motif
    //on affecte
    nb_op_filtre = nb_op_filtre + 1 ; 
    int motif_len = strlen(motif);

    // Parcours de la chaîne principale (mot)
    nb_op_filtre = nb_op_filtre + 3 ;
    for (int i = 0; mot[i] != '\0'; i++) {
        // on incrémente et on affecte dans i
        nb_op_filtre = nb_op_filtre + 2 ;
        // Comparaison caractère par caractère, en ignorant la casse
        // on effectue une opération TOLOWER dans le meilleur des cas mot[i] est déjà en minuscule
        // dans le pire des cas, on doit faire -32 puis affecter. (Donc dans TOLOWER on a un test(mot[i] donc calcul), un calcul, une affectation) x 2 + la comparaison "==" 
        nb_op_filtre = nb_op_filtre + 9 ; 
        if (tolower(mot[i]) == tolower(motif[0])) {
            // Si le premier caractère correspond, on vérifie le reste de la chaîne
            nb_op_filtre = nb_op_filtre + 1 ; 
            int j = 0;
            nb_op_filtre = nb_op_filtre + 17 ; 
            //      3                  1    2             1   4           1      1          4 
            while (mot[i + j] != '\0' && motif[j] != '\0' && tolower(mot[i + j]) == tolower(motif[j])) {
                nb_op_filtre = nb_op_filtre + 2 ; 
                j++;
            }

            // Si on a trouvé toute la sous-chaîne (fin de motif)
            //on calcule motif[0] et on le compare
            nb_op_filtre = nb_op_filtre + 2 ; 
            if (motif[j] == '\0') {
                return 1;  // Retourne l'indice où la sous-chaîne a été trouvée
            }
        }
    }

    // Si le motif n'a pas été trouvé
    return -1;  // Retourne -1 pour indiquer que le motif n'a pas été trouvé
}


int filtre(int taille, CLIENT tab[taille] ){
    char choix[2],select = -1,option;
    int indice[100];
    int indice2 = 0;
    char motif[40];
    CLIENT tableau[100];
    printf("Entrez un champ approximatif : ");
    fgets(motif,41,stdin);
    // Nettoie la chaîne de caractères (espaces, sauts de ligne)
    nettoyer_char(motif);
    printf("Dans quel champ voulez-vous filtrer l'annuaire ?\n");
    printf("1) Son prénom ?\n");
    printf("2) Son nom ?\n");
    printf("3) Son numero de telephone ?\n");
    printf("4) Son mail ?\n");
    printf("Entrez votre choix ici : ");
    choix[0] = fgetc(stdin);
    // Conversion en entier pour les choix
    option = atoi(choix);
    // Vérifie si le choix est dans la plage correcte, sinon redemande
    while (choix[0] < '1' || choix[0] > '4') {
        printf("Sasie hors plage\nRéessayez : ");
        choix[0] = fgetc(stdin);
    }
    option = atoi(choix);
    getchar();
    switch (option)
    {
    // Filtrage par prénom
    case 1: 
        nb_op_filtre = 0;
        for (int i = 0; i<taille;i++){
            // Si le prenom contient le motif
            if (stristr(tab[i].prenom,motif)==1){
                    indice[indice2] = i;
                    tableau[indice2] = tab[i];
                    indice2++;
            }
        }
        printf("nombre d'operation élementaire pour le tri : %d\n",nb_op_filtre);
        break;
    // Filtrage par nom
    case 2:
        for (int i = 0; i<taille;i++){
            // Si le nom contient le motif
            if (stristr(tab[i].nom,motif)){
                    indice[indice2] = i;
                    tab[indice2] = tableau[i];
                    indice2++;
            }
        }
        break;
    // Filtrage par numéro de téléphone
    case 3:
        for (int i = 0; i<taille;i++){
            // Si le téléphone contient le motif
            if (stristr(tab[i].tel,motif)){
                    indice[indice2] = i;
                    tab[indice2] = tableau[i];
                    indice2++;
            }
        }
        break;
    // Filtrage par adresse mail
    case 4:
        for (int i = 0; i<taille;i++){
            // Si l'adresse mail contient le motif
            if (stristr(tab[i].adrmail,motif)){
                    indice[indice2] = i;
                    tab[indice2] = tableau[i];
                    indice2++;
            }
        }
        break;
    
    default: 
        // Gestion d'une saisie incorrecte
        printf("Erreur de valeur");
        break;
    }
    afficher_avec_lignes(indice2,tableau);
    // Demande à l'utilisateur quel élément de la liste il veut modifier
    printf("Entrez le numéro de la ligne sur laquelle vous voulez modifier un élément sinon tapez 0 : ");
    int ligne_choisie;
    scanf("%d",&ligne_choisie);
    if (ligne_choisie ==0){
        return select;
    }
    // Si un numéro valide est saisi, sélectionne l'élément correspondant
    if (ligne_choisie!=0){
        select = indice[ligne_choisie - 1];
        }

    return select;

    
}

int recherche(int nb_ligne, CLIENT tableau[nb_ligne]) {
    int indice_temporaire[100];
    // 4 affectations ci-dessous, 4 "="
    nb_op_recherche = nb_op_recherche + 4 ;
    int indice2 = 0;
    int indice_final = -1; //l'indice est init à -1 en cas de CLIENT non trouvé
    int option,nb_l;
    char choix[2];
    int nb_ligne_change = nb_ligne;
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
    // Lecture du premier caractère de l'entrée utilisateur en cas d'erreur de saisi, c'est seulement le premier élément qui est retenu
    choix[0] = fgetc(stdin);
    //(calcul de choix[0] puis comparaison) x 2 puis opérateurs logique "ou" utilisé
    nb_op_recherche = nb_op_recherche + 5 ;
    while (choix[0] < '1' || choix[0] > '5') {
        // Si la saisie est hors plage (c'est-à-dire en dehors des chiffres 1-5),
        // un message d'erreur est affiché et une nouvelle saisie est demandée
        printf("Sasie hors plage\nRéessayez : ");
        choix[0] = fgetc(stdin);
    }
    //affectation
    nb_op_recherche = nb_op_recherche + 1 ;
    option = atoi(choix);
    vider_buffer();
    //on prend le pire des cas car on recherche le nb d'opérations élémentaires, le pire des cas est le cas 5
    switch (option) {
        //recherche avec le prénom
        case 1:
            printf("Entrez le prénom de la personne : ");
            fgets(prenom, 41, stdin);
            nettoyer_char(prenom);
            for (int i = 0; i < nb_ligne; i++) {
                // Comparaison du nom saisi avec le nom de la personne dans le tableau
                // stricmp permet une comparaison sans tenir compte de la casse des caractères
                if (stricmp(prenom, tableau[i].prenom) == 0) {
                    // Si les noms correspondent, on ajoute l'indice dans un tableau temporaire
                    indice_temporaire[indice2] = i;
                    // On copie l'élément correspondant dans le tableau temporaire
                    tab[indice2] = tableau[i];
                    // On incrémente l'indice pour le tableau temporaire
                    indice2++;

                }
            }
            // Si aucun résultat n'a été trouvé, indice_final reste à -1
            if (indice2 == 0) {
                printf("Aucun client trouvé avec ce prénom.\n");
                return indice_final; // Retourne -1
            }
            break;
        //recherche avec le nom
        case 2:
            printf("Entrez le nom de la personne : ");
            fgets(nom, 41, stdin);
            nettoyer_char(nom);
            for (int i = 0; i < nb_ligne; i++) {
                if (stricmp(nom, tableau[i].nom) == 0) {
                    // Si les noms correspondent, on ajoute l'indice dans un tableau temporaire
                    indice_temporaire[indice2] = i;
                    // On copie l'élément correspondant dans le tableau temporaire
                    tab[indice2] = tableau[i];
                    // On incrémente l'indice pour le tableau temporaire
                    indice2++;

                }
            }
            // Si aucun résultat n'a été trouvé, indice_final reste à -1
            if (indice2 == 0) {
                printf("Aucun client trouvé avec ce prénom.\n");
                return indice_final; // Retourne -1
            }
            break;
        //recherche avec numéro de téléphone
        case 3:
            value = 1;
            printf("Entrez le numero de telephone de la personne : ");
            fgets(numero, 41, stdin);
            nettoyer_char(numero);
            for (int i = 0; i < nb_ligne && value; i++) {
                if (stricmp(numero, tableau[i].tel) == 0) {
                    // Si les noms correspondent, on ajoute l'indice dans un tableau temporaire
                    indice_temporaire[indice2] = i;
                    // On copie l'élément correspondant dans le tableau temporaire
                    tab[indice2] = tableau[i];
                    // On incrémente l'indice pour le tableau temporaire
                    indice2++;

                }
            }
                
            // Si aucun résultat n'a été trouvé, indice_final reste à -1
            if (indice2 == 0) {
                printf("Aucun client trouvé avec ce prénom.\n");
                return indice_final; // Retourne -1
            }
            else{
                printf("Vous avez rentré sa clé primaire, il a été trouvé !\n");
                return indice_temporaire[0];
            }
            break;
        //recherche avec mail
        case 4:
            printf("Entrez le mail de la personne : ");
            fgets(mail, 41, stdin);
            nettoyer_char(mail);
            for (int i = 0; i < nb_ligne; i++) {
                if (stricmp(mail, tableau[i].adrmail) == 0) {
                    // Si les noms correspondent, on ajoute l'indice dans un tableau temporaire
                    indice_temporaire[indice2] = i;
                    // On copie l'élément correspondant dans le tableau temporaire
                    tab[indice2] = tableau[i];
                    // On incrémente l'indice pour le tableau temporaire
                    indice2++;

                }
            }
            // Si aucun résultat n'a été trouvé, indice_final reste à -1
            if (indice2 == 0) {
                printf("Aucun client trouvé avec ce prénom.\n");
                return indice_final; // Retourne -1
            }
            break;
        //recherche avec cumul d'infos
        case 5: 

            printf("Entrez le prénom de la personne : ");
            fgets(prenom, 41, stdin);
            //nettoyer_char parcours la chaine entière jusqu'à trouver \n 
            //calcul de nb_op_recherche dans nettoyer char.
            nettoyer_char(prenom);
            //comparaison + calcul de prenom[0]
            nb_op_recherche = nb_op_recherche + 2 ;
            if (prenom[0]!='\0'){
                //affectation de i, comparaison
                nb_op_recherche = nb_op_recherche + 2 ;
                for (int i = 0; i < nb_ligne; i++) {
                    //i++ donc 2 opérations + comparaison dans la boucle
                    nb_op_recherche = nb_op_recherche + 3 ;
                    //comparaison puis calcul tableau[i]
                    nb_op_recherche = nb_op_recherche + 2 ;
                    if (stricmp(prenom, tableau[i].prenom) == 0) {
                        // Si les noms correspondent, on ajoute l'indice dans un tableau temporaire
                        //affection + calcul de indice_temporaire[indice2] 
                        nb_op_recherche = nb_op_recherche + 2 ;
                        indice_temporaire[indice2] = i;
                        // On copie l'élément correspondant dans le tableau temporaire
                        //affection + calcul de indice_temporaire[indice2] 
                        nb_op_recherche = nb_op_recherche + 2 ;
                        tab[indice2] = tableau[i];
                        // On incrémente l'indice pour le tableau temporaire
                        //affection + calcul indice2
                        nb_op_recherche = nb_op_recherche + 2 ;
                        indice2++;
                    }
                    //affectation
                    nb_op_recherche = nb_op_recherche + 1;
                    nb_ligne_change = indice2;
                }
            }

            printf("Entrez le nom de la personne : ");
            fgets(nom, 41, stdin);
            //calcul de nb_op_recherche dans nettoyer_char.
            nettoyer_char(nom);
            //comparaison + calcul de nom[0] + 2 opérateurs logiques
            nb_op_recherche = nb_op_recherche + 4 ;
            if (nom[0]!='\0' && nb_ligne_change==nb_ligne){
                for (int i = 0; i < nb_ligne; i++) {
                    //i++ donc 2 opérations + comparaison dans la boucle
                    nb_op_recherche = nb_op_recherche + 3 ;
                    //comparaison puis calcul tableau[i]
                    nb_op_recherche = nb_op_recherche + 2 ;
                    if (stricmp(nom, tableau[i].nom) == 0) {
                        // Si les noms correspondent, on ajoute l'indice dans un tableau temporaire
                        //affection + calcul de indice_temporaire[indice2] 
                        nb_op_recherche = nb_op_recherche + 2 ;
                        indice_temporaire[indice2] = i;
                        // On copie l'élément correspondant dans le tableau temporaire
                        //affection + calcul de indice_temporaire[indice2] 
                        nb_op_recherche = nb_op_recherche + 2 ;
                        tab[indice2] = tableau[i];
                        // On incrémente l'indice pour le tableau temporaire
                        //affection + calcul indice2
                        nb_op_recherche = nb_op_recherche + 2 ;
                        indice2++;
                    }
                    //affectation
                    nb_op_recherche = nb_op_recherche + 1;
                    nb_ligne_change = indice2;
                }
            }
            else if (nom[0]!='\0' && nb_ligne_change!=nb_ligne){
            //comparaison, calculs
            nb_op_recherche = nb_op_recherche + 4 ;
                // affection de i + comparaison
                nb_op_recherche = nb_op_recherche + 2 ;
                for (int i = 0; i < nb_ligne_change; ) { // pas de i++ car bug avec le décalage
                    //calcul de tab[i] + comparaison
                    nb_op_recherche = nb_op_recherche + 2 ;
                    if (stricmp(nom, tab[i].nom) != 0) {
                        // Décaler les éléments suivants pour supprimer l'élément courant
                        //affection de j, comparaison
                        nb_op_recherche = nb_op_recherche + 2 ;
                        for (int j = i; j < nb_ligne_change - 1; j++) {
                            //(calcul de j + 1, de tab[j+1], de tab[j] et affection) x 2
                            nb_op_recherche = nb_op_recherche + 8 ;
                            tab[j] = tab[j + 1];
                            indice_temporaire[j] = indice_temporaire[j+1];

                        }
                        //affection et calcul
                        nb_op_recherche = nb_op_recherche + 2 ;
                        nb_ligne_change--; // Réduire la taille logique
                        // Ne pas incrémenter i pour revérifier l'élément décalé
                    } else {
                        //affection et calcul
                        nb_op_recherche = nb_op_recherche + 2 ;
                        i++;
                    }
                }

            }
            printf("Entrez la ville de la personne : ");
            fgets(ville, 41, stdin);
            nettoyer_char(ville);
            //calcul de ville[0], 2 comparaison et une opération logique
            nb_op_recherche = nb_op_recherche + 4;
            if (ville[0]!='\0' && nb_ligne_change==nb_ligne){
                for (int i = 0; i < nb_ligne; i++) {
                    if (stricmp(ville, tableau[i].ville) == 0) {
                        // Si les noms correspondent, on ajoute l'indice dans un tableau temporaire
                        indice_temporaire[indice2] = i;
                        // On copie l'élément correspondant dans le tableau temporaire
                        tab[indice2] = tableau[i];
                        // On incrémente l'indice pour le tableau temporaire
                        indice2++;
                    }
                    nb_ligne_change = indice2;
                }
            }
            else if (ville[0]!='\0' && nb_ligne_change!=nb_ligne){
                for (int i = 0; i < nb_ligne_change; ) { // pas de i++ car bug avec le décalage
                    if (stricmp(ville, tab[i].ville) != 0) {
                        // Décaler les éléments suivants pour supprimer l'élément courant
                        for (int j = i; j < nb_ligne_change - 1; j++) {
                            tab[j] = tab[j + 1];
                            indice_temporaire[j] = indice_temporaire[j+1];

                        }
                        nb_ligne_change--; // Réduire la taille logique
                        // Ne pas incrémenter i pour revérifier l'élément décalé
                    } else {
                        i++;
                    }
                }

            }
            printf("Entrez le code postal de la personne : ");
            fgets(code, 41, stdin);
            nettoyer_char(code);
            //calcul de code[0], 2 comparaison et une opération logique
            nb_op_recherche = nb_op_recherche + 4;
            if (code[0]!='\0' && nb_ligne_change==nb_ligne){
                for (int i = 0; i < nb_ligne; i++) {
                    if (stricmp(code, tableau[i].codep) == 0) {
                        // Si les noms correspondent, on ajoute l'indice dans un tableau temporaire
                        indice_temporaire[indice2] = i;
                        // On copie l'élément correspondant dans le tableau temporaire
                        tab[indice2] = tableau[i];
                        // On incrémente l'indice pour le tableau temporaire
                        indice2++;
                    }
                    nb_ligne_change = indice2;
                }
            }
            else if (code[0]!='\0' && nb_ligne_change!=nb_ligne){
                for (int i = 0; i < nb_ligne_change; ) { // pas de i++ car bug avec le décalage
                    if (stricmp(code, tab[i].codep) != 0) {
                        // Décaler les éléments suivants pour supprimer l'élément courant
                        for (int j = i; j < nb_ligne_change - 1; j++) {
                            tab[j] = tab[j + 1];
                            indice_temporaire[j] = indice_temporaire[j+1];
                        }
                        nb_ligne_change--; // Réduire la taille logique
                        // Ne pas incrémenter i pour revérifier l'élément décalé
                    } else {
                        i++;
                    }
                }

            }
            printf("Entrez le numéro de téléphone : ");
            fgets(numero, 41, stdin);
            nettoyer_char(numero);
            //calcul de numero[0], 2 comparaison et une opération logique
            nb_op_recherche = nb_op_recherche + 4;
            if (numero[0]!='\0' && nb_ligne_change==nb_ligne){
                for (int i = 0; i < nb_ligne; i++) {
                    if (stricmp(numero, tableau[i].tel) == 0) {
                        // Si les noms correspondent, on ajoute l'indice dans un tableau temporaire
                        indice_temporaire[indice2] = i;
                        // On copie l'élément correspondant dans le tableau temporaire
                        tab[indice2] = tableau[i];
                        // On incrémente l'indice pour le tableau temporaire
                        indice2++;
                    }
                    nb_ligne_change = indice2;
                }
            }
            else if (numero[0]!='\0' && nb_ligne_change!=nb_ligne){
                for (int i = 0; i < nb_ligne_change; ) { // pas de i++ car bug avec le décalage
                    if (stricmp(numero, tab[i].tel) != 0) {
                        // Décaler les éléments suivants pour supprimer l'élément courant
                        for (int j = i; j < nb_ligne_change - 1; j++) {
                            tab[j] = tab[j + 1];
                            indice_temporaire[j] = indice_temporaire[j+1];
                        }
                        nb_ligne_change--; // Réduire la taille logique
                        // Ne pas incrémenter i pour revérifier l'élément décalé
                    } else {
                        i++;
                    }
                }

            }
            printf("Entrez l'adresse mail : ");
            fgets(mail, 41, stdin);
            nettoyer_char(mail);
            //calcul de mail[0], 2 comparaison et une opération logique
            nb_op_recherche = nb_op_recherche + 4;
            if (mail[0]!='\0' && nb_ligne_change==nb_ligne){
                for (int i = 0; i < nb_ligne; i++) {
                    if (stricmp(mail, tableau[i].adrmail) == 0) {
                        // Si les noms correspondent, on ajoute l'indice dans un tableau temporaire
                        indice_temporaire[indice2] = i;
                        // On copie l'élément correspondant dans le tableau temporaire
                        tab[indice2] = tableau[i];
                        // On incrémente l'indice pour le tableau temporaire
                        indice2++;
                    }
                    nb_ligne_change = indice2;
                }
            }
            else if (mail[0]!='\0' && nb_ligne_change!=nb_ligne){
                for (int i = 0; i < nb_ligne_change; ) { // pas de i++ car bug avec le décalage
                    if (stricmp(mail, tab[i].adrmail) != 0) {
                        // Décaler les éléments suivants pour supprimer l'élément courant
                        for (int j = i; j < nb_ligne_change - 1; j++) {
                            tab[j] = tab[j + 1];
                            indice_temporaire[j] = indice_temporaire[j+1];
                        }
                        nb_ligne_change--; // Réduire la taille logique
                        // Ne pas incrémenter i pour revérifier l'élément décalé
                    } else {
                        i++;
                    }
                }

            }
            printf("Entrez le métier : ");
            fgets(metier, 21, stdin);
            nettoyer_char(metier);
            //calcul de metier[0], 2 comparaison et une opération logique
            nb_op_recherche = nb_op_recherche + 4;
            if (metier[0]!='\0' && nb_ligne_change==nb_ligne){
                for (int i = 0; i < nb_ligne; i++) {
                    if (stricmp(metier, tableau[i].profession) == 0) {
                        // Si les noms correspondent, on ajoute l'indice dans un tableau temporaire
                        indice_temporaire[indice2] = i;
                        // On copie l'élément correspondant dans le tableau temporaire
                        tab[indice2] = tableau[i];
                        // On incrémente l'indice pour le tableau temporaire
                        indice2++;
                    }
                    nb_ligne_change = indice2;
                }
            }
            else if (metier[0]!='\0' && nb_ligne_change!=nb_ligne){
                for (int i = 0; i < nb_ligne_change; ) { // pas de i++ car bug avec le décalage
                    if (stricmp(metier, tab[i].profession) != 0) {
                        // Décaler les éléments suivants pour supprimer l'élément courant
                        for (int j = i; j < nb_ligne_change - 1; j++) {
                            tab[j] = tab[j + 1];
                            indice_temporaire[j] = indice_temporaire[j+1];
                        }
                        nb_ligne_change--; // Réduire la taille logique
                        // Ne pas incrémenter i pour revérifier l'élément décalé
                    } else {
                        i++;
                    }
                }

            }
            printf("Entrez la date de naissance : ");
            fgets(date, 21, stdin);
            nettoyer_char(date);
            //calcul de date[0], 2 comparaison et une opération logique
            nb_op_recherche = nb_op_recherche + 4;
            if (date[0]!='\0' && nb_ligne_change==nb_ligne){
                for (int i = 0; i < nb_ligne; i++) {
                    if (stricmp(date, tableau[i].date_naissance) == 0) {
                        // Si les noms correspondent, on ajoute l'indice dans un tableau temporaire
                        indice_temporaire[indice2] = i;
                        // On copie l'élément correspondant dans le tableau temporaire
                        tab[indice2] = tableau[i];
                        // On incrémente l'indice pour le tableau temporaire
                        indice2++;
                    }
                    nb_ligne_change = indice2;
                }
            }
            else if (date[0]!='\0' && nb_ligne_change!=nb_ligne){
                for (int i = 0; i < nb_ligne_change; ) { // pas de i++ car bug avec le décalage
                    if (stricmp(date, tab[i].date_naissance) != 0) {
                        // Décaler les éléments suivants pour supprimer l'élément courant
                        for (int j = i; j < nb_ligne_change - 1; j++) {
                            tab[j] = tab[j + 1];
                            indice_temporaire[j] = indice_temporaire[j+1];
                        }
                        nb_ligne_change--; // Réduire la taille logique
                        // Ne pas incrémenter i pour revérifier l'élément décalé
                    } else {
                        i++;
                    }
                }

            }

            if (numero[0]!='\0'){
                printf("Vous avez rentré sa clé primaire, il a été trouvé !\n");
                return indice_temporaire[0];
            }
            else{
                afficher_avec_lignes(nb_ligne_change,tab);
            }
            
            break;
        default:
            printf("Choix incorrect\n");
            break;
    }
    //comparaison
    nb_op_recherche = nb_op_recherche + 1;
    if (option!=5)
    afficher_avec_lignes(indice2,tab);
    //comparaison
    nb_op_recherche = nb_op_recherche + 1;
    if (option!=3){
        printf("Entrez le numéro de la ligne sur laquelle vous voulez modifier un élément sinon tapez 0 : ");
        int ligne;
        scanf("%d",&ligne);
        //comparaison
        nb_op_recherche = nb_op_recherche + 1;
        if (ligne != 0){
        //affectation, calcul de ligne - 1 et calcul de indice_temporaire[ligne - 1]
        nb_op_recherche = nb_op_recherche + 3;
        indice_final = indice_temporaire[ligne - 1];
            }
        }
        
    return indice_final;
}

void suppression(int* nb_ligne, CLIENT tableau[*nb_ligne]){
    // Appel à la fonction de recherche pour obtenir l'élément à supprimer
    int select = recherche(*nb_ligne,tableau);
    if (select == -1) {
        printf("Aucune sélection valide effectuée.\n");
        // On quitte la fonction sans rien faire
        return ;
    }
    // Déplacement des éléments après l'élément sélectionné pour combler l'espace
    // Le tableau est réorganisé pour "supprimer" l'élément
    for (int i = select; i<((*nb_ligne)-1);i++){
        tableau[i] = tableau[i+1];
    }
    // Réduction de la taille du tableau (enlevant l'élément)
    *nb_ligne = *nb_ligne - 1;
}


void modif(int nb_ligne, CLIENT tableau[nb_ligne]){
    char choix[2];
    int select = -1, vrai_choix;
    printf("Comment voulez-vous retrouver la personne ?\n");
    printf("1) Par recherche (avec un champ précis)\n");
    printf("2) Par filtre (avec un champ approximatif)\n");
    printf("Entrez votre choix : ");
    choix[0] = fgetc(stdin);
    while (choix[0] < '1' || choix[0] > '2') {
        printf("Sasie hors plage\nRéessayez : ");
        choix[0] = fgetc(stdin);
    }
    vrai_choix = atoi(choix);
    vider_buffer();
    switch (vrai_choix)
    {
    case 1:
        select = recherche(nb_ligne, tableau);
        printf("nb_op_recherche est %d\n",nb_op_recherche);
        break;
    case 2:
        select = filtre(nb_ligne, tableau);
        break;
    default:
        printf("Erreur dans la valeur");
        break;
    }

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
        nettoyer_char(nouveau);
        strcpy(tableau[select].prenom, nouveau);
        break;
    case 2:
        printf("Entrez le nouveau nom : ");
        fgets(nouveau, 51, stdin);
        nettoyer_char(nouveau);
        strcpy(tableau[select].nom, nouveau);
        break;
    case 3:
        printf("Entrez la nouvelle ville : ");
        fgets(nouveau, 51, stdin);
        nettoyer_char(nouveau);
        strcpy(tableau[select].ville, nouveau);
        break;
    case 4:
        printf("Entrez le nouveau code postal : ");
        fgets(nouveau, 51, stdin);
        nettoyer_char(nouveau);
        strcpy(tableau[select].codep, nouveau);
        break;
    case 5:
        printf("Entrez le nouveau numéro de téléphone : ");
        fgets(nouveau, 51, stdin);
        nettoyer_char(nouveau);
        strcpy(tableau[select].tel, nouveau);
        break;
    case 6:
        printf("Entrez la nouvelle adresse mail : ");
        fgets(nouveau, 51, stdin);
        nettoyer_char(nouveau);
        strcpy(tableau[select].adrmail, nouveau);
        break;
    case 7:
        printf("Entrez la nouvelle profession : ");
        fgets(nouveau, 51, stdin);
        nettoyer_char(nouveau);
        strcpy(tableau[select].profession, nouveau);
        break;
    case 8:
        printf("Entrez la nouvelle date de naissance : ");
        fgets(nouveau, 51, stdin);
        nettoyer_char(nouveau);
        strcpy(tableau[select].date_naissance, nouveau);
        break;
    default:
        printf("Erreur dans la saisie\n");
        break;
    }
}


void list_to_file(FILE* file,int taille, CLIENT tableau[taille]){
    for (int i = 0; i<taille;i++){
        if (strlen(tableau[i].ville)<=0){
            fprintf(file, "%s,%s,,%s,%s,%s,%s\n",
                    tableau[i].prenom, tableau[i].nom,
                    tableau[i].tel,
                    tableau[i].adrmail, tableau[i].profession,
                    tableau[i].date_naissance);
            }
        else{
            fprintf(file, "%s,%s,%s %s,%s,%s,%s,%s\n",
                    tableau[i].prenom, tableau[i].nom,
                    tableau[i].ville,tableau[i].codep, tableau[i].tel,
                    tableau[i].adrmail, tableau[i].profession,
                    tableau[i].date_naissance);
        }
                
    }
}

