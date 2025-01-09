//
// Created by Leny_ARIZZI on 27/11/2024.
//
#include "../head/head.h"

int main(void) {
    system("chcp 65001");
    system("cls");
    char  choix[2];
    int option;
    char annuaire[7][30] = {"annuaire à 10 entrée", "annuaire à 50 entrée", "annuaire à 100 entrée",
                            "annuaire à 500 entrée", "annuaire à 1000 entrée", "annuaire à 5000 entrée",
                            "Terminer"};
    do{
    printf("Quel fichier voulez vous consulter\n");//affichage des option
    for (int i = 0; i < 7; i++) {
        printf("%d) %s\n", i + 1, annuaire[i]);
    }
    printf("\nEntrez le chiffre correspondant au fichier que vous souhaitez ouvrir : ");
    scanf("%c", &choix);//saisie utilisateur sécurisé
    option = atoi(choix);
    while (choix[0] < '1' || choix[0] > '7' ) {
        vider_buffer();
        printf("Sasie hors plage\nRéessayez : ");
        scanf("%c", &choix);
        option = atoi(choix);
    }
    vider_buffer();
    switch (option) {// access au fichier demander par l'utilisateur
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
}while(option != 7);
    return 0;
}