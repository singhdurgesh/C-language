# The principal structure of a program

This section covers
1. C grammar
2. Declaring identifiers
3. Defining objects
4. Instructing the compiler with statements

There are two categories of aspects to consider in a C program: syntactical aspects (how do we specify the program so the compiler understands it?) and semantic aspects (what do we specify so that the program does what we want it to do?).

## 1. C Grammar

### Special Words:

The special words like `#include, int, void` represents concepts and features that the C language imposes and that cannot be changed

### Punctuation:

C uses several types of punctuation to structure the program text.
1. Therearefivekindsofbrackets: { ... },( ... ),[ ... ],/* ... */ and < ... >. Brackets group certain parts of the program together and should always come in pairs. Fortunately, the < ... > brackets are rare in C and are only used to include libraries like `#include <stdlib.h>`, on the same logical line of text. The other four are not limited to a single line; their contents might span several lines, as they did when we used printf earlier

2. There are two different separators or terminators: comma and semicolon. 

Note: Punctuation characters can be used with several different meanings.

### Comments:

The construct /* ... */ tells the compiler that every-thing inside it is a comment. For example: ` /* The main thing that this program does. */`
Another form of comment is the so-called C++-style comment. These are marked with //. C++-style comments extend from the // to the end of the line.

### Literals:

Literals refer to fixed values that are part of the program like: `0, 1, 3, 4, 5, 9.0, 2.9, 3.E+25, .00007, and "I'm a literal string"`

### Identifiers:

These are `names` that we (or the C standard) give to certain entities in the program. For example: `main, printf, size_t, and EXIT_SUCCESS`. Identifiers can play different roles in a program. Among other things, they may refer to
1. Data objects (such as A and i). These are also referred to as variables .
2. TypeC aliases, such as size_t, that specify the “sort” of a new object, here of i. Observe the trailing _t in the name. This naming convention is used by the C standard to remind you that the identifier refers to a type.
3. Functions, such as main and printf.
4. Constants, such as EXIT_SUCCESS.

### Functions

In above example, Two of the identifiers refer to functions: `main and printf`. `printf` is used by the program to produce some output.
The function `main` in turn is defined : that is, its declaration `int main(void)` is followed by a `block` enclosed in `{ ... }` that describes what that function is supposed to do.

### Operators

There are numerous C operators. Listed a few operators below:

1. =forinitialization and assignment,
2. < for comparison,
3. ++ to increment a variable (to increase its value by 1), and
4. \* to multiply two values.

## 2. Declaration

Before we may use a particular identifier in a program, we have to give the compiler a declaration that specifies what that identifier is supposed to represent. This is where identifiers differ from keywords: keywords are predefined by the language and must not be declared or redefined.

Conceptually, it is important to distinguish the box itself (the object), the specification (its type), the box contents (its value), and the name or label that is written on the box (the identifier).
For three identifiers, `printf, size_t, and EXIT_SUCCESS`, that are predeclared identifiers. The information about these identifiers doesn’t come out of nowhere. We have to tell the compiler where it can obtain information about them. This is done right at the start of the program, `printf` is provided by stdio.h, whereas `size_t` and `EXIT_SUCCESS` come from stdlib.h.

A declaration only describes a feature but does not create it, so repeating a declaration does not do much harm but adds redundancy.
Note:
1. Identifiers may have several consistent declarations.
2. Declarations are bound to the scope in which they appear.

These scopes of identifiers are unambiguously described by the grammar. we have declarations in different scopes:
```
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
```
In the above code snippet

1. A is visible inside the definition of main, starting at its declaration on line 78 and ending at the closing } on line 83 of the innermost { .. } block that contains that declaration.
2. i has more restricted visibility. It is bound to the for construct in which it is declared. Its visibility reaches from that declaration on line 85 to the end of the { ... } block that is associated with the for on line 90.
3. main is not enclosed in a { ... } block, so it is visible from its declaration onward until the end of the file.
In a slight abuse of terminology, the first two types of scope are called block scopeC , because the scope is limited by a `block` of matching { ... }. The third type, as used for `main`, which is not inside a { ... } pair, is called file scope. Identifiers in file scope are often referred to as globals.


## 3. Definitions

Generally, declarations only specify the kind of object an identifier refers to, not what the concrete value of an identifier is, nor where the object it refers to can be found. This important role is filled by a definition.
Declarations specify identifiers, whereas definitions specify objects.
An initialization is a grammatical construct that augments a declaration and provides an initial value for the object. For instance,
`size_t i = 0;`
is a declaration of i such that the initial value is 0.
In C, such a declaration with an initializer also defines the object with the corresponding name: that is, it instructs the compiler to provide storage in which the value of the variable can be stored.
- An object is defined at the same time it is initialized.
- Missing elements in initializers default to 0.
- For an array with n elements, the first element has index 0, and the last has index n-1.
For a function, we have a definition (as opposed to only a declaration) if its declaration is followed by braces { ... } containing the code of the function:
```
 int main(void) {
  ...
}
```
In contrast to object or function declarations, where several are allowed for the same identifier, definitions of objects or functions must be unique. That is, for a C program to be operational, any object or function that is used must have a definition (otherwise the execution would not know where to look for them), and there must be no more than one definition (otherwise the execution could become inconsistent).


## 4. Statements

The second part of the main function consists primarily of state- ments. Statements are instructions that tell the compiler what to do with identifiers that have been declared so far.
In the following subsection, we will go a bit into the details of three categories of statements: iterations (do something several times), function calls (delegate execution somewhere else), and function returns (resume execution from where a function was called).

### 1. Iteration:
Theforstatementtellsthecompilerthattheprogramshouldexecute the printf line a number of times. This is the simplest form of domain iterationC that C has to offer. It has four different parts.
The code that is to be repeated is called the loop bodyC : it is the { ... } block that follows the for ( ... ). The other three parts are those inside the ( ... ) part, divided by semicolons:
1. The declaration, definition, and initialization of the loop variableC i, which we already discussed. This initialization is executed once before any of the rest of the entire for statement.
2. A loop conditionC , i < 5 specifies how long the for iteration should continue. This tells the compiler to continue iterating as long as i is strictly less than 5. The loop condition is checked before each execution of the loop body.
3. Another statement, ++i, is executed after each iteration. In this case, it increases the value of i by 1 each time.

- Domain iterations should be coded with a for statement.
- The loop variable should be defined in the initial part of a for.

### 2. Function Calls:
Function calls are special statements that suspend the execu- tion of the current function (at the beginning, this is usually main) and then hand over control to the named function.
A function call usually provides more than just the name of the function, but also arguments.
C does not implement pass by reference, but it has another mechanism to pass the control of a variable to another function: by taking addresses and transmitting pointers.

### 3. Function Return:

The last statement in main is a return. It tells the main func- tion to return to the statement that it was called from once it’s done. Here, since main has int in its declaration, a return must send back a value of type int to the calling statement. In this case, that value is EXIT_SUCCESS.
Even though we can’t see its definition, the `printf` function must contain a similar return statement. At the point where we call the function, execution of the statements in main is temporarily suspended. Execution continues in the `printf` function until a return is encountered. After the return from printf, execution of the statements in main continues from where it stopped.

## Summary
- C distinguishes the lexical structure (the punctuators, identifiers, and numbers), the grammatical structure (syntax), and the semantics (meaning) of programs.
- All identifiers (names) must be declared such that we know the properties of the
concept they represent.
- All objects (things that we deal with) and functions (methods that we use to deal
with things) must be defined; that is, we must specify how and where they come
to be.
- Statements indicate how things are going to be done: iterations (for) repeat
variations of a certain tasks, functions calls (printf(...)) delegate a task to a function, and function returns (return something;) go back where we came from.
