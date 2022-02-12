#include <stdlib.h>  //Defines "srand()", "NULL", and "rand()"
#include <time.h>  //Defines "NULL" which is the same as that of "stdlib.h", and time()
#include <stdio.h>  //Also defines "NULL"

int main() {
	int a, b;
	
	srand(time(NULL));  
	//srand() seeds the random number generator rand()
	//time() calculates the current calander time
	//NULL is the value of a null pointer constant
	
	while(1) {
		a = rand() % 20;  //rand() returns a pseudo-random number
		printf("%d\n", a);
		if(a == 10) {
			break;
		}
		b = rand() % 20;
		printf("%d\n", b);
	}
	
	return 0;
}
