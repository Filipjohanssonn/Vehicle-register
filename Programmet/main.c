// Main.c

#include "filhantering.h"

int main()
{
    /* Fordonsregistret med 10 platser */
    fordon_f fordonsRegister[FMAX];
    /* För att hålla koll på antalet fordon */
    int antal = 0;
    /* Läser in fordon från fordon.txt till vektor */ 
    lasInRegister(fordonsRegister, &antal);

   while(1)
   {
        int val;
        printMeny();
        val = menyInmatning();
        
        switch (val)
        {
        case 1:     /* Användaren kan lägga till ett fordon i registret */
                    registreraFordon(fordonsRegister, &antal);
                    printf("Fordon tillagt i registret!\n"); break;

        case 2:     /* Raderar valt fordon ur registret */
                    raderaFordon(fordonsRegister, &antal); break;

        case 3:     /* Sorterar registret efter märke från a-z */
                    bubbleSort(fordonsRegister, antal);
                    printf("Registret sorterades efter bilmärke!\n"); break;

        case 4:     /* Söka i registret och skriva ut informationen om ett fordon */
                    sokSkriv(fordonsRegister, &antal); break;

        case 5:     /* Skriver ut hela registret */
                    printf("Hela registret skrivs ut!\n"); 
                    skrivUtRegister(fordonsRegister, antal); break;

        case 6:   /* Skriver ut registret till fil */
                    skrivTillFil(fordonsRegister, antal); break;
            
        default:    printf("Okänt val! Se meny för valbara alterlativ\n"); break;
        break;
        }
    }

    return 0;
}   
