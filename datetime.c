//
// Created by tim on 27.10.16.
//

#include "datastructure.h"
#include <stdio.h>
#include <stdlib.h>

int isLeapYear (int year){
    /*
     * Wenn teilbar durch 400 teilbar, dann Schaltjahr.
     * Wenn teilbar durch 100, dann kein Schaltjahr.
     * Wenn teilbar durch 4, dann Schaltjahr.
     */

    if (year % 400 == 0)
        return 1;

    else if (year % 100 == 0)
        return 0;

    else if (year % 4 == 0)
        return 1;

    else
        return 0;
}

int getDaysOfMonth(TDate date){
    int daysOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(date.Month == 2){
        if(isLeapYear(date.Year)){
            return 29;
        }
        else{
            return 28;
        }
    }
    if(date.Month >= 1 && date.Month <=12){
        return daysOfMonth[date.Month];
    }
    else{
        return 0;
    }
}

int isDateValid(TDate date){
    if(getDaysOfMonth(date) && date.Day <= getDaysOfMonth(date) && date.Day > 0 && date.Year >= 0 ){
        return 1;
    }
    else{
        return 0;
    }
}

int isTimeValid(TTime time){
    if(time.Hour >= 0 && time.Hour <= 23 && time.Minute >= 0 && time.Minute <= 59 && time.Second >= 0 && time.Second <= 59)
        return 1;
    else
        return 0;
}

void parse(char *input, char *first, char *second, char *third, char delimiter) {
    int countc = 0;
    int counti = 0;
    int cycle = 1;

    //TDate *tmpDate = malloc(sizeof(TDate));


    while (*(input + counti)) {
        if (*(input + counti) != delimiter) {
            switch (cycle) {
                case 1:
                    *(first + countc) = *(input + counti);
                    counti++;
                    countc++;
                    break;
                case 2:
                    *(second + countc) = *(input + counti);
                    counti++;
                    countc++;
                    break;
                case 3:
                    *(third + countc) = *(input + counti);
                    counti++;
                    countc++;

                    if (!*(input + counti)) {
                        *(third + countc) = '\0';
                        //(*tmpDate).Year = atoi(third);
                    }
                    break;
            }

        } else {
            switch (cycle) {
                case 1:
                    *(first + countc) = '\0';
                    counti++;
                    // (*tmpDate).Day = atoi(first);
                    break;
                case 2:
                    *(second + countc) = '\0';
                    //(*tmpDate).Month = atoi(second);
                    counti++;
                    break;
                case 3:
                    *(third + countc) = '\0';
                    //(*tmpDate).Year = atoi(third);
                    counti++;
                    break;
            }
            cycle++;
            countc = 0;

        }

    }
}

int getDateFromString(char *input, TDate *date){

    char *cday = malloc(sizeof(input));
    char *cmonth = malloc(sizeof(input));
    char *cyear = malloc(sizeof(input));

    parse(input, cday, cmonth, cyear, '.');

    TDate *tmpDate = malloc(sizeof(TDate));

    (*tmpDate).Day = atoi(cday);
    (*tmpDate).Month = atoi(cmonth);
    (*tmpDate).Year = atoi(cyear);


    if (isDateValid(*tmpDate)){
        *date = *tmpDate;
        return 1;
    }
    else {
        return 0;
    }
}

int getTimeFromString(char *input, TTime *time){
    char *csecond = malloc(sizeof(input));
    char *cminute = malloc(sizeof(input));
    char *chour = malloc(sizeof(input));

    parse (input, csecond, cminute, chour, ':');

    TTime *tmpTime = malloc(sizeof(TTime));

    (*tmpTime).Second = atoi(csecond);
    (*tmpTime).Minute = atoi(cminute);
    (*tmpTime).Hour = atoi(chour);

    if (isTimeValid(*tmpTime)){
        *time = *tmpTime;
        return 1;
    }
    else {
        return 0;
    }

}
