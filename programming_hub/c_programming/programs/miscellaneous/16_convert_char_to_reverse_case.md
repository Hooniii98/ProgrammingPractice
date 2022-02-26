# C Library - <ctype.h>
This header file of the C Standard Library declares several functions that are useful for testing an mapping characters.
All the functions accepts `int` as a parameter, whose value must be `EOF` or representable as an unsigned char.
All the functions return non-zero(true) if the argument satisfies the condition described, and zero(false) if not.

### islower()
This function checks whether the passed character is lowercase letter.

**Syntax**
```c
int islower(int c)
```

### toupper()
This function converts lowercase letters to uppercase.

**Syntax**
```c
int toupper(int c)
```

### tolower()
This function converts uppercase letters to lowercase.

**Syntax**
```c
int tolower(int c)
```
