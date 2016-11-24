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
void freeAppointment(TAppointment **appointment);

void freeCalendar(TAppointment **appointment, int amount);

//TODO: Kati: freeCalendar
//TODO: Tim: freeAppointment
//TODO: Kati: listCalendar gibt nach Ausgabe einer Listenüberschrift alle Termine tabellarisch aus. Zuerst wird das Datum ausgegeben, darunter alle Termine dieses Datums.
//TODO: Tim: createAppointment lässt den Benutzer einen neuen Termin erstellen. Benutzer soll Datum, Uhrzeit, Terminbeschreibung, Ort und Dauer eingeben können.
#endif //UEB1_CALENDAR_H
