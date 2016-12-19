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
void deleteWhiteSpaces(char *pCalendarLine){
    while ((*pCalendarLine == 20) || (*pCalendarLine == 0))
        pCalendarLine++;
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
*  void:    reallocTagMemory
***************************************************************************/
void reallocTagMemory(char **pThisStr)
{

    char *pTmpStr = malloc((strlen(*pThisStr) + 1) * sizeof(char));

    strcpy(pTmpStr, *pThisStr);

    free(*pThisStr);
    *pThisStr = pTmpStr;

}

/***************************************************************************
*  int:    parseDateInAppointment
***************************************************************************/
int parseDateInAppointment(FILE *DbFile, TDate *pDate)
{
    char *pEndTag;
    char *pSomeText; // here is text between tags
    char *pDateLine = malloc(MAX_CHARS * sizeof(char));
    char *pDateParsed = malloc(MAX_CHARS * sizeof(char));
    memset(pDateParsed, 0, MAX_CHARS); // fill all with NULL

    fscanf(DbFile, "%[^\n]s", pDateLine);
    deleteWhiteSpaces(pDateLine);
    reallocTagMemory(&pDateLine);

    /******* If it is a real <Date> */
    int isCorrectTag = parseTag(&pDateLine, &fBeginDate, strlen(fBeginDate));
    if (isCorrectTag)
    {
        pEndTag = pDateLine;
        char *tmp = pEndTag;

        while(tmp) {
            pEndTag++; // staying at \0
            tmp++;
        }

        (*pEndTag)--; // End of String

        while ((*pEndTag == 20) || (*pEndTag == 0)) // skipping white spaces
            pEndTag--;

        pEndTag -= (strlen(fBeginDate) - 1); // position at beginning of end-tag
        isCorrectTag = parseTag(&pEndTag, &fEndDate, strlen(fEndDate));

        if(isCorrectTag)
        {
            pSomeText = pDateLine + strlen(fBeginDate); // position at first char of text to be parsed
            strncpy(pDateParsed, pSomeText, pEndTag - pSomeText);
            deleteWhiteSpaces(pDateParsed);
            reallocTagMemory(&pDateParsed);
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
    char *pTimeLine = malloc(MAX_CHARS * sizeof(char));
    char *pTimeParsed = malloc(MAX_CHARS * sizeof(char));
    memset(pTimeParsed, 0, MAX_CHARS); // fill all with NULL


    fscanf(DbFile, "%[^\n]s", pTimeLine);
    deleteWhiteSpaces(pTimeLine);
    reallocTagMemory(&pTimeLine);

    /******* If it is a real <Time> */
    int isCorrectTag = parseTag(&pTimeLine, &fBeginDate, strlen(fBeginDate));
    if (isCorrectTag)
    {
        pEndTag = pTimeLine;
        char *tmp = pEndTag;

        while(tmp) {
            pEndTag++; // staying at \0
            tmp++;
        }

        pEndTag--; // End of String

        while ((*pEndTag == 20) || (*pEndTag == 0)) // skipping white spaces
            pEndTag--;

        pEndTag -= (strlen(fBeginDate) - 1); // position at beginning of end-tag
        isCorrectTag = parseTag(&pEndTag, &fEndDate, strlen(fEndDate));

        if(isCorrectTag)
        {
            pSomeText = pTimeLine + strlen(fBeginDate); // position at first char of text to be parsed
            strncpy(pTimeParsed, pSomeText, pEndTag - pSomeText);
            deleteWhiteSpaces(pTimeParsed);
            reallocTagMemory(&pTimeParsed);
            getTimeFromString(pTimeParsed, pTime, 0); // execute a date
        }
    }

    fgetc(DbFile); // skip the end line symbol
    return isCorrectTag;
}


/***************************************************************************
*  int:    parseDurationInAppointment
***************************************************************************/
int parseDurationInAppointment(FILE *DbFile, TTime *pTime)
{
    char *pEndTag;
    char *pSomeText;
    char *pDurationLine = malloc(MAX_CHARS * sizeof(char));
    char *pDurationParsed = malloc(MAX_CHARS * sizeof(char));
    memset(pDurationParsed, 0, MAX_CHARS); // fill all with NULL


    fscanf(DbFile, "%[^\n]s", pDurationLine);
    deleteWhiteSpaces(pDurationLine);
    reallocTagMemory(&pDurationLine);

    /******* If it is a real <Duration> */
    int isCorrectTag = parseTag(&pDurationLine, &fBeginDate, strlen(fBeginDate));
    if (isCorrectTag)
    {
        pEndTag = pDurationLine;
        char *tmp = pEndTag;

        while(tmp) {
            pEndTag++; // staying at \0
            tmp++;
        }

        pEndTag--; // End of String

        while ((*pEndTag == 20) || (*pEndTag == 0)) // skipping white spaces
            pEndTag--;

        pEndTag -= (strlen(fBeginDate) - 1); // position at beginning of end-tag
        isCorrectTag = parseTag(&pEndTag, &fEndDate, strlen(fEndDate));

        if(isCorrectTag)
        {
            pSomeText = pDurationLine + strlen(fBeginDate); // position at first char of text to be parsed
            strncpy(pDurationParsed, pSomeText, pEndTag - pSomeText);
            deleteWhiteSpaces(pDurationParsed);
            reallocTagMemory(&pDurationParsed);
            getTimeFromString(pDurationParsed, pTime, 0); // execute a date
        }
    }

    fgetc(DbFile); // skip the end line symbol
    return isCorrectTag;
}


/***************************************************************************
*  int:    parseTextInAppointment
***************************************************************************/
int parseTextInAppointment(FILE *DbFile, char **pText)
{
    char *pEndTag;
    char *pSomeText;
    char *pTextLine = malloc(MAX_DESCRIPTION * sizeof(char));
    char *pTextParsed = malloc(MAX_DESCRIPTION * sizeof(char));
    memset(pTextParsed, 0, MAX_CHARS); // fill all with NULL


    fscanf(DbFile, "%[^\n]s", pTextLine);
    deleteWhiteSpaces(pTextLine);
    reallocTagMemory(&pTextLine);

    /******* If it is a real <Duration> */
    int isCorrectTag = parseTag(&pTextLine, &fBeginDate, strlen(fBeginDate));
    if (isCorrectTag)
    {
        pEndTag = pTextLine;
        char *tmp = pEndTag;

        while(tmp) {
            pEndTag++; // staying at \0
            tmp++;
        }

        pEndTag--; // End of String

        while ((*pEndTag == 20) || (*pEndTag == 0)) // skipping white spaces
            pEndTag--;

        pEndTag -= (strlen(fBeginDate) - 1); // position at beginning of end-tag
        isCorrectTag = parseTag(&pEndTag, &fEndDate, strlen(fEndDate));

        if(isCorrectTag)
        {
            pSomeText = pTextLine + strlen(fBeginDate); // position at first char of text to be parsed
            strncpy(pTextParsed, pSomeText, pEndTag - pSomeText);
            deleteWhiteSpaces(pTextParsed);
            reallocTagMemory(&pTextParsed);
            *pText = pTextParsed; // parsed Text is saved into a specified field of structure

        }
    }
    fgetc(DbFile); // skip the end line symbol
    return isCorrectTag;
}

/***************************************************************************
*  int:    loadAppointment
***************************************************************************/
int loadAppointment(FILE *DbFile, TAppointment appointment){

    fpos_t pPosition;
    char testSymb[3] = {0,0,0};

    /****** Obligatory part of each appointment */
    char *pAppointmentLine = malloc(MAX_CHARS * sizeof(char));
    fscanf(DbFile, "%[^\n]s", pAppointmentLine);
    fgetc(DbFile); // skip the end line symbol
    deleteWhiteSpaces(pAppointmentLine);
    reallocTagMemory(&pAppointmentLine);
    printf("%s - is read where <Appointment> has to be\n", pAppointmentLine);

    int isCorrectTag = parseTag(&pAppointmentLine, &fBeginAppointment, strlen(fBeginAppointment));

    if (isCorrectTag)
    { // if it is a real appointment record in a database

        /********** Start of a Loop for Appointment's Parsing */
        do
        {
            /********** Detecting what kind of tag is the next **/
            long pos = ftell(DbFile);
            fscanf(DbFile, "%3[^\n]s", testSymb);
            fseek(DbFile, SEEK_SET, pos);
            printf("%s - detected as next Tag\n", testSymb); // TEST DON'T DELETE

            /********** if DATE */
            if (strncmp(testSymb, "<Da", 3) == 0) {
                isCorrectTag = parseDateInAppointment(DbFile, &appointment.Date);

            }

            /********** if TIME */
            if (strncmp(testSymb, "<Ti", 3) == 0) {
                isCorrectTag = parseTimeInAppointment(DbFile, &appointment.Time);

            }

            /********** if DURATION */
            if (strncmp(testSymb, "<Du", 3) == 0) {
                isCorrectTag = parseDurationInAppointment(DbFile, &appointment.Time);

            }

            /********** if DECSRIPTION */
            if (strncmp(testSymb, "<De", 3) == 0) {
                isCorrectTag = parseTextInAppointment(DbFile, &appointment.Description);

            }

            /********** if LOCATION */
            if (strncmp(testSymb, "<De", 3) == 0) {
                isCorrectTag = parseTextInAppointment(DbFile, &appointment.Location);

            }

        } while(strncmp(testSymb, "</A", 3) != 0);
    }

    else

    {
        printf("\nDie Datenbank-Datei hat ein falshes Format\n");
        waitForEnter();
        return isCorrectTag;

    }

    return isCorrectTag;
}

/***************************************************************************
*  int:    loadCalendar
***************************************************************************/
int loadCalendar(char *DbFileName, TAppointment *appointments, int amount){

    FILE *DbFile;

    DbFile = fopen(DbFileName, "rb");

    char *pCalendarLine = malloc(MAX_CHARS * sizeof(char)); // memory allocation 20 symbols for <Calendar>-Tag

    if (DbFile != NULL){

        fscanf(DbFile, "%[^\n]s", pCalendarLine);
        fgetc(DbFile); // skip the end line symbol
        deleteWhiteSpaces(pCalendarLine);

        /******** Memory reallocation^ */
        reallocTagMemory(&pCalendarLine);

        int isCorrectFile = parseTag(&pCalendarLine, &fBeginFile, strlen(fBeginFile));
        // printf("%s - is read where <Calendar> has to be\n", pCalendarLine); // TEST DON'T DELETE

        /******* Extracting appointments between tags */
        if (isCorrectFile)
        { // if database file is in a right format


            for (amount = 0; ; amount++)
            { // if the end of a file will be reached,
                                           // loop will be broken by if-statement below

                int isCorrectRecord = loadAppointment(DbFile, *(appointments + amount));

                // if Database file has a wrong structure and
                // appointment can not be parsed
                if (!isCorrectRecord)
                {
                    break;
                }

                if (feof(DbFile)) // if it is a real EOF
                {
                    break;
                }
            }
        }

        else {
            printf("Die Datenbank-Datei hat ein falshes Format\n");
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
        printf("\n%i Termine sind in der Datenbank vorhanden\n\n", appointmentCount);
    }

    else {
        printf("\nBitte legen Sie einen neuen Termin an\n\n");
    }
}

