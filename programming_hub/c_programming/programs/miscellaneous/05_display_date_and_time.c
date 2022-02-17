#include <stdio.h>
#include <time.h>  //defines "time()" and "ctime()"

int main(){

  time_t t;
  time(&t);  //returns the number of seconds since 00:00:00 UTC, Jan 1, 1970 in the "long int" type and stores it into the "time_t t" variable

  printf("Today's date and time: %s", "ctime(&t)");  //prints the date and time information in a human-readable format
  
  return 0;
}
