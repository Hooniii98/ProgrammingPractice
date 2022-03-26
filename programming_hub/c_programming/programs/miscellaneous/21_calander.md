# Structure
Arrays allow to define type of variables that can hold several data items of the same kind. Similarly **structure** is another user defined data type available in C that allows to combine data items of different kinds.
### Defining a Structure
```c
struct [structure tag] {
   member definition;
   member definition;
   ...
   member definition;
} [one or more structure variables];
```
The `structure tag` is optional and each `member definition` is a normal variable definition. At the end of the structure's definition, before the final semicolon, you can specify one or more structure variables but it is optional.
For example,
```c
struct Books {
   char title[50];
   char author[50];
   char subject[100];
   int  book_id;
} book;
```
or
```c
struct Books {
   char title[50];
   char author[50];
   char subject[100];
   int  book_id;
} book = {"The C Programming", "K&R", "Programming", 0131};
```
You can declare and initialized at the same time.

### Structure Array
```c
struct employee {
   int id;
   char name[5];
   float salary;
};
struct employee emp[2];
```

# C <stdio.h> Library Function - sprintf()
### Description
This function sends formatted output to a string pointed to. It can convert an Integer to a String like the `itoa()` function.

### Declaration
```c
int sprintf(char *str, const char *format, ...)
```

### Parameters
**str**: This is the pointer to an array of char elements where the resulting C string is stored.

**format**: This is the string that contains the text to be written to buffer.

**additional arguments**: Depending on the format string, the function may expect a sequence of additional arguments.

### Return Value
If successful, the total number characters written is returned excluding the null-character appended at the end of the string, otherwise a negative number is returned in case of failure.

# Command Line Arguments in C/C++
Command line arguments are given after the name of the program in command-line shell of Operating Systems.
To pass command line arguments, we typically define main() with two arguments. The first argument is the number of command line arguments and the second is list of command line arguments.
```c
int main(int argc, char *argv[]) { /* ... */ }
```
or
```c
int main(int argc, char **argv) { /* ... */ }
```
**argc (ARGument Count)**: It is `int` and stores number of command line arguments passed by the user including the name of the program. So if we pass a value to a program, value of `argc` would be 2 (one for argument and one for program name).

**argv (ARGument Vector)**: It is array of character pointers listing all the arguments. `argv[0]` is the name of the program. After that till `argv[argc -1 ]` every element is command line arguments.

For example, 
```c
//mainreturn.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    cout << "You have entered " << argc << "arguments:" << "\n";

    for(int i = 0; i < argc; ++i)
        cout << argv[i] << "\n";
 
    return 0;
}
```

Input:
```
$ g++ maintreturn.cpp -o main
$ ./main geeks for geeks
```

Output:
```
You have entered 4 arguments:
./main
geeks
for
geeks
```

# Double Pointer
```c
#include <stdio.h>

int main(void) {
    int *numPtr1;
    int **numPtr2;  //double pointer
    int num1 = 10;
	
	numPtr1 = &num1;
	numPtr2 = &numPtr1;

	printf("%d\n", **numPtr2);

	return 0;
}
```
Result:
```
10
```
`numPtr2` is a pointer to pointer to integer.

We can store a string in C using a character pointer or character array, however, using a character double pointer in C, we can store a list of strings.

![Alt](https://i.stack.imgur.com/z8osw.png)

For example,
```c
#include <stdio.h>
#define SIZE 3
void pr_str_array(char **dp, int n);
int main(void) {
	char *p[SIZE] = {"Apple", "Samsung", "Intel"};
	pr_str_array(p, SIZE);
	return 0;
}

void pr_str_array(char **dp, int n) {
	char i;
	for(i = 0;i < n;i++); 
		printf("String %d : %s\n", i, *(dp+1));
}
```

Result:
```
String 0 : Apple
String 1 : Samsung
String 2 : Intel
```
In the example, `p` is a double pointer since its elements are pointers (`p[0]`, `p[1]`, and `p[2]`).

# C <string.h> Library Function - strcmp()
**Description**
This functions compares the string to the string.

**Declaration**
```c
int strcmp(const char *str1, const char *str2)
```

**Parameters**
**str1**: This is the first string to be compared.
**str2**: This is the second string to be compared.

**Return Value**
- If Return value < 0, then `str1` is less than `str2` in ASCII.
- If Return value > 0, then `str2` is less than `str1`.
- If Return value = 0, then `str1` is equal to `str2`.
