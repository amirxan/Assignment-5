#include <stdio.h>


static void hourName(int h, char out[]) {
    h %= 24;
    if (h == 0)
        sprintf(out, "midnight");
    else if (h == 12)
        sprintf(out, "noon");
    else
        sprintf(out, "%d", h % 12);
}

void convertToHumanTime(const char date[]) {
    int h, m;
    char name[16];

    sscanf(date, "%d:%d", &h, &m);  

    if (m == 0) {
        hourName(h, name);
        if (h % 24 == 0 || h % 24 == 12)
            printf("It is %s.\n", name);           
        else
            printf("It is %s o'clock.\n", name);
    }
    else if (m <= 30) {
        
        hourName(h, name);
        if (m == 15)
            printf("It is quarter past %s.\n", name);
        else if (m == 30)
            printf("It is half past %s.\n", name);
        else
            printf("It is %d past %s.\n", m, name);
    }
    else {
       
        hourName(h + 1, name);
        if (m == 45)
            printf("It is quarter to %s.\n", name);
        else
            printf("It is %d to %s.\n", 60 - m, name);
    }
}

int main(void) {
    convertToHumanTime("13:00"); 
    convertToHumanTime("1:00");  
    convertToHumanTime("00:00");  
    convertToHumanTime("00:25");  
    convertToHumanTime("23:55");  
    convertToHumanTime("12:00");  
    convertToHumanTime("14:30");  
    convertToHumanTime("4:10");   
    convertToHumanTime("4:40");   
    convertToHumanTime("12:15");  
    convertToHumanTime("11:45");  
    return 0;
}