# Controlling Program Flow
Controlling program flow means directing how a program makes decisions and repeats actions. C++ provides selection statements (if, if-else, switch) and iteration statements (for, while, do-while) to control the order of execution.

## The if statement
The if statement allows a program to execute code inly if a condition is true.
if the expresion is true then execute the statement, but if the expression is false, then skip the statement.
**Syntax**
```cpp
if (condition) {
    // statements executed if condition is true
}
```

**Example:**
```cpp
if (age >= 18) {
    std::cout << "You can vote\n";
}
```
The condition must evaluate to a boolean (true or false)

## The if-else statement
Adds an alternative block that executes when the condition is false
If the expressiojn is true then execute statement 1 but if the expression is false thene execute statement 2
**Syntax**
```cpp
if (condition) {
    // true branch
} else {
    // false branch
}
```
**Example:**
```cpp
if (grade >= 60) {
    std::cout << "Pass\n";
} else {
    std::cout << "Fail\n";
}
```

## Nested if statements
if statements inside other if statements, this allows testing multiple conditions.
It is used when multiple conditions must be checked in order
**Example:**
```cpp
if (score >= 90) {
    if (score <= 100) {
        std::cout << "A\n";
    }
}
```
**Another common style:**
```cpp
if (score >= 90) {
    std::cout << "A\n";
} else if (score >= 80) {
    std::cout << "B\n";
} else {
    std::cout << "C\n";
}
```
**Note:**
`else if` happens when the `if` before is false but we need to evaluate a new condition

## The switch statement
USed when testing a variable against multiple constant values.
Often cleaner than many `else-if` chain.
**Syntax**
```cpp
switch (expression) {
    case value1:
        statements;
        break;
    case value2:
        statements;
        break;
    default:
        statements;
}
```
**Important rules**
- Expression must be an integral type (int, char, enum).
- break prevents "fall though" into the next case.
- The default block is optional but should be handled (Best practice)
- Provide break statement for each case.

**Example**
```cpp
int option = 2;

switch (option) {
    case 1:
        std::cout << "Start\n";
        break;
    case 2:
        std::cout << "Settings\n";
        break;
    default:
        std::cout << "Invalid\n";
}
```
**Switch Case with enum**
```cpp
enum Color{
    red, green, blue
};
Color screen_color {green};

switch (screen_color)
{
    case red: cout << "red"; break;
    case green: cout << "green"; break;
    case blue: cout << "blue"; break;
    default: cout << "should never execute";
}
```

## The conditional Operator ?:
A compact form of an `if-else` statement.
Also called the ternary operator
**Syntax**
```cpp
condition ? value_if_true : value_if_false;
```
**Example:**
```cpp
int age = 20;
std::string result = (age >= 18) ? "Adult" : "Minor";
```
Useful for short decisions inside expressions.

## Looping (Iteration)
Loops repeat a block of code multiple times
C++ provides multiple options as:
- for
- range based for
- while
- do while

### for Loop
USed when the number of iterations is know in advance
**Syntax**
```cpp
for (initialization; condition; increment) {
    // repeated statements
}
```
**Example:**
```cpp
for (int i = 0; i < 5; i++) {
    std::cout << i << " ";          
}
// output 0 1 2 3 4
```

### Range based for loop
Introduced in C++11
It is used to loop directly over a collection such as arrays, vectors, or strings
**Syntax**
```cpp
for (auto element : container) {
    // process element
}
```
**Note**
`auto` is used to say the compiler that assign the data type of the element automatically


**Example:**
```cpp
std::vector<int> nums = {1, 2, 3};

for (int n : nums) {
    std::cout << n << " ";
}
```
You can use `auto&` to modify elements
```cpp
for (auto& n : nums) {
    n *= 2;
}
```

### while loop
Executes a block while a condition is true
**Syntax**
```cpp
while (condition) {
    // statements
}
```
**Example**
```cpp
int n = 5;

while (n > 0) {
    std::cout << n << "\n";
    n--;
}
```
if the condition is false initially, the loop never executes.

### do while Loop
Like a while loop, but guaranees at least one eecution because the condition is tested afeter the loop body
**Syntax**
```cpp
do {
    // statements
} while (condition);
```
**Example**
```cpp
int n = 0;
do {
    std::cout << n << "\n";
    n++;
} while (n < 3);
```
Even if n start negative, the loops runs once

## Continue and break
### break
No further statements in the body of the loop are executed
loop is immediately terminated
control immediately goes to the statement following the loop construct
**Example**
```cpp
for (int i = 0; i < 10; i++) {
    if (i == 5) break;
}
```

### continue
No further statements in the body of the loop are executed
Control immediately goes directly to the beginning of the loop for the next iteration
**Example**
```cpp
for (int i = 0; i < 5; i++) {
    if (i == 2) continue; // skip 2
    std::cout << i << " ";
}
// Output 0 1 3 4
```

## Infinite Loops
An infinite loop is when a conditions is always true
**Example using while**
```cpp
while (true) {
    // endless
}
```
**Exampling using for**
```cpp
for (;;) {
   // endless
}
```
**Note:**
You can use break to exit if needed

## Nested Loops
A loop inside another loop
common for working with grids, matrices and repeated patterns
**Example:**
```cpp
for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 4; j++) {
        std::cout << i << "," << j << "\n";
    }
}
```
this prints every combination of row and columns

## Summary
- if: Execute code based on a condition
- if else: Provide alternative execution
- Nested if: Multiple dependent conditions
- switch: Compare one expression against many values
- ?: :Short form of if else
- for: Loop with counter and known iteration count
- Range for: Loop directly over elements
- while: Loop with condition checked first
- do while: Loop with condition checked last
- break: Exit loop immediately
- Continue: Skip to next iteration
- Infinite loop: condition always true
- Nested Loop: Loop inside another