#include <stdio.h>
#include <string.h>  //defines "strlen()"

// A function that prints given number in words

void convert_to_words(char *num) {
    // Get number of digits in given number
    int len = strlen(num);  //computes the length of the "num" string

    // Base cases
    if(len == 0) {
        fprintf(stderr, "empty string\n");  //prints out the error message
        return;
    }
    if(len > 4) {
        fprintf(stderr, "Length more than 4 is not supported\n");  //prints out the error message
        return;
    }

    char *single_digits[] = {
            "zero", "one", "two", "three", "four",
            "five", "six", "seven", "eight", "nine"
    };

    // The first string is not used, it is to make array indexing simple
    char *two_digits[] = {
            "", "ten", "eleven", "twelve", "thirteen", "fourteen",
            "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
    };

    // The first two string are not used, they are to make array indexing simple
    char *tens_multiple[] = {
            "", "", "twenty", "thirty", "forty", "fifty",
            "sixty", "seventy", "eighty", "ninety"
    };

    char *tens_power[] = {"hundred", "thousand"};

    // Used for debugging purpose only
    printf("\n%s: ", num);

    // For single digit number
    if(len == 1) {
        printf("%s\n", single_digits[*num - '0']);  //*num - '0' results in an integer number and is the same as the number character of *num
        return;
    }

    // Iterate while num is not '\0' that is until the end of the *num string not including the null character
    while(*num != '\0') {

        // Code path for thousands and hundreds if the string has
        if(len >= 3) {
            if(*num - '0' != 0) {  //*num returns the character in the first element of the string being pointed by the pointer
                printf("%s ", single_digits[*num - '0']);
                // here len can be 3 or 4
                printf("%s ", tens_power[len - 3]);
            }
            --len;
        }
        // Code path for two digit number
        else {
            // Need to explicitly handle 10-19
            if(*num == '1') {
                int sum = *(num + 1) - '0' + 1;  //1 is added since the two_digits array's index strats from one
                printf("%s\n", two_digits[sum]);
                return;
            }
            // Need to explicitely handle 20 => still couldn't find why? This program works well without this block
            //else if(*num == '2' && *(num + 1) == '0') {
            //    printf("twenty\n");
            //    return;
            //}
            // Rest of the two digit numbers i.e., 21 to 99
            else {
                int i = *num - '0';
                printf("%s ", i ? tens_multiple[i] : "");
                ++num;
                if(*num != '0') {
                    printf("%s ", single_digits[*num - '0']);
                }
            }
        }
        ++num;  //the pointer points to the next element of the string
    }
}

int main()
{
    char num[100];
    printf("Enter number to convert to words : ");
    scanf("%s", num);
    convert_to_words(num);

    return 0;
}