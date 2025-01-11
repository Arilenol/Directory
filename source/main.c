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

/* Boite noire :
void test_functions() {
    // Test de `ouvrir`
    char chemin[] = "../benchmark_1/annuaire_10_entrees.csv";
    ouverture(chemin); // Pas de retour, validation manuelle possible

    // Test de `ajout`
    FILE *fic = fopen("test_fichier.txt", "w+");
    assert(fic != NULL);
    ajout(fic);
    fclose(fic);

    // Test de `total_lignes`
    fic = fopen("test_fichier.txt", "r");
    assert(fic != NULL);
    fprintf(fic, "Ligne 1\nLigne 2\n");
    rewind(fic);
    assert(total_lignes(fic) == 2);
    fclose(fic);

    // Test de `afficher`
    CLIENT clients[2] = {{.nom = "Client1"}, {.nom = "Client2"}};
    afficher(2, clients);

    // Test de `vider_buffer`
    vider_buffer();

    // Test de `retirer_chariot`
    char mot1[] = "Hello\n";
    retirer_chariot(mot1);
    assert(strcmp(mot1, "Hello") == 0);

    // Test de `afficher_manq`
    CLIENT clients2[2] = {{.nom = "", .age = 0}, {.nom = "Valid", .age = 20}};
    afficher_manq(2, clients2);

    // Test de `mot_par_mot`
    fic = fopen("test_fichier.txt", "w+");
    fprintf(fic, "Nom1,20\nNom2,25\n");
    rewind(fic);
    mot_par_mot(fic, 2, clients);
    assert(strcmp(clients[0].nom, "Nom1") == 0);
    assert(clients[0].age == 20);
    fclose(fic);

    // Test de `affecter_struct`
    CLIENT c;
    affecter_struct(&c, "nom", "ClientX");
    assert(strcmp(c.nom, "ClientX") == 0);

    // Test de `sep_cdp_ville`
    CLIENT clients3[1] = {{.adresse = "Paris 75001"}};
    sep_cdp_ville(1, clients3);
    assert(strcmp(clients3[0].ville, "Paris") == 0);
    assert(strcmp(clients3[0].code, "75001") == 0);

    // Test de `afficher_ligne`
    afficher_ligne(2, clients, 1);

    // Test de `tri_tableau`
    CLIENT clients4[2] = {{.age = 30}, {.age = 20}};
    tri_tableau(2, clients4);
    assert(clients4[0].age == 20);

    // Test de `calcul_age`
    calcul_age("2000-01-01");

    // Test de `recherche`
    CLIENT clients5[1] = {{.nom = "Target"}};
    assert(recherche(1, clients5) == 0);
    assert(recherche(1, clients4) == -1);

    // Test de `modif`
    modif(1, clients5);
    assert(strcmp(clients5[0].nom, "ModifiedName") == 0);

    // Test de `list_to_file`
    fic = fopen("output.csv", "w");
    list_to_file(fic, 2, clients4);
    fclose(fic);

    // Test de `suppression`
    int nb_lignes = 2;
    suppression(&nb_lignes, clients4);
    assert(nb_lignes == 1);

    // Test de `nettoyer_char`
    char mot2[] = "   Test   ";
    nettoyer_char(mot2);
    assert(strcmp(mot2, "Test") == 0);

    // Test de `stristr`
    assert(stristr("HelloWorld", "world") == 1);
    assert(stristr("HelloWorld", "test") == -1);

    // Test de `filtre`
    assert(filtre(1, clients5) == 0);

    // Test de `afficher_avec_lignes`
    afficher_avec_lignes(2, clients4);

    // Test de `enlever_espace_fin`
    char mot3[] = "Hello   ";
    enlever_espace_fin(mot3);
    assert(strcmp(mot3, "Hello") == 0);

    // Test de `enlever_espace_debut`
    char mot4[] = "   Hello";
    enlever_espace_debut(mot4);
    assert(strcmp(mot4, "Hello") == 0);
}

int main() {
    test_functions();
    printf("Tous les tests sont passés avec succès !\n");
    return 0;
}

*/