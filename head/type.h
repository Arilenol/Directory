//
// Created by Aymeric_ONFRAY on 27/11/2024.
//
#ifndef TYPE_H_INCLUDED
#define TYPE_H_INCLUDED
 typedef struct{
    int id;
    char prenom[76];
    char nom[85];
    char ville[85];
    char codep[7];
    char tel[16];
    char adrmail[100];
    char profession[85];
    char date_naissance[11];
}CLIENT;
#endif //TYPE_H_INCLUDED
