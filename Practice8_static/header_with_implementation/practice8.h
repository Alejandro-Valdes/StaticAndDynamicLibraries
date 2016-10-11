#include <math.h>
#include <string.h>

int asciiBinaryToInt(char *s);
int asciiHEXToInt(char *s);
double asciiToDouble(char *s);

//Method to return an integer from an ascii binary string
int asciiBinaryToInt(char *s)
{
    int iRes = 0;
    int i;
    int iPow = 0;
    int iCurrBinary;
    int iLength = strlen(s); //Get length of string

    //iterate from right to left increase power of 2
    for(i = iLength - 1; i >= 0; i--, iPow++)
    {
        iCurrBinary = *(s + i) - '0'; // -'0' gives the int value
        //if different form 0 or 1 ret -1
        if(iCurrBinary < 0 || iCurrBinary > 1)
        {
            return -1;
        }
        //add each binary decimal value
        iRes += iCurrBinary * pow(2, iPow);
    }
    return iRes;
}

//Method that returns an integer from a hexadecimal string
int asciiHEXToInt(char *s)
{
    int iRes = 0;
    int i;
    int iPow = 0;
    int iCurrHex = 0;
    char iChar;
    int iLength = strlen(s);

    //iterate R to L increase power
    for(i = iLength - 1; i >= 0; i--, ++iPow)
    {
        iChar = *(s + i);
        if(iChar >= 'a' && iChar <= 'f')
        {
            iCurrHex = iChar - 'a' + 10; //Gives value 10-15
        }
        else if(iChar >= 'A' && iChar <= 'F')
        {
            iCurrHex = iChar - 'A' + 10; //Gives value 10-15
        }
        else if(iChar >= '0' && iChar <= '9')
        {
            iCurrHex = iChar - '0'; //Gives digit
        }
        else
        {
            return -1;
        }
        //Add hex int value
        iRes += iCurrHex * pow(16, iPow);
    }

    return iRes;
}

//Method returns a double from a string
double asciiToDouble(char *s)
{
    int iLength = strlen(s);
    int iPosOrNeg = 1;
    double dRes = 0;
    double dDecimals = 0;
    int iCurr;
    int iDecimalSpc = 1;
    int i;

    for(i = iLength - 1; i >= 0; i--)
    {
        iCurr = *(s + i);
        /*if i have a point then my current response gets divided by the decimal spaces to get fraction.*/
        if(iCurr == '.')
        {
            dDecimals = dRes / iDecimalSpc;
            dRes = 0;
            iDecimalSpc = 1;
        }
        else if(i == 0 && (iCurr == '-' || iCurr == '+'))
        {
            iPosOrNeg = 44 - iCurr; //gives 1 or -1 only if first char
        }
        else if(iCurr >= '0' && iCurr <= '9')
        {
            iCurr -= '0';
            dRes += (iCurr * iDecimalSpc);
            //gives me my decimal space, or my integer space tens, hundreds, etc.
            iDecimalSpc *= 10;
        }
        else
        {
            return -1;
        }
    }

    //Catching error there were no numbers
    if(dRes == 0 && dDecimals == 0 && iDecimalSpc == 1)
    {
        return -1;
    }

    return iPosOrNeg * (dRes + dDecimals);
}
