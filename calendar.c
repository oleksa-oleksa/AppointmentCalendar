#include <stdio.h>
#include <stdlib.h>
#include "calendar.h"
#include "menu.h"
#include "sort.h"
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

int orderByDate(TAppointment *a, TAppointment *b)
{

    if (a->Date.Year < b->Date.Year) {
       return -1;
    }


    if (a->Date.Year > b->Date.Year) {
     return 1;
    }


    if (a->Date.Year == b->Date.Year) {
        if (a->Date.Month == b->Date.Month) {

            if (a->Date.Day == b->Date.Day) {
                return 0;
            }

            else {
                if (a->Date.Day > b->Date.Day) {
                    return 1;
                }

                else {
                    return -1;
                }
            }
        }
        else {
            if (a->Date.Month > b->Date.Month) {
                return 1;
            }

            else {
                return -1;
            }
        }

        }
    }

}

void sortCalendar(TAppointment *appointments, int amount) {

    int choice;
    char *Menu[] = {"Sortieren nach Datum und Uhrzeit",
                    "Sortieren nach Beschreibung",
                    "Sortieren nach Ort",
                    "Sortieren nach Dauer",
                    "Zuruck zum Hauptmenu"};

    do
    {
        choice = getMenu("Termine sortieren", Menu, 5);

        switch (choice) {
            case 1:
                quickSortAppointments(appointments, 0, amount, orderByDate);
                break;
            case 2:
                break;
            default: printf("Fehler");
        }
    }while (choice != 5);

}

void printAppointment(TAppointment appointment) {
    printLine('=', 78);
    printf("\n");
    printDate(appointment.Date);
    printf("\n");
    printLine('-', 15);
    printf("\n   ");
    printTime(appointment.Time);
    char *Location = "";

    if (appointment.Location)
        Location = appointment.Location;

    if (strlen(appointment.Description) <= 48)
        printf(" -> %-15s | %-48s", Location, appointment.Description);
    else
        printf(" -> %-15s | %-44s ...", Location, appointment.Description);
}

//TODO: listCalendar
void listCalendar(TAppointment *appointments, int amount) {
   int appointmentsOnScreen = 0; //saves the number of appointments on the screen
   int page = 1;

    printf("Liste der Termine \n");
    printLine('=', strlen("Liste der Termine"));
    printf("\n \n");

    char *prompt = malloc(strlen("Bitte Enter drücken, um die nächsten 100 Termine anzuzeigen...") * sizeof(char));
   for (int currentAppointment = 0; currentAppointment < amount; currentAppointment++)
   {
      if (appointmentsOnScreen >= 15)
      {
         if (amount - 1 - currentAppointment >= 15)
         {
                sprintf(prompt, "Seite %d/%d \n\nBitte Enter dr%ccken, um die n%cchsten %d Termine anzuzeigen",
                        page, (int) ceil((double) amount / (double) MAX_APPOINTMENTS_ON_SCREEN), ue, ae,
                        MAX_APPOINTMENTS_ON_SCREEN);
                waitForEnterSpecialPrompt(prompt);
            } else {
                sprintf(prompt, "Seite %d/%d \n\nBitte Enter dr%ccken, um die n%cchsten %d Termine anzuzeigen",
                        page, (int) ceil((double) amount / (double) MAX_APPOINTMENTS_ON_SCREEN), ue, ae,
                        amount - currentAppointment);
                waitForEnterSpecialPrompt(prompt);
            }

            sprintf(prompt, "Seite %d/%d \n\nBitte Enter dr%ccken... ",
                    page, (int) ceil((double) amount / (double) MAX_APPOINTMENTS_ON_SCREEN), ue);

         appointmentsOnScreen = 0;

            page++;
        }
      printAppointment(*(appointments + currentAppointment));
        printf("\n \n");
      appointmentsOnScreen++;
    }
    //free(prompt);
    printf("Seite %d/%d \n\n", page, (int) ceil((double) amount / (double) MAX_APPOINTMENTS_ON_SCREEN));
    waitForEnter();
}


void freeCalendar(TAppointment *appointments) {
    free(appointments);
}