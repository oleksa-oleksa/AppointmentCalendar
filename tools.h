//
// Created by Tim on 02.06.2016.
//

#ifndef TOOLS_TOOLS_H
#define TOOLS_TOOLS_H

//TODO: waitForEnter
//TODO: printLine

/***************************************************************************
 *  function:    clearBuffer
 *  description: clears the input buffer
 *  parameter:   -
 *  result :     returns 0
 ***************************************************************************/
int clearBuffer(){
    char c;
    do{
        scanf("%c", &c);
    }while(c != '\n');

    return 0;
}


/***************************************************************************
 *  function:    clearScreen
 *  description: clears the console screen
 *  parameter:   -
 *  result :     -
 ***************************************************************************/
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#endif //WIN_32

#ifdef unix
    printf("\033[2J");
#endif
}

/***************************************************************************
 *  function:    askYesOrNo
 *  description: Print out a message and take an input (j/n).
 *  parameter:   text: the message (question) to be asked.
 *  result :     returns 1 if the input is 'j'; 0 if it's 'n'.
 ***************************************************************************/
int askYesOrNo(char *text) {

    char Abfrage;
    int Erg;
    do{
        //   Beispielausgabe("Möchten Sie noch einmal? (j/n) ", 'I');
        printf(text);
        Erg = scanf("%c", &Abfrage);
        clearBuffer();

        if(Abfrage != 'J' && Abfrage != 'j' && Abfrage != 'n' && Abfrage != 'N')
            Erg = 0;
    }while(!Erg);
    if(Abfrage == 'j' || Abfrage == 'J')
        return 1;
    else
        return 0;
}

#endif //TOOLS_TOOLS_H
