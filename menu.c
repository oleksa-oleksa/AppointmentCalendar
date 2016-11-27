//
// Created by tim on 28.10.16.
//

#include "menu.h"
#include "tools.h"
#include <stdio.h>
#include <string.h>

int getMenu(char *Title, char **Points, unsigned int anz){
    int valid = 0;
    int choice;
    do
    {
        int i = 0;
        clearScreen();
        printf("%s \n",Title);
        printLine('=', strlen(Title));
        printf("\n");
        for (i = 0; i < anz; ++i)
        {
            printf("%i. %s \n",i+1,Points[i]);
        }
        printf("\nBitte w%chlen Sie einen Men%cpunkt:\n ", ae, ue);
        valid = scanf("%i",&choice);
        clearBuffer();
        if(choice > anz || choice <= 0)
        {
            printf("Fehler, keine g%cltige Men%cwahl \n\n", ue, ue);
            valid = 0;
        }

    } while(!valid);

    return choice;

}