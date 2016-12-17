#include <stdio.h>
#include <stdlib.h>
#include "calendar.h"
#include "datastructure.h"
#include "tools.h"
#include "datetime.h"
#include <string.h>
#include <math.h>


char *fBeginFile = "<Calendar>";
char *fEndFile = "</Calendar>";

char *fBeginAppointment = "<Appointment>";
char *fEndAppointment = "</Appointment>";

char *fBeginDate = "<Date>";
char *fEndDate = "</Date>";

char *fBeginTime = "<Time>";
char *fEndTime = "</Time>";

char *fBeginDuration = "<Duration>";
char *fEndDuration = "</Duration>";

char *fBeginDescription = "<Description>";
char *fEndDescription = "</Description>";

char *fBeginLocation = "<Location>";
char *fEndLocation = "</Location>";

/***************************************************************************
*  int:    writeDate
***************************************************************************/
void writeDate(FILE *file, TDate *date)
{
    fprintf(file, "%s%02i.%02i.%i%s\n", fBeginDate, date->Day, date->Month, date->Year, fEndDate);
}

/***************************************************************************
*  int:    writeTime
***************************************************************************/
void writeTime(FILE *file, TTime *time)
{
    if(time->Second) {

        fprintf(file, "%s%02i:%02i:%02i%s\n", fBeginTime, time->Hour, time->Minute, time->Second, fEndTime);
    }

    else {
        fprintf(file, "%s%02i:%02i%s\n", fBeginTime, time->Hour, time->Minute, fEndTime);
    }
}

/***************************************************************************
*  int:    writeTDuration
***************************************************************************/
void writeDuration(FILE *file, TTime *time)
{
    fprintf(file, "%s%02i:%02i%s\n", fBeginDuration, time->Hour, time->Minute, fEndDuration);
}

/***************************************************************************
*  int:    saveCAppointment
***************************************************************************/
void saveAppointment(FILE *DbFile, TAppointment appointment){

    fprintf(DbFile, "%s\n", fBeginAppointment);

    /****** Obligatory part of each appointment */
    writeDate(DbFile, &appointment.Date);
    writeTime(DbFile, &appointment.Time);



    /****** Optional part of appointment */

    if (appointment.Duration)
        writeDuration(DbFile, appointment.Duration);

    if(strlen(appointment.Description) != 0){
        fprintf(DbFile, "%s%s%s\n", fBeginDescription, appointment.Description, fEndDescription);
    }

    if(strlen(appointment.Location) != 0){
        fprintf(DbFile, "%s%s%s\n", fBeginLocation, appointment.Location, fEndLocation);
    }

    fprintf(DbFile, "%s\n", fEndAppointment);
}


/***************************************************************************
*  int:    saveCalendar
***************************************************************************/
int saveCalendar(char *DbFileName, TAppointment *appointments, int amount)
{
    FILE *DbFile;
    DbFile = fopen(DbFileName, "wt");

    if (DbFile == NULL) {
        printf("Datei nicht erzeugt/geoffnet! \n");

    } else {

        fprintf(DbFile, "%s\n", fBeginFile);

        /****************************************
         * Writing a single termin into a file
         *****************************************/

        for (int currentAppointment = 0; currentAppointment < amount; currentAppointment++){

            saveAppointment(DbFile, *(appointments + currentAppointment));
        }


        fprintf(DbFile, "%s", fEndFile);

    }

    fflush(DbFile); // immediately write to disk

    fseek(DbFile, 0L, SEEK_END); // position at the end of file
    int fSize = ftell(DbFile);

    fclose(DbFile);

    return fSize;
}

