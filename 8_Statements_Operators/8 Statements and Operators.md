# 8 Statements and Operators
In C++, statements and operators form the backbone of how programs perform actions and make decisions. This chapter explains how expressions are built, how operators behave, and how the program evaluates statements.
## Expressions and Statements
**Expression**
It is the most basic building block of a program and a sequence of operators and operands that specifices a computation.
An expression is any combination of 
- Variables
- Literals
- Operators
- Function calls
that produces a value
For Example:
```cpp
34                  // literal
favoite_number      // variable
5 + 3               // adition
x * y               // multiplication
a = b + c           // assigment
```

**Statement**
A statement is a complete instruction that the compiler can execute
In c++, statements usually end with a semicolon and contain expressions
For Example:
```cpp
int x = 10;         // declaration statement
x = x + 5;          // assignment statement
std::cout << x;     // Expression statement
```

## Using Operators
C++ operators are special symbols that perform operations on data
Type include:
- Arithmetic operators (sum, substract, product, etc.)
- Assignment operators (x = 10)
- Relational operators (a == b, a != b, etc.)
- Logical operators (p && q, p || q, !p)
- Increment / decrement operators (x++, ++x, x--, --x)
- Bitwise operators (x >> 1, x << 1)
- Compound assignment operators (a += 1, a *= 2, etc.)

Operators from expressions, which are evaluated according to precedence rules.

## The assignment operator (`=`)
the assignmen operator stores a value into a variable
```cpp
int x;
x = 5;
```
The right side is evalauted first, then stored in the left side
the right side has to be type compatible with left side.
You can also chan assignments:
```cpp
int a, b, c;
a = b = c = 10 // All the variables become 10
```

## Arithmetic Operators
Used for mathematical operations
| Operator | Meaning             | Example |
| -------- | ------------------- | ------- |
| `+`      | addition            | `a + b` |
| `-`      | subtraction         | `a - b` |
| `*`      | multiplication      | `a * b` |
| `/`      | division            | `a / b` |
| `%`      | modulus (remainder) | `a % b` |

**Warnings**
- When we use integer division, it truncates for example: 
```cpp
int x;
x = 7 / 2;
cout << x << endl;      // Output will be 3
```
- **Modulus only works on integers**

## Increment an Decrement Operators
These increase or decrease a variable by one
- `++` : increment by one
- `--` : decrement by one
They can be used in two forms:

**Pre-increment**
```cpp
++x;     // First increment, then use x
```

**Post-increment**
```cpp
x++;        // First use x, then increment
```

Example:
```cpp
int x = 5;
int 7 = ++x;    // x = 6, y = 6
int z = x++;    // x = 7, z = 6
```

**Warning**
Never use it twice for the same variable in the same statement, this cause an undefine behavior

## Mixed Expressions and Conversions
When different type appear in the same expression, C++ performs implicit type conversions

**Warning**
It could affect calculation results

Rules:
- Smaller types convert to larger types
- int convert dobule if mixed
- Integer division occurs only if both operands are integers
- Floating point values dominate integers
Example:
```cpp
double result = 5/2;    // result = 2 (integer division)
double result2 = 5.0 / 2;   // result2 = 2.5 (floating point)
```

Pomotions occurs automatically, but sometimes explicit conversion are better.
We can cast variables using `static_cast<datatype>(variable)`
For example:
```cpp
double average = static_cast<double>(sum) / count;
```
**Note**
`static_cast<datatype>(variable)` is a modern version of `(datatype)variable`

## Testing for Equality
When we use "=" it is not the same use it simple or use it double
- `=`: Assigns
- `==`: Compares

**Equality operator**
```cpp
a == b      // Returns true or false
```

**Inequality operator**
```cpp
a != b      // Compare if a and b are different
```

## Relational operators
This operators are used for comparisons
| Operator | Meaning               |
| -------- | --------------------- |
| `<`      | less than             |
| `>`      | greater than          |
| `<=`     | less than or equal    |
| `>=`     | greater than or equal |
| `<=>`    | three way comparison  |

**Examples:**
```cpp
x < 10
y >= 0
```
They return true or false

## Logical Operators
Combine or invert boolean expressions
**Logical AND**
The operator `&&` indicates that both conditions have to meet
for example:
```cpp
int a = 1;
int b = 6;
if (a > 0 && b < 5)
{
    cout << "True";
}
else
{
    cout << "False"
}
```
In this case the output will be "False" because a is fulfilling but b no.

**Logical OR**
The operator `||` indicates that fulfilling any condition the result will be "true"
for example:
```cpp
int a = 1;
int b = 6;
if (a > 0 || b < 5)
{
    cout << "True";
}
else
{
    cout << "False"
}
```
In this case the output will be "True" because a is fulfilling the condition and we only need one condition to be true

**Logical NOT**
The operator `!` negates the value of the evaluation
for example:
```cpp
int a = 5;
int b = 5;
!(a == b)       // The result of (a == b) is true but using "!" the result will be false
```
Another way to use it is to indicate difference
for example:
```cpp
(a != b)    // if a and b are equal the result will be "false" because we are evaluating if they are different
```

## Compound Assignment Operators
These combine an operator with assignment
| Operator | Meaning             | Equivalent               |
| -------- | ------------------- | ------------------------ |
| `+=`     | add and assign      | `x += 5;` → `x = x + 5;` |
| `-=`     | subtract and assign | `x -= 5;`                |
| `*=`     | multiply and assign | `x *= 3;`                |
| `/=`     | divide and assign   | `x /= 2;`                |
| `%=`     | modulus and assign  | `x %= 10;`               |

Other compound assignment Operator are the following:
- `>>=` -> `a = a >> b;`
- `<<=` -> `a = a << b;`
- `&=` -> `a = a & b;`
- `^=` -> `a = a ^ b;`
- `|=` -> `a = a | b;`

Example:
```cpp
int x = 10;
x += 5;  // x = 15 same as x = x + 5
x *= 2;  // x = 30 same as x = x * 2
```

## Operator precedence
Operator precedence determines which operations are evaluated first in an expression
**Highest precedence (evaluated first)**
1. `()` parentheses
2. `++`, `--`, unary `+`and `-`
3. `*`, `/`, `%`
4. `+`, `- `
5. `<, <=, >, >=`
6. `==, !=`
7. `&&`
8. `||`
9. `=, +=, -=`, etc.

Example:
```cpp
int x = 10 + 5 * 2;  // result = 20, because 5*2 happens first
```
We can use parentheses to enforce clarity
```cpp
int x = (10 + 5) * 2;  // result = 30
```

## Suamary
- Expressions: Produce a value
- Statements: Complete instructions ending in ;
- Assigment operator: Stores a value (=)
- Arithmetic operators: +,-,*,/,%
- Increment / decrement: Pre vs post (`++x` `x++`)
- Mixed expressions: Automatic type conversions
- Equality: Use `==`, not `=`
- Relational: `<,>,<=,>=`
- Logical `&&, ||, !`
- Compound assignment: `+=, *=, etc.`
- Operator precendence: Defines evaluation order







Expressions and Statements
Using operators
The Assignment Operator
Arithmetic Operator
Increment and decrement operator
Mixed Expressions and conversions
Testing ofr equality
Equality
Relational operators
Logical operators
Compound Assignment Operators
Operator Precedence
