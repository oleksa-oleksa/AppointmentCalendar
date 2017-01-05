#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"
#include "datetime.h"
#include "tools.h"
#include "calendar.h"
#include "menu.h"
#include "database.h"
#include "escapesequenzen.h"

int main() {

    setUnicode(); // If Win32 is detected, the proper UTF-8 will be set
    clearScreen();

    TAppointment *appointments = calloc(sizeof(TAppointment), MAX_APPOINTMENTS);
    char *DbFileName = "calendar.xml";
    int newCount = 0; // for tracking changes to save
    int sortedCount = 0; // same

    /******* This part loads appointments into a memory
     * and increments appointmentCount */
    int appointmentCount = 0;

    appointmentCount = loadCalendar(DbFileName, appointments, appointmentCount);

    printDbInfo(appointmentCount);
    waitForEnter();

    /******** Menu output on the screen   **/

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
        clearScreen();

        /**** Reminder about new appointments */
        if (newCount) {
            printInfoNewAppointments(newCount);
        }

        if (sortedCount)
        {
            printInfoSortedAppointments(sortedCount);
        }

        /**** MENU */

        choice = getMenu("Terminverwaltung v.5.0", Menu, 7);

        switch (choice) {
            case 1:
                    if (appointmentCount < MAX_APPOINTMENTS) {
                        createAppointment((appointments + appointmentCount));
                        appointmentCount++;
                        newCount++;
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
                    sortedCount++;
                    break;
            case 6:
                    listCalendar(appointments, appointmentCount);
                    break;
            case 7:


                    if (newCount > 0 || sortedCount > 0)
                    {

                        FORECOLOR_YELLOW;
                        printf("\nWollen Sie Änderungen in die Datei speichern?\n\n");
                        ATTRIBUTE_OFF;

                        int hasChangesToSave = askYesOrNo("Speichern? (j/n): ");
                        if (hasChangesToSave)
                        {

                            int isSaved = saveCalendar(DbFileName, appointments, appointmentCount);

                            if (isSaved)
                            {
                                FORECOLOR_GREEN;
                                printf(" -> Alle Terminen wurden in die Datei calendar.xml gespeichert.\n\n");
                                ATTRIBUTE_OFF;
                                printf("Das Programm wurde erfolgreich beendet...\n");
                            } else
                            {
                                FORECOLOR_RED;
                                printf("\nFehler beim Speichern!\n");
                                printf("Die neuen Terminen sind nicht gespeichert!\n\n");
                                ATTRIBUTE_OFF;
                                waitForEnter();
                                printf("Das Programm wurde beendet...\n\n");

                            }
                        }

                        else
                        {
                            FORECOLOR_BLUE;
                            printf(" -> Nicht speichern\n\n");
                            ATTRIBUTE_OFF;
                            printf("Das Programm wurde beendet...");
                            printf("\n\n");
                        }
                    }

                else
                    {
                        FORECOLOR_BLUE;
                        printf("\nKeine Änderungen in die Datenbank sind zu speichern\n");
                        ATTRIBUTE_OFF;
                        printf("Das Program wurde beendet...");
                        printf("\n\n");


                    }
                    break;

            default: printf("Fehler");
        }
    } while (choice != 7);

    freeCalendar(appointments);

    return 0;

}
