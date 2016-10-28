//
// Created by tim on 27.10.16.
//

#ifndef UEB1_DATETIME_H
#define UEB1_DATETIME_H
/*****************************************************
 * Funktion: isLeapYear
 * Beschreibung: Überprüft ob das Jahr ein Schaltjahr ist
 * Parameter: int year, Jahreszahl
 * Ergebnis: Wahrheitswert int
 */
int isLeapYear (int year);

/*****************************************************
 * Funktion: getDaysofMonth
 * Beschreibung: Ordnet den Monaten die passende Anzahl an Tagen zu
 * Parameter: TDate Struktur mit dem Jahr,Monat und Tag
 * Ergebnis: gibt die Anzahl der Tage des Monats zürück
 */
int getDaysOfMonth(TDate date);

/*****************************************************
 * Funktion: isDateValid
 * Beschreibung: Überprüft ob das Datum gültig ist
 * Parameter: TDate Struktur mit dem Jahr,Monat und Tag
 * Ergebnis: Wahrheitswert int
 */
int isDateValid(TDate date);

/*****************************************************
 * Funktion: getDateFromString
 * Beschreibung: Wandelt die Eingabe in der Zeichenkette in ein gültiges Datum um
 * Parameter: char Zeiger auf die Eingabe, Zeiger auf die TDate Struktur
 * Ergebnis: Gibt das Datum in der passenden Form zurück
 */
int getDateFromString(char *input, TDate *date);

/*****************************************************
 * Funktion: getTimeFromString
 * Beschreibung: Wandelt die Eingabe der Zeit aus der Zeichenkette in eine gültige Uhrzeit um
 * Parameter: char Zeiger auf die Eingabe, Zeiger auf die TTime Struktur
 * Ergebnis: Gibt die Uhrzeit in der passenden Form zurück
 */
int getTimeFromString(char *input, TTime *time);

#endif //UEB1_DATETIME_H

