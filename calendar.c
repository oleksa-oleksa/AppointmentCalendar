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
#include "escapesequenzen.h"
#include "database.h"

int AppointmentCount = 0;
TAppointment Calendar[MAX_APPOINTMENTS];

void createAppointment(TAppointment *appointment) {
    TAppointment *tmpAppointment = malloc(sizeof(TAppointment));

    clearScreen();

    printLine('-', 78);
    printf("                     Neuen Termin anlegen:\n");
    printLine('-', 78);
    printf("\n");

    getDate("Datum: ", &(tmpAppointment->Date));
    getTime("Uhrzeit: ", &(tmpAppointment->Time), 0);
    (*(tmpAppointment)).Duration = malloc(sizeof(TTime));
    getTime("Dauer: ", tmpAppointment->Duration, 0);
    getText("Beschreibung: ", MAX_DESCRIPTION, &(tmpAppointment->Description), 0);
    getText("Ort: ", MAX_LOCATION, &(tmpAppointment->Location), 1);
    *appointment = *tmpAppointment;
    free(tmpAppointment);
    FORECOLOR_GREEN;
    printf("\n\nNeuen Termin ist angelegt. \n\n");
    ATTRIBUTE_OFF;
    waitForEnter();
}

void editAppointment() {

}

void deleteAppointment() {

}

void searchAppointment() {

}

int orderByDescription(TAppointment *a, TAppointment *b)
{

    int n = strcmp(a->Description, b->Description);

    if (n == 0) {
        return 0;
    }
    else {
        if (n < 0)
            return -1;
        else
            return 1;
    }

}


int orderByLocation(TAppointment *a, TAppointment *b)
{

    int n = strcmp(a->Location, b->Location);

    if (n == 0) {
        return 0;
    }
    else {
        if (n < 0)
            return -1;
        else
            return 1;
    }

}

int orderByTime(TAppointment *a, TAppointment *b)
{
    if (a->Time.Hour < b->Time.Hour) {
        return -1;
    }


    if (a->Time.Hour > b->Time.Hour) {
        return 1;
    }


        if (a->Time.Minute == b->Time.Minute) {

            if (a->Time.Second == b->Time.Second) {
                return 0;
            }

            else {
                if (a->Time.Second > b->Time.Second) {
                    return 1;
                }

                else {
                    return -1;
                }
            }
        }
        else {
            if (a->Time.Minute > b->Time.Minute) {
                return 1;
            }

            else {
                return -1;
            }
        }
}



int orderByDuration(TAppointment *a, TAppointment *b)
{
    if (a->Duration->Hour < b->Duration->Hour) {
        return -1;
    }


    if (a->Duration->Hour > b->Duration->Hour) {
        return 1;
    }


        if (a->Duration->Minute == b->Duration->Minute) {

            if (a->Duration->Second == b->Duration->Second) {
                return 0;
            }

            else {
                if (a->Duration->Second > b->Duration->Second) {
                    return 1;
                }

                else {
                    return -1;
                }
            }
        }
        else {
            if (a->Duration->Minute > b->Duration->Minute) {
                return 1;
            }

            else {
                return -1;
            }
        }
 }


int orderByDate(TAppointment *a, TAppointment *b)
{

    if (a->Date.Year < b->Date.Year) {
       return -1;
    }


    if (a->Date.Year > b->Date.Year) {
     return 1;
    }


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

int orderByDateTime(TAppointment *a, TAppointment *b)
{
    int dateComparison = orderByDate(a, b);

    if (dateComparison == 0)
        return orderByTime(a, b);

    return dateComparison;

}

int orderByDescriptionDateTime(TAppointment *a, TAppointment *b)
{
    int desComp = orderByDescription(a, b);

    if (desComp == 0)
        return orderByDateTime(a,b);

    return desComp;
}

int orderByLocationDateTime(TAppointment *a, TAppointment *b)
{
    int locComp = orderByLocation(a, b);

    if (locComp == 0)
        return orderByDateTime(a,b);

    return locComp;
}

int orderByDurationDateTime(TAppointment *a, TAppointment *b)
{
    int locComp = orderByDuration(a, b);

    if (locComp == 0)
        return orderByDateTime(a,b);

    return locComp;


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
                quickSortAppointments(appointments, amount, orderByDateTime);
                FORECOLOR_GREEN;
                printf("\n\nTermine sind nach Datum sortiert\n");
                ATTRIBUTE_OFF;
                printLine('-', strlen("Termine sind nach Datum sortiert"));
                printf("\n");
                waitForEnter();
                return;
            case 2:
                quickSortAppointments(appointments, amount, orderByDescriptionDateTime);
                FORECOLOR_GREEN;
                printf("Termine sind nach Beschreibung sortiert\n");
                ATTRIBUTE_OFF;
                printLine('-', strlen("Termine sind nach Beschreibung sortiert"));
                printf("\n");
                return;
            case 3:
                quickSortAppointments(appointments, amount, orderByLocationDateTime);
                FORECOLOR_GREEN;
                printf("Termine sind nach Ort sortiert\n");
                ATTRIBUTE_OFF;
                printLine('-', strlen("Termine sind nach Ort sortiert"));
                printf("\n");
                waitForEnter();
                return;

            case 4:
                quickSortAppointments(appointments, amount, orderByDurationDateTime);
                FORECOLOR_GREEN;
                printf("Termine sind nach Dauer sortiert\n");
                ATTRIBUTE_OFF;
                printLine('-', strlen("Termine sind nach Dauer sortiert"));
                printf("\n");
                waitForEnter();
                return;

            case 5:
                break;

            default: printf("Fehler");
        }
    }while (choice != 5);

}

void printAppointment(TAppointment appointment) {
    FORECOLOR_BLACK;
    printLine('=', 78);
    ATTRIBUTE_OFF;
    printf("\n");
    FORECOLOR_GREEN;
    printDate(appointment.Date);
    ATTRIBUTE_OFF;
    printf("\n");
    printLine('-', 15);
    printf("\n   ");
    printTime(appointment.Time);

    TTime endTime;

    if(appointment.Duration != 0)
    {
        addTime(&appointment.Time, appointment.Duration, &endTime);
    }
    printf(" - ");
    printTime(endTime);

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
    clearScreen();
    printLine('=', 78);
    printf("                          Liste der Termine\n");
    printLine('=', 78);
    printf("\n");

    char *prompt = malloc(strlen("Bitte Enter drücken, um die nächsten 100 Termine anzuzeigen...") * sizeof(char));
   for (int currentAppointment = 0; currentAppointment < amount; currentAppointment++)
   {
      if (appointmentsOnScreen >= 5)
      {
         if (amount - 1 - currentAppointment >= 5)
         {
                sprintf(prompt, "Seite %d/%d \n\nBitte Enter drücken, um die nächsten %d Termine anzuzeigen",
                        page, (int) ceil((double) amount / (double) MAX_APPOINTMENTS_ON_SCREEN),
                        MAX_APPOINTMENTS_ON_SCREEN);
                waitForEnterSpecialPrompt(prompt);
                clearScreen();

            } else {
                sprintf(prompt, "Seite %d/%d \n\nBitte Enter drücken, um die nächsten %d Termine anzuzeigen",
                        page, (int) ceil((double) amount / (double) MAX_APPOINTMENTS_ON_SCREEN),
                        amount - currentAppointment);
                waitForEnterSpecialPrompt(prompt);
                clearScreen();
            }

            sprintf(prompt, "Seite %d/%d \n\nBitte Enter drücken... ",
                    page, (int) ceil((double) amount / (double) MAX_APPOINTMENTS_ON_SCREEN));

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