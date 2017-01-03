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
    char *DbFileName = "calendar.xml";

    /******* This part loads appointments into a memory
     * and increments appointmentCount */
    int appointmentCount = 0;
    appointmentCount = loadCalendar(DbFileName, appointments, appointmentCount);

    printDbInfo(appointmentCount);

    /******** Menu output on the screen   **/

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
        choice = getMenu("Terminverwaltung v.5.0", Menu, 7);

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
            case 5: sortCalendar(appointments, appointmentCount);
                    break;
            case 6:
                    listCalendar(appointments, appointmentCount);
                    break;
            case 7:


                    if (appointmentCount > 0){
                        int isSaved = saveCalendar(DbFileName, appointments, appointmentCount);

                        if (isSaved) {
                            printf("\nAlle Terminen wurden in die Datei calendar.xml gespeichert.\n\n");
                            printf("Das Programm wurde erfolgreich beendet...");
                        }
                        else {
                            printf("\nFehler beim Speichern!\n");
                            printf("Die neuen Terminen sind nicht gespeichert!");
                            waitForEnter();

                        }
                    }

                    break;
            default: printf("Fehler");
        }
    } while (choice != 7);

    freeCalendar(appointments);

    return 0;

}
