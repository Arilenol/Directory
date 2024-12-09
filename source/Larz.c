#include "../head/head.h"

int total_lignes(FILE * fichier){
    char c;
    int res = 0;
    c = fgetc(fichier);
    while (c!=EOF)
    {   
        if(c=='\n'){
            res++;
        }
        c = fgetc(fichier);
    }
    return res;
}


//fonction modi