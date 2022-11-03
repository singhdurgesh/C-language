# Everything is about control

This section covers

- Conditional execution with if 
- Iterating over domains
- Making multiple selections

C has five conditional control statements: if, for, do, while, and switch.
We will look at these statements in this section: if introduces a conditional execution de- pending on a Boolean expression; for, do, and while are different forms of iterations; and switch is a `multiple selection` based on an integer value.
C has some other conditionals that we will discuss later: `the ternary operator` and de-noted by an expression in the form `cond ? A : B`, the compile-time pre-processor conditionals `#if/#ifdef/#ifndef/#elif/#else/#endif` , and type generic expressions denoted with the keyword `_Generic`

## 1. Conditional execution

The if (...) ... else ... is a selection statementC. It selects one of the two possible code pathsC according to the contents of ( ... ). The general form is
```
if (condition) statement0-or-block0
else statement1-or-block1
```

There are two simple rules for the evaluation of a numerical condition:
1. The value 0 represents logical false.
2. Any value different from 0 represents logical true.

The type bool, specified in stdbool.h, is what we should be using if we want to store truth values. Its values are `false` and true. Technically, false is just another name for 0 and true for 1. It’s important to use false and true (and not the numbers) to emphasize that a value is to be interpreted as a condition.

Redundant comparisons quickly become unreadable and clutter your code. If you have a conditional that depends on a truth value, use that truth value directly as the condition.

- Don’t compare to 0, false, or true.
- All scalars have a truth value.

## 2. Iterations

### For Loop
The general form of this statement is:
`for (clause1; condition2; expression3) statement-or-block`

This statement is actually quite generic. Usually, clause1 is an assignment expres- sion or a variable definition. It serves to state an initial value for the iteration domain. condition2 tests whether the iteration should continue. Then, expression3 updates the iteration variable used in clause1. It is performed at the end of each iteration.

### While amd do..while Loop

The general forms are
```
while (condition) statement-or-block
do statement-or-block while(condition);
```

As with the for statement, with do and while it is advisable to use the { ... } block variants. There is also a subtle syntactical difference between the two: do always needs a semicolon ; after the while (condition) to terminate the statement.

All three iteration statements become even more flexible with `break` and `continue` statements. A `break` statement stops the loop without reevaluating the termination condition or executing the part of the dependent block after the `break` statement.
The `continue` statement is less frequently used. Like `break`, it skips the execution of the rest of the dependent block, so all statements in the block after the continue are not executed for the current iteration. However, it then reevaluates the condition and continues from the start of the dependent block if the condition is true.

## 3. Multiple Selection:

The last control statement that C has to offer is the `switch` statement and is another selection statement. It is mainly used when cascades of `if-else` constructs would be too tedious.

Syntactically, a switch is as simple as
`switch (expression) statement-or-block`

and its semantics are quite straightforward: the case and default labels serve as jump targetsC . According to the value of the expression, control continues at the statement that is labeled accordingly. If we hit a break statement, the whole switch under which it appears terminates, and control is transferred to the next statement after the switch.

By that specification, switch statements can be used much more widely than iterated if-else constructs:
```
switch (count) { default:puts("++++␣.....␣+++"); case 4: puts("++++");
case 3: puts("+++");
case 2: puts("++");
case 1: puts("+");
case 0:;
}
```

Once we have jumped into the block, execution continues until it reaches a break or the end of the block. In this case, because there are no break statements, we end up running all subsequent puts statements. For example, the output when the value of count is 3 is a triangle with three lines:
```
+++
++
+
```
The structure of a switch can be more flexible than if-else, but it is restricted in another way:

- case values must be integer constant expressions.
With the greater flexibility of the switch statement also comes a price: it is more error prone. In particular, we might accidentally skip variable definitions:
- case labels must not jump beyond a variable definition.

## Summary
- Numerical values can be directly used as conditions for if statements; 0 repre- sents `false,` and all other values are `true.`
- There are three different iteration statements: `for, do, and while`. `for` is the preferred tool for domain iterations.
- A `switch` statement performs multiple selection. One case runs into the next, if it is not terminated by a break.
