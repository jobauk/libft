*This project has been created as part of the 42 curriculum by jaukes*

## Description
This project contains a lot of utility fuctions from libc to handle strings, memory, and numbers. It also includes some additional functionality for linked lists. Every implementation of a libc function follows the behaviour described in it's man page.

## Instructions
Compile the library:
```sh
make
```
Delete all generated .o files:
```sh
make clean
```
Delete all generated files:
```sh
make fclean
```
Re-compile:
```sh
make re
```
Run all tests:
```sh
make test
```
Filter tests:
```sh
# This will run all tests in the ft_split suite
make test FILTER='ft_split/*'
```
Run a program (for quick testing):
```sh
make run
```
Debug a program (gdb/lldb):
```sh
make debug
```
Run norminette on all srcs:
```sh
make norm
```

## Resources
Man pages
