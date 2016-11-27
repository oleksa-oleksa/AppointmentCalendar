#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"
#include "datetime.h"
#include "tools.h"
#include "calendar.h"
#include "menu.h"

int main() {
    TAppointment *appointments = calloc(sizeof(TAppointment), MAX_APPOINTMENTS);
    int appointmentCount = 0;

    int i = 0;
    calloc(sizeof(TAppointment), MAX_APPOINTMENTS);
    for (; i <= 35; i++) {
        (*(appointments + i)).Duration = malloc(sizeof(TTime));
        (*(appointments + i)).Description = "Beschreibung Sdfsdafkljhsöjdklhölsdkfjlskdfjsaedfsdfsdaf sdfdafsdf";
        (*(appointments + i)).Location = malloc(15 * sizeof(char));
        sprintf((*(appointments + i)).Location, "%d", i + 1);
        (*(appointments + i)).Date.Day = 12;
        (*(appointments + i)).Date.Month = 12;
        (*(appointments + i)).Date.Year = 2016;
        (*(appointments + i)).Time.Hour = 12;
        (*(appointments + i)).Time.Minute = 12;
        (*(appointments + i)).Duration->Minute = 5;
        (*(appointments + i)).Duration->Hour = 12;
        appointmentCount++;
    }
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

        switch (choice) {
            case 1:
                if (appointmentCount < MAX_APPOINTMENTS) {
                    createAppointment((appointments + appointmentCount));
                    appointmentCount++;
                } else {
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
                listCalendar(appointments, appointmentCount - 1);
                    break;
            case 7:
                break;
            default: printf("Fehler");
        }
    } while (choice != 7);

    freeCalendar(&appointments, MAX_APPOINTMENTS);
}
