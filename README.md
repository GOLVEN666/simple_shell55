# Simple Shell Project Repository

This repository contains the files for ALX **simple_shell** project, a basic UNIX command line interpreter. The shell supports common commands and programs typically found in the `/bin/` directory.

## Pre-requisites

To compile the shell, you will need the following authorized functions and macros:

- `access` (man 2 access)
- `chdir` (man 2 chdir)
- `close` (man 2 close)
- `closedir` (man 3 closedir)
- `execve` (man 2 execve)
- `exit` (man 3 exit)
- `_exit` (man 2 _exit)
- `fflush` (man 3 fflush)
- `fork` (man 2 fork)
- `free` (man 3 free)
- `getcwd` (man 3 getcwd)
- `getline` (man 3 getline)
- `isatty` (man 3 isatty)
- `kill` (man 2 kill)
- `malloc` (man 3 malloc)
- `open` (man 2 open)
- `opendir` (man 3 opendir)
- `perror` (man 3 perror)
- `read` (man 2 read)
- `readdir` (man 3 readdir)
- `signal` (man 2 signal)
- `stat` (`__xstat`) (man 2 stat)
- `lstat` (`__lxstat`) (man 2 lstat)
- `fstat` (`__fxstat`) (man 2 fstat)
- `strtok` (man 3 strtok)
- `wait` (man 2 wait)
- `waitpid` (man 2 waitpid)
- `wait3` (man 2 wait3)
- `wait4` (man 2 wait4)
- `write` (man 2 write)

You can compile the shell using the following GCC command:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

This command compiles all the .c files in the repository and generates an executable called hsh.

# Usage
After compiling the shell, you can run it by executing the hsh executable:
$ ./hsh

### Contact Info:

Git: [GOLVEN666](https://github.com/GOLVEN666)
