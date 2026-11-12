#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isValidSchoolEmail(const char str[]) {
    
    const char* at = strchr(str, '@');
    if (at == NULL || strchr(at + 1, '@') != NULL)
        return false;

    
    int idLen = (int)(at - str);
    if (idLen < 3)                    
        return false;
    if (!isalpha((unsigned char)str[0]))
        return false;
    for (int i = 0; i < idLen; i++) {
        unsigned char c = (unsigned char)str[i];
        if (!isalnum(c) && c != '_')   
            return false;
    }


    const char* domain = at + 1;
    int n = (int)strlen(domain);
    int prefixLen = -1;               

    if (n >= 4 && strcmp(domain + n - 4, ".edu") == 0) {
       
        prefixLen = n - 4;
    }
    else {
        
        for (int k = 2; k <= 3; k++) {
            int dot = n - k - 1;      
            int start = dot - 4;       
            if (start < 0) continue;
            if (domain[dot] != '.') continue;
            if (strncmp(domain + start, ".edu", 4) != 0) continue;

            bool lettersOk = true;
            for (int i = dot + 1; i < n; i++) {
                if (!isalpha((unsigned char)domain[i])) {
                    lettersOk = false;
                    break;
                }
            }
            if (lettersOk) {
                prefixLen = start;
                break;
            }
        }
    }

    if (prefixLen < 1)             
        return false;

    for (int i = 0; i < prefixLen; i++) {
        unsigned char c = (unsigned char)domain[i];
        if (!isalnum(c) && c != '-' && c != '.')
            return false;
    }

    return true;
}

int main(void) {
    printf("%d\n", isValidSchoolEmail("emil@ada.edu.az"));       
    printf("%d\n", isValidSchoolEmail("tofig@qu.edu"));          
    printf("%d\n", isValidSchoolEmail("gulam@qu.edudd"));        
    printf("%d\n", isValidSchoolEmail("to@qu.edu"));             
    printf("%d\n", isValidSchoolEmail("to?fig@qu.edu"));         
    printf("%d\n", isValidSchoolEmail("eabbasov2019@ada.edu.tr"));
    printf("%d\n", isValidSchoolEmail("eabbasov2019ada.edu.tr"));
    return 0;
}