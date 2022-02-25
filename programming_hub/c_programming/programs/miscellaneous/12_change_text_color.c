#include <windows.h>  //enables Win32 API
#include <stdio.h>
#include <conio.h>  //defines "getch()"

void setColor(int ForgC);

int main(void) {
    setColor(26);
    printf("Color Change: Programming Hub");
    setColor(36);
    printf("\n\nColor Change: Programming Hub");
    setColor(46);
    printf("\n\nColor Change: Programming Hub");
    setColor(56);
    printf("\n\nColor Change: Programming Hub");
    setColor(66);
    printf("\n\nColor Change: Programming Hub");
    setColor(76);
    printf("\n\nColor Change: Programming Hub");
    getch();  //holds the console until the user presses any key on the keyboard
    
    return 0;
}

void setColor(int ForgC) {
    WORD wColor;  //unsigned short variable to store the color value
    
    //We will need this HANDLE to get the current background attribute
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);  //get the state of the standard output resource through OS
    CONSOLE_SCREEN_BUFFER_INFO csbi;  //contains information about a console screen buffer
    
    //We use csbi for the wAttributes word
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)) {  //check if there is a current color attributes of a screen buffer
        //Mask out all but the background attribute, and add in the foreground Color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);  //wColor stores the values of background color + foreground color
        SetConsoleTextAttribute(hStdOut, wColor);  //set color
    }
}
