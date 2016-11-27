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
#include <math.h>

int AppointmentCount = 0;
TAppointment Calendar[MAX_APPOINTMENTS];

//TODO: createAppointment
void createAppointment(TAppointment *appointment) {
    TAppointment *tmpAppointment = malloc(sizeof(TAppointment));

    getDate("Datum        : ", &(tmpAppointment->Date));

    getTime("Uhrzeit      : ", &(tmpAppointment->Time), 0);

    (*(tmpAppointment)).Duration = malloc(sizeof(TTime));

    getTime("Dauer        : ", tmpAppointment->Duration, 0);

    getText("Beschreibung : ", MAX_DESCRIPTION, &(tmpAppointment->Description), 0);

    getText("Ort          : ", MAX_LOCATION, &(tmpAppointment->Location), 1);

    *appointment = *tmpAppointment;

    free(tmpAppointment);

    printf("Termin gespeichert. \n");

    waitForEnter();

}

void editAppointment() {

}

void deleteAppointment() {

}

void searchAppointment() {

}

void sortCalendar() {

}

void printAppointment(TAppointment appointment) {
    printLine('=', 78);
    printf("\n");
    printDate(appointment.Date);
    printf("\n");
    printLine('-', 15);
    printf("\n   ");
    printTime(appointment.Time);
    if (strlen(appointment.Description) <= 48)
        printf(" -> %-15s | %-48s", appointment.Location, appointment.Description);
    else
        printf(" -> %-15s | %-44s ...", appointment.Location, appointment.Description);
}

//TODO: listCalendar
void listCalendar(TAppointment *appointments, int amount) {
    printf("Liste der Termine \n");
    printLine('=', strlen("Liste der Termine"));
    printf("\n \n");
    int i = 0; //counter variable for appointment pointer
    int ii = 0; //counter variable for max appointments on screen at the same time
    int page = 1;
    for (i; i < amount; i++) {
        if (ii >= 15) {
            printf("Seite %d/%d \n\n", page, (int) ceil((double) amount / (double) MAX_APPOINTMENTS_ON_SCREEN));
            if (amount - 1 - i >= 15) {
                printf("Bitte Enter drücken, um die nächsten %d ", MAX_APPOINTMENTS_ON_SCREEN);
            } else {
                printf("Bitte Enter drücken, um die nächsten %d ", amount - i);
            }
            printf("Termine anzuzeigen... ");
            ii = 0;
            page++;
            waitForEnterNoPrompt();
        }
        printAppointment(*(appointments + i));
        printf("\n \n");
        ii++;
    }
    printf("Seite %d/%d \n\n", page, (int) ceil((double) amount / (double) MAX_APPOINTMENTS_ON_SCREEN));
    waitForEnter();
}

void freeAppointment(TAppointment **appointment) {

    if (*appointment != NULL) {
        free(*appointment);
    }
}

void freeCalendar(TAppointment **appointment, int amount) {
    int i = 0;
    for (i; i < amount; i++) {
        freeAppointment((appointment + i));
    }
}

