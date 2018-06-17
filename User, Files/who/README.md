# who command
## Sample Code
```
$ who 
ryan     :0           2018-06-11 11:46 (:0)
```
## Implementation
| Version | Overview |
|---------|----------|
| [who1.c](https://github.com/AtlasUnion/Unix/blob/master/User%2C%20Files/who/who1.c)  | a basic implementation of who command |
| [who2.c](https://github.com/AtlasUnion/Unix/blob/master/User%2C%20Files/who/who2.c)  | add human-readable time display |
| [who3.c](https://github.com/AtlasUnion/Unix/blob/master/User%2C%20Files/who/who3.c)  | add buffer |
## System calls
### int open(const char* pathname, int flags)
The open() system call opens the file specified by pathname.  If the specified file does not exist, it may optionally (if O_CREAT is specified in flags) be created by open(). [Open mode](http://man7.org/linux/man-pages/man2/open.2.html) is specified by the flags.


|         	| open                                                                   	|
|---------	|------------------------------------------------------------------------	|
| **PURPOSE** 	| Create a connection to file                                            	|
| **INCLUDE** 	| `#include <fcntl.h>`                                         	|
| **USAGE**   	| `int fd = open (char *name, int how)`                           	|
| **ARGS**  	| `name` &nbsp; name of file    <br>       `how` &nbsp;   O_RDONLY, O_WRONLY, O_RDWR 	|
| **RETURNS** 	| `-1` &nbsp; on error    <br>      `int` &nbsp; on success                          	|

### ssize_t read(int fd, void *buf, size_t count)
[read()](http://man7.org/linux/man-pages/man2/read.2.html) attempts to read up to count bytes from file descriptor fd into the buffer starting at buf.


|         	| read                                                                       	|
|---------	|----------------------------------------------------------------------------	|
| **PURPOSE** 	| Transfer up to qty bytes from fd to buf                                    	|
| **INCLUDE** 	| `#include <unistd.h>`                                                        	|
| **USAGE**   	| `ssize_t numread = read (int fd, void *buf, size_t qty)`                     	|
| **ARGS**    	| `fd` &nbsp; source of data <br> `buf` &nbsp; destination for data <br> `qty` &nbsp; number of bytes to transfer 	|
| **RETURNS** 	| `-1` &nbsp; on error <br> `numread` &nbsp; on success                                            	|

|           | close                           |
|-----------|---------------------------------|
| **Purpose** | Closes a file                 |
| **INCLUDE** | `#include <unistd.h>`         |
| **USAGE**   | `int result = close(int fd)`  |
| **ARGS**    | `fd` &nbsp; file descriptor   |
| **RETURNS** | `-1` &nbsp; on error <br> `0` &nbsp; on success|

## System files
### utmp
[utmp](http://man7.org/linux/man-pages/man5/utmp.5.html) file stores login records
## Helpful Links
* [c printf format](https://en.wikipedia.org/wiki/Printf_format_string#Format_placeholder_specification)
