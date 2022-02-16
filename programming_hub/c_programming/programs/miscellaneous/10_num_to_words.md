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
		![Alt](https://overiq.com/media/uploads/character-array-in-memory-1504599203175.png#gh-light-mode-only)
		- A character array may not include a null character at the end such as `char str1[2] = "Hi";`, but there will be problem when treating the char array as a string.
	- ```c
	  char *str2 = "Hello World";
		```
		- Compiler allocates 12 consecutive bytes for string literal `"Hello World"` and 4 extra bytes for pointer variable `ptr`.
		- The `char` pointer points to the address of `'H'`. `'\0'` is already included in the string
		![Alt](https://overiq.com/media/uploads/2020/07/26/character-pointer-and-string-literal-1504599248003.png)
		- the string value is stored in a read-only block (generally in text segment) which is why `str2[0] = 'a'` occurs a run time error. `const` is recommended at the declaration to avoid the run time error.
		!{Alt](https://user-images.githubusercontent.com/42318591/111931296-46dac200-8afe-11eb-8ea9-7da9d9faff1a.png)
		- `str1 == str2` (they are both pointers), the difference is `str2` can point to different addresses.
		![Alt](https://media.geeksforgeeks.org/wp-content/cdn-uploads/CommonArticleDesign18-min.png)
		```c
		char *str2 = {'H','e','l','l','o',' ','W','o','r','l','d','\0'};
		//this doesn't compile
		```

# Char Pointer Array


# C Library - <string.h>
- 
