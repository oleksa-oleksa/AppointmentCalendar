#ifndef DATETIME_H
#define DATETIME_H DATETIME_H

/**********************************
* Funktionergebnisse ist Wahrheitswert,
* ob angegebene Datum ein gültiges Datum ist
**********************************/
int getDateFromString(char *, TDate *);

/**********************************
* checks if the entered date is valid
**********************************/
int isDateValid (TDate);

/**********************************
* Is a year leap?
**********************************/
int isLeapYear (int Y);


/**********************************
* Checks 31th day
** 1,3,5,7 months have 31 day, 8,10,12 have the same.
** the rest has 30 days
**********************************/
int getDaysOfMonth(TDate);

/**********************************
* INext 2 Funktions check the time
**********************************/
int getTimeFromString (char *, TTime *);


/**********************************
* checks if the entered time is valid
**********************************/
int isTimeValid (TTime);



#endif