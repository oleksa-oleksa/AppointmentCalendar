#include <stdio.h>
#include "datastructure.h"
#include "datetime.h"
#include "tools.h"
#include "calendar.h"
#include "menu.h"

int main()
{
//TODO: Menü in Schleife anzeigen.

    char *Menu[] = {"Neuen Termin anlegen",
                    "Termin bearbeiten",
                    "Termin löschen",
                    "Termin suchen",
                    "Termine sortieren",
                    "Termine auflisten",
                    "Programm beenden"};

    do
    {
        int choice = getMenu("Kalender", Menu, 7);

        switch(choice)
        {
            //case 1:
        }
    }while (askYesOrNo("Nochmal?"));
}