# Char Array and Pointer
- **String** is a sequence of characters that are treated as a single data and terminated by a null character `'\0'` (It helps the computer to locate the end of the string). C does not support strings as a data type. A **string** is actually a one-dimensional array of characters in C.
- There are various ways of declaring a string using the char data type.
	- ```c
	  char str1[] = "Hello World";  
	  //'\0' character is automatically added by the compiler at the end of the string
		``` 
		```c
		char str1[12] = "Hello World"; 
		```
		```c
		char str1[] = {'H','e','l','l','o',' ','W','o','r','l','d','\0'};
		```
		```c
		char str1[12] = {'H','e','l','l','o',' ','W','o','r','l','d','\0'};
		```
		These four char arrays are the same.
		- Compiler allocates 12 consecutive bytes of memory and associates the address of the first allocated byte with `str1` which is a constant pointer.
		
		![Alt](https://overiq.com/media/uploads/character-array-in-memory-1504599203175.png)
		- A character array may not include a null character at the end such as `char str1[2] = "Hi";`, but there will be problem when treating the char array as a string.
	- ```c
	  char *str2 = "Hello World";
		```
		- Compiler allocates 12 consecutive bytes for string literal `"Hello World"` and 4 extra bytes for pointer variable `ptr`.
		- The `char` pointer points to the address of `'H'`. `'\0'` is already included in the string
		![Alt](https://overiq.com/media/uploads/2020/07/26/character-pointer-and-string-literal-1504599248003.png)
		- the string value is stored in a read-only block (generally in text segment) which is why `str2[0] = 'a'` occurs a run time error. `const` is recommended at the declaration to avoid the run time error.
		
			![Alt](https://courses.engr.illinois.edu/cs225/sp2022/assets/notes/stack_heap_memory/memory_layout.png)
		- `str1 == str2` (they are both pointers), the difference is `str2` can point to different addresses.
		![Alt](https://media.geeksforgeeks.org/wp-content/cdn-uploads/CommonArticleDesign18-min.png)
		```c
		char *str2 = {'H','e','l','l','o',' ','W','o','r','l','d','\0'};
		//this doesn't compile
		```

# Char Pointer Array
An array of strings stores more than one string as follows:
```c
char sports[5][15] = {"golf","hockey","football","cricket","shooting"};
```
or
```c
char sports[5][15] = {{'g','o','l','f'},{'h','o','c','k','e','y'},{'f','o','o','t','b','a','l','l'},{'c','r','i','c','k','e','t'},{'s','h','o','o','t','i','n','g'}};
```
This array is stored as follows:

![Alt](https://overiq.com/media/uploads/memory-representation-of-array-of-strings-1504599913892.png)

As you can see, there are abundant null characters. Char Pointer Array lets you avoid this kind of situation.

### Description
- An array of pointers to strings is an array of character pointers where each pointer points to the first character of the string.

### Declaration
```c
char *sports[5] = {"golf","hockey","football","cricket","shooting"};
```
or
```c
char *sports[] = {"golf","hockey","football","cricket","shooting"};
```
If initialization of an array is done at the time of declaration then the size of an array can be omitted.

### Elements
- Each element of the sports array earlier is a **string literal** and since a string literal points to the **base address** of the first character, the base type of each element of the array is `char*`.

	![Alt](https://overiq.com/media/uploads/memory-representation-of-array-of-pointers-1504599930139.png)
- It is not guaranteed that the all the strings will be stored in contiguous memory locations.
- A new string can be assigned as follows:
	```c
	char *games[3] = {"roadrash","nfs","angrybirds"};
	games[0] = "hitman";
	```
	This is valid since each element of `games` array is `char*`
	
# C Library - <string.h>
### Description
This header defines a variable, macro, and various functions for manipulating arrays of characters.

### strlen()
- **Description**: This function computes the length of a string up to, but not including the terminating null character.
- **Declaration**:
	```c
	size_t strlen(const char *str)
	```
	- `size_t` is the variable type defined in `<string.h>` and many other header files. This is the unsigned integral type and is the result of the `sizeof` keyword.
	- `*str` is the string whose length is to be found. 

# C Operator - sizeof()
### Description
This special operator is a compile-time unary operator and used to compute the size of its operand. It returns the size of a variable as a `size_t` datatype.

### Example
```c
#include <stdio.h>
int main(void) {
	int i = 10;
	printf("integer: %d\n", sizeof(i));
}
```
**Output**
```
integer: 4
```

# C <stdio.h> Library Function - fprintf()
### Description
This function sends formatted output to a stream.

### Declaration
```c
int fprintf(FILE *stream, const char *format, ...)
```
### Parameters
- **stream**: This is the pointer to a `FILE` object that identifies the stream
	- `File` is a variable defined in `<stdio.h>` and suitable for storing information for a file stream.
	- It is a type of structure typedef as `FILE` considered as opaque data type as its implementation is hidden. We only use pointer to the type and library knows the internal of the type.
	- It is system specific.
- **format**: This is the C string that contains the text to be written to the stream. It can optionally contain embedded format tags whose prototype is **%[flags][width][.precision][length]specifier**.

### Return Value
If successful, the total number of characters written is returned otherwise, a negative number is returned.

### stderr
- This is a macro defined in`<stdio.h>`.
- It is a pointer to `FILE` types.
- This is similar to `stdout` in that they both print on monitor, but `stderr` doesn't buffer in order to print out immediately in any circumstances. For example:
	```c
	fprintf(stdout, "%s", message);
	fprintf(stderr, "%s", message);
	```
	The second `fprintf` is printed first since the `stdout` format doesn't have `\n`. The `stdout` stream buffers line by line.

# Character arithmetic in C
Character arithmetic is used to implement arithmetic operations like addition and subtraction on characters. It is used to manipulate the strings. Arithmetic operations convert the characters into integer value automatically i.e. ASCII value of them.

### Example
```c
#include <stdio.h>
int main(void) {
	char s = 'm';
	char t = 'z' - 'y';
	printf("%d\n", s);
	printf("%c\n", s);
	printf("%d\n", (s+1));
	printf("%c\n", (s+1));
	printf("%d\n", (s-1));
	printf("%c\n", (s-1));
	printf("%d\n", t);
	printf("%c", t);

	return 0;
}
```
**Output**
```
109
m
110
n
108
l
1
1
```

# C Operator - ?:
This conditional operator is a ternary operator to construct conditional expressions.

### Syntax
```
Expression1? expression2: expression3;
```
![Alt](https://static.javatpoint.com/cpages/images/conditional-operator-in-c.png)
