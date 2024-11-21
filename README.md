# get_next_line

## Table of contents

- [Overview](#overview)
- [Function Prototype](#function-prototype)
- [Personal notes](#personal-notes)

## Overview

The **get_next_line** project is a fundamental C programming exercise that aims to deepen the understanding of file handling and memory management in the C language. The goal is to create a function `get_next_line()` which reads a line from a file descriptor, including handling edge cases, large files, and different buffers efficiently. This project is commonly assigned in coding schools like 42 to practice buffer-based reading and linked list management.

## Function Prototype

```c
char *get_next_line(int fd);
```

## Personal notes

### File descriptor

A file descriptor(fd) is a small integer that the operating system uses to represent an open file or I/O resource(like a socket or a pipe). It acts as a handle that allows programs to interact with files or devices in a standardized way, without needing to know the specific details of the underlying system.

- Each time a program opens a new file, the operating system assigns the lowest unused integer as the file descriptor for that file. If the standard descriptors 0, 1, and 2 are in use, the next open file might get the file descriptor 3.

- The file descriptor is used in subsequent system calls like read(), write(), and close() to identify which file to operate on.

#### Standard File Descriptors

When a program starts, the operating system automatically opens three standard file descriptors:

- 0 (stdin): Standard input (e.g., keyboard input).

- 1 (stdout): Standard output (e.g., terminal display for normal output).

- 2 (stderr): Standard error (e.g., terminal display for error messages).

### Open, read and close

### Open

open() is used to open a file for reading, writing, or both, and it returns a file descriptor (an integer) that acts as a handle for subsequent file operations.

```c
int open(const char *pathname, int flags, mode_t mode);
```

#### pathname:

The path to the file you want to open (absolute or relative).
Example: "file.txt" or "/home/user/file.txt".

#### flags:

Specifies how the file should be opened. Common options include:

- O_RDONLY: Open the file for reading only.
- O_WRONLY: Open the file for writing only.
- O_RDWR: Open the file for both reading and writing.

Additional modifiers can be combined using the bitwise OR operator (|):

- O_CREAT: Create the file if it doesn’t exist.
- O_TRUNC: Truncate the file (set its size to 0) if it already exists.
- O_APPEND: Append data to the end of the file.

Example: O_RDWR | O_CREAT.

#### mode:

(Optional) Used when creating a new file (when O_CREAT is specified).

Specifies the file permissions (e.g., read, write, execute) for the owner, group, and others using octal notation:

- S_IRUSR: Read permission for the owner.
- S_IWUSR: Write permission for the owner.
- S_IRGRP: Read permission for the group.

Example: 0644 grants read/write for the owner and read-only for others.

Return value: On success return a non-negative fd, on failure return -1 and sets errno to indicate the error.

### Read

read() reads data from a file (or any file descriptor) into a buffer in memory.

```c
ssize_t read(int fd, void *buf, size_t count);
```

#### fd

File descriptor obtained from open().

Example: The integer returned by open().

#### buf

A pointer to a memory buffer where the data will be stored.

Example: A character array like char buffer[1024];.

#### count

The maximum number of bytes to read into the buffer.

Example: 1024 to read up to 1024 bytes.

Return value: On success, the number of bytes read, returns 0 if the end of the file(EOF) is reached. On failure, -1 and set errno.

### Close

close() releases the file descriptor and any associated resources. It ensures that data is written to the disk and prevents resource leaks.

```c
int close(int fd);
```

Return Value:

- On success: Returns 0.
- On failure: Returns -1 and sets errno.

### Local, Global and Static Variables

To understand this concepts, I used this [Resources](https://www.codequoi.com/en/local-global-static-variables-in-c/#static-variables)

Summary of static in C:

- In a function: Maintains the variable's value across calls to that function.
- In global scope (outside functions): Limits the variable's scope to the file, providing internal linkage and hiding it from other files in a multi-file program.
