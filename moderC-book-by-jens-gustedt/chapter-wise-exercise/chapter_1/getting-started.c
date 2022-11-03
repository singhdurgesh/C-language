/* This may look like nonsense , but really is -*- mode : C -*- */
# include <stdlib.h>
# include <stdio.h>
/* The main thing that this program does . */
int main ( void ) {
// Declarations
double A [5] = {
[0] = 9.0 ,
[1] = 2.9 ,
[4] = 3.E+25 ,
[3] = .00007 ,
};
// Doing some work
for ( size_t i = 0; i < 5; ++i) {
printf ("element %zu is %g, \tits square is %g\n",
i,
A[i] ,
A[i]*A[i]) ;
}
return EXIT_SUCCESS ;
}

// Run a C program with the following command:
// $ gcc -Wall -Wextra -Wpedantic -std=c99 -o sample sample.c
// $ ./sample

// with c99
// c99 -o sample sample.c
// ./sample [args]

// Author: Durgesh Singh
// Email: singhdurgesh403@gmail.com
// Date: 02 November 2022
