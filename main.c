#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"
#include "datetime.h"
#include "tools.h"
#include "calendar.h"
#include "menu.h"
#include "database.h"

int main() {
    TAppointment *appointments = calloc(sizeof(TAppointment), MAX_APPOINTMENTS);
    int appointmentCount = 0;
    char *DbFileName = "calendar.xml";

    int choice;
    char *Menu[] = {"Neuen Termin anlegen",
                    "Termin bearbeiten",
                    "Termin l\x94schen",
                    "Termin suchen",
                    "Termine sortieren",
                    "Termine auflisten",
                    "Programm beenden"};

    do
    {
        choice = getMenu("Terminverwaltung", Menu, 7);

        switch (choice) {
            case 1:
                    if (appointmentCount < MAX_APPOINTMENTS) {
                        createAppointment((appointments + appointmentCount));
                        appointmentCount++;
                     }

                    else {
                         printf("Keine freien Speicherplätze mehr vorhanden!");
                         waitForEnter();
                     }

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
                    listCalendar(appointments, appointmentCount);
                    break;
            case 7:
                    if (appointmentCount > 0){
                        saveCalendar(DbFileName, appointments, appointmentCount);
                    }

                    break;
            default: printf("Fehler");
        }
    } while (choice != 7);

    freeCalendar(appointments);

    return 0;

}
