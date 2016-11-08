#ifndef DATASTRUCTURE_H
    #define DATASTRUCTURE_H DATASTRUCTURE_H
    #define MAX-APPOINTMENTS 100;

    typedef struct
    {
        int NotADay = 0;
        int Mo = 1;
        int Tu = 2;
        int We = 3;
        int Th = 4;
        int Fr = 5;
        int Sa = 6;
        int Su = 7;

    } TDayOfTheWeek;

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

    typedef struct
    {
        TDate Date;
        TTime Time;
        char Decription;
        char Location;

    } TAppointment;

#endif //UEB1_DATASTRUCTURE_H
