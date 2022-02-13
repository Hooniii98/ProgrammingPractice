# C <stdio.h> Library Function - scanf()
### Description
- This function reads formatted input from the standard input stream **stdin**.

### Declaration
```c
int scanf(const char *format, ...)
```

### Parameters
- **format**: This is the C string that contains one or more of the following items - *Whitespace character*, *Non-whitespace character* and *Format specifiers*.

### Return Value
- This function returns the whole number of characters written in it otherwise, returns a negative value.

### Examples
- ```c
	// C program to demonstrate that we can ignore some string in "scanf()"
	#include <stdio.h>
	int main() {
		  int a;
		  scanf("This is the value %d", &a);
		  printf("Input value read : a = %d", a);
	}
	```
	**Input**
	`This is the value 100`
	
	**Output**
	`Input value read : a = 100`
- ```c
	// C program to demonstrate use of *s
	#include <stdio.h>
	int main() {
		  int a;
		  scanf("%*s %d", &a);
		  printf("Input value read : a = %d", a);
		  return 0;
	}
	```
	**Input**
	`blablabla 25`
	
	**Output**
	`Input value read : 25`
	
	**Explanation**: `%*s` is used to ignore some input as required until the next space or newline.

### stdin
- C programming treats all the devices as files. So devices such as the display are addressed in the same way as files and the following three files are automatically opened when a program executes to provide access to the keyboard and screen.
	|Standard File|File Pointer|Device|
	|-|-|-|
	|Standard input|stdin|Keyboard|
	|Standard output|stdout|Screen|
	|Standard error|stderr|Your screen|
	
	The file pointers defined in `<stdio.h>` are the means to access the file for reading and writing purpose.

# C <stdlib.h> Library Function - exit()
### Description
- This function terminates the calling process immediately. Any open file descriptors belonging to the process are closed and any children of the process are inherited by process 1, init, and the parent process is sent a `SIGCHLD` signal.
- It is the same as the `return` function in `main()` except `return` executes the code behind it.

### Declaration
```c
void exit(int status)
```

### Parameters
- **status**: This is the status value returned to the parent process.
 1. **Exit Success**: It is indicated by `exit(0)`
 2. **Exit Failure**: It is indicated by `exit(1)`. We can use different integer other than 1 to indicate different types of errors.
