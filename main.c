#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"
#include "datetime.h"
#include "tools.h"
#include "calendar.h"
#include "menu.h"

int main() {
    TAppointment *appointments[MAX_APPOINTMENTS];
    int nextFree = 0;

/*
    appointments[0].Description = "Beschreibung";
    appointments[0].Location = "Ort";
    appointments[0].Date.Day = 12;
    appointments[0].Date.Month = 12;
    appointments[0].Date.Year = 2016;
    appointments[0].Time.Hour = 12;
    appointments[0].Time.Minute = 12;
    appointments[0].Duration->Minute = 5;
    appointments[0].Duration->Hour = 12;
*/

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
                createAppointment(*(appointments + nextFree));
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
                listCalendar(*appointments, nextFree);
                    break;
            case 7:
                break;
            default: printf("Fehler");
        }
    } while (choice != 7);

    freeCalendar(appointments, MAX_APPOINTMENTS);
    waitForEnter();
}