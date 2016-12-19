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
****************************************************************************/
int saveCalendar(char *DbFileName, TAppointment *appointments, int amount);


/***************************************************************************
*  void:    saveAppointment
*  description: Saves current appointment into file
*  parameter:   see function arguments
* ***************************************************************************/
void saveAppointment(FILE *DbFile, TAppointment *appointment);


/***************************************************************************
*  int:    loadAppointment
*  description: loads current appointment into TAppointment
*  result :     not a zero of appointment is correct
* ***************************************************************************/
int loadAppointment(FILE *DbFile, TAppointment *appointment);


/***************************************************************************
*  int:    loadCalendar
*  description: Opens the file and searchs for <Calendar> and </Calendar> beetween appointments
*  parameter:   fileName, TAppointment, counter
*  result :     notZero if was succesful opened and a data is transfered into a memory
 *  ***************************************************************************/
int loadCalendar(char *, TAppointment *, int amount);

/***************************************************************************
*  int:    writeDate
*  description: wtites formated TDate into a file
*  parameter:   pointer to a file, pointer to TDate
*  result :     -
****************************************************************************/
void writeDate(FILE *file, TDate *date);

/***************************************************************************
*  int:    writeTime
*  description: writes formated TTime into a file
*  parameter:   pointer to a file, pointer to TTime
*  result :     -
****************************************************************************/
void writeTime(FILE *, TTime *);


/***************************************************************************
*  int:    writeTDuration
*  description: is equal to writeTime
***************************************************************************/
void writeDuration(FILE *, TTime *);


/***************************************************************************
*  void:    printDbInfo
*  description: prints the amount of appointments in the dagtabase-file
*  or zero if file is empty
***************************************************************************/
void printDbInfo(int);


/***************************************************************************
*  void:    deleteWhiteSpaces
*  description: deletes spaces and horisontal tabs
***************************************************************************/
void deleteWhiteSpaces(char *);


/***************************************************************************
*  int:    parceTag
*  description: parses a tag and recognizes it
*  parameter:   pointer to an memory address
*  result :     zero if tag is wrong, else one is returned (changes a pointer)
*  ***************************************************************************/
int parseTag(char **pThisLine, int l);


/***************************************************************************
*  void:    reallocTagMemory
*  description: reallocates a memory according with a real size of string
***************************************************************************/
void reallocTagMemory(char **pThisStr);

/***************************************************************************
*  void:    parseDateInAppointment
*  description: parces a date in format dd:mm:yyyy
 *  into a TDate of current appointment
***************************************************************************/
void parseDateInAppointment(FILE *, fpos_t **, char **);

#endif