# Memory Layout of C Programs
A typical memory representation of a C program consists of the following sections.
1. Text segment (i.e. instructions)
2. Initialized data segment
3. Uninitialized data segment (bss)
4. Heap
5. Stack

![Alt](https://media.geeksforgeeks.org/wp-content/uploads/memoryLayoutC.jpg)

A typical memory layout of a **running process**

### 1. Text Segment
>A text segment, also knows as a **code segment** or simply as **text**, is one of the sections of a program in an **object file** or in **memory**, which contains **executable instructions**. 

- As a memory region, a text segment may be placed below the heap or stack in order prevent heaps and stack overflows from overwriting it.

- Usually, the text segment is sharable(can be accessed by several different CPUs) so that only a single copy needs to be in memory for frequently executed programs, such as text editors, the C compiler, the shells, and so on. Also, the text segment is often read-only, to prevent a program from accidentally modifying its instructions.

### 2. Initialized Data Segment
> An initialized data segment, usually called simply the **data segment**. A data segment is a portion of the virtual address space(allocated memory space by segmentation)  of a program, which contains the **global variables** and **static variables** that are initialized by the programmer.

- The data segment can be further classified into the initialized read-only area and the initialized read-write area. 
- For instance, the global string defined by `char s[] = "hello world"` in C and a C statement like `int debug = 1` outside the `main` (i.e. global) would be stored in the initialized read-write area. And a global C statement like `const char* string = "hello world"` makes the string literal `"hello world"` to be stored in the initialized read-only area and the character pointer variable `string` in the initialized read-write area. 

### 3. Uninitialized Data Segment
> Uninitialized data segment often called the **bss** segment, named after an ancient assembler operator that stood for **"Block Started by Symbol"**.

- Data in this segment is initialized by the kernel to arithmetic 0 before the program starts executing.
- Uninitialized data starts at the end of the data segment and contains all global variables and static variables that are initialized to zero or do not have explicit initialization in source code.

### 4. Stack
> The stack area traditionally adjoined the **heap** area and grew in the opposite direction; when the stack pointer met the heap pointer, free memory was exhausted. With modern large address spaces and virtual memory techniques they may be placed almost anywhere, but they still typically grow in opposite directions.
- The stack area contains the program stack, a LIFO structure, typically located in the higher parts of memory. On the standard PC x86 computer architecture, it grows toward address zero; on some other architectures, it grows in the opposite direction. A "stack pointer" register tracks the top of the stack; it is adjusted each time a value is "pushed" onto the stack. The set of values pushed for one function call is termed a "stack frame"; A stack frame consists at minimum of a return address.
- Stack, where **automatic variables** are stored, along with information that is saved each time a **function** is called. Each time a function is called, the address of where to return to and certain information about the caller's environment, such as some of the machine registers, are saved on the track. The newly called function then allocates room on the stack for its **automatic and temporary variables**. This is how **recursive functions** in C can work. 

### 5. Heap
> Heap is the segment where **dynamic memory allocation** usually takes place.
- The heap area begins at the end of the BSS segment and grows to larger addresses from there.
- The heap area is managed by `malloc`, `realloc`, and `free`, which may use the `brk` and `sbrk` system calls to adjust its size.
- The heap area is shared by all shared libraries and dynamically loaded modules in a process.

### Examples
1. ```c
	//memory-layout.c
	#include <stdio.h>
	int main(void) {
		 return 0;
	}
	```
	```
	$ gcc memory-layout.c -o memory-layout
	$ size memory-layout
	text	data	bss		dec		hex		filename
	960		248		8		1216	4c0		memory-layout
	```
	The `size` command on the console reports the sizes (in bytes) of the text, data, and bss segments.
2. Add one global variable in the program.
	```c
	#include <stdio.h>
	int global;  //uninitialized variable stored in bss
	int main(void) {
		return 0;
	}
	```
	```
	$ gcc memory-layout.c -o memory-layout
	$ size memory-layout
	text	data	bss		dec		hex		filename
	960		248		12		1216	4c0		memory-layout
	```
3. Add one static variable which is also stored in bss.
	```c
	#include <stdio.h>
	int global;  //uninitialized variable stored in bss
	int main(void) {
		static int i;  //uninitialized static variable stored in bss
		return 0;
	}
	```
	```
	$ gcc memory-layout.c -o memory-layout
	$ size memory-layout
	text	data	bss		dec		hex		filename
	960		248		16		1216	4c0		memory-layout
	```
4. Initialize the static variable which will then be stored in the data segment.
	```c
	#include <stdio.h>
	int global;  //uninitialized variable stored in bss
	int main(void) {
		static int i = 100;  //initialized static variable stored in DS
		return 0;
	}
	```
	```
	$ gcc memory-layout.c -o memory-layout
	$ size memory-layout
	text	data	bss		dec		hex		filename
	960		252		12		1216	4c0		memory-layout
	```	
5. Initialize the global variable which will then be stored in the data segment.
	```c
	#include <stdio.h>
	int global = 10;  //initialized global variable stored in DS
	int main(void) {
		static int i = 100;  //initialized static variable stored in DS
		return 0;
	}
	```
	```
	$ gcc memory-layout.c -o memory-layout
	$ size memory-layout
	text	data	bss		dec		hex		filename
	960		256		8		1216	4c0		memory-layout
	```	
	
### *references*:
[https://www.geeksforgeeks.org/memory-layout-of-c-program/](https://www.geeksforgeeks.org/memory-layout-of-c-program/)



# Segmentation vs. Paging
These are **non-contiguous memory allocation schemes** for processes to run on a physical memory(most frequently used memory management technique is **Virtual Memory Management**). 

### Segmentation
 A process is divided into segments. The chunks that a program is divided into which are not necessarily all of the same sizes are called segments. 
1. **Virtual memory segmentation**:
Each process is divided into a number of segments, not all of which are resident at any one point in time.
2. **Simple Segmentation**:
	Each process is divided into a number of segments, all of which are loaded into memory at run time, though not necessarily contiguously.

**Segment Table**:
It maps two-dimensional logical address into one-dimensional physical address.
- **Base Address**: It contains the starting physical address where the segments reside in memory.
- **Limit**: It specifies the length of the segment.
	
	![Alt](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2016/02/segmentation.png)
Translation of two-dimensional logical address to one-dimensional physical address.

![Alt](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2016/02/Translation.png)
Address generated by the CPU is divided into:
- **Segment Number (s)**: Number of bits required to represent the segment.
- **Segment Offset (d)**: Number of bits required to represent the size of the segment.

**Advantages of Segmentation**
- No internal fragmentation.
- Segment table consumes less space in comparison to page table in paging.

**Disadvantage of Segmentation**
- As processes are loaded and removed from the memory, the free memory space is broken into little pieces, causing external fragmentation.

### Paging
It is a fixed size partitioning scheme. Both main memory and secondary memory are divided into equal fixed size partitions. The partitions of secondary memory area unit and main memory area unit known as pages and frames respectively.

![Alt](https://media.geeksforgeeks.org/wp-content/uploads/20190925181700/Untitled-Diagram-910.png)

### *references*:
[https://www.geeksforgeeks.org/difference-between-paging-and-segmentation/](https://www.geeksforgeeks.org/difference-between-paging-and-segmentation/)
