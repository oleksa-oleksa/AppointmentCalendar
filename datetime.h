#ifndef DATETIME_H
    #define DATETIME_H DATETIME_H

    /***************************************************************************
     *  function:    isLeapYear
     *  description: Checks if the input date is a leap year.
     *  parameter:   year: the input year
     *  result :     Returns if the year is a leap year.
     ***************************************************************************/
    int isLeapYear (int year);

    /***************************************************************************
     *  function:    getDaysOfMonth
     *  description: Returns the amount of days of the input month.
     *  parameter:   date: the input date
     *  result :     Returns the number of days as integer.
     ***************************************************************************/
    int getDaysOfMonth(TDate date);

    /***************************************************************************
     *  function:    isDateValid
     *  description: Checks if the input date is valid.
     *  parameter:   date: The input date to check.
     *  result :     Returns 1 if valid, 0 if invalid.
     ***************************************************************************/
    int isDateValid(TDate date);

    /***************************************************************************
     *  function:    isTimeValid
     *  description: Checks if the input time is valid.
     *  parameter:   time: The input time to check.
     *  result :     Returns 1 if valid, 0 if invalid.
     ***************************************************************************/
    int isTimeValid(TTime time);

    /***************************************************************************
     *  function:    getDateFromString
     *  description: Parses the input string into a TDate.
     *  parameter:   input: the input string
     *               date: the output TDate
     *  result :     1 if the date is valid, 0 if the date is invalid.
     ***************************************************************************/
    int getDateFromString(char *input, TDate *date);

    /***************************************************************************
     *  function:    getTimeFromString
     *  description: Parses the input string into a TTime.
     *  parameter:   input: the input string
     *               date: the output TTime
     *  result :     1 if the date is valid, 0 if the date is invalid.
     ***************************************************************************/
    int getTimeFromString(char *input, TTime *time);

/***************************************************************************
 *  function:    getDate
 *  description: Asks for time input by user
 *  parameter:   char *prompt: prompt for input
 *
 *  result :
 ***************************************************************************/
//TODO: Alexandra: getDate lässt Benutzer ein Datum eingeben.
//TODO: Alexandra: getTime lässt Benutzer eine Zeit eingeben.
//TODO: getDateFromString um Ermittlung des Wochentags erweitern.
//TODO: getTimeFromString ändern - es soll möglich sein, eine Uhrzeit wahlweise mit oder ohne Sekunden anzugeben.
//TODO: printDate soll Datum formatiert ausgeben
//TODO: printTime soll Zeit formatiert ausgeben.
#endif //UEB1_DATETIME_H

