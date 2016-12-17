//
// Created by tim on 28.10.16.
//

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
void sortCalendar();
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

#endif //UEB1_CALENDAR_H
