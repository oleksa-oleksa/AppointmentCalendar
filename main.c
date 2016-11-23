#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"
#include "datetime.h"
#include "tools.h"
#include "calendar.h"
#include "menu.h"

int main() {
    TAppointment appointments[100];
    int nextFree = 2;
    appointments[0].Description = "Beschreibung1";
    appointments[0].Date.Day = 23;
    appointments[0].Date.Month = 11;
    appointments[0].Date.Year = 2016;
    appointments[0].Date.DayOfTheWeek = We;
    appointments[0].Time.Hour = 12;
    appointments[0].Time.Minute = 50;
    appointments[0].Location = "Ort";

    appointments[1].Description = "Beschreibung12";
    appointments[1].Date.Day = 24;
    appointments[1].Date.Month = 11;
    appointments[1].Date.Year = 2016;
    appointments[1].Date.DayOfTheWeek = We;
    appointments[1].Time.Hour = 13;
    appointments[1].Time.Minute = 56;
    appointments[1].Location = "Ort2";
    listCalendar(appointments, nextFree);
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