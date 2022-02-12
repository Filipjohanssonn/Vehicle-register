// Filhantering.c
#include "filhantering.h"


/* Källa/Insperation: 
* Jonas Hammar[KAU] hjälpe mig att skriva funktionen. */
void test(char* Name)
{
    char *pos;
        if ((pos=strchr(Name, '\n')) != NULL)
         *pos = '\0';

}

/* Källa/Insperation: 
* Jonas Hammar[KAU] hjälpe mig att skriva funktionen. */
void fixString(char array[], char array2[])
{
    test(array);
    strcpy(array2, array);
}

fordon_f skapaFordon(char fordonsTyp[], char marke[], char regNummer[], char fornamn[], char efternamn[], char age[])
{
    fordon_f f;
    fixString(fordonsTyp, f.fordonsTyp);
    fixString(marke, f.marke);
    fixString(regNummer, f.regNummer);
    fixString(fornamn, f.agare.fornamn);
    fixString(efternamn, f.agare.efternamn);
    fixString(age, f.agare.age);
    return f;
}

void getInput(char arr[], int size)

/* Källa/Insperation: 
* Jonas Hammar[KAU] hjälpe mig att skriva funktionen. */
// Rapport: Antagande att man ej får använda ÅÄÖ ' '

{
    int k = 1;
    do
    {
        fgets(arr, size, stdin);
        k = 1;
        
        for(int i=0; i < strlen(arr)-1; i++)
        {
            if(isalnum(arr[i]) == 0) 
            {
                k = 0;
                printf("Felaktig inmatning!\n");
                printf("Du kan enbart använda dig av bokstäver och sifffor.\n");
            }
        }
    } while(k == 0);
}

/* Registrerar ett fordon med fgets */
void registreraFordon(fordon_f fordonsRegister[], int *antal)
{
    
    char fordonsTyp[FSIZE]={0}, marke[MSIZE]={0}, regNummer[RSIZE]={0}, fornamn[ASIZE]={0}, efternamn[ASIZE]={0}, age[AGESIZE]={0};
    
    printf("Ange fordonstyp: "); getInput(fordonsTyp, FSIZE); 
    printf("Ange märke: "); getInput(marke, MSIZE);
    printf("Ange registreringsnummer: "); getInput(regNummer, RSIZE);
    printf("Ange ägarens förnamn: "); getInput(fornamn, ASIZE);
    printf("Ange ägarens efternamn: "); getInput(efternamn, ASIZE);
    printf("Ange ägarens ålder: "); getInput(age, ASIZE);
    fordonsRegister[*antal] = skapaFordon(fordonsTyp, marke, regNummer, fornamn, efternamn, age);
    (*antal)++;
}

/* Funktion för att skriva ut information om Fordon */
void skrivUtFordon(fordon_f f)
{
    printf("\nFordonstyp: %s\nMärke: %s\nRegistreringsnummer: %s\nFörnamn: %s\nEfternamn: %s\nÅlder: %s\n", f.fordonsTyp, f.marke, f.regNummer,f.agare.fornamn,f.agare.efternamn, f.agare.age);
    printf("----------------------------\n");
}

/* Skriver ut hela registret */
void skrivUtRegister(fordon_f fordonsRegister[], int antal)
{
    int i;
    for (i = 0; i < antal; i++)
    {
        skrivUtFordon(fordonsRegister[i]);
    }
}
/* Skriver ut meny */
void printMeny()
{
    printf("--------------------------------------------\n");
    printf("1. Lägg till ett fordon\n");
    printf("2. Ta bort ett fordon\n");
    printf("3. Sortera efter bilmärke\n");
    printf("4. Skriv ut information om ett fordon\n");
    printf("5. Skriv ut hela fordonsregistret\n");
    printf("6. Avsluta\n");
    printf("--------------------------------------------\n");
}

int menyInmatning()
{
    char menyval[FMAX];
    char i;
    int check = 1;

    printf("Välj menyval mellan 1-6: "); fgets(menyval, FMAX-1, stdin);
    
    for(i=0; i < strlen(menyval)-1; i++)
    {
        if(isdigit(menyval[i]) == 0)
        {
            return 0;
        }
    }
    return atoi(menyval);
}

/* Källa */
/* https://www.kth.se/social/upload/5252a1fbf276544f32a18e94/F10InputOutput.pdf */
void lasInRegister(fordon_f fordonsRegister[], int *antal) 
{
    FILE *fil;
    fil = fopen("fordon.txt","r");
    if(fil!= NULL)
    {
        char fordonsTyp[FSIZE], marke[MSIZE], regNummer[RSIZE],fornamn[ASIZE], efternamn[ASIZE], age[AGESIZE];
        while(fscanf(fil, "%s %s %s %s %s %s", fordonsTyp, marke, regNummer, fornamn, efternamn, age)!=EOF)
        {
            fordonsRegister[*antal] = skapaFordon(fordonsTyp, marke, regNummer, fornamn, efternamn, age);
            (*antal)++;
        }
        fclose(fil);
    }
}


void bubbleSort(fordon_f fordonsRegister[], int size)
{
	int k, bytt;
	fordon_f tmp;
	do 
	{
		bytt = 0;
		for(k = 0; k < size - 1; k++)
			if(strcasecmp(fordonsRegister[k].marke, fordonsRegister[k + 1].marke) > 0)
			{
				/*swapping*/
				tmp = fordonsRegister[k];
				fordonsRegister[k] = fordonsRegister[k + 1];
				fordonsRegister[k + 1] = tmp;
				bytt = 1;
			}
	} while(bytt);

}

/* Källa/inspiration:
* https://www.log2base2.com/data-structures/array/remove-a-specific-element-from-array.html 
* Axel Pettersson [KAU] som hjälpte till i Zoom breakoutroom. */

void raderaFordon(fordon_f fordonsRegister[], int *size)
{
    int key, i;
    char text[FMAX];
    do
    {
        printf("Ange positionen på fordonet du vill ta bort: "); fgets(text, SOKRADERA, stdin);
    } 
    while (atoi(text) < 1);
    key = atoi(text)-1;

    if(key > *size-1)
    {
        printf("Det finns inget fordon på den valda positionen.\n");
    }
    else
    {
         /* Skiftar elementet en position till vänster. */
        for(i = key; i < *size - 1; i++)
            fordonsRegister[i] = fordonsRegister[i+1];
        *size -= 1;
         printf("Fordonet är borttaget från registret!\n");
    }        
}

void sokSkriv(fordon_f fordonsRegister[], int *size)
{
    int key, i;
    char text[FMAX];
    do
    {
        printf("Ange positionen på fordonet du vill söka efter: "); fgets(text, SOKRADERA, stdin);
    } 
    while (atoi(text) < 1);

    key = atoi(text)-1;

    if(key > *size-1)
    {
        printf("Det finns inget fordon på den valda positionen.\n");
    }
    else
    {
            i = key;
            printf("Information om angivet fordon skrivs ut!\n");
            skrivUtFordon(fordonsRegister[i]);
    }   
}

void skrivTillFil(fordon_f fordonsRegister[],int antal)
{
    printf("Program avslutas. Välkommen åter!\n"); 

    FILE * fil;
	fil = fopen("fordon.txt", "w");
	if(!fil)
    {
		printf("Filen kunde inte öppnas! ");
		return;
	}
    int i;
    for (i = 0; i < antal; i++)
    {
        fprintf(fil, "%s %s %s %s %s %s \n", fordonsRegister[i].fordonsTyp, fordonsRegister[i].marke, fordonsRegister[i].regNummer,fordonsRegister[i].agare.fornamn, fordonsRegister[i].agare.efternamn, fordonsRegister[i].agare.age);
    }
	fclose(fil); 
    exit(0);
}