# C Library - <stdlib.h>
This is the header of the **general purpose standard library** which includes functions involving memory allocation, process control, conversions and others. It is compatible with C++ and is known as `cstdlib` in C++. The name "stdlib" stands for "standard library"

### Library Functions
|Function|Description|
|-|-|
|```void srand(unsigned int seed)```|This function seeds the random number generator `rand()`
|`int rand(void)`|Returns a pseudo-random number in the range of 0 to `RAND_MAX`(= 32767)|

#### rand()
- The default seed value for this function is `1`

#### RAND_MAX
- Defined as follows:
```c
#define RAND_MAX 0x7fff
```

# C Library - <time.h>
This header defines the C date and time operations. It is known as `ctime` in C++.

### Library Functions
|Function|Description|
|-|-|
|`time_t time(time_t *timer)`|Calculates the current calender time and encodes it into `time_t` format|

#### time_t
- Although not defined by the C standard, this is almost always an integer value holding the number of seconds since 00:00:00 UTC, Jan 1, 1970
- Defined by `typedef` as follows: 
```c
typedef __time_t time_t;
```
```c
typedef long int __time_t;
```
#### time()
- Returns the time since 00:00:00 UTC, Jan 1, 1970
- If the argument is not `NULL` the same return value is stored in the argument as well (the parameter is a pointer and the arguments is a memory address)

#### NULL
- This macro is the value of a null pointer constant (`(void*) 0`) 
- Usually defined in `stdio.h` and `iostream` in C++
- For example, `char *ptr = NULL` and `char *ptr = 0` are the same
- However, `int a = NULL` and `int a = 0` are different
- `NULL = 0x00000000 or 0x000000000000000` (32 vs 64 bit)
- If one macro is defined as the same name in different header files and the files are included in a source code simultaneously, then the compiler will raise a Warning and take the value of the latest include declared
