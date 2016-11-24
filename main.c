#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"
#include "datetime.h"
#include "tools.h"
#include "calendar.h"
#include "menu.h"

int main() {
    TAppointment appointments[100];
    int nextFree = 0;

    char *text = malloc(50 * sizeof(char));
    char **pText = &text;

    getText("Text eingeben", 50, *pText, 0);
    printf("Text %s", text);
    waitForEnter();


    /*
    int choice;
    char *Menu[] = {"Neuen Termin anlegen",
                    "Termin bearbeiten",
                    "Termin löschen",
                    "Termin suchen",
                    "Termine sortieren",
                    "Termine auflisten",
                    "Programm beenden"};

    do
    {
        choice = getMenu("Terminverwaltung", Menu, 7);

        switch(choice)
        {
            case 1:
                createAppointment(&appointments[nextFree]);
                nextFree++;
                break;
            case 2: editAppointment();
                    break;
            case 3: deleteAppointment();
                    break;
            case 4: searchAppointment();
                    break;
            case 5: sortCalendar();
                    break;
            case 6:
                listCalendar(appointments, nextFree);
                    break;
            default: printf("Fehler");
        }
    } while (choice != 7);
*/
}