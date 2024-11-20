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
