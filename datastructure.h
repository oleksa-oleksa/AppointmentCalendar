#ifndef DATASTRUCTURE_H
    #define DATASTRUCTURE_H DATASTRUCTURE_H

    #define MAX_APPOINTMENTS 100

    typedef struct
    {
        TDate Date;
        TTime Time;
        char Decription;
        char Location;

    } TAppointment;

    extern int countAppointment;
    extern TAppointment Calendar[];


  enum TDayOfTheWeek {NotaDay, Mo, Tu, We, Th, Fr, Sa, Su};

    typedef struct
    {
        int Day;
        int Month;
        int Year;
        TDayOfTheWeek DayOfTheWeek;
    } TDate;

    typedef struct
    {
        int Hour;
        int Minute;
        int Second;
    } TTime;



#endif //DATASTRUCTURE_H
