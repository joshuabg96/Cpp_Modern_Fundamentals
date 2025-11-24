# Structure of a C++ Program
## Basic components
### C++ Keywords
The keywords are words that C++ reserves for their inner work
They can not be used as variable, functions or class name.
Some Common examples are the following:
| Categoría        | Palabras                                                                  |
| ---------------- | ------------------------------------------------------------------------- |
| Tipos de datos   | `int`, `char`, `float`, `double`, `bool`, `void`                          |
| Control de flujo | `if`, `else`, `switch`, `case`, `for`, `while`, `do`, `break`, `continue` |
| Declaración      | `class`, `struct`, `enum`, `typedef`, `namespace`                         |
| Acceso           | `public`, `private`, `protected`                                          |
| Memoria          | `new`, `delete`                                                           |
| Constantes       | `const`, `constexpr`                                                      |
| Otros            | `return`, `sizeof`, `static`, `using`, `try`, `catch`                     |

### Identifiers
The Identifiers are variables, functions, classes, objects, etc. defined by the programmer.
The identifiers have some rules:
- It can only contain
    - Letters (a-z, A-Z)
    - Digits (0-9)
    - Underscore (_)
- It can not start with a number
- It can not be a keyword
- It is case sensitive Age != age

**Best Practices**
- Use very descriptive name as: Temperature, counter, average
- Conventions
    - Variables and functions -> lowerCamelCase or snake_case
    - Classes -> PascalCase

## Preprocessor Directives
They are instructions that are executed before compiling the code, all of them start with "#"
What does preprocessor do?
- Copies the content of the headers
- Expand macros
- Delete comments
- Generate a final code that the compiler uses for compiling.
Some typical examples of preprocessor directives are:
### #include
It works to include headers file
```cpp
#include <iostream>  // include standard I/O 
#include "miHeader.h" // include own header file
```

### #define
Define constant and macros
```cpp
#define PI 3.1416
#define CUADRADO(x) ((x)*(x))
```

### #ifndef / #define / #endif
This is a conditional that you can use to avoid multiple header inclusion
```cpp
#ifndef MIHEADER_H
#define MIHEADER_H

// content

#endif
```

## Main function
The main function is the entry point of the program, here we have two ways to write it
**Basic way**
```cpp
int main() {
    return 0;
}
```

**Allowed variant**
```cpp
int main(int argc, char* argv[]) {
    // argc = Number of arguments
    // argv = Element's array from the terminal
    return 0;
}
```

**Why return 0?**
The zero is a code that means that the execution finished correctly, different codes than zero means errors.

## Namespaces
Namespaces are used to avoid library conflicts.
The most common example is the standard c++ library, that is inside the std namespace.
```cpp
std::cout
std::cin
std::string
std::vector
```
However if we use a directive `using namespace std;` it can help us to skip the `std::` all the time.

## Comments
We use the comments to document and explain the code, However the preprocessor deletes it before compiling.
We have two types of comments:
**Single line comment**
```cpp
// This is a single line comment
```

**Multiline comment**
```cpp
/*
    This is 
    a multiline
    comment
*/
```

**Best Practices**
- A good comment explain why you do something, not only what the code does.
- Avoid obvious comments
- Comment important sections or complex algorithms


## Basic I/O: cin and cout
All the following functions are part of the standard library
### cout - output
This is the most common way to show a message
```cpp
std::cout << "Hello World";
```
`<<` is the insertion operator and it works by chaining
```cpp
std::cout << "Result: " << 5 + 3 << "\n";
```

### cin - input
This function reads values from the keyboard, it stops reading until it reads a space or an enter.
```cpp
int edad;
std::cin >> edad;
```

### Common handlers
```cpp
std::endl    // enter and flush
"\n"         // enter
```

### Typical problems with cin
When you mix cin with string input
```cpp
std::string name;
std::getline(std::cin, name);
```
If you use `cin >>`m a "\n" can be pending in the buffer, so we have to flush the buffer with `std::cin.ignore()`
