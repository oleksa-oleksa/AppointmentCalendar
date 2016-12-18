#ifndef DATABASE_DATABASE_H
#define DATABASE_DATABASE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "calendar.h"
#include "datetime.h"
#include "datastructure.h"

/***************************************************************************
*  int:    saveCalendar
*  description: Opens the file and puts <Calendar> and </Canendar> beetween appointments
*  parameter:   fileName, TAppointment, counter
*  result :     notZero if was succesful saved
 *  ***************************************************************************/
int saveCalendar(char *DbFileName, TAppointment *appointments, int amount);

/***************************************************************************
*  int:    saveAppointment
*  description: Saves current appointment into file
*  parameter:   fileName,
*  result :     bool if was succesful saved
 *  ***************************************************************************/
void saveAppointment(FILE *DbFile, TAppointment *appointment);

/***************************************************************************
*  int:    writeDate
*  description: wtites formated TDate into a file
*  parameter:   pointer to a file, pointer to TDate
*  result :     -
 *  ***************************************************************************/
void writeDate(FILE *file, TDate *date);

/***************************************************************************
*  int:    writeTime
*  description: wtites formated TTime into a file
*  parameter:   pointer to a file, pointer to TTime
*  result :     -
 *  ***************************************************************************/
void writeTime(FILE *, TTime *);

/***************************************************************************
*  int:    writeTDuration
*  description: is equal to writeTime
***************************************************************************/
void writeDuration(FILE *, TTime *);

#endif