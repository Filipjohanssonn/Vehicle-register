// filhantering.h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define FMAX 10 // Storlek för registret
#define BUFSIZE 10 // Storlek för inmatning

#define FSIZE 50 // Storlek för fordonstyp.
#define MSIZE 50 // Storlek för märke.
#define RSIZE 50 // Storlek för regnummer.
#define ASIZE 70 // Storlek för ägare.
#define AGESIZE 100 // Storlek för namn.
#define SOKRADERA 31 // Storlek för sök och radera. 

void test(char* Name);
struct person
{
    char fornamn[ASIZE];
    char efternamn[ASIZE];
    char age[AGESIZE];
};
typedef struct person person_p;
struct fordon
{
    char fordonsTyp[FSIZE];
    char marke[MSIZE];
    char regNummer[RSIZE];
    person_p agare;
}; 
typedef struct fordon fordon_f;
void fixString(char array[], char array2[]);
fordon_f skapaFordon(char fordonsTyp[], char marke[], char regNummer[], char fornamn[], char efternamn[], char age[]);
void getInput(char arr[], int size);
void registreraFordon(fordon_f fordonsRegister[], int *antal);
void skrivUtFordon(fordon_f f);
void skrivUtRegister(fordon_f fordonsRegister[], int antal);
void printMeny();
int menyInmatning();
void lasInRegister(fordon_f fordonsRegister[], int *antal);
void bubbleSort(fordon_f fordonsRegister[], int size);
void raderaFordon(fordon_f fordonsRegister[], int *size);
void sokSkriv(fordon_f fordonsRegister[], int *size);
void skrivTillFil(fordon_f fordonsRegister[],int antal);