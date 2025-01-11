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
 * @param[in] int x,y,char[x][y],FILE*,char[]
 * @post : la fonction affiche un menu qui demande à l'utilisateur de
 * choisir parmis les fichier disponible lequel ouvrir
 * @author AYmeric
 * @return void
 */
void ouverture(char chemin[]);

/**
 *
 * @param fic
 * @post: demande a l'utilisateur de saisir les informations du nouveau client et les rentre a la fin du
 * fichier
 * @author AYmeric
 * @return void
 */
void ajout(FILE* fic);

/**
 * @author Leny
 * @pre fichier doit être en mode r
 * @param[in] fichier : *FILE de fichier
 * @post retourne le nombre de ligne de fichier
 * @return : int le nombre de ligne contenant du texte d'un fichier
 */
int total_lignes(FILE * fichier);

/**
 * @param fic
 * @post affiche dans le terminal toute les ligne du fichier rentrée en parametre
 * @author AYmeric
 * @return void
 */
void afficher(int nb_l,CLIENT tab[nb_l]);

/**
 * @post decale le curseur du fichier stdin (buffer) pour eviter une lecture involontaire
 * du buffer par fgets
 * @author AYmeric
 * @return void
 */
void vider_buffer();

/**
 * @author Leny
 * @brief enlève le \n laissé par fgets
 * @pre mot ne doit pas être vide
 * @param[in,out] mot : [char] chaine de caractères
 * @post mot ne contient plus \n à la fin 
 * @return void
 */
void retirer_chariot(char mot[]);

/**
 * @author AYmeric
 * @param fic
 * @post affiche toute les ligne ou il manque des informations
 * @return void
 */
void afficher_manq(int nb_l,CLIENT tab[nb_l]);

/**
 * @author Leny
 * @brief Remplit la liste de structures `CLIENT` avec les données extraites d'un fichier.
 * @pre nb_ligne > 0 et fichier en mode r
 * @param[in] fichier : *FILE Pointeur vers un fichier ouvert en mode lecture (`r`). Ce fichier 
 *               doit contenir les informations à assigner aux structures `CLIENT`.
 * @param[in] nb_ligne : int 
 * @param[in] tableau : [CLIENT] 
 * @post Tableau de structures `CLIENT` rempli avec les données du fichier.
 * @return void
 */
void mot_par_mot(FILE* fichier,int nb_ligne, CLIENT tableau[nb_ligne]);

/**
 * @author Leny
 * @brief Affecte des valeurs aux champs d'une structure `CLIENT` en fonction de l'option et du mot donnés.
 * @pre option et option doivent être non vide
 * @param[in,out] c1 : *CLIENT Pointeur vers la structure `CLIENT` à modifier.
 * @param[in] option : [char] 
 * @param[in] mot : [char]
 * @return void
 */
void affecter_struct(CLIENT *c1, char option[], char mot[]);

/**
 * @author Aymeric
 * @param nb_lignes, tab
 * @post separe les ville des code de departement
 * @return void
 */
void sep_cdp_ville(int nb_lignes,CLIENT tab[nb_lignes]);

/**
 * @author Aymeric
 * @param
 * @post affiche la ligne rentré par l'utilisateur;
 * @author AYmeric
 * @return void
 */
void afficher_ligne(int nb_l,CLIENT tab[nb_l],int ligne);

/**
 * @author Aymeric
 * @param nb_l tab
 * @post renvoie un tableau trié selon le critère rentré par l'utilisateur
 * @author AYmeric
 * @return void
 */
void tri_tableau(int nb_l,CLIENT tab[nb_l]);

/**
 * @author Aymeric
 * @param
 * @post renvoie l'age de la perssonne au moment de la saisie
 * @return void
 */
void calcul_age(char mot[]);

/**
 * @author Leny
 * @pre nb_ligne > 0
 * @brief Recherche un individu dans un tableau de structures `CLIENT`.
 * @param[in] nb_ligne : int
 * @param[in] tableau : [CLIENT] 
 * @post La position de l'individu recherché dans le tableau, ou `-1` si l'individu n'est pas trouvé.
 * @return : int  
 */
int recherche(int nb_ligne, CLIENT tableau[nb_ligne]);

/**
 * @author Leny
 * @pre nb_ligne > 0
 * @brief Modifie un ou plusieurs champs d'une structure `CLIENT` dans un tableau.
 * @param[in] nb_ligne : int 
 * @param[in,out] tableau : [CLIENT] 
 * @post Un tableau de `CLIENT` modifié, avec `nb_ligne` éléments.
 * @return void
 */
void modif(int nb_ligne, CLIENT tableau[nb_ligne]);

/**
 * @author Leny
 * @brief Convertit une liste de `CLIENT` en un fichier CSV.
 * @pre taille > 0 et *file doit être en mode w
 * @param[in] file : *FILE Pointeur vers un fichier ouvert en mode écriture où les données 
 *             seront sauvegardées au format CSV.
 * @param[in] taille : int 
 * @param[in] tableau : [CLIENT] 
 * @post Tableau de `CLIENT` contenant les informations à écrire dans le fichier.
 * @return void
 */
void list_to_file(FILE* file,int taille, CLIENT tableau[taille]);

/**
 * @author Leny
 * @brief Supprime un élément dans un tableau de `CLIENT` après recherche ou filtre.
 * @pre *nb_ligne > 0
 * @param[in] nb_ligne : *int Pointeur vers le nombre d'éléments dans le tableau `tableau`. Ce 
 *                 nombre sera mis à jour après la suppression.
 * @param[in] tableau : [CLIENT]        
 * @post Un tableau de `CLIENT` à partir duquel un élément sera supprimé. 
 * @return void
 */
void suppression(int* nb_ligne, CLIENT tableau[*nb_ligne]);

/**
 * @author Leny
 * @brief Supprime les espaces superflus avant et après une chaîne, et enlève le caractère de nouvelle ligne `\n` généré par `fgets`.
 * @pre mot ne doit pas être vide
 * @param[in,out] mot: [char] 
 * @post Les espaces au début et à la fin de la chaîne 
 *        seront supprimés, ainsi que le caractère `\n` généré par `fgets`. 
 *        La chaîne est modifiée en place.
 * @return void
 */
void nettoyer_char(char mot[]);


/**
 * @author Leny
 * @brief Recherche un sous-ensemble de chaîne (`motif`) dans une autre chaîne (`mot`), insensible à la casse.
 * @pre mot ne doit pas être vide
 * @param[in] mot : [char] 
 * @param[in] motif : [char] 
 * @post retourne 1 si motif est dans `mot`, ou -1 si le motif n'est pas trouvé, ou 0 si motif est vide.
 * @return : int 
 */
int stristr(char mot[],  char motif[]);

/**
 * @author Leny
 * @brief Demande à l'utilisateur de sélectionner un motif puis un champ avant de recherche le motif dans ce champ dans la liste de CLIENT
 * @pre taille > 0 
 * @param[in] taille : int 
 * @param[in] tableau : [CLIENT]
 * @post La position de l'individu recherché dans le tableau, ou `-1` si l'individu n'est pas trouvé.
 * @return : int 
 */
int filtre(int taille, CLIENT tab[taille] );


/**
 * @author Leny
 * @brief Affiche les informations des clients dans un tableau avec les numéros de lignes.
 * @pre nb_l > 0 
 * @param[in] nb_l : int
 * @param[in] tab : [CLIENT] 
 * @post Le tableau des structures CLIENT à afficher
 * @return void
 */
void afficher_avec_lignes(int nb_l,CLIENT tab[nb_l]);

/**
 * @author Leny
 * @brief Supprime les espaces à la fin d'une chaîne de caractères.
 * @pre le mot ne doit pas être vide
 * @param[in,out] mot : [char] 
 * @post Chaîne de caractères dont les espaces à la fin seront supprimés. La chaîne est modifiée directement.
 * @return void
 */
void enlever_espace_fin(char mot[]) ;

/**
 * @author Leny
 * @brief Supprime les espaces au début d'une chaîne de caractères.
 * @pre le mot ne doit pas être vide
 * @param[in,out] mot : [char] 
 * @post Chaîne de caractères dont les espaces au début seront supprimés. La chaîne est modifiée directement.
 * @return void
 */
void enlever_espace_debut(char mot[]);

/**
 * @author Leny
 * @brief Creation d'un fichier et csv et copie de la liste de CLIENT dedans
 * @pre taille > 0
 * @param[in] taille : int
 * @param[in] clients : [CLIENT] 
 * @post copie la liste de client dans un fichier csv 
 * @return void
 */
void creerFichierCSV(int taille, CLIENT clients[taille]) ;
#endif // HEAD_H_INCLUDED
