//
// Created by tim on 28.10.16.
//

#include "menu.h"
#include "tools.h"
#include <stdio.h>
#include <string.h>

int getMenu(char *pTitle, char **pItems, unsigned int amount)
{
    int isValid = 0;
    int choice;
    do
    {
        int i = 0;
        clearScreen();
        printf("%s \n", pTitle);
        printLine('=', strlen(pTitle));
        printf("\n");
        for (i = 0; i < amount; ++i)
        {
            printf("%i. %s \n", i + 1, pItems[i]);
        }
        printf("\nBitte w%chlen Sie einen Men%cpunkt:\n ", ae, ue);
        isValid = scanf("%i", &choice);
        clearBuffer();
        if (choice > amount || choice <= 0)
        {
            printf("Fehler, keine g%cltige Men%cwahl \n\n", ue, ue);
            isValid = 0;
        }

    } while (!isValid);

    return choice;

}