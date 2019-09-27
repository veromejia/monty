## C - Stacks, Queues - LIFO, FIFO

## The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

### OBJECTIVES

understand and be hable to explain the following

* What do LIFO and FIFO mean
* What is a stack, and when to use it
* What is a queue, and when to use it
* What are the common implementations of stacks and queues
* What are the most common use cases of stacks and queues
* What is the proper way to use global variables
* How to work with git submodules


## FILES

* file_functions: contain all the helpers functions to find and call the functions to be executed
* monty.h: contains two structures and all the prototipes of the functions
* lists.c: contains the helpers functions to manipulate the doble linked list
* opcode.c: contains the functios push, pall, pint, pop, swap
* calculator.c: contains the functions add, sub, div, mul, not
* opcode2.c: contains the function mod
* bytecodes file: contains all the files to test the program


## TEST

*  All output prints on stdout
*  All errors are printed on stderr
   - No file or more than 1 argument? USAGE: monty file
   - Not possible to open file? Error: Can't open file <file>
   - Invalid instruction? L<line_number>: unknown instruction <opcode>
   - Unable to malloc? Error: malloc failed
   - Specific errors for each opcode (unable to pint, pop, swap, etc)


## COMPILATION

```gcc -Wall -Werror -Wextra -pedantic *.c -o monty```

```./monty bytecodes/00.m```  you have to change the file .m to test all the functions
