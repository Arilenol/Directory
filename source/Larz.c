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

void lire_carac(FILE* f){
    char c;
    c = fgetc(f);

    while(c!=EOF){
        printf("%c",c);
        c=fgetc(f);
    }
    fclose(f);

}
void retirerchariot(char mot[]){
    int i = 0;
    while (mot[i]!='\n' && mot[i]!='\0'){
        i++;
        }
    
    mot[i]='\0';
}

void poser_curseur(FILE* fichier, int ligne){
    char c;
    int indice = 1;
    c = fgetc(fichier);
    while(c!=EOF && indice < ligne){
        if (c=='\n'){
            indice++;
        }
        c=fgetc(fichier);
    }
    
}

//FONCTION terminée, en attente d'un point ensemble pour rectfier 2-3 choses
int recherche(int nb_ligne, CLIENT tableau[nb_ligne]) {
    int indice[nb_ligne];
    int indice2 = 0;
    int select = -1; //initialisation par défaut
    int choix;
    int verification = nb_ligne;
    char prenom[40], nom[40], ville[40], code[40], mail[40], numero[40], metier[40], date[20];
    int value;
    CLIENT tab[nb_ligne];
    FILE* fic2;
    FILE* fic;
    printf("Par quel moyen voulez-vous retrouver la personne\n");
    printf("1) Son prénom ?\n");
    printf("2) Son nom ?\n");
    printf("3) Son numero de telephone ?\n");
    printf("4) Son mail ?\n");
    printf("5) Par cumul d'info ?\n");
    printf("Entrez votre choix ici : ");
    scanf("%d", &choix);
    vider_buffer(); //avale le \n laissé par scanf


    switch (choix) {
        case 1:
            printf("Entrez le prénom de la personne : ");
            fgets(prenom, 41, stdin);
            retirerchariot(prenom);
            fic2 = fopen("../head/fichiertmp.csv", "w");
            for (int i = 0; i < nb_ligne; i++) {
                if (stricmp(prenom, tableau[i].prenom) == 0) {
                    indice[indice2++] = i;
                    fprintf(fic2, "%s,%s,%s,%s,%s,%s,%s\n",
                            tableau[i].prenom, tableau[i].nom,
                            tableau[i].ville, tableau[i].tel,
                            tableau[i].adrmail, tableau[i].profession,
                            tableau[i].date_naissance);
                }
            }
            fclose(fic2);
            // Si aucun résultat n'a été trouvé, select reste à -1
            if (indice2 == 0) {
                printf("Aucun client trouvé avec ce prénom.\n");
                remove("../head/fichiertmp.csv");
                return select; // Retourne -1
            }
            fic = fopen("../head/fichiertmp.csv", "r");
            printf("Parmi ces éléments : \n");
            lire_carac(fic);
            fclose(fic);
            remove("../head/fichiertmp.csv");
            break;
        
        case 2:
            printf("Entrez le nom de la personne : ");
            fgets(nom, 41, stdin);
            retirerchariot(nom);
            fic2 = fopen("../head/fichiertmp.csv", "w");
            for (int i = 0; i < nb_ligne; i++) {
                if (stricmp(nom, tableau[i].nom) == 0) {
                    indice[indice2++] = i;
                    fprintf(fic2, "%s,%s,%s,%s,%s,%s,%s\n",
                            tableau[i].prenom, tableau[i].nom,
                            tableau[i].ville, tableau[i].tel,
                            tableau[i].adrmail, tableau[i].profession,
                            tableau[i].date_naissance);
                }
            }
            fclose(fic2);
            // Si aucun résultat n'a été trouvé, select reste à -1
            if (indice2 == 0) {
                printf("Aucun client trouvé avec ce nom.\n");
                remove("../head/fichiertmp.csv");
                return select; // Retourne -1
            }
            fic = fopen("../head/fichiertmp.csv", "r");
            printf("Parmi ces éléments : \n");
            lire_carac(fic);
            fclose(fic);
            remove("../head/fichiertmp.csv");
            break;

        case 3:
            value = 1;
            printf("Entrez le numero de telephone de la personne : ");
            fgets(numero, 41, stdin);
            retirerchariot(numero);
            for (int i = 0; i < nb_ligne && value; i++) {
                if (stricmp(numero, tableau[i].tel) == 0) {
                    value = 0;
                    indice[indice2++] = i;
                    fprintf(fic2, "%s,%s,%s,%s,%s,%s,%s\n",
                            tableau[i].prenom, tableau[i].nom,
                            tableau[i].ville, tableau[i].tel,
                            tableau[i].adrmail, tableau[i].profession,
                            tableau[i].date_naissance);
                }
            }
            // Si aucun résultat n'a été trouvé, select reste à -1
            if (indice2 == 0) {
                printf("Aucun client trouvé avec ce numéro de téléphone.\n");
                remove("../head/fichiertmp.csv");
                return select; // Retourne -1
            }
            select = indice[0];
            break;
        case 4:
            printf("Entrez le mail de la personne : ");
            fgets(mail, 41, stdin);
            retirerchariot(mail);
            fic2 = fopen("../head/fichiertmp.csv", "w");
            for (int i = 0; i < nb_ligne; i++) {
                if (stricmp(mail, tableau[i].adrmail) == 0) {
                    indice[indice2++] = i;
                    fprintf(fic2, "%s,%s,%s,%s,%s,%s,%s\n",
                            tableau[i].prenom, tableau[i].nom,
                            tableau[i].ville, tableau[i].tel,
                            tableau[i].adrmail, tableau[i].profession,
                            tableau[i].date_naissance);
                }
            }
            fclose(fic2);
            // Si aucun résultat n'a été trouvé, select reste à -1
            if (indice2 == 0) {
                printf("Aucun client trouvé avec ce mail.\n");
                remove("../head/fichiertmp.csv");
                return select; // Retourne -1
            }
            fic = fopen("../head/fichiertmp.csv", "r");
            printf("Parmi ces éléments : \n");
            lire_carac(fic);
            fclose(fic);
            remove("../head/fichiertmp.csv");
            break;
        case 5:
            
            printf("Entrez le prénom de la personne : ");
            fgets(prenom, 41, stdin);
            retirerchariot(prenom);
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
            if (ville[0]!='\0' && verification==nb_ligne){
                for (int i = 0; i < nb_ligne; i++) {
                    printf("%s\n", tableau[i].tel);
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
                fic = fopen("../head/fichiertmp.csv", "w");
                for (int i = 0; i<verification;i++){
                    fprintf(fic, "%s,%s,%s,%s,%s,%s,%s,%s\n",
                            tab[i].prenom, tab[i].nom,
                            tab[i].ville,tab[i].codep, tab[i].tel,
                            tab[i].adrmail, tab[i].profession,
                            tab[i].date_naissance);
                }
            }
            fclose(fic);
            fic = fopen("../head/fichiertmp.csv", "r");
            printf("Parmi ces éléments : \n");
            lire_carac(fic);
            fclose(fic);
            remove("../head/fichiertmp.csv");
            

            break;

        default:
            printf("Choix incorrect\n");
            break;
    }
    if (choix!=3){
        printf("Entrez le numéro de la ligne sur laquelle vous voulez modifier un élément : ");
        int ligne;
        scanf("%d", &ligne);
        select = indice[ligne - 1];
        }
    return select;
}

void suppression(int* nb_ligne, CLIENT tableau[*nb_ligne]){
    int select = recherche_nom(*nb_ligne,tableau);
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
    getchar(); // Pour consommer le caractère '\n' laissé par scanf
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




void list_to_file(int taille, CLIENT c[taille]){
    FILE* fic = fopen("../head/test.csv","w");
    for (int i = 0; i<taille;i++){
            fprintf(fic, "%s,%s,%s %s,%s,%s,%s,%s\n",
                    c[i].prenom, c[i].nom,
                    c[i].ville,c[i].codep, c[i].tel,
                    c[i].adrmail, c[i].profession,
                    c[i].date_naissance);
                
    }
    fclose(fic);
}

