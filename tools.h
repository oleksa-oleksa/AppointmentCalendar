#ifndef TOOLS_TOOLS_H
#define TOOLS_H TOOLS_H


    /***************************************************************************
     *  function:    waitForEnter
     *  description: Holds the program flow before Enter key is pressed
     *  parameter:   -
     *  result :     -
     ***************************************************************************/
    void waitForEnter ();

    /***************************************************************************
     *  function:    printLine
     *  description: prints '-' n times
     *  parameter:   Char to be printed, n as an amounts of repeats
     *  result :     -
     ***************************************************************************/
    void printLine (char s, int n);

    /***************************************************************************
     *  function:    clearBuffer
     *  description: clears the input buffer
     *  parameter:   -
     *  result :     returns 0
     ***************************************************************************/
    void clearBuffer();


    /***************************************************************************
     *  function:    clearScreen
     *  description: clears the console screen
     *  parameter:   -
     *  result :     -
     ***************************************************************************/
    void clearScreen();

    /***************************************************************************
     *  function:    askYesOrNo
     *  description: Print out a message and take an input (j/n).
     *  parameter:   text: the message (question) to be asked.
     *  result :     returns 1 if the input is 'j'; 0 if it's 'n'.
     ***************************************************************************/
    int askYesOrNo (char *);

//TODO: Alexandra: getText

#endif //TOOLS_TOOLS_H
