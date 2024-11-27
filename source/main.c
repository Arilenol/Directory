#include "../head/head.h"

int main(void){
    system("chcp 65001");
    system("cls");
    char possible[2][10]={"Consulter","Ajouter"};
    int choix;
    printf("Que voulez-faire parmi les actions suivantes ? \n");
    for (int i = 0; i<2;i++){
        printf("%d) %s\n",i+1,possible[i]);
    }
    printf("\nEntrez le chiffre correspondant à l'action que vous souhaitez réaliser : ");
    scanf("%d",&choix);
    while (assert(int choix==1) ){
        printf("L'élément que vous avez rentré n'est pas un entier ! \n Réessayez : ");
    }
    switch (choix)
    {
    case 1:
        //fonction Consulter
        break;
    
    case 2:
        //fonction Ajouter
        break;
    
    default:
        printf("\nVous avez rentré un nombre erroné");
        break;
    }

    return 0;
}