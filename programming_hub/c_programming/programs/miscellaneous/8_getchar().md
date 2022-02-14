# C <stdio.h> Library Function - getchar()
### Description
- This function gets a character (an unsigned char) from stdin. This is equivalent to `getc()` with `stdin` as its argument.

### Declaration
```c
int getchar(void)
```

### Return Value
- This function returns the character read as an unsigned char cast to an int or EOF on end of file or error.

### Example
- ```c
	#include <stdio.h>
	int main(void) {
		  int ch = getchar();
		  printf("%c", ch);
		  return 0;
	}
	```
	**Input**
	
	`abcd`
	
	**Output**
	
	`a`
	
	**Explanation**: The first character in the stdin buffer is fetched by `getchar()`.

- ```c
	#include <stdio.h>
	int main(void) {
		  int ch1 = getchar();
		  printf("%c\n", ch1);
		  int ch2 = getchar();
		  printf("%c\n", ch2);
		  return 0;
	}
	```
	**Input**
	
	`abcd`
	
	**Output**
	
	```
	a
	b
	```
	
	**Explanation**: The second `getchar()` fetches the character `b` from the stdin buffer automatically. If nothing was in the buffer, the program would wait for the user input.

### Buffer
- It is a temporary storage area.
- All standard input and output devices contain an input and output buffer.
- In standard C/C++, streams are buffered, for example in the case of standard input, when we press the key on the keyboard, it isn't sent to your program, rather it is buffered by the operating system untill the time is allotted to that program.

	![Alt](https://flylib.com/books/4/330/1/html/2/files/08fig01.jpg)

	![Alt](https://1.bp.blogspot.com/-xTzYa3qgRFQ/XbFVJRd9bhI/AAAAAAAACWk/3ooPQ2iCz-ksLUA1-SPtXhzHjCjZeI4dgCLcBGAsYHQ/s640/concept%257Eof%257Estream.jpg)
	

# int main() vs. int main(void)
- In C++, there is no difference
- In C, `int main()` can be called with any number of arguments, but `int main(void)` can only be called without any argument. Although it doesn't make any difference most of the times, using `int main(void)` is a recommended practice in C.
- For example:
	- ```c
		// This program compiles and runs fine in C, but not in C++
		void fun() {}
		int main(void) {
			  fun(10, "GFG", "GQ");
			  return 0;
		}
		```
	- ```c
		// This program fails in compilation in both C and C++
		void fun(void) {}
		int main(void) {
			  fun(10, "GFG", "GQ");
			  return 0;
		}
		```
	
