# 6 Variables and Constants
In C++, programs store and manipulate data using variables and constants. Understanding how they work and the types available is fundamental to all C++ programming.

## Declaring Variables
A variable is a named storage location in memory whose value can change during program execution.
This allow programmers to use meaninful names and not memory addresses
**General Form**
```cpp
type identifier;
```
**Example**
```cpp
int age;
double price;
char grade;
bool isActive;
```

You can also initialize variables (And it is a good practice) at the momento of a declaration
```cpp
int count = 10;
double temperature = 36.7;
```
**Rules for variable names**
- Must start with a letter or underscore
- Cannot start with a number
- Can contain letters_ digits, and underscores
- Cannot be a C++ keyword (int, return, class, etc.)
- Case-sensitive (Age and age are different)

**Best Practices**
- Be consistent with your naming conventions
- Use meaningul names, no too long and not too short
- Never use variables before initializing them
- Declare variables close to when you need them in your code

But you can declare new variable types that are not part of C++ standard types with the Object Oriented Programming.
OOP allows us to create variables that represent differents things for example an Account or a Person.
```cpp
Account franks_account;
Person james;
```

**Initializing Variables**
We have three different ways to initialize variables in C++
```cpp
int age;        // Variabl uninitialized
int age = 21;   // C like initialization
int age (21);   // Constructor initialization
int age {21};   // C++11 list initialization syntax 
```

**Global Variables**
All the variables that are outside any function are called global variables and it can be accessed in any part of the program
**Warning**
Be carefull of using g¿many global variables when it is not necessary, because we can make the mistake to create a local variable with the same name as a global variable that we have created before. 

## C++ Primitive Types
Primitive types are basic built in data types provided directly by the lenguage. They represent fundamental kinds of data
Size and precision os often compiler dependent, you can use the library `#include <climits>` to know more about it

### Integer types
Used for whole number with no decimals
Common integer types
| Type        | Typical Size | Range                           |
| ----------- | ------------ | ------------------------------- |
| `short`     | 2 bytes      | –32,768 to 32,767               |
| `int`       | 4 bytes      | –2,147,483,648 to 2,147,483,647 |
| `long`      | 4 or 8 bytes | platform-dependent              |
| `long long` | 8 bytes      | very large range                |

**Example:**
```cpp
int items = 25;
```
You can also add unsigned to allow only positive numbers and icnrease the upper limit
```cpp
unsigned int score = 300;
```

### Floating-Point Types
Used for numbers with decimals
| Type          | Size        | Precision        |
| ------------- | ----------- | ---------------- |
| `float`       | 4 bytes     | ~7 digits        |
| `double`      | 8 bytes     | ~15 digits       |
| `long double` | 10–16 bytes | higher precision |

**Example**
```cpp
float height = 1.75f;
double weight = 70.35;
```

### Boolean Type
Stores true or false
**Example**
```cpp
bool isFinished = false;
``` 

### Character type
Stores a single character using ASCII or UTF-8 encoding
```cpp
char letter = 'A';
char digit = '5';
char symbol = '#';
```
Characters use single quotes ' '


## sizeof Operator
The size of operatir return the number of bytes required to store a variable or data type
**Examples**
```cpp
sizeof(int);        // commonly 4
sizeof(double);     // commonly 8
sizeof(char);       // always 1
```
You can also use it on variables
```cpp
int x = 10;
cout << sizeof(x);  // prints size of an int
```
The results depend on the system architecture and compiler
You can know the size of every variable using the libraries `<climits>` and `<cfloat>`
This libraries provide some information related with the size of the variable types for example:
- `INIT_MAX`
- `LONG_MIN`
- `FLT__MIN`

## What is a Constant?
A constant is a value that cannot change during program execution.
Using constants increases:
- Safetuy (avoid accidental modification)
- Readability
- Maintainability
**Example**
```cpp
const double PI = 3.14159265;
```
Once assigned, PI cannot be cahnged.

## Declaring Constants
There are two main ways to declare constats in C++
### Using const keyword
The value must be dset at declaration time
**Example**
```cpp
const int DAYS_IN_WEEK = 7;
const double TAX_RATE = 0.16;
```

### Using constexpr (Compile-time constant)
Introduced in modern C++ (C++11 or higher)
**Example**
```cpp
constexpr int MAX_USERS = 100;
```
**Diferences**
- const -> value cannot change, but may be set at runtime
- constexpr -> must be known at compile time

**Example**
```cpp
const int x = rand();      // OK (runtime)
constexpr int y = rand();  // ERROR (not compile-time)
```
**Advantages constexpr**
- Optimize performance by moving calculations to compile time
- constexpr functions can be executed in compile-time and run time
- Ensures evaluation at compile time when possible

**Advantages const**
- It can be initialized with runtime values
- Easy and flexible
- It can not be modified after initialization

### Define Constants
`#define` is a preprocessor directive, not part of the C++ type system
However, before the compilation starts, the preprocessor replaces the text with the value of the definition everywhere in the code.
Example how it is defined
```cpp
#define PI 3.14159
```
**Advantages**
- It is very simple
- Works with any type
- Useful for conditional compilation

### Enumerated constants
Enums define a set of named integers constants that elong to a specific type
for example:
```cpp
enum Color
{
    red,
    green,
    blue
};
```
**Advantages**
- Type safe expecially with enum class
- Values appear in the debugger
- Much safer and cleaner than define
- Self documenting: describes categories or states
- Can restrict valid values

### Literal Constants
Literal constants are fixed values written directly in the code
**Examples**
```cpp
// Integer Literals
10
255
-42
// floating point literals
3.14
0.001
-12.75
// Character literals
'A'
'Z'
'5'
'\n'  // newline
// String Literals (Not Technically primitive, but common)
"Hello"
"Welcome to C++"
// Boolean literals
true
false
```

### Constant Expressions
A constant expression is an expression whose value is known at compile time
**Example**
```cpp
constexpr int a = 10 + 20;  // OK
constexpr int b = a * 2;    // OK
```
Invalid constant expression
```cpp
int x = 5;
constexpr int y = x + 2;   // ❌ ERROR, x is not constant
```
Constant expressions can be used to define
- Array sizes
- Template parameters
- Compile time evaluations