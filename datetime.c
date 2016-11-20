#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"
#include "tools.c"


/***************************************************************************
*  function:    isLeapYear
*  description: Checks if the input date is a leap year.
***************************************************************************/
int isLeapYear (int Y)
{
    int leap;

    if (Y % 4 == 0)
    {
        if (Y % 100 != 0)
        {
            leap = 1;
        }

        else
        if (Y % 400 == 0)
        {
            leap = 1;
        }

        else
        {
            leap = 0;
        }
    }
    else
    {
        leap = 0;
    }

    return leap;
}

/***************************************************************************
*  function:    getDaysOfMonth
*  description: Returns the amount of days of the input month.
***************************************************************************/
int getDaysOfMonth(TDate Date)
{
    int daysOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(Date.Month == 2)
    {
        if(isLeapYear(Date.Year))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
    if(Date.Month >= 1 && Date.Month <=12)
    {
        return daysOfMonth[Date.Month];
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

int isDateValid(TDate Date)
{
    if(getDaysOfMonth(Date) && Date.Day <= getDaysOfMonth(Date) && Date.Day > 0 && Date.Year >= 0 )
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
int getDateFromString(char *Input, TDate *Date)
{

    int D, M, Y, CheckDate;
    char point = '.';
    char *pD, *pM, *pY, *tmp;

    pD = Input;
    tmp = Input;

    // Looking for a first non-digit sign and moving a pointer to a month´s side
    while (*tmp && (*tmp >= '0' && *tmp <= '9'))
    {
        tmp++;
    }

    D = atoi(pD);

    // checks if the correct point was entered
    CheckDate = (point == *tmp);

    tmp++; // Skips the dots

    pM = tmp;

    while (*tmp && (*tmp >= '0' && *tmp <= '9'))
    {
        tmp++;
    }

    M = atoi(pM);

    CheckDate *= (point == *tmp);

    if (*tmp == '\0') {
        return 0;
    }
    tmp++; // Skips the dots
    pY = tmp;

    Y = atoi(pY);

    Date->Day = D;
    Date->Month = M;
    Date->Year = Y;

    CheckDate *= isDateValid (*Date);


    return CheckDate;

}

/***************************************************************************
*  function:    isTimeValid
*  description: Checks if the input time is valid.
***************************************************************************/
int isTimeValid(TTime Time)
{
    if(Time.Hour >= 0 && Time.Hour <= 23 && Time.Minute >= 0 && Time.Minute <= 59 && Time.Second >= 0 && Time.Second <= 59)
        return 1;
    else
        return 0;
}

/***************************************************************************
*  function:    getTimeFromString
*  description: Parses the input string into a TTime.
***************************************************************************/
int getTimeFromString(char *Input, TTime *Time, int withSec)
{
    //h = hour, m = minute, s = second
    int H, Min, S = 0, CheckTime;
    char semicol = ':';

    //pH = pHour, pM = pMinute, pS = pSecond, tmpT = pTmpTime
    char *pH, *pMin, *pS, *tmpT;

    pH = Input;
    tmpT = Input;

    while (*tmpT >= '0' && *tmpT <= '9' )
    {
        tmpT++;
    }

    // the (probably) semicolon was found
    // reading the hours
    H = atoi (pH);

    // checking if a semicolon stays in a string entered
    CheckTime = (semicol == *tmpT);

    tmpT++;
    pMin = tmpT;

    while (*tmpT >= '0' && *tmpT <= '9' )
    {
        tmpT++;
    }

    // the (probably) semicolon was found
    // reading the minutes
    Min = atoi (pMin);

    if (withSec) {
        // checking if a semicolon stays in a string entered
        CheckTime *= (semicol == *tmpT);

        tmpT++;
        pS = tmpT;


        // reading the seconds
        S = atoi(pS);
    }

    CheckTime *= isTimeValid (*Time);

    Time->Hour = H;
    Time->Minute = Min;
    Time->Second = S;

    return CheckTime;

}

void printTime(TTime time) {
    printf("%d:%d", time.Hour, time.Minute);
}


/***************************************************************************
*  function:    getDate
*  description: reads an user´s Input, calls the sub-function for check
***************************************************************************/
void getDate (char *InfoText, TDate *Date)
{
    char EnteredDate[MAX_CHARS];
    int CheckDate;

    do
    {
        printf("%s", InfoText);
        CheckDate = scanf("%s", EnteredDate);
        clearBuffer();
        if (CheckDate)
        {

            CheckDate *= getDateFromString(EnteredDate, Date);
        }

    } while (!CheckDate);

}


/***************************************************************************
*  function:    getTime
*  description: reads an user´s Input, calls the sub-function for check
***************************************************************************/
void getTime (char *InfoText, TTime *Time, int withSec)
{
    char EnteredDate[MAX_CHARS];
    int CheckDate;

    do
    {
        printf("%s", InfoText);
        CheckDate = scanf("%s", EnteredDate);
        clearBuffer();
        if (CheckDate)
        {

            CheckDate *= getTimeFromString(EnteredDate, Time, withSec);
        }

    } while (!CheckDate);

}











