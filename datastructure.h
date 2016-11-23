#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H DATASTRUCTURE_H

#define MAX_APPOINTMENTS 100
#define MAX_CHARS 20
#define MAX_DESCRIPTION 100
#define MAX_LOCATION 15

typedef enum {
    NotaDay, Mo, Tu, We, Th, Fr, Sa, Su
} TDayOfTheWeek;

typedef struct {
    int Day;
    int Month;
    int Year;
    TDayOfTheWeek DayOfTheWeek;
} TDate;


typedef struct {
    int Hour;
    int Minute;
    int Second;
} TTime;


typedef struct {
    TDate Date;
    TTime Time;
    char *Description;
    char *Location;
    TTime *Duration;
} TAppointment;

extern int countAppointment;
extern TAppointment Calendar[];

#endif //DATASTRUCTURE_H
