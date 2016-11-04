//
// Created by Tim on 02.06.2016.
//

//TODO: waitForEnter
//TODO: printLine

#ifndef UEB1_TOOLS_H
#define UEB1_TOOLS_H

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
int askYesOrNo(char *text);


#endif //UEB1_DATETIME_H