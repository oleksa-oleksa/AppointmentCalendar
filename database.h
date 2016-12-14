#ifndef DATABASE_DATABASE_H
#define DATABASE_H DATABASE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "calendar.h"
#include "datetime.h"
#include "datastructure.h"

/***************************************************************************
*  int:    saveCalendar
*  description: Opens the file and puts <Calendar> and </Canendra> beetween appointments
*  parameter:   fileName,
*  result :     bool if was succesful saved
 *  ***************************************************************************/
int saveCalendar(char *DbFileName);