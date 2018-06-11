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
The open() system call opens the file specified by pathname.  If the specified file does not exist, it may optionally (if O_CREAT isspecified in flags) be created by open(). [Open mode](http://man7.org/linux/man-pages/man2/open.2.html) is specified by the flags.
###### return value
file descriptor is success, else -1

##### ssize_t read(int fd, void *buf, size_t count)
read() attempts to read up to count bytes from file descriptor fd into the buffer starting at buf.
###### return value
On success, the number of bytes read is returned(zero indicates end of file), and the file position is advanced by this number. [The returned bytes may be smaller than requested](http://man7.org/linux/man-pages/man2/read.2.html). Else, -1.
#### System files
##### utmp
[utmp](http://man7.org/linux/man-pages/man5/utmp.5.html) file stores login records