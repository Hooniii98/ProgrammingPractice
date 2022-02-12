# C Data Type - char
This is a basic data type in C  and further classified into an **integer type** which has the storage size of **1 byte** and the value range of **-128 to 127** or **0 to 255**.

### Encoding
- A computer stores data in bits and bytes. So, to display a character on screen or map the character as a byte in memory of the computer a standard is needed.
- There are several standards such as ASCII (American Standard Code for Information Interchange) and UTF-8 (Unicode Transformation Format).
- In C, if a `char` value (enclosed in single quotes) is assgined to a `char` variable, it is encoded as per the standard and stored in the variable.
- On the other hand, if a `int` value is assigned to a `char` variable, it doesn't need to be encoded and stored in the variable immediately.

### Decoding
- If a `char` variable is printed as a `char` data type, the value in the memory of the variable is decoded as per the standard and printed.
- On the other hand, if a `char` variable is printed as an `int` data type, it doens't need to be decoded and just printed.

### CRLF
- CR and LF are **Escape Character** (control characters) than can be used to mark a line in a text file.
- CR = **Carriage Return** (`\r`, `0x0D` in hexadecimal, 13 in decimal) moves the cursor to the beginning of the line without advancing to the next line.
- LF = **Line Feed** (`\n`, `0x0A` in hexadecimal, 10 in decimal) moves the cursor down to the next line without returning tot he beginning of the line
