//
// Created by tim on 28.10.16.
//

#include <afxres.h>
#include <stdio.h>
#include "calendar.h"
#include "datastructure.h"
#include "tools.h"
#include "datetime.h"

int AppointmentCount = 0;
TAppointment Calendar[MAX_APPOINTMENTS];

//TODO: createAppointment
void createAppointment(TAppointment *appointment) {

    /*
     * Datum, Uhrzeit, Terminbeschreibung,
Ort und die Dauer eingeben können
     */

    /*
    TDate* date = malloc(sizeof(TDate));
    TTime* time = malloc(sizeof(TTime));
    char** description = malloc(sizeof(char) * 100);
    char* location = malloc(sizeof(char) * 15);
     */



    TAppointment *newAppointment = malloc(sizeof(TAppointment));

    char **description = &(newAppointment->Description);
    char **location = &(newAppointment->Location);

    getDate("Bitte geben Sie das Datum ein. ", &(newAppointment)->Date);

    getTime("Bitte geben Sie die Zeit des Termins ein. ", &(newAppointment)->Time, 0);

    getText("Bitte geben Sie die Terminbeschreibung an. ", 100, *description, 0);

    getText("Bitte geben Sie den Ort des Termins an. ", 15, *location, 1);

    /* (*appointment).Date.Day = date->Day;
     (*appointment).Date.Month = date->Month;
     (*appointment).Date.Year = date->Year;

     (*appointment).Time.Minute = time->Minute;
     (*appointment).Time.Hour = time->Hour;

     (*appointment).Description = description;
     (*appointment).Location = location;
 */
}

void editAppointment() {

}

void deleteAppointment() {

}

void searchAppointment() {

}

void sortCalendar() {

}

//TODO: listCalendar
void listCalendar(TAppointment *appointments, int amount) {
    printf("Liste der Termine \n");
    printLine('=', strlen("Liste der Termine"));
    printf("\n \n");
    int i = 0;
    for (i; i < amount; i++) {
        printLine('=', 78);
        printf("\n");
        printDate((*(appointments + i)).Date);
        printf("\n");
        printLine('-', 15);
        printf("\n   ");
        printTime((*(appointments + i)).Time);
        printf(" -> %15s | %48s", (*(appointments + i)).Location, (*(appointments + i)).Description);
        printf("\n \n");
    }
    printf("Bitte Eingabetaste druecken...");
    waitForEnter();
}
