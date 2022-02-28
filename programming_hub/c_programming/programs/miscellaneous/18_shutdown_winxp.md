# C <stdlib.h> Library Function - system()
This functions is used to pass the commands or program names that can be executed in the command processor or the terminal of the operating system, and finally returns the command after it has been completed. It is defined in `<cstdlib>` in C++.

### Declaration
```c
int system(const char *command)
```

### Parameters
`command`: This is the C string containing the name of the requested variable.

### Return Value
The value returned is -1 on error, and the return status of the command otherwise.

### Example
```c
#include <stdlib.h>
int main(void) {
	system("C:\\WINDOWS\\System32\\shutdown -s");
	return 0;
}
```
This program shuts down the Windows XP computer. There is a `shutdown` command that can be executed within a command shell window. Also `shutdown.exe` is located in that file path. Different parameters allow different functions. For instance, `-s` turns off the computer and `-r` shuts downs and reboots. The parameter is slightly different in Windows 7 which has a slash like `/s` or `/r`. Furthermore, in Ubuntu Linux, the shutdown command is `shutdown -P now` which instructs the system to shut down and then power down immediately.

### *Reference*
https://www.tutorialspoint.com/c_standard_library/c_function_system.htm

https://docs.microsoft.com/en-us/windows-server/administration/windows-commands/shutdown

https://www.computerhope.com/unix/ushutdow.htm


  
