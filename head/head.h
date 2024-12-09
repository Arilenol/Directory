//
// Created by Leny_ARIZZI on 27/11/2024.
//
#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "type.h"
#include <assert.h>
#define NB_PROP 2
#define NB_FICH 6
#define DIX "../benchmark_1/annuaire_10_entrees.csv"
#define CINQUANTE "../benchmark_1/annuaire_50_entrees.csv"
#define CENT "../benchmark_1/annuaire_100_entrees.csv"
#define CINQ_CENTS "../benchmark_1/annuaire_500_entrees.csv"
#define MILLE "../benchmark_1/annuaire_1000_entrees.csv"
#define CINQ_MILLES "../benchmark_1/annuaire_5000_entrees.csv"
/**
 * param[in] int* pann
 * @post : la fonction affiche un menu qui demande à l'utilisateur de
 * choisir parmis les fichier disponible lequel ouvrir
 */
int ouverture(int x,int y,char annuaires[x][y],FILE* fic);
void ajout(FILE* fic);
int total_lignes(FILE * fichier);
void fermeture(FILE* fic);
void retirer_chariot(char* mot);
void afficher(FILE* fic,int lignes);
#endif // HEAD_H_INCLUDED
