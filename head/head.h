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
 */
void ouverture(char chemin[]);
/**
 *
 * @param fic
 * @post: demande a l'utilisateur de saisir les informations du nouveau client et les rentre a la fin du
 * fichier
 */
void ajout(FILE* fic);
/**
 * @param fichier
 * @return le nombre de ligne contenant du texte d'un fichier
 */
int total_lignes(FILE * fichier);
/**
 * @param fic
 * @post ferme le fichier dont le pointeur est rentré en parametre
 */
void fermeture(FILE* fic);
/**
 * @param mot
 * @post prend la chaine mot et supprime la premiere ocurrence de '\n'
 */
void retirer_chariot(char* mot);
/**
 * @param fic
 * @post affiche dans le terminal toute les ligne du fichier rentrée en parametre
 */
void afficher(int nb_l,CLIENT tab[nb_l]);
/**
 * @post decale le curseur du fichier stdin (buffer) pour eviter une lecture involontaire
 * du buffer par fgets
 */
void vider_buffer();
/**
 * @param mot
 * @post transforme toute les lettre minuscule en majuscule
 */
void upper(char mot[]);
/**
 * @param fic
 * @post affiche toute les ligne ou il manque des informations
 */
void afficher_manq(int nb_l,CLIENT tab[nb_l]);
/**
 * @param fic,nb_ligne,tableau
 * @post renvoie un tableau avec chaque ligne du fichier un élément du tableau
 */
void mot_par_mot(FILE* fichier,int nb_ligne, CLIENT tableau[nb_ligne]);
/**
 * @param 
 */
void affecter_struct(CLIENT *c1, char option[], char mot[]);
/**
 * @param nb_lignes, tab
 * @post separe les ville des code de departement
 */
void sep_cdp_ville(int nb_lignes,CLIENT tab[nb_lignes]);
/**
 * @param
 * @post affiche la ligne rentré par l'utilisateur;
 */
void afficher_ligne(int nb_l,CLIENT tab[nb_l],int ligne);
/**
 * @param fic
 * @post renvoie un tableau trié selon le critère rentré par l'utilisateur
 */
void tri_tableau(FILE* fic);
/**
 *
 */
#endif // HEAD_H_INCLUDED
