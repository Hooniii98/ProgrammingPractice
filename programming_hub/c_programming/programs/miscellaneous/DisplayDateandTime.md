# C <time.h> Library Function - ctime()

### Description
- This function returns a string representing the localtime based on the argument. (Technically, it returns the address of the first element of the string)
- The returned string has the following format:
**Www Mmm dd hh:mm:ss yyyy**
where, **Www** is the weekday, **Mmm** the month in letters, **dd** the day of the month, **hh:mm:ss** the time, and **yyyy** the year.

### Declaration
```c
char *ctime(const time_t *timer)
```



