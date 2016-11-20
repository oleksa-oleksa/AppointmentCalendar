#include <stdio.h>
#include <malloc.h>
#include "datastructure.h"
#include "datetime.h"
#include "tools.h"
#include "calendar.h"
#include "menu.h"

int main()
{
    TTime time = {.Hour = 12, .Minute = 22, .Second = 33};
    printTime(time);
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
            case 1: createAppointment();
                    break;
            case 2: editAppointment();
                    break;
            case 3: deleteAppointment();
                    break;
            case 4: searchAppointment();
                    break;
            case 5: sortCalendar();
                    break;
            case 6: listCalendar();
                    break;
            default: printf("Fehler");
        }
    } while (choice != 7);
    */
}