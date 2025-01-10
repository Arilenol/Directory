//
// Created by Leny_ARIZZI on 27/11/2024.
//
#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "type.h"
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
/**
 * param[in] int x,y,char[x][y],FILE*,char[]
 * @post : la fonction affiche un menu qui demande à l'utilisateur de
 * choisir parmis les fichier disponible lequel ouvrir
 * @author AYmeric
 */
void ouverture(char chemin[]);

/**
 *
 * @param fic
 * @post: demande a l'utilisateur de saisir les informations du nouveau client et les rentre a la fin du
 * fichier
 * @author AYmeric
 */
void ajout(FILE* fic);

/**
 * @author Leny
 * @param pointeur de fichier
 * @return le nombre de ligne contenant du texte d'un fichier
 */
int total_lignes(FILE * fichier);

/**
 * @param fic
 * @post affiche dans le terminal toute les ligne du fichier rentrée en parametre
 * @author AYmeric
 */
void afficher(int nb_l,CLIENT tab[nb_l]);

/**
 * @post decale le curseur du fichier stdin (buffer) pour eviter une lecture involontaire
 * du buffer par fgets
 * @author AYmeric
 */
void vider_buffer();

/**
 * @author Leny
 * @brief enlève le \n laissé par fgets
 * @param une chaine de caractères
 */
void retirer_chariot(char mot[]);

/**
 * @param fic
 * @post affiche toute les ligne ou il manque des informations
 * @author AYmeric
 */
void afficher_manq(int nb_l,CLIENT tab[nb_l]);

/**
 * @author Leny
 * @brief Remplit la liste de structures `CLIENT` avec les données extraites d'un fichier.
 * @param fichier Pointeur vers un fichier ouvert en mode lecture (`r`). Ce fichier 
 *               doit contenir les informations à assigner aux structures `CLIENT`.
 * @param nb_ligne Le nombre de clients (taille de la liste) à traiter dans la liste.
 * @param tableau Tableau de structures `CLIENT` à remplir avec les données du fichier.
 */
void mot_par_mot(FILE* fichier,int nb_ligne, CLIENT tableau[nb_ligne]);

/**
 * @author Leny
 * @brief Affecte des valeurs aux champs d'une structure `CLIENT` en fonction de l'option et du mot donnés.
 * @param c1 Pointeur vers la structure `CLIENT` à modifier.
 * @param option Chaîne de caractères représentant l'option qui détermine quel champ 
 *               de la structure `CLIENT` sera modifié.
 * @param mot Chaîne de caractères contenant la valeur à affecter au champ sélectionné 
 *            de la structure `CLIENT`.
 */
void affecter_struct(CLIENT *c1, char option[], char mot[]);

/**
 * @param nb_lignes, tab
 * @post separe les ville des code de departement
 * @author AYmeric
 */
void sep_cdp_ville(int nb_lignes,CLIENT tab[nb_lignes]);

/**
 * @param
 * @post affiche la ligne rentré par l'utilisateur;
 * @author AYmeric
 */
void afficher_ligne(int nb_l,CLIENT tab[nb_l],int ligne);

/**
 * @param nb_l tab
 * @post renvoie un tableau trié selon le critère rentré par l'utilisateur
 * @author AYmeric
 */
void tri_tableau(int nb_l,CLIENT tab[nb_l]);

/**
 * @param
 * @post renvoie l'age de la perssonne au moment de la saisie
 */
void calcul_age(char mot[]);

/**
 * @author Leny
 * @brief Recherche un individu dans un tableau de structures `CLIENT`.
 * @param nb_ligne Le nombre d'éléments dans le tableau `tableau`.
 * @param tableau Un tableau de `CLIENT` dans lequel la recherche sera effectuée.
 * @return La position de l'individu recherché dans le tableau, ou `-1` si l'individu n'est pas trouvé.
 */
int recherche(int nb_ligne, CLIENT tableau[nb_ligne]);

/**
 * @author Leny
 * @brief Modifie un ou plusieurs champs d'une structure `CLIENT` dans un tableau.
 * @param nb_ligne Le nombre de clients dans le tableau `tableau`.
 * @param tableau Un tableau de `CLIENT` à modifier, avec `nb_ligne` éléments.
 * @return Aucun retour. La fonction modifie les éléments directement dans le tableau.
 */
void modif(int nb_ligne, CLIENT tableau[nb_ligne]);

/**
 * @author Leny
 * @brief Converti une liste de CLIENT en fichier csv
 * @param prend un pointeur de fichier
 * @param prend la taille d'un tableau
 * @param prend un tableau de taille 'taille'
 */
void list_to_file(FILE* file,int taille, CLIENT c[taille]);

/**
 * @author Leny
 * @brief supprime un élément dans un tableau après recherche ou filtre
 * @param prend un pointeur d'entier
 * @param prend un tableau de CLIENT
 */
void suppression(int* nb_ligne, CLIENT tableau[*nb_ligne]);

/**
 * @author Leny
 * @brief enlève les espaces avant, après le mot et enlève \n généré par fgets
 * @param prend une chaine de caractères 
 */
void nettoyer_char(char mot[]);
#endif // HEAD_H_INCLUDED
