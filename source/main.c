//
// Created by Leny_ARIZZI on 27/11/2024.
//
#include "../head/head.h"

int main(void) {
    system("chcp 65001");
    system("cls");
    int choix;
    char annuaire[7][30] = {"annuaire à 10 entrée", "annuaire à 50 entrée", "annuaire à 100 entrée",
                            "annuaire à 500 entrée", "annuaire à 1000 entrée", "annuaire à 5000 entrée",
                            "Terminer"};
    do{
    printf("Quel fichier voulez vous consulter\n");
    for (int i = 0; i < 7; i++) {
        printf("%d) %s\n", i + 1, annuaire[i]);
    }
    printf("\nEntrez le chiffre correspondant au fichier que vous souhaitez ouvrir : ");
    scanf("%d", &choix);
    while (choix < 1 || choix > 7) {
        printf("Sasie hors plage\nRéessayez : ");
        scanf("%d", &choix);
    }
    switch (choix) {
        case (1):
            system("cls");
            ouverture("../benchmark_1/annuaire_10_entrees.csv");
            break;
        case (2):
            system("cls");
            ouverture("../benchmark_1/annuaire_50_entrees.csv");
            break;
        case (3):
            system("cls");
            ouverture("../benchmark_1/annuaire_100_entrees.csv");
            break;
        case (4):
            system("cls");
            ouverture("../benchmark_1/annuaire_500_entrees.csv");
            break;
        case (5):
            system("cls");
            ouverture("../benchmark_1/annuaire_1000_entrees.csv");
            break;
        case (6):
            system("cls");
            ouverture("../benchmark_1/annuaire_5000_entrees.csv");
            break;
        case (7):
            system("cls");
            break;
        default:
            printf("erreur");
    }
}while(choix != 7);
    return 0;
}