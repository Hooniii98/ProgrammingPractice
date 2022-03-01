#include <stdio.h>

int main(void) {
    //variable declaration
    double number, sum = 0, i;  //three variables
    
    //take user input
    printf("Enter the number: ");
    scanf("%lf", &number);  //"lf" is a format specifier for double floating-point number
    
    for(i = 1; i <= number; i++) {
        sum = sum + (1/i);
        
        if(i == 1) {
            printf("\n1 +");
        }
        else if(i == number) {
            printf(" (1 / %1f)", i);  //"1f" secures a width of at least 1 wide
        }
        else {
            printf(" (1 / %1f) +", i);
        }
    }
    
    //display output
    printf("\n\nThe sum of series is: %.2lf", sum);  //".2lf" means a precision of two decimal places
    printf("\n");
    
    return 0;
}