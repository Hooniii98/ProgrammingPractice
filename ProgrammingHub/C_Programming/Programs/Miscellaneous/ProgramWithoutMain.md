# C Preprocessor Directive - #define
The **C Preprocessor** is just a text substitution tool and it instructs the compiler to do required pre-processing before the actual compilation. All preprocessor commands begin with a hash symbol `#`.

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
- 
	- `decode()` macro concatenates the fourth, the first, the third, and the second argument one after another

