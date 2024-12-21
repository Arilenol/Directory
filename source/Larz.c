#include "../head/head.h"

int total_lignes(FILE * fichier){
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
    /*
    else if (stricmp(option, "codep") == 0) {
        strcpy(c1->codep, mot);
    } */
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
            //printf("%s et mot : %s",info[nb_champ],mot);
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
        }
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

//FONCTION EN DEVELOPPEMENT 
void modif(FILE* fichier){
    int nb_ligne = total_lignes(fichier);
    rewind(fichier);
    CLIENT tableau[nb_ligne];
    mot_par_mot(fichier,nb_ligne,tableau);
    printf("Qui souhaitez vous modifier ? Entrez son prenom : ");
    char prenom[20];
    fgets(prenom,21,stdin);
    retirerchariot(prenom);
    FILE* fic2 = fopen("../head/fichiertmp.csv","w");
    for (int i = 0; i<nb_ligne;i++){
        if (stricmp(prenom, tableau[i].prenom) == 0){
            fprintf(fic2,"%s,",tableau[i].prenom);
            fprintf(fic2,"%s,",tableau[i].nom);
            fprintf(fic2,"%s,",tableau[i].ville);
            //fprintf(fic2,"%s,",tableau[i].codep);   A RECTIFIER ICI
            fprintf(fic2,"%s,",tableau[i].tel);
            fprintf(fic2,"%s,",tableau[i].adrmail);
            fprintf(fic2,"%s,",tableau[i].profession);
            fprintf(fic2,"%s\n",tableau[i].date_naissance);
        }

    }
    fclose(fic2);
    FILE* fic = fopen("../head/fichiertmp.csv","r");
    printf("Entrez le numero de la ligne sur laquelle vous voulez modifier un element\n");
    lire_carac(fic);
    /*
    
        if (stricmp(option, "prenom") == 0) {
            
        } 
        else if (stricmp(option, "nom") == 0) {
            
        } 
        else if (stricmp(option, "ville") == 0) {
            
        
        } 
        else if (stricmp(option, "codep") == 0) {
            
        } 
        else if (stricmp(option, "tel") == 0) {
            
        } 
        else if (stricmp(option, "adrmail") == 0) {
            
        } 
    
        else if (stricmp(option, "profession") == 0) {
            
        } 
        
        else if (stricmp(option, "date_naissance") == 0) {
            
        } 
    
        else{
            printf("Le choix rentré n'est pas possible");
        }

    }
        
*/
}
// T'ammuse pas a mettre des main un pau partout ça fait capauter le compilateur
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
