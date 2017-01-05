#ifndef UEB1_CALENDAR_H
#define UEB1_CALENDAR_H

#include "datastructure.h"

/***************************************************************************
 *  function:    createAppointment
 *  description:
 *  parameter:
 *  result :
 ***************************************************************************/
void createAppointment(TAppointment *appointment);
/***************************************************************************
 *  function:    editAppointment
 *  description: 
 *  parameter:   
 *  result :     
 ***************************************************************************/
void editAppointment();
/***************************************************************************
 *  function:    deleteAppointment
 *  description: 
 *  parameter:   
 *  result :     
 ***************************************************************************/
void deleteAppointment();
/***************************************************************************
 *  function:    searchAppointment
 *  description:
 *  parameter:
 *  result :
 ***************************************************************************/
void searchAppointment();
/***************************************************************************
 *  function:    sortCalendar
 *  description:
 *  parameter:
 *  result :
 ***************************************************************************/
void sortCalendar(TAppointment *appointments, int amount);
/***************************************************************************
 *  function:    listCalendar
 *  description:
 *  parameter:
 *  result :
 ***************************************************************************/
void listCalendar(TAppointment *appointments, int amount);

/***************************************************************************
 *  function:    
 *  description: 
 *  parameter:   
 *  result :     
 ***************************************************************************/
void freeCalendar(TAppointment *appointments);

/***************************************************************************
 *  function: printInfoNewAppointments
 *  description: Prints Information how many new appointmens are created
 *  parameter:
 *  result :  text on the screen
 ***************************************************************************/
void printInfoNewAppointments(int n);

void printInfoSortedAppointments(int n);

void printDateHeader(TAppointment *a);

void printLineAppointment();

#endif //UEB1_CALENDAR_H
