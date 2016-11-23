#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define str(x) #x
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
        printf("%s", text);
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
void getText(char *infoText, int maxInput, char *targetText, short isAllowedEmpty)
{
    int input;
    char *pInputString = malloc((maxInput + 1) * sizeof(char)); // reserves a place in memory for user´s input

    printf("%s\n", infoText);

    if (pInputString != NULL) // if memory was allocated
    {
        do
        {
            input = scanf("%s", pInputString);

            clearBuffer();

            // if empty input is allowed and it was given
            // the CheckDate has to be set to 1
            if (input || isAllowedEmpty)
                input = 1;

        } while (!input);
        //*(pInputString + maxInput + 1) = '\n';

        strcpy(targetText, pInputString);

        free(pInputString);
    }

    else
        printf("Kein Speicher verfuegbar!\n");
}

