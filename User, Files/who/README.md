# who command
## Sample Code
```
$ who 
ryan     :0           2018-06-11 11:46 (:0)
```
## Implementation
### who1.c
#### System calls
##### int open(const char* pathname, int flags)
The open() &nbsp; &nbsp; system call opens the file specified by pathname.  If the specified file does not exist, it may optionally (if O_CREAT isspecified in flags) be created by open(). [Open mode](http://man7.org/linux/man-pages/man2/open.2.html) is specified by the flags.


|         	| open                                                                   	|
|---------	|------------------------------------------------------------------------	|
| PURPOSE 	| Create a connection to file                                            	|
| INCLUDE 	| #include <fcntl.h>                                            	|
| USAGE   	| int fd = open (char *name, int how)                           	|
| ARGS    	| name &nbsp; &nbsp; name of file    <br>       how &nbsp; &nbsp;&nbsp;   O_RDONLY, O_WRONLY, O_RDWR 	|
| RETURNS 	| -1 &nbsp; &nbsp; on error    <br>      int &nbsp; on success                          	|

##### ssize_t read(int fd, void *buf, size_t count)
[read()](http://man7.org/linux/man-pages/man2/read.2.html) attempts to read up to count bytes from file descriptor fd into the buffer starting at buf.


|         	| read                                                                       	|
|---------	|----------------------------------------------------------------------------	|
| PURPOSE 	| Transfer up to qty bytes from fd to buf                                    	|
| INCLUDE 	| #include <unistd.h>                                                        	|
| USAGE   	| ssize_t numread = read (int fd, void *buf, size_t qty)                     	|
| ARGS    	| fd &nbsp; &nbsp; source of data <br> buf &nbsp; &nbsp; destination for data <br> qty &nbsp;&nbsp; number of bytes to transfer 	|
| RETURNS 	| -1  on error numread on success                                            	|
###### return value
#### System files
##### utmp
[utmp](http://man7.org/linux/man-pages/man5/utmp.5.html) file stores login records
