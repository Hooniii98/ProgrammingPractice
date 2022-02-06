#include <stdio.h>

int main() {
	char c;
	printf("Enter a character: ");
	scanf("%c", &c);  //"%d" integer formate can be used since what is actually stored in a "char" variable is an integer value
	printf("ASCII value of %c = %d", c, c);  //"char" can be printed as both a character and integer 
	
	return 0;
}
