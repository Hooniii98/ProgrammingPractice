#include <stdio.h>
#define decode(s,t,u,m,p,e,d) m##s##u##t  //define a function-like macro using the token-pasting operator
#define begin decode(a,n,i,m,a,t,e)  //define a macro using another macro

int begin() {
	printf("Hello World");
}
