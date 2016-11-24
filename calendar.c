//
// Created by tim on 28.10.16.
//

#include <stdio.h>
#include <stdlib.h>
#include "calendar.h"
#include "datastructure.h"
#include "tools.h"
#include "datetime.h"
#include <string.h>

int AppointmentCount = 0;
TAppointment Calendar[MAX_APPOINTMENTS];

//TODO: createAppointment
void createAppointment(TAppointment *appointment) {

    (*(appointment)).Description = malloc(MAX_DESCRIPTION * sizeof(char));
    (*appointment).Location = malloc(MAX_LOCATION * sizeof(char));

    getDate("Bitte geben Sie das Datum ein. ", appointment->Date);

    getTime("Bitte geben Sie die Zeit des Termins ein. ", appointment->Time, 0);

    getText("Bitte geben Sie die Terminbeschreibung an. ", MAX_DESCRIPTION, appointment->Description, 0);

    getText("Bitte geben Sie den Ort des Termins an. ", MAX_LOCATION, appointment->Location, 1);
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
        printDate(*(appointments + i)->Date);
        printf("\n");
        printLine('-', 15);
        printf("\n   ");
        printTime(*(appointments + i)->Time);
        printf(" -> %15s | %48s", (*(appointments + i)).Location, (*(appointments + i)).Description);
        printf("\n \n");
    }
    printf("Bitte Eingabetaste druecken...");
    waitForEnter();
}

void freeAppointment(TAppointment *appointment) {

    free(appointment->Description);
    free(appointment->Location);
    free(appointment->Duration);

}
