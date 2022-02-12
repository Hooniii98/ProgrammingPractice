# C Library Function - Puts()
### Declaration
```c
int puts(const char *str)
```

### Description

- Defined in `stdio.h` (`cstdio` in C++)
- Writes a string to stdout up to but not including the null character. A new line character is appended to the output

### Return Value
- If successful, non-negative value is returned. On error, the function returns EOF

### Strings
- One-dimensional array of characters terminated by a **null** character `\0` which is different from the character `'0'`, the integer 0, the double 0.0, or the pointer `NULL` 
- A string can be declared and initialized as follows:
```c
char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
```
```c
char greeting[] = "Hello";
```
![](https://www.tutorialspoint.com/cprogramming/images/string_representation.jpg)
- The C compiler automatically places the `\0` at the end of the string when it initializes the array.

### String Literals
- A **string literal** is a string of characters enclosed in double quotes, such as "Hello World", also known as a **string constant** or **constant string**
- It is stored in C as an array of chars, terminated by a **null byte** `\0` 
- An empty string, `""` consists of only the null byte, and is considered to have a string length of zero.
- When passed to functions, a pointer to a stored string is used
	- For example,
`printf("Hello World");`
The string literal will be stored somewhere in memory, and the address will be passed to `printf()`, The first argument to `printf()` is actually defined as a `char *`


### stdout
- This is a macro defined in `stdio.h` as a pointer to `FILE` type which correspond to standard output streams along with `stdin` and `stderr`
- Connected to a computer's monitor and stores outputs temporarily

### FILE
- This is an object type suitable for storing information for a file stream and defined in `stdio.h` as follows:
```c
typedef struct _iobuf
{
	char* _ptr;
	int _cnt;
	char* _base;
	int _flag;
	int _file;
	int _charbuf;
	int _bufsiz;
	char* _tmpfname;
} FILE;
```

### typedef and struct
```c
typedef struct tag_name{
	type member1;
	type member2;
} struct_alias;
```
- This structure can be declared in two ways as follows:
```c
struct_alis p1;
struct tag_name p1;
```

### EOF
- This is a macro with value -1 defined in `stdio.h` and several other header file
- When the number of inputs is not sure, you can use EOF as follows:
```c
#include <stdio.h>

int main() {
	int x, y;
	while(scanf("%d %d", &x, &y) != EOF) {
	//scanf() returns total number of Inputs Scanned successfully, or EOF if input failure occurs
	}

	return 0;
}
```

