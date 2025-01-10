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
 * @param fichier
 * @return le nombre de ligne contenant du texte d'un fichier
 */
int total_lignes(FILE * fichier);

/**
 * @param mot
 * @post prend la chaine mot et supprime la premiere ocurrence de '\n'
 */
void retirer_chariot(char* mot);

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
 * @param mot
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
 * @param fic,nb_ligne,tableau
 * @post renvoie un tableau avec chaque ligne du fichier un élément du tableau
 */
void mot_par_mot(FILE* fichier,int nb_ligne, CLIENT tableau[nb_ligne]);

/**
 * @author Leny
 * @param 
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
 *@param tableau nb_ligne
 * @post
 */
int recherche(int nb_ligne, CLIENT tableau[nb_ligne]);

/**
 * @author Leny
 */
void modif(int nb_ligne, CLIENT tableau[nb_ligne]);

/**
 * @author Leny
 *
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
