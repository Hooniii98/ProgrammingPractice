#include <stdio.h>

const char* wd(int year, int month, int day) {
    static const char* weekdayname[] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    
    //backslash allows multi-lines initialization
    //calculate the day based on the Julian Day Number
    size_t JDN =                                                    \
          day                                                       \
        + ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5)  \
        + (365 * (year + 4800 - ((14 - month) / 12)))               \
        + ((year + 4800 - ((14 - month) / 12)) / 4)                 \
        - ((year + 4800 - ((14 - month) / 12)) / 100)               \
        + ((year + 4800 - ((14 - month) / 12)) / 400)               \
        - 32045;
    return weekdayname[JDN % 7];
}

int main(void) {
    int year, month, date;

    printf("Enter Year : ");
    scanf("%d",&year);
    printf("\nEnter Month : ");
    scanf("%d",&month);
    printf("\nEnter Date : ");
    scanf("%d",&date);

    printf("\n%d-%02d-%02d: %s\n", year, month, date, wd(year, month, date));  //%02d means the field is two characters wide and any empty space will be padded with a 0

    return 0;
}