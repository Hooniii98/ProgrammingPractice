#include <stdio.h>
#include <stdlib.h>  //defines "EXIT_SUCCESS"
#include <time.h>  //defines "struct tm", "localtime()", and "strftime()"

#define MAX_BUF 50

int main(void) {
    char buf[MAX_BUF];
    time_t seconds = time(NULL);  //stores the current time since 00:00:00 UTC, Jan 1, 1970 into the long int variable
    struct tm* now = localtime(&seconds);
    
    const char *months[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    
    const char* days[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
    
    (void) printf("%d-%d-%d\n", now->tm_year + 1900, now->tm_mon + 1, now->tm_mday);
    (void) printf("%s, %s %d, %d\n", days[now->tm_wday], months[now->tm_mon], now->tm_mday, now->tm_year + 1900);
    
    //using the strftime
    (void) strftime(buf, MAX_BUF, "%A, %B %e, %Y", now);
    (void) printf("%s\n", buf);
    return EXIT_SUCCESS;
}