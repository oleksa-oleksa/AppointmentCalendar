//
// Created by Tim on 02.06.2016.
//

#ifndef TOOLS_TOOLS_H
#define TOOLS_TOOLS_H

int clearBuffer(){
    char c;
    do{
        scanf("%c", &c);
    }while(c != '\n');

    return 0;
}



void clearScreen()
{
#ifdef _WIN32
    system("cls");
#endif //WIN_32

#ifdef unix
    printf("\033[2J");
#endif
}

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
