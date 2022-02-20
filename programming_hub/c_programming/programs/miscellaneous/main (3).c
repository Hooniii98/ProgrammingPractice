/*
An escape sequence is a sequence of characters that does not represent itself
when used inside a character or string literal, but is translated into another
character or a sequence of characters that may be difficult or impossible to 
represent directly
*/
#include <stdio.h>

int main(void) {
    printf("audible alert (bell) BEL \\a %d\n", '\a');
    printf("backspace            BS  \\b %d\n", '\b');
    printf("horizontal tab       HT  \\t %d\n", '\t');
    printf("newline              LF  \\n %d\n", '\n');
    printf("vertical tab         VT  \\v %d\n", '\v');
    printf("formfeed             FF  \\f %d\n", '\f');  //formfeed advances downward to the next page
    printf("carriage return      CR  \\r %d\n", '\r');
    printf("double quote         \"   \\\" %d\n", '\"');
    printf("single quote         \'   \\\' %d\n", '\'');
    printf("question mark        ?   \\? %d\n", '\?');
    printf("backslash            \\   \\\\ %d\n", '\\');
    
    return 0;
}