//
// Created by tim on 28.10.16.
//

#include "menu.h"
#include "tools.h"

//TODO: getMenu
int getMenu(char *Title, char* Points[], int anz){
    int valid = 0;
    i = 0;
    int choice;
    do{
        clearScreen();
        printf("%s \n",Title);
        printf("============"); // eigentlich printline()
        for (int i = 0; i < anz; ++i) {
            printf("%i. %s \n",i,Points[i]); //TODO:Punkt ?
        }
        printf("\nBitte wählen Sie einen Menüpunkt");
        valid = scanf("%i",&choice);
        if(choice > anz || choice <= 0){
            printf("Fehler, keine gültige Menüwahl");
            valid = 0;
        }

    }while(!valid);

    return choice;

}