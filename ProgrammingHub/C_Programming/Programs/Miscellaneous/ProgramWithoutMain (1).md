# C Preprocessor Directive - #define
The **C Preprocessor** is just a text substitution tool and it instructs the compiler to do required pre-processing before the actual compilation. All preprocessor commands begin with a hash symbol `#`.

### #define
- This can create a **constant** as follows;
	```c
	#define CNAME value
	```
	or
	```c
	#define CNAME (expression)
	```
- This can create function like macros  as follows:
	```c
	#define circleArea(r) (3.1415*(r)*(r))
	```
- Macros can be defined by other macros

### The Token Pasting (##) Operator
- This is offered by the C preprocessor to help create macros
- This concatenates two arguments within a macro definition as follows:
	```c
	#include <stdio.h>
	#define decode(s,t,u,m,p,e,d) m##s##u##t
	#define begin decode(a,n,i,m,a,t,e)
	
	int begin() {
	printf("Hello World");
	}
	``` 
	- `decode()` macro concatenates the fourth, the first, the third, and the second parameter one after another. Thus, `decode(a,n,i,m,a,t,e)` is replaced with `main`

### return 0;
- This tells an OS that the program exited successfully with no errors 
- As of C99, reaching the `}` at the end of `main` return `0` if the return type of `main` is compatible with `int`
