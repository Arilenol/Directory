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
void modif(int nb_ligne, CLIENT tableau[nb_ligne]){
    int indice[15];
    int indice2 = 0;
    int select = -1; // Initialisation par défaut
    printf("Comment voulez-vous modifier ?\n");
    printf("1) Par son numéro de téléphone (clé primaire) ?\n");
    printf("2) Par son prénom ?\n");
    int choix;
    scanf("%d", &choix);
    getchar(); // Consomme le caractère '\n' laissé par scanf
    switch (choix)
    {
    case 1:
        printf("Entrez son numéro de téléphone (espacez les nombres par des points) : ");
        char num[14];
        scanf("%s", num);
        for (int i = 0; i < nb_ligne; i++) {
            if (stricmp(num, tableau[i].tel) == 0) {
                select = i;
            }
        }

        break;

    case 2:
        printf("Entrez le prénom de la personne : ");
        char prenom[20];
        fgets(prenom, 21, stdin);
        retirerchariot(prenom);
        FILE* fic2 = fopen("../head/fichiertmp.csv", "w");
        for (int i = 0; i < nb_ligne; i++) {
            printf("%s et %s \n",prenom, tableau[i].prenom);
            if (stricmp(prenom, tableau[i].prenom) == 0) {
                printf("1");
                indice[indice2] = i;
                indice2++;
                fprintf(fic2, "%s,", tableau[i].prenom);
                fprintf(fic2, "%s,", tableau[i].nom);
                fprintf(fic2, "%s,", tableau[i].ville);
                fprintf(fic2, "%s,", tableau[i].tel);
                fprintf(fic2, "%s,", tableau[i].adrmail);
                fprintf(fic2, "%s,", tableau[i].profession);
                fprintf(fic2, "%s\n", tableau[i].date_naissance);
            }
        }
        fclose(fic2);
        FILE* fic = fopen("../head/fichiertmp.csv", "r");
        printf("Parmi ces éléments : \n");
        lire_carac(fic);
        fclose(fic);
        remove("../head/fichiertmp.csv");
        printf("Entrez le numéro de la ligne sur laquelle vous voulez modifier un élément : ");
        int ligne;
        scanf("%d", &ligne);
        select = indice[ligne - 1];
        break;
    default:
        printf("Erreur lors de la saisie\n");
        return; // On sort de la fonction si une erreur survient
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
        fprintf(fic,"%s,",c[i].prenom);
        fprintf(fic,"%s,",c[i].nom);
        fprintf(fic,"%s,",c[i].ville);
        fprintf(fic,"%s,",c[i].tel);
        fprintf(fic,"%s,",c[i].adrmail);
        fprintf(fic,"%s,",c[i].profession);
        fprintf(fic,"%s",c[i].date_naissance);
        fprintf(fic, "\n");
    }
    fclose(fic);
}
        

// T'ammuse pas a mettre des main un pau partout ça fait capauter le compilateur
// Effectivement, c'était pour test de base, pour moi 
/*
int main(void){ 
    
    FILE* fic = fopen(chemin,"r");
    if (fic==NULL){
        printf("Echec ouverture du fichier \n");
        exit(EXIT_FAILURE);
    }
      
    CLIENT tableau[500];
    mot_par_mot(fic,500,tableau);
    printf("%s",tableau[499].prenom);
    
    
    fclose(fic);

    return EXIT_SUCCESS;
}
*/
