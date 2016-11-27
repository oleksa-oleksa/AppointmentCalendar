#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"
#include "tools.h"
#include <math.h>


/***************************************************************************
*  function:    isLeapYear
*  description: Checks if the input date is a leap year.
***************************************************************************/
int isLeapYear(int year)
{
   int isLeapYear;

   if (year % 4 == 0)
    {
       if (year % 100 != 0)
        {
           isLeapYear = 1;
        }

        else if (year % 400 == 0)
        {
           isLeapYear = 1;
        }

        else
        {
           isLeapYear = 0;
        }
    }
    else
    {
       isLeapYear = 0;
    }

   return isLeapYear;
}

/***************************************************************************
*  function:    getDaysOfMonth
*  description: Returns the amount of days of the input month.
***************************************************************************/
int getDaysOfMonth(TDate date)
{
    int daysOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   if (date.Month == 2)
    {
       if (isLeapYear(date.Year))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
   if (date.Month >= 1 && date.Month <= 12)
    {
       return daysOfMonth[date.Month];
    }
    else
    {
        return 0;
    }
}
/***************************************************************************
*  function:    isDateValid
*  description: Checks if the input date is valid.
***************************************************************************/

int isDateValid(TDate date)
{
   if (getDaysOfMonth(date) && date.Day <= getDaysOfMonth(date) && date.Day > 0 && date.Year >= 0)
    {
        return 1;
    }
    else{
        return 0;
    }
}


/* Checks if the entered year is a leap year, if a 29.02 was entered
*/ // added new Tim

/***************************************************************************
 *  function:    getDateFromString
 *  description: Parses the input string into a TDate.
 ***************************************************************************/
int getDateFromString(char *pInput, TDate *pDate)
{

   int givenDay;
   int givenMonth;
   int givenYear;
   int julianYear;
   int julianMonth;
   int isValid; //If the given delimiter is valid.
   int intDayOfTheWeek;
   int first2DigitsOfYear; //Die beiden ersten Stellen der Jahreszahl, bei den Monaten Januar und Februar die ersten Stellen des Vorjahres
   char delimiter = '.';
   char *pDay; //String that holds the number of the day.
   char *pMonth; //String that holds the number of the month.
   char *pYear; //String that holds the number of the year.
   char *pTmp; //String to save a string temporarily

    int months[] = {0, 11, 12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //Months in julian count
   pDay = pInput;
   pTmp = pInput;

    // Looking for a first non-digit sign and moving a pointer to a month´s side
   while (*pTmp && (*pTmp >= '0' && *pTmp <= '9'))
    {
       pTmp++;
    }

   givenDay = atoi(pDay);

   // checks if the correct delimiter was entered
   isValid = (delimiter == *pTmp);

   pTmp++; // Skips the dots

   pMonth = pTmp;

   while (*pTmp && (*pTmp >= '0' && *pTmp <= '9'))
    {
       pTmp++;
    }

   givenMonth = atoi(pMonth);

   isValid *= (delimiter == *pTmp);

   if (*pTmp == '\0')
   {
        return 0;
    }
   pTmp++; // Skips the dots
   pYear = pTmp;

   givenYear = atoi(pYear);

   pDate->Day = givenDay;
   pDate->Month = givenMonth;
   pDate->Year = givenYear;

   isValid *= isDateValid(*pDate);

   julianMonth = months[givenMonth];

   if (julianMonth == 2 || julianMonth == 1)
   {
      first2DigitsOfYear = (int) floor(givenYear - 1 / 100);
    } else {
      first2DigitsOfYear = (int) floor(givenYear / 100);
    }

   if (julianMonth == 2 || julianMonth == 1)
   {
      julianYear = (int) floor(givenYear - 1 % 100);
    } else {
      julianYear = (int) floor(givenYear % 100);
    }

   double x = (givenDay + (2.6 * julianMonth - 0.2) + julianYear + (julianYear / 4) + (first2DigitsOfYear / 4) -
               2 * first2DigitsOfYear);



    intDayOfTheWeek = (int) x % 7;

    switch (intDayOfTheWeek) {
        case 0:
           pDate->DayOfTheWeek = Su;
            break;
        case 1:
           pDate->DayOfTheWeek = Mo;
            break;
        case 2:
           pDate->DayOfTheWeek = Tu;
            break;
        case 3:
           pDate->DayOfTheWeek = We;
            break;
        case 4:
           pDate->DayOfTheWeek = Th;
            break;
        case 5:
           pDate->DayOfTheWeek = Fr;
            break;
        case 6:
           pDate->DayOfTheWeek = Sa;
            break;
        default:
            break;
    }

   return isValid;

}

/***************************************************************************
*  function:    isTimeValid
*  description: Checks if the input time is valid.
***************************************************************************/
int isTimeValid(TTime time)
{
   if (time.Hour >= 0 && time.Hour <= 23 && time.Minute >= 0 && time.Minute <= 59 && time.Second >= 0 &&
       time.Second <= 59)
        return 1;
    else
        return 0;
}

/***************************************************************************
*  function:    getTimeFromString
*  description: Parses the input string into a TTime.
***************************************************************************/
int getTimeFromString(char *input, TTime *pTime, int withSeconds)
{
    //h = hour, m = minute, s = second
   int hour;
   int minute;
   int second;
   int isValid;
   char delimiter = ':';

   //pHour = pHour, pM = pMinute, pS = pSecond, tmpT = pTmpTime
   char *pHour;
   char *pMinute;
   char *pSecond;
   char *pTmp;

   pHour = input;
   pTmp = input;

   while (*pTmp >= '0' && *pTmp <= '9')
    {
       pTmp++;
    }

    // the (probably) semicolon was found
    // reading the hours
   hour = atoi(pHour);

    // checking if a semicolon stays in a string entered
   isValid = (delimiter == *pTmp);

   pTmp++;
   pMinute = pTmp;

   while (*pTmp >= '0' && *pTmp <= '9')
    {
       pTmp++;
    }

    // the (probably) semicolon was found
    // reading the minutes
   minute = atoi(pMinute);

   if (withSeconds)
   {
        // checking if a semicolon stays in a string entered
      isValid *= (delimiter == *pTmp);

      pTmp++;
      pSecond = pTmp;


        // reading the seconds
      second = atoi(pSecond);
      pTime->Hour = hour;
      pTime->Minute = minute;
      pTime->Second = second;
    }

    else {

      second = 0;
      pTime->Hour = hour;
      pTime->Minute = minute;
      pTime->Second = second;
    }

   isValid *= isTimeValid(*pTime);

   return isValid;

}

void printTime(TTime time) {
    printf("%02d:%02d", time.Hour, time.Minute);
}


/***************************************************************************
*  function:    getDate
*  description: reads an user´s Input, calls the sub-function for check
***************************************************************************/
void getDate(char *pInfoText, TDate *pDate)
{
   char enteredDate[MAX_CHARS];
   int isValid;

    do
    {
       printf("%s", pInfoText);
       isValid = scanf("%s", enteredDate);
        clearBuffer();
       if (isValid)
        {

           isValid *= getDateFromString(enteredDate, pDate);
        }

    } while (!isValid);

}


/***************************************************************************
*  function:    getTime
*  description: reads an user´s Input, calls the sub-function for check
***************************************************************************/
void getTime(char *pInfoText, TTime *pTime, int withSeconds)
{
   char enteredDate[MAX_CHARS];
   int isValid;

    do
    {
       printf("%s", pInfoText);
       isValid = scanf("%s", enteredDate);
        clearBuffer();

       if (isValid)
        {
           isValid *= getTimeFromString(enteredDate, pTime, withSeconds);
        }

    } while (!isValid);

}


void printDate(TDate date) {

    printf("XX, %d.%d.%d", date.Day, date.Month, date.Year);

}