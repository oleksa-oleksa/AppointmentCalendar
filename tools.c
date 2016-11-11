#include <stdio.h>
#include <stdlib.h>



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