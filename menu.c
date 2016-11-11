//
// Created by tim on 28.10.16.
//

#include "menu.h"
#include "tools.h"
#include <stdio.h>

int getMenu(char *Title, char* Points[], int anz){
    int valid = 0;
    int choice;
    do{
        int i = 0;
        clearScreen();
        printf("%s \n",Title);
        printf("==================\n\n");
        for (0; i < anz; ++i) {
            printf("%i. %s \n",i+1,Points[i]);
        }
        printf("\nBitte wählen Sie einen Menüpunkt: ");
        valid = scanf("%i",&choice);
        clearBuffer();
        if(choice > anz || choice <= 0){
            printf("Fehler, keine gültige Menüwahl \n\n");
            valid = 0;
        }

    }while(!valid);

    return choice;

}