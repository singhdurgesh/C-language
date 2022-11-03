# 1. Getting Started

- C is a compiled programming language.

To run a C program using Terminal use one of the following commands

> c99 -Wall -o getting-started getting-started.c -lm
> ./getting-started

- c99 is the compiler program.
- -Wall tells it to warn us about anything that it finds unusual.
- -o getting-started tells it to store the compiler outputC in a file named
getting-started.
- getting-started.c names the source fileC , the file that contains the C code
we have written. Note that the .c extension at the end of the filename refers to
the C programming language.
- -lm tells it to add some standard mathematical functions if necessary; we will need those later on.

> clang -Wall -lm -o getting-started getting-started.c
> gcc -std=c99 -Wall -lm -o getting-started getting-started.c
> icc -std=c99 -Wall -lm -o getting-started getting-started.c

Note: clang is even more picky than gcc and gives us even longer diagnostic lines

- C is designed to give computers orders. Thereby it mediates between us (the programmers) and computers.
- C must be compiled to be executed. The compiler provides the translation be- tween the language that we understand (C) and the specific needs of the particular platform.
- C gives a level of abstraction that provides portability. One C program can be used on many different computer architectures.
- The C compiler is there to help you. If it warns you about something in your program, listen to it.
