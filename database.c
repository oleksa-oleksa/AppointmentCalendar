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
*  int:    writeDuration
***************************************************************************/
void writeDuration(FILE *file, TTime *time)
{
    fprintf(file, "%s%02i:%02i%s\n", fBeginDuration, time->Hour, time->Minute, fEndDuration);
}


/***************************************************************************
*  void:    deleteWhiteSpaces
***************************************************************************/
void deleteWhiteSpaces(char **pString){
  char *str = *pString;

  while (*str == 0x20 || *str == 9)
    str++;

  *pString = str;
}



/***************************************************************************
*  int:    parseTag
***************************************************************************/
int parseTag(char **pThisLine, char **pExample, int length)
{
    int isSame = strncmp(*pThisLine, *pExample, length);

    return (!isSame);
}

/***************************************************************************
*  int:    parseDateInAppointment
***************************************************************************/
int parseDateInAppointment(FILE *DbFile, TDate *pDate)
{

    char *pEndTag;
    char *pSomeText; // here is text between tags
    char *pDataBuffer = malloc(MAX_CHARS * sizeof(char));
    char *pDateParsed = malloc(MAX_CHARS * sizeof(char));
    memset(pDataBuffer, 0, MAX_CHARS); // fill all with NULL
    memset(pDateParsed, 0, MAX_CHARS); // fill all with NULL

    char *pDateLine = pDataBuffer;
    fscanf(DbFile, "%[^\n]s", pDateLine);
    deleteWhiteSpaces(&pDateLine);

    /******* If it is a real <Date> */
    int isCorrectTag = parseTag(&pDateLine, &fBeginDate, strlen(fBeginDate));
    if (isCorrectTag)
    {
        pEndTag = pDateLine;
        char *tmp = pEndTag;

        while(*tmp) {
            pEndTag++; // staying at \0
            tmp++;
        }

        pEndTag--; // End of String

        while ((*pEndTag == 20) || (*pEndTag == 0)) // skipping white spaces
            pEndTag--;

        pEndTag -= strlen(fBeginDate); // position at beginning of end-tag
        isCorrectTag = parseTag(&pEndTag, &fEndDate, strlen(fEndDate));

        if(isCorrectTag)
        {
          pSomeText = pDateLine + strlen(fBeginDate); // position at first char of text to be parsed
          deleteWhiteSpaces(&pSomeText);

          strncpy(pDateParsed, pSomeText, pEndTag - pSomeText);
          getDateFromString(pDateParsed, pDate); // execute a date
        }
    }

    fgetc(DbFile); // skip the end line symbol
    return isCorrectTag;
}



/***************************************************************************
*  int:    parseTimeInAppointment
***************************************************************************/
int parseTimeInAppointment(FILE *DbFile, TTime *pTime)
{
    char *pEndTag;
    char *pSomeText;
    char *pDataBuffer = malloc(MAX_CHARS * sizeof(char));
    char *pTimeParsed = malloc(MAX_CHARS * sizeof(char));
    memset(pTimeParsed, 0, MAX_CHARS); // fill all with NULL
    memset(pDataBuffer, 0, MAX_CHARS); // fill all with NULL

    char *pTimeLine = pDataBuffer;
    
    fscanf(DbFile, "%[^\n]s", pTimeLine);
    deleteWhiteSpaces(&pTimeLine);

    /******* If it is a real <Time> */
    int isCorrectTag = parseTag(&pTimeLine, &fBeginTime, strlen(fBeginTime));
    if (isCorrectTag)
    {
        pEndTag = pTimeLine;
        char *tmp = pEndTag;

        while(*tmp) {
            pEndTag++; // staying at \0
            tmp++;
        }

        pEndTag--; // End of String

        while ((*pEndTag == 20) || (*pEndTag == 0)) // skipping white spaces
            pEndTag--;

        pEndTag -= strlen(fBeginTime); // position at beginning of end-tag
        isCorrectTag = parseTag(&pEndTag, &fEndTime, strlen(fEndTime));

        if(isCorrectTag)
        {
            pSomeText = pTimeLine + strlen(fBeginTime); // position at first char of text to be parsed
            strncpy(pTimeParsed, pSomeText, pEndTag - pSomeText);
            char *pTimeData = pTimeParsed;
            deleteWhiteSpaces(&pTimeData);

            getTimeFromString(pTimeData, pTime, 0); // execute a date
        }
    }

    fgetc(DbFile); // skip the end line symbol
    return isCorrectTag;
}


/***************************************************************************
*  int:    parseDurationInAppointment
***************************************************************************/
int parseDurationInAppointment(FILE *DbFile, TTime **pTime)
{
    char *pEndTag;
    char *pSomeText;
    char *pDataBuffer = malloc(MAX_CHARS * sizeof(char));
    char *pDurationParsed = malloc(MAX_CHARS * sizeof(char));
    memset(pDataBuffer, 0, MAX_CHARS); // fill all with NULL
    memset(pDurationParsed, 0, MAX_CHARS); // fill all with NULL

    char *pDurationLine = pDataBuffer;
    fscanf(DbFile, "%[^\n]s", pDurationLine);
    deleteWhiteSpaces(&pDurationLine);

    /******* If it is a real <Duration> */
    int isCorrectTag = parseTag(&pDurationLine, &fBeginDuration, strlen(fBeginDuration));
    if (isCorrectTag)
    {
        pEndTag = pDurationLine;
        char *tmp = pEndTag;

        while(*tmp) {
            pEndTag++; // staying at \0
            tmp++;
        }

        pEndTag--; // End of String

        while ((*pEndTag == 20) || (*pEndTag == 0)) // skipping white spaces
            pEndTag--;

        pEndTag -= strlen(fBeginDuration); // position at beginning of end-tag
        isCorrectTag = parseTag(&pEndTag, &fEndDuration, strlen(fEndDuration));

        if(isCorrectTag)
        {
            pSomeText = pDurationLine + strlen(fBeginDuration); // position at first char of text to be parsed
            strncpy(pDurationParsed, pSomeText, pEndTag - pSomeText);
            char *pDurationContent= pDurationParsed;
            deleteWhiteSpaces(&pDurationContent);

            *pTime = malloc(sizeof(TTime));
            getTimeFromString(pDurationContent, *pTime, 0); // execute a date
        }
    }

    fgetc(DbFile); // skip the end line symbol
    return isCorrectTag;
}


/***************************************************************************
*  int:    parseDescriptionInAppointment
***************************************************************************/
int parseDescriptionInAppointment(FILE *DbFile, char **pText)
{
    char *pEndTag;
    char *pSomeText;
    char *pDataBuffer = malloc(MAX_DESCRIPTION * sizeof(char));
    char *pDescParsed = malloc(MAX_DESCRIPTION * sizeof(char));
    memset(pDescParsed, 0, MAX_DESCRIPTION); // fill all with NULL
    memset(pDataBuffer, 0, MAX_DESCRIPTION);

    char *pDescLine = pDataBuffer;
    fscanf(DbFile, "%[^\n]s", pDescLine);
    deleteWhiteSpaces(&pDescLine);

    /******* If it is a real <Description> */
    int isCorrectTag = parseTag(&pDescLine, &fBeginDescription, strlen(fBeginDescription));
    if (isCorrectTag)
    {
        pEndTag = pDescLine;
        char *tmp = pEndTag;

        while(*tmp) {
            pEndTag++; // staying at \0
            tmp++;
        }

        pEndTag--; // End of String

        while ((*pEndTag == 0x20) || (*pEndTag == 0)) // skipping white spaces
            pEndTag--;

        pEndTag -= strlen(fEndDescription)-1; // position at beginning of end-tag
        isCorrectTag = parseTag(&pEndTag, &fEndDescription, strlen(fEndDescription));

        if(isCorrectTag)
        {
            pSomeText = pDescLine + strlen(fBeginDescription); // position at first char of text to be parsed
            deleteWhiteSpaces(&pSomeText);
            int resultLength = pEndTag-pSomeText+1;
            char *pResult = malloc(resultLength);
            memset(pResult, 0, resultLength);
            strncpy(pResult, pSomeText, resultLength-1);

            *pText = pResult; // parsed Text is saved into a specified field of structure

        }
    }
    fgetc(DbFile); // skip the end line symbol
    return isCorrectTag;
}

/***************************************************************************
*  int:    parseLocationInAppointment
***************************************************************************/
int parseLocationInAppointment(FILE *DbFile, char **pText)
{
    char *pEndTag;
    char *pSomeText;
    char *pDataBuffer = malloc(MAX_DESCRIPTION * sizeof(char));
    char *pLocParsed = malloc(MAX_DESCRIPTION * sizeof(char));
    memset(pLocParsed, 0, MAX_DESCRIPTION); // fill all with NULL
    memset(pDataBuffer, 0, MAX_DESCRIPTION);

    char *pLocLine = pDataBuffer;
    fscanf(DbFile, "%[^\n]s", pLocLine);
    deleteWhiteSpaces(&pLocLine);

    /******* If it is a real <Location> */
    int isCorrectTag = parseTag(&pLocLine, &fBeginLocation, strlen(fBeginLocation));
    if (isCorrectTag)
    {
        pEndTag = pLocLine;
        char *tmp = pEndTag;

        while(*tmp) {
            pEndTag++; // staying at \0
            tmp++;
        }

        pEndTag--; // End of String

        while ((*pEndTag == 0x20) || (*pEndTag == 0)) // skipping white spaces
            pEndTag--;

        pEndTag -= strlen(fEndLocation)-1; // position at beginning of end-tag
        isCorrectTag = parseTag(&pEndTag, &fEndLocation, strlen(fEndLocation));

        if(isCorrectTag)
        {
            pSomeText = pLocLine + strlen(fBeginLocation); // position at first char of text to be parsed
            deleteWhiteSpaces(&pSomeText);
            int resultLength = pEndTag - pSomeText;
            char *pResult = malloc(resultLength);
            memset(pResult, 0, resultLength);

            strncpy(pResult, pSomeText, pEndTag - pSomeText);

            *pText = pResult; // parsed Text is saved into a specified field of structure

        }
    }
    fgetc(DbFile); // skip the end line symbol
    return isCorrectTag;
}


/***************************************************************************
*  int:    loadAppointment
***************************************************************************/
int loadAppointment(FILE *DbFile, TAppointment *appointment){

    char *pDataStart;
    /****** Obligatory part of each appointment */
    char *pDataBuffer = malloc(MAX_CHARS * sizeof(char));
    memset(pDataBuffer, 0, MAX_CHARS);
    long oldPos = ftell(DbFile);

    fscanf(DbFile, "%[^\n]s", pDataBuffer);
    fgetc(DbFile); // skip the end line symbol

    char *pData = pDataBuffer;
    deleteWhiteSpaces(&pData);

    int isCorrectTag = parseTag(&pData, &fBeginAppointment, strlen(fBeginAppointment));

    if (isCorrectTag)
    { // if it is a real appointment record in a database
        int gotDuration = 0;
        /********** Start of a Loop for Appointment's Parsing */
        char *pContent = 0;
        do
        {
            /********** Detecting what kind of tag is the next **/
            long pos = ftell(DbFile);
            pContent = pDataBuffer;

            fscanf(DbFile, "%[^\n]s", pContent);
            deleteWhiteSpaces(&pContent);
            fseek(DbFile, pos, SEEK_SET);

            /********** if DATE */
            if (strncmp(pContent, "<Da", 3) == 0) {
                isCorrectTag = parseDateInAppointment(DbFile, &appointment->Date);
            }

            /********** if TIME */
            if (strncmp(pContent, "<Ti", 3) == 0) {
                isCorrectTag = parseTimeInAppointment(DbFile, &appointment->Time);
            }

            /********** if DURATION */
            if (strncmp(pContent, "<Du", 3) == 0) {
                isCorrectTag = parseDurationInAppointment(DbFile, &appointment->Duration);
                gotDuration = isCorrectTag;
            }

            /********** if DESCRIPTION */
            if (strncmp(pContent, "<De", 3) == 0) {
              isCorrectTag = parseDescriptionInAppointment(DbFile, &appointment->Description);
            }

            /********** if LOCATION */
            if (strncmp(pContent, "<Lo", 3) == 0) {
                isCorrectTag = parseLocationInAppointment(DbFile, &appointment->Location);
            }

        } while(strncmp(pContent, "</A", 3) != 0);

        if (isCorrectTag && !gotDuration) {
            appointment->Duration = malloc(sizeof(TTime));
            appointment->Duration->Hour = 1;
        }

        fscanf(DbFile, "%[^\n]s", pDataBuffer); // read the garbage
        fgetc(DbFile);

    } else {
        fseek(DbFile, oldPos, SEEK_SET);
        isCorrectTag = 0;
    }

    free(pDataBuffer);
    return isCorrectTag;
}

/***************************************************************************
*  int:    loadCalendar
***************************************************************************/
int loadCalendar(char *DbFileName, TAppointment *appointments, int amount){

    FILE *DbFile;

    DbFile = fopen(DbFileName, "r+");
    char *pDataBuffer = malloc(MAX_CHARS * sizeof(char)); // memory allocation 20 symbols for <Calendar>-Tag

    if (DbFile != NULL){
        char *pCalendarLine = pDataBuffer;
        fscanf(DbFile, "%[^\n]s", pCalendarLine);
        fgetc(DbFile); // skip the end line symbol
  
        deleteWhiteSpaces(&pCalendarLine);

        int isCorrectFile = parseTag(&pCalendarLine, &fBeginFile, strlen(fBeginFile));

        /******* Extracting appointments between tags */
        if (isCorrectFile)
        { // if database file is in a right format


            for (amount = 0; ; amount++)
            {
                // if the end of a file will be reached,
                // loop will be broken by if-statement below

                int isCorrectRecord = loadAppointment(DbFile, appointments + amount);

                // if Database file has a wrong structure and
                // appointment can not be parsed
                if (!isCorrectRecord)
                {
                    break;
                }

            }

            fscanf(DbFile, "%[^\n]s", pCalendarLine);
            fgetc(DbFile); // skip the end line symbol
            deleteWhiteSpaces(&pCalendarLine);
            if (parseTag(&pCalendarLine, &fEndFile, strlen(fEndFile))) {
                printf("Alle Termine wurden ergolgreich hochgeladen.\n");
                fclose(DbFile);
                return amount;
            } else {
                printf("Der End der Databank-Datei ist falsch\n");
            }
        }


        else {
            printf("Der Anfang der Datenbank-Datei hat ein falshes Format\n");
            waitForEnter();
            return -1;
        }
    }

    else
        return 0;

    fclose(DbFile);
    return amount;
}
/***************************************************************************
*  void:    saveAppointment
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
        return 0;

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

/***************************************************************************
*  void:    printDbInfo
***************************************************************************/
void printDbInfo(int appointmentCount){
    if (appointmentCount){
        if (appointmentCount == 1)
            printf("%i Termin ist in der Datenbank vorhanden.\n", appointmentCount);

        else
            printf("%i Termine sind in der Datenbank vorhanden.\n", appointmentCount);

    }

    else {
        printf("\nBitte legen Sie einen neuen Termin an\n");
    }
}

