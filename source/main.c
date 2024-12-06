//
// Created by Leny_ARIZZI on 27/11/2024.
//
#include "../head/head.h"
int main(void){
    system("chcp 65001");
    system("cls");
    char possible[NB_PROP][10]={"Consulter","Ajouter"};
    int choix;
    FILE* fic = NULL;int nb_ligne;
    char annuaire[6][30]={"annuaire à 10 entrée","annuaire à 50 entrée","annuaire à 100 entrée","annuaire à 500 entrée","annuaire à 1000 entrée","annuaire à 5000 entrée"};
    printf("Que voulez-faire parmi les actions suivantes ? \n");
    for (int i = 0; i<NB_PROP; i++){
        printf("%d) %s\n",i+1,possible[i]);
    }
    printf("\nEntrez le chiffre correspondant à l'action que vous souhaitez réaliser : ");
    scanf("%d",&choix);
    while (choix<1 || choix >NB_PROP){
        printf("Sasie hors plage\nRéessayez : ");
        scanf("%d",&choix);
    }

    switch (choix)
    {
    case 1:
        ouverture(6,30,annuaire,fic);
         nb_ligne = total_lignes(fic);
            fermeture(fic);
        break;
    
    case 2:
        ouverture(6,30,annuaire,fic);
        ajout(fic);
        fermeture(fic);
        break;

    default:
        printf("Valeur erronée");
        break;
    }

    return 0;
}