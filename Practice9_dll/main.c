//
// Autor: Jesus Alejandro Valdes Valdes
// Matrícula: A00999044
// Fecha: 10/10/2016
//
// Practice 11
// DLL that allows us to use the method in the
// practice for malloc

#include <stdio.h>
#include <stdlib.h>

#define DLL_EXPORT __declspec(dllexport)

//method to get an unknown length string
DLL_EXPORT char * extremelyLargeString()
{
    char *sForeverString; //string "array"
    int iMaxLength = 11; //original max length
    int iIncrement = 5; //increments
    int iLength = 0;
    char cCurrChar;

    sForeverString = malloc(iMaxLength); //original memory allocation

    while(cCurrChar != 10){
        cCurrChar = getchar();
        sForeverString[iLength++] = cCurrChar; //add char to string
        //if length is equal to iMaxLength - 1 reallo memory
        if(iLength == iMaxLength)
        {
            iMaxLength += iIncrement;
            sForeverString = realloc(sForeverString, iMaxLength);
            //catch error
            if(!sForeverString)
            {
                return "Error";
            }
        }
    }

    sForeverString[iLength++] = '\0'; //add null char
    //last realloc, to fit lenght, gets rid of excess.
    sForeverString = realloc(sForeverString, sizeof(char) * iLength);
    return sForeverString;
}
