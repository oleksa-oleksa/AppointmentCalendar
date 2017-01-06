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
    tmpAppointment->Duration = 0;
    tmpAppointment->Location = 0;

    clearScreen();

    printLine('=', 35);
    printf("   Erfassung eines neuen Termins\n");
    printLine('=', 35);
    printf("\n");

    getDate("Datum        : ", &(tmpAppointment->Date));
    getTime("Uhrzeit      : ", &(tmpAppointment->Time), 0, 0);

    TTime *duration = malloc(sizeof(TTime));
    memset(duration, 0, sizeof(TTime));
    getTime("Dauer        : ", duration, 0, 1);
    if (duration->Second == duration->Minute == duration->Hour == 0) {
        free(duration);
    } else {
        tmpAppointment->Duration = duration;
    }

    getText("Beschreibung : ", MAX_DESCRIPTION, &(tmpAppointment->Description), 0);
    getText("Ort          : ", MAX_LOCATION, &(tmpAppointment->Location), 1);
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

    if ((a->Location == NULL) && (b->Location == NULL))
        return 0;

    if (a->Location == NULL)
        return 1;

    if (b->Location == NULL)
        return -1;

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

    if ((a->Duration == NULL) && (b->Duration == NULL))
        return 0;

    if (a->Duration == NULL)
        return 1;

    if (b->Duration == NULL)
        return -1;

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
        clearScreen();
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
                waitForEnter();
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

void printAppointment(TAppointment *appointment) {
    printf("\n   ");
    printTime(appointment->Time);

    TTime endTime = appointment->Time;

    if(appointment->Duration != NULL)
    {
        addTime(&appointment->Time, appointment->Duration, &endTime);
        printf(" - ");
        printTime(endTime);
    } else printf(":       ");


    char *Location = "";
    char *LP = "";


    if (appointment->Location) {
        Location = appointment->Location;
        LP = "->";
    }
    else {
        Location = "               ";
        LP = "  ";
    }

    /******* If Description is longer 48 symbols, then print only first 44 symbols */

    char *tmpDes = appointment->Description;

    if (strlen(appointment->Description) <= 48)
        printf(" %s %-15s | %-48s", LP, Location, appointment->Description);

    else {
        printf(" %s %-15s  | ", LP, Location);
        for (int i = 0; i < 44; i++)
        {
            printf("%c", *(tmpDes + i));
        }
        printf(" ...");


    }


}

void printLineAppointment()
{
    printf("\n");
    printLine('=', 90);
    printf("\n\n");

}

void printInfoSortedAppointments(int newN)
{
    FORECOLOR_BLUE;
    printf("Datenreihenfolge wurde aktualisiert\n");
    ATTRIBUTE_OFF;
}

void printInfoNewAppointments(int newN)
{

    if (newN == 1)
    {
        FORECOLOR_BLUE;
        printf("%d neuer Termin is angelegt\n", newN);
        ATTRIBUTE_OFF;
    }

    else
    {
        FORECOLOR_BLUE;
        printf("%d neuen Termine is angelegt\n", newN);
        ATTRIBUTE_OFF;
    }
}

void printDateHeader(TAppointment *a)
{
    FORECOLOR_GREEN;
    printDate(a->Date);
    ATTRIBUTE_OFF;
    printf("\n");
    printLine('-', 15);

}


void listCalendar(TAppointment *appointments, int amount) {
   int appointmentsOnScreen = 0; //saves the number of appointments on the screen
   int page = 1;
    clearScreen();
    printLine('=', 90);
    printf("                                 Liste der Termine\n");
    printLine('=', 90);
    printf("\n");

    char *prompt = malloc(strlen("Bitte Enter drücken, um die nächsten 100 Termine anzuzeigen...") * sizeof(char));
   for (int currentAppointment = 0; currentAppointment < amount; currentAppointment++)
   {
      if (appointmentsOnScreen >= 10)
      {
         if (amount - 1 - currentAppointment >= 10)
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


      /**** If current appointment has the same date as previous, the date will not be printed twice */

       int isHeaderRequired = (currentAppointment == 0 ||
                                      orderByDate ((appointments + currentAppointment -1), (appointments + currentAppointment)) != 0);

       if (isHeaderRequired) {
          if (currentAppointment != 0)
              printLineAppointment();
          printDateHeader(appointments + currentAppointment);

       }

       // Part for each appointment
       printAppointment(appointments + currentAppointment);

       printf("\n \n");
       appointmentsOnScreen++;
    }

    printf("Seite %d/%d \n\n", page, (int) ceil((double) amount / (double) MAX_APPOINTMENTS_ON_SCREEN));
    free(prompt);
    waitForEnter();
}


void freeCalendar(TAppointment *appointments) {
    free(appointments);
}