#include <ctype.h>
#include <string.h>

void extractText(char dst[], const char src[])
{
    int j = 0;               
    int pendingSpace = 0;     

    for (int i = 0; src[i] != '\0'; i++)
    {
        if (isdigit((unsigned char)src[i]))
        {
            continue;                      
        }
        else if (isspace((unsigned char)src[i]))
        {
            pendingSpace = 1;          
        }
        else
        {
            if (pendingSpace && j > 0)    
            {
                dst[j++] = ' ';
            }
            pendingSpace = 0;
            dst[j++] = src[i];
        }
    }
    dst[j] = '\0';
}