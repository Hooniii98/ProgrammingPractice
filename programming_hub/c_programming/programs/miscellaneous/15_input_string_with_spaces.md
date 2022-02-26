# C <stdio.h> Library Function - gets()
### Description
This function reads a line from stdin and stores it into the string pointed to. It stops when either the newline character is read or when the end-of-file is reached, whichever comes first.

### Declaration
```c
char* gets(char* str)
```

### Parameters
`str`: This is the pointer to an array of chars where the C string is stored.

### Return Value
This function returns `str` on success, and `NULL` on error or when end of file occurs, while no characters have been read.
