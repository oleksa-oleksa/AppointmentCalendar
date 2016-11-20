#include <stdio.h>
#include <stdlib.h>
#include <string.h>




/***************************************************************************
*  function:    printLine
***************************************************************************/
void printLine (char s, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%c", s);
    }
}

/***************************************************************************
 *  function:    clearBuffer
 ***************************************************************************/
void clearBuffer()
{
    char c;
    do
    {
        scanf("%c", &c);
    } while(c != '\n');
}


/***************************************************************************
 *  function:    clearScreen
 ***************************************************************************/
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#endif //WIN_32

#ifdef unix
    printf("\033[2J");
#endif

#ifdef __APPLE__
    system("clear");
#endif
}

/***************************************************************************
 *  function:    askYesOrNo
 ***************************************************************************/
int askYesOrNo(char *text)
{
    char Abfrage;
    int Erg;
    do
    {
        //   Beispielausgabe("Möchten Sie noch einmal? (j/n) ", 'I');
        printf(text);
        Erg = scanf("%c", &Abfrage);
        clearBuffer();

        if(Abfrage != 'J' && Abfrage != 'j' && Abfrage != 'n' && Abfrage != 'N')
            Erg = 0;
    } while(!Erg);

    if(Abfrage == 'j' || Abfrage == 'J')
        return 1;
    else
        return 0;
}


/***************************************************************************
*  function:    waitForEnter
***************************************************************************/
void waitForEnter ()
{
    char c;
    scanf("%c", &c);
    clearBuffer();
}

/***************************************************************************
*  function:    getText
*  description: Reads description / location of appointment
***************************************************************************/
void getText (char *InfoText, int MaxInput, char **CalendarItem, short EmptyIsOn)
{
    int CheckDate;
    char *pCalendarItem = (char *) malloc(MaxInput); // reserves a place in memory for user´s input

    printf("%s\n", InfoText);

    if (pCalendarItem != NULL) // if memory was allocated
    {
        do
        {
            CheckDate = scanf("%s", pCalendarItem);

            clearBuffer();

            // if empty input is allowed and it was given
            // the CheckDate has to be set to 1
            if (CheckDate || EmptyIsOn)
                CheckDate = 1;

        } while (!CheckDate);

        char *pCalendarItemAdded = malloc(strlen(pCalendarItem));
        strcpy(pCalendarItemAdded, pCalendarItem);

        free(pCalendarItem);

        *CalendarItem = pCalendarItem;

    }

    else
        printf("Kein Speicher verfuegbar!\n");
}
