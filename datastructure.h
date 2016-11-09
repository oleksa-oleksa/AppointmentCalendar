#ifndef DATASTRUCTURE_H
    #define DATASTRUCTURE_H DATASTRUCTURE_H

    #define MAX_APPOINTMENTS 100



    extern int countAppointment;



  enum TDayOfTheWeek {NotaDay, Mo, Tu, We, Th, Fr, Sa, Su};

    typedef struct
    {
        int Day;
        int Month;
        int Year;
        enum TDayOfTheWeek DayOfTheWeek;
    } TDate;


    typedef struct
    {
        int Hour;
        int Minute;
        int Second;
    } TTime;


typedef struct
{
    TDate Date;
    TTime Time;
    char Decription;
    char Location;

} TAppointment;

extern TAppointment Calendar[];
#endif //DATASTRUCTURE_H
