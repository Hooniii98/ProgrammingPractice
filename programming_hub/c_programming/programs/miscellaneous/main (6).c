#include <windows.h>  //enalbes Win32 API
#include <stdio.h>

int main() {
    //BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY | BACKGROUND_BLUE are the values defined as the character attributes in <windows.h>
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE)), BACKGROUND_BLUE|BACKGROUND_RED);  //mixes blue and red color
    printf("\n\nBackground Color Change");
    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);
    printf("\n\nBackground Color Change");
    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY);
    printf("\n\nBackground Color Change");
    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
    printf("\n\nBackground Color Change)");
    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);
    printf("\n\nBackground Color Change)");
    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED|BACKGROUND_INTENSITY);  //intensified red
    printf("\n\nBackground COlor Change)");
    
    return 0;
}