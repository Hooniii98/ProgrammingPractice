# C/C++ Library - <windows.h>
This Library is a **Windows-specific** header file for the C and C++ programming languages which contains declarations for all of the functions in the **Windows API**, all the common macros used by Windows programmers, and all the data types used by the various  functions and subsystems. The **Win32 API** can be added to a C programming project by including the `<windows.h>` header file and linking to the appropriate libraries. More details are provided on the [Microsoft web page](https://docs.microsoft.com/ko-kr/windows/win32/winprog/windows-data-types)

### WORD
This is a datatype defined in `<WinDef.h>` included by `<windows.h>`. Its definition is as follows:
```c
typedef unsigned short WORD;  //2 byte
```
It is the amount of data that a machine can process at one time. The size of a processor's general-purpose registers is equal to its `WORD` size.

### HANDLE
This is a datatype defined in `<WinNT.h>` included by  `<windows.h>`. Its definition is as follows:
```c
typedef void *PVOID;
typedef PVOID HANDLE;
```
Inside the kernel, Windows maintains a table of all the different objects that the kernel is responsible for. Windows, buttons, icons, mouse pointer, menus, and so on, all get an entry in the table, and each entry is assigned a unique address known as a `HANDLE`. If you want to pick a particular entry out of that table, you need to give Windows the `HANDLE` value, and Windows will return the corresponding table entry.

![Alt](https://mblogthumb-phinf.pstatic.net/MjAxNzA4MDJfMTYz/MDAxNTAxNjYyNDYyOTcx.3_fGK11x4PDWUeOITEh4wMsdMgj4pereuVxq1I5Rpzwg.uIaaYMJdZeFG7uUi46FxsF-g4WVv8SLxPQAkkLn688kg.PNG.tipsware/20170802_163752_373.png?type=w800)

![Alt](https://mblogthumb-phinf.pstatic.net/MjAxNzA4MDJfMjgg/MDAxNTAxNjYyNTIwNjMy.zSg80GtIuohISkJvNUuFif8uA9gOZ619kf4lB9WtHUIg.dMOlH1GLsgueGqGLpf0LuMkBXecYYOZjH1kGIgj2c98g.PNG.tipsware/20170802_163811_253.png?type=w800)

To avoid using wrong `HANDLE` value, every resource has its distinct name as follows:
```c
HCURSOR h_my_cursor = LoadCursor(NULL, IDC_ARROW);  //stores the HANDLE value of cursor
HICON h_my_icon = LoadIcon(NULL, IDI_APPLICATION);  //stores the HANDLE value of icon
```

### GetStdHandle()
This function is defined in `<windows.h>`. It retrieves a handle to the specified standard device (standard input, standard output, or standard error).

**Syntax**
```c
HANDLE WINAPI GetStdHandle(_In_ DWORD nStdHandle);
```

**Parameters**

`nStdHandle` [in]: This parameter can be on of the following values.
Value|Meaning
-|-
`STD_INPUT_HANDLE`|The standard input device. Initially, this is the console input buffer.
`STD_OUTPUT_HANDLE`|The standard output device. Initially, this is the active console screen buffer.
`STD_ERROR_HANDLE`|The standard error device. Initially, this is the active console screen buffer.

**Return Value**

If the function succeeds, the return value is a handle to the specified device, or a redirected handle set by a previous call to `SetStdHandle`. If the function fails, the return values is `INVALID_HANDLE_VALUE`. If an application does not have associated standard handles, the return value is `NULL`.

### CONSOLE_SCREEN_BUFFER_INFO
This is a `struct` datatype defined in `<windows.h>`. It contains information about a console screen buffer.

**Syntax**
```c
typedef struct _CONSOLE_SCREEN_BUFFER_INFO {
  COORD		 dwSize;
  COORD		 dwCursorPosition;
  WORD		 wAttributes;
  SMALL_RECT srWindow;
  COORD		 dwMaximumWindowSize;
} CONSOLE_SCREEN_BUFFER_INFO;
```

**Members**

`wAttributes`: The attributes of the characters written to a screen buffer by the `WriteFile` and `WriteConsole` functions, or echoed to a screen buffer by the `ReadFile` and `ReadConsole` functions.

### GetConsoleScreenBufferInfo()
This function is defined in `<windows.h>`. It retrieves information about the specified console screen buffer.

**Syntax**
```c
BOOL WINAPI GetConsoleScreenBufferInfo(
  _In_ HANDLE 						hConsoleOutput,
  _Out_ PCONSOLE_SCREEN_BUFFER_INFO lpConsoleScreenBufferInfo
);
```

**Parameters**

`hConsoleOutput` [in]: A handle to the console screen buffer. The handle must have the **GENERIC_READ** access right.
`lpConsoleScreenBufferInfo` [out]: A pointer to a `CONSOLE_SCREEN_BUFFER_INFO` structure that receives the console screen buffer information.

**Return Value**

If the function succeeds, the return value is nonzero. If the function fails, the return values is zero.

### SetConsoleTextAttribute()
This function sets the attributes of characters written to the console screen buffer by the `WriteFile` or `WriteConsole` function, or echoed by the `ReadFile` or `ReadConsole` function. This function affects text written after the function call.

**Syntax**
```c
BOOL WINAPI SetConsoleTextAttribute(
  _In_ HANDLE hConsoleOutput,
  _In_ WORD   wAttributes
);
```

**Parameters**

`hConsoleOutput` [in]: A handle to the console screen buffer. The handle must have the **GENERIC_READ** access right.
`wAttributes` [in]: The [character attributes](https://docs.microsoft.com/en-us/windows/console/console-screen-buffers#character-attributes). 

**Return Value**

If the function succeeds, the return value is nonzero. If the function fails, the return value is zero.

# C Library - <conio.h>
This is a C header file used mostly by **MS-DOS** compilers to provide console input/output. It is not part of the C standard library or ISO C. Most C compilers that target DOS, Windows 3.x, or Win32 have this header and supply the associated library functions in the default C library. Most C compilers that target UNIX and Linux do not have this header.

### getch()
This functions gets a character from the console without echo. Its name is deprecated because it doesn't follow the Standard C rules for implementation-specific names. However, the function is still supported. `_getch()` is recommended instead.

**Syntax**
```c
int _getch(void);
```

**Return Value**

Returns the character read. There's no error return.

**Remarks**

It is mostly used to hold the screen until the use passes a single value to exit from the console screen. It has no buffer area to store the input character in a program. The input character provided by the users can be hided.


