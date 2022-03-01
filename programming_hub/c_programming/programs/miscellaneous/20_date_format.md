# C <time.h> Library Variables and Functions
### Variable - struct tm
This is a structure used to hold the time and date.

**Definition**
```c
struct tm {
   int tm_sec;			//seconds, range 0 to 59
   int tm_min;			//minutes, range 9 to 59
   int tm_hour;			//hours, range 0 to 23
   int tm_mday;			//day of the month, range 1 to 31
   int tm_mon;			//month, range 0 to 11
   int tm_year;			//The number of years since 1900
   int tm_wday;			//day of the week, range 0 to 6
   int tm_yday;			//day in the year, range 0 to 365
   int tm_isdst;		//daylight saving time
```

### Function - localtime()
**Declaration**
```c
struct tm* localtime(const time_t *timer)
```

**Description**
This function uses the time pointed by `timer` to fill a `tm` structure with the values that represent the correspoinding local time. The value of `timer` is broken up into the structure `tm` and expressed in the local time zone.

**Parameter**
`timer`: This is the pointer to a `time_t` value representing a calendar time.

**Return Value**
This function returns a pointer to a `tm` structure with the time filled in.

### Function - strftime()
**Declaration**
```c
size_t strftime(char* str, size_t maxsize, const char* format, const struct tm* timeptr)
```

**Description**
This functions formats the time represented in the structure `timeptr` according to the formatting rules defined in `format` and stored into `str`.

**Parameters**
- `str`: This is the pointer to the destination array where the resulting C string is copied.
- `maxsize`: This is the maximum number of characters to be copied to `str`.
- `format`: This is the C string containing any combination of regular characters and special format specifiers. These format specifiers are replaced by the function to the corresponding values to represent the time specified in `tm`. There are specifiers such as

	|**Specifier**|**Replaced By**|**Example**|
	|---|---|---|
	|%A|Full weekday name|Sunday|
	|%B|Full month name|March|
	|%e|Day of the month, with a space preceding single digits|31|
	|%Y|Year|2022|
- `timeptr`: This is the pointer to a `tm` structure that contains a calendar time broken down into its components,

**Return Value**
If the resulting C string fits in less than size characters (which includes the terminating null-character), the total number of characters copied to `str` (not including the terminating null-character) is returned otherwise, it returns zero.
	

# void with printf()
```c
(void) printf("Hello World.");
```
`printf()` returns a value which most people don't use most of the time. Some tools (e.g. 'lint') warn about this unused return value, and a common way of suprressing this warning is to add the `(void)` cast. It does nothing in terms of execution.

# C <stdlib.h> Macro - EXIT_SUCCESS
This is the value equivalent to `0` for the `exit()` function to return in case of success. It is also defined in `<cstdlib>` in C++.

Also there is a macro `EXIT_FAILURE` whose value is equivalent to `1` to indicate failure in a C or C++ program.

There is no difference between
```c
return 0;
```
and
```c
return EXIT_SUCCESS;
