#ifndef UEB1_CALENDAR_H
#define UEB1_CALENDAR_H

#include "datastructure.h"

/***************************************************************************
 *  Creates a new appointment with optional Location and Duration
 ***************************************************************************/
void createAppointment(TAppointment *appointment);

/***************************************************************************
 *
***************************************************************************/
void editAppointment();

/***************************************************************************
 *
***************************************************************************/
void deleteAppointment();

/***************************************************************************
 *
 ***************************************************************************/
void searchAppointment();

/***************************************************************************
 *  Main function for sorting
 ***************************************************************************/
void sortCalendar(TAppointment *appointments, int amount);

/***************************************************************************
 *  Helper: printAppointment
 ***************************************************************************/
void listCalendar(TAppointment *appointments, int amount);

/***************************************************************************
 *  Frees allocated memory
 ***************************************************************************/
void freeCalendar(TAppointment *appointments);

/***************************************************************************
 *  Prints Information how many new appointmens are created
 ***************************************************************************/
void printInfoNewAppointments(int n);
void printInfoSortedAppointments(int n);

/***************************************************************************
 *  Prints aate and aay of the week
 ***************************************************************************/
void printDateHeader(TAppointment *a);

void printLineAppointment();

#endif //UEB1_CALENDAR_H
