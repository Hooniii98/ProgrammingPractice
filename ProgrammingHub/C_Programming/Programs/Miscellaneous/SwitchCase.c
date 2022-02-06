#include <stdio.h>

int main() {
	//local variable definition
	char grade = 'B';
	
	switch(grade) {
		case 'A':
			printf("excellent!\n");
			break;
			
		case 'B':  //Fall through occurs since "break;" is missing. It is not always necessary to avoid fall through
		case 'C':
			printf("Well done\n");
			break;
		
		case 'D':
			printf("You passed\n");
			break;
		
		case 'F':
			printf("Better try again\n");
			break;
		default:
			printf("Invalid grade\n");
	}
	
	printf("Your grade is %c\n", grade);
	
	return 0;
}
