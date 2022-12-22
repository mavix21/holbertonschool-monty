# **HOLBERTON SCHOOL-MONTY LANGUAGE INTERPRETER**

## Monty Language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it.

The goal of this project is to create an interpreter for Monty ByteCodes files.

## Compilation and Output

- Compile your code this way:
  - gcc -Wall -Werror -Wextra -pedantic *.c -o monty
    - usage: ./monty <filename>
    - filename should contain the opcode
    - one opcode per line
    - spaces and newlines are ignored
    - '#' sign represent comments and the line will be ignored

## Main files code
The main code files are the ones that the compiler will read first.

In this case they are the following:

- monty.h : contains all the structure and prototype
- main.c : main function for monty interpreter

## Secondary files code
For this project the secondary code files are the following:

| OPCODE | DESCRIPTION |
| :---: | :---:|
| push | pushes value to stack |
| pall | prints everything on the stack LIFO |
| pint | prints the top value of the stack |
| pop | removes the top element of the stack |
| swap | swaps the top two elements of the stack |
| add | adds the top two elements of the stack |
| sub | subtracs the top element of the stack from the second top elelement of the stack |
| nop | doesn't do anything |

### Authors
Marcelo Vizcarra

Alex Nuñez



