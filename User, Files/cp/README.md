# cp command
## Sample Bash Code
```
$ ls
test.txt
$ cp test.txt test_copy.txt
$ ls
test.txt test_copy.txt
```

## Implementation
| Version | Overview |
|---------|----------|
|cp1.c    | A basic implementation of cp command|

## System Calls
### int creat(char *filename, mode_t mode)
|       | creat  |
|-------|--------|
| **PURPOSE** | Create or zero a file |
| **INCLUDE** | `#include <fcntl.h>`  |
| **USAGE** | `int fd = creat(char *filename, mode_t mode)` |
| **ARGS** | `filename` &nbsp; the name of the file <br> `mode` &nbsp; access permission |
| **RETURNS** | `-1` &nbsp; on error <br> `0` &nbsp; on success  |

### int write(int fd, void *buf, size_t amt)
|       | write  |
|-------|--------|
| **PURPOSE** | Send data from memory to a file |
| **INCLUDE** | `#include <unistd.h>`  |
| **USAGE** | `ssize_t result = write(int fd, void *buf, size_t amt)` |
| **ARGS** | `fd` &nbsp; a file descriptor <br> `buf` &nbsp; an array <br> `amt` &nbsp; how many bytes to write |
| **RETURNS** | `-1` &nbsp; on error <br> `num written` &nbsp; on success  |