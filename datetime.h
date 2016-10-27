//
// Created by tim on 27.10.16.
//

#ifndef UEB1_DATETIME_H
#define UEB1_DATETIME_H

int isLeapYear (int year);

int getDaysOfMonth(TDate date);

int isDateValid(TDate date);

int getDateFromString(char *input, TDate *date);

int getTimeFromString(char *input, TTime *time);

#endif //UEB1_DATETIME_H
