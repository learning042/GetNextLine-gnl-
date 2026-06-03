_This project has been created as part of the 42 curriculum by tpinto-v._

# Description

This project implements a function that takes a **file descriptor** related to a file and returns a string containing the next line from it (delimited by a newline character `'\n'`).

## File descriptor details

A file descriptor is an integer identifier that marks a specific file or other input/output resource. Typically, file descriptors are non-negative integers. In the traditional Unix implementation, file descriptors index into a per-process **file descriptor table** maintained by the kernel. Each entry in that table points to an entry in the **open file table**, which in turn references an **inode table**.

![File destriptor table](data:image/png;base64,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)

Another important detail: the first three file descriptors are standardized as the **standard streams**:

| FD | Name | Meaning |
|----|------|---------|
| 0 | stdin | Standard input |
| 1 | stdout | Standard output |
| 2 | stderr | Standard error |

![Standard streams](https://miro.medium.com/v2/resize:fit:1200/0*zEsSRKyg3fUMUfba.png)

## Mandatory part

The mandatory part is implemented using a `static` char buffer. Static variables reside in the **BSS segment** (if zero-initialized) or the **data segment** (if explicitly initialized), rather than on the stack. This means they persist across function calls — when the function returns, the variable retains its value for the next invocation.

The buffer is declared as follows:

```c
static char buffer[BUFFER_SIZE + 1];
```

`BUFFER_SIZE` is a macro specified by the user at compile time (see the Instructions section). It controls how many bytes are read into the buffer per iteration inside `get_next_line`.

```c
char    *get_next_line(int fd);
```

where `fd` is the file descriptor.

At each call, the function first checks whether the buffer already contains data from a previous read. Since stack-allocated arrays are conventionally zero-initialized, testing whether `buffer[0] == '\0'` tells us if this is the first call or if the buffer has been fully consumed. If data remains, the function checks for a newline; otherwise it reads more data from the file.

The internal workhorse is:

```c
char    *ft_get_line(int fd, char *buf, char **s)
```

where `buf` is a pointer to the static buffer and `s` is a double pointer to the `line` string (the one that will hold the returned line). A double pointer is used because the function needs to reassign the pointer itself — passing a single pointer would only modify a local copy.

All helper functions are declared `static` since they are only used within `ft_get_line`:

| Function | Description |
|----------|-------------|
| `static int ft_strlen(char *s, char term)` | Returns the length of `s` up to `term`. Falls back to `'\0'` if `term` is not found. |
| `static int ft_findnl(char *s)` | Returns non-zero if `s` contains a newline `'\n'`. |
| `static char *ft_strjoin(char *s1, char *s2)` | Concatenates `s2` onto `s1`, treating `'\n'` as the end of `s2` (or `'\0'` if no newline is found). The result is heap-allocated via `malloc()`. `s1` is freed via `free()` before returning, since it was a previous dynamic allocation. Returns the new string. |
| `static void ft_shift_buffer(char *buf)` | Shifts all characters after the first `'\n'` to the beginning of `buf`, then null-terminates the remainder so stale data is not re-read. |

File reading is done with the `read()` function from `<unistd.h>`.

## Bonus part

When the mandatory version's `get_next_line` is called with different file descriptors within the same program, the shared static buffer causes them to interfere with each other — leading to undefined behaviour.

The fix is straightforward: change the buffer from:

```c
static char buffer[BUFFER_SIZE + 1];
```

to:

```c
static char buffer[1024][BUFFER_SIZE + 1];
```

`1024` corresponds to the default soft limit for open file descriptors per process. When calling `ft_get_line`, simply pass `buffer[fd]` instead of `buffer` to isolate each file descriptor's state.

# Instructions

1. Download the files.

2. In your `.c` file, include the appropriate header:
   - Mandatory part: `#include "get_next_line.h"`
   - Bonus part: `#include "get_next_line_bonus.h"`

   If the header is not in your current directory, use a relative path: `#include "../path/to/get_next_line.h"` — or handle it via the `-I` flag in the next step.

3. Compile (mandatory example):
   ```bash
   cc -I[path/to/header] -D BUFFER_SIZE=42 -Wall -Wextra -Werror \
       get_next_line_utils.c get_next_line.c your_file.c -o your_program
   ```
   Replace `42` with your desired buffer size and adjust paths as needed.

4. Run the executable:
   ```bash
   ./your_program
   ```

# Resources

- [Limit on file descriptors in a file descriptor table](https://www.baeldung.com/linux/limit-file-descriptors)
- [File descriptor — Wikipedia](https://en.wikipedia.org/wiki/File_descriptor)
- [What are file descriptors? (Stack Overflow)](https://stackoverflow.com/questions/5256599/what-are-file-descriptors-explained-in-simple-terms)
- [GeeksforGeeks](https://www.geeksforgeeks.org) — tutorials on C and many other computing topics
- [CS50x](https://cs50.harvard.edu/x/) — introductory course covering C and programming fundamentals
- [Standard streams — Wikipedia](https://en.wikipedia.org/wiki/Standard_streams)