//This program prints FizzBuzz if a number is divided by 15, Fizz if divided only by 3, and Buzz if divided only by 5
#include <stdio.h>

int main(void) {
    int i = 1;
    for(i = 1; i <= 100; i++) {
        if(i % 15 == 0) {
            printf("FizzBuzz\n");
        }
        else if(i % 3 == 0) {
            printf("Fizz\n");
        }
        else if(i % 5 == 0) {
            printf("Buzz\n");
        }
        else {
            printf("%d\n", i);
        }
    }
    
    return 0;
}
