//
// Created by Leny_ARIZZI on 27/11/2024.
//
#include "../head/head.h"
/*
int main(void){
    system("chcp 65001");
    system("cls");
    char possible[5][50]={"Consulter","Ajouter","Consulter les Client avec données manquantes","Consulter un tableau trié","Terminer"};
    int choix;
    FILE* fic = NULL;
    int nb_ligne;
    char annuaire[7][30]={"annuaire à 10 entrée","annuaire à 50 entrée","annuaire à 100 entrée","annuaire à 500 entrée","annuaire à 1000 entrée","annuaire à 5000 entrée","revenir en arrière"};
    do{
        printf("\n\nQue voulez-faire parmi les actions suivantes ? \n");
        for (int i = 0; i < 5; i++) {
            printf("%d) %s\n", i + 1, possible[i]);
        }
        printf("\nEntrez le chiffre correspondant à l'action que vous souhaitez réaliser : ");
        scanf("%d", &choix);
        while (choix < 1 || choix > 5) {
            printf("Sasie hors plage\nRéessayez : ");
            scanf("%d", &choix);
        }
        switch (choix) {
            case (1):
                system("cls");
                fic = ouverture(7, 30, annuaire, fic, "r");
                afficher(fic);
                printf("\nVoulez afficher une ligne en particulier\n1) 0ui\n2) Non\n");
                scanf("%d",&choix);
                while (choix < 1 || choix > 2) {
                    printf("Sasie hors plage\nRéessayez : ");
                    scanf("%d", &choix);
                }
                if(choix == 1){
                    afficher_ligne(fic);
                }
                fermeture(fic);
                break;

            case (2):
                system("cls");
                fic = ouverture(7, 30, annuaire, fic, "a+");
                ajout(fic);
                afficher(fic);
                fermeture(fic);
                break;

            case (3):
                system("cls");
                fic = ouverture(7, 30, annuaire, fic, "r");
                afficher_manq(fic);
                fermeture(fic);
                break;
            case(4):
                system("cls");
                fic = ouverture(7, 30, annuaire, fic, "r");
                tri_tableau(fic);
                fermeture(fic);
                break;
            case (5):
                system("cls");
                break;

            default:
                printf("Valeur erronée");
                break;
        }
        system("cls");
    }while(choix != 5);
    return 0;
}

*/