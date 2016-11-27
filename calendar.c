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
    char *prompt = malloc(strlen("Bitte Enter drücken, um die nächsten 100 Termine anzuzeigen...") * sizeof(char));
    for (i; i < amount; i++) {
        if (ii >= 15) {
            if (amount - 1 - i >= 15) {
                sprintf(prompt, "Seite %d/%d \n\nBitte Enter dr%ccken, um die n%cchsten %d Termine anzuzeigen",
                        page, (int) ceil((double) amount / (double) MAX_APPOINTMENTS_ON_SCREEN), ue, ae,
                        MAX_APPOINTMENTS_ON_SCREEN);
                waitForEnterSpecialPrompt(prompt);
            } else {
                sprintf(prompt, "Seite %d/%d \n\nBitte Enter dr%ccken, um die n%cchsten %d Termine anzuzeigen",
                        page, (int) ceil((double) amount / (double) MAX_APPOINTMENTS_ON_SCREEN), ue, ae, amount - i);
                waitForEnterSpecialPrompt(prompt);
            }

            sprintf(prompt, "Seite %d/%d \n\nBitte Enter dr%ccken... ",
                    page, (int) ceil((double) amount / (double) MAX_APPOINTMENTS_ON_SCREEN), ue);


            ii = 0;

            page++;
        }
        printAppointment(*(appointments + i));
        printf("\n \n");
        ii++;
    }
    //free(prompt);
    printf("Seite %d/%d \n\n", page, (int) ceil((double) amount / (double) MAX_APPOINTMENTS_ON_SCREEN));
    waitForEnter();
}

void freeAppointment(TAppointment *appointment) {

    if (appointment) {
        free(appointment);
    }
}

void freeCalendar(TAppointment *appointment, int amount) {
    int i = 0;
    for (i; i < amount; i++) {
        freeAppointment((appointment + i));
    }
}

