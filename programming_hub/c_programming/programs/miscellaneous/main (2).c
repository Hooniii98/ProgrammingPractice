#include <stdio.h>
#include <ctype.h>

int main(void) {
    char alphabet;
    
    printf("Enter an alphabet: ");
    alphabet = getchar();
    
    printf("Reversed case: ");
    if(islower(alphabet)) {
        putchar(toupper(alphabet));
    }
    else {
        putchar(tolower(alphabet));
    }
    
    return 0;
}