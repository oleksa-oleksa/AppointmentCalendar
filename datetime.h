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
     *  function:    printTime
     *  description: prints a TTime one the screen
     *  parameter:   time: the time to print
     *  result :
     ***************************************************************************/
    void printTime(TTime time);

/***************************************************************************
*  function:
*  description:
*  parameter:
*  result :
***************************************************************************/
void printDate(TDate date);
    /***************************************************************************
     *  function:    getDate
     *  description: reads an user´s Input, calls the sub-function for check
     *  parameter:   InfoText: Information for user what to do
     *               TDate: pointer for data structure
     *  result :
     ***************************************************************************/
    void getDate (char *InfoText, TDate *Date);

    /***************************************************************************
     *  function:    getTime
     *  description: reads an user´s Input, calls the sub-function for check
     *  parameter:   InfoText: Information for user what to do
     *               TTime: pointer for data structure
     *               withSec: 1 is for reading the seconds; 0 is for ignoring the input of seconds
     *  result :
     ***************************************************************************/
    void getTime (char *InfoText, TTime *Time, int witSec);


//TODO: Alexandra: getTime IN TEST

#endif

