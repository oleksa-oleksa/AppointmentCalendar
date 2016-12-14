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

char *fBeginApp = "<Appointment>";
char *fEndApp = "</Appoinment>";

char *fBeginDate = "<Date>";
char *fEndDate = "</Date>";

char *fBeginTime = "<Time>";
char *fEndTime = "</Time>";

char *fBeginDuration = "<Duration>";
char *fEndDuration = "</Duration>";

char *fBeginDescription = "<Description>";
char *fEndDescription = "</Description>";

char *fBeginLocation = "<Location>";
char *fEndLocation = "<Location>";


/***************************************************************************
*  int:    saveCalendar
/***************************************************************************/
int saveCalendar(char *DbFileName){

    FILE *DbFile;
    DbFile = fopen(DbFileName, "wt");

    if (DbFile == NULL)
        printf("Datei nicht erzeugt/geoffnet! \n");
    else{
        fprintf(DbFile, "%s", fBeginFile);

        fprintf(DbFile, "%s", fEndFile);

    }

    fclose(DbFileName);
}