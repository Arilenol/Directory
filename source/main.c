#include "../head/head.h"
#define NB_PROP 2
int main(void){
    system("chcp 65001");
    system("cls");
    char possible[NB_PROP][10]={"Consulter","Ajouter"};
    int choix;
    printf("Que voulez-faire parmi les actions suivantes ? \n");
    for (int i = 0; i<NB_PROP; i++){
        printf("%d) %s\n",i+1,possible[i]);
    }
    printf("\nEntrez le chiffre correspondant à l'action que vous souhaitez réaliser : ");
    scanf("%d",&choix);

    while (choix<1 || choix >NB_PROP){
        printf("Sasie hors plage\nRéessayez : ");
        scanf("%d",&choix);
    }
    switch (choix)
    {
    case 1:
        //fonction Consulter
        break;
    
    case 2:
        //fonction Ajouter
        break;
    }

    return 0;
}