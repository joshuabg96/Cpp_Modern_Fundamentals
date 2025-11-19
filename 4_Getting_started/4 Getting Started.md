# Getting Started

## C++ VSCode configuration
### install needed extensions
- C/C++ (Microsoft)
    - Intellisense (hints and autocomplete)
    - Real time error detection
    - Debugging

### Compiler
#### MacOS
1. Install Clang 
```bash
xcode-select --install
```

### Windows
MinGw-w64

### Linux (Debian / Ubuntu)
```bash
sudo apt update
sudo apt install build-essential
```

### VSCode configuration 
Using the c_cpp_properties.json file at .vscode folder, we can define the compiler and headers paths.
MacOS Example:
```json
{
  "configurations": [
    {
      "name": "Mac",
      "compilerPath": "/usr/bin/clang++",
      "cppStandard": "c++17",
      "intelliSenseMode": "macos-clang-arm64"
    }
  ],
  "version": 4
}
```

## C++ Basic Structure
```cpp
#include <iostream>      // 1. Include libraries

// 2. Main function
int main() {

    std::cout << "Hello world\n";   // 3. Program Logic

    return 0;                      // 4. Return value.
}
```
- `#include`: the precompiler copy the content of the library
- `int main()`: Where the program start
- `std::cout`: Standard output
- `return 0`: Indicate correct execution

## Steps for termial compilation
### Basic manual compilation an execution
#### Compilation
```bash
g++ main.cpp -o main
```
- `g++` : Compiler
- `main.cpp` : Program to be compiled
- `-o`: indicate that the executable will not have a default
- `main` : the name of the executable

#### Execution
**macOS / Linux**
```bash
./ main
```

**Windows**
```bash
main.exe
```


## Compiler Errors
**Errors can be syntactic or semantic**
### Syntax Errors
This means that we have gramatical lengagee violations, for example:
```cpp
int main( {         
std::cout << "Hi"
return 0;
```
- In this code we have a missing closing pharentesis after main
- A semicolon is missing after "Hi"

The compiler will show us a tipical message as
- expected ';' before 'return'
- expected declaration before '}'

### Semantic Errors
In this case the code is valid, however the meaning does not make sense to the compiler
```cpp
int x = "hola";      // incompatible types
cout << y;           // undeclare variable
return "ok";         // invalid return type
```
The compiler will show us a tipical message as:
- cannot convert 'const char*' to 'int'
- 'y' was not declared in this scope'

## Compiler Warnings
In this case the code compile, but the compiler detected something suspicious 
For example:
**Unused variable**
```cpp
int x = 10;
```

**Uninitialized variable**
```cpp
int x;
std::cout << x;
```

**No sense conditions**
```cpp
if (x = 5) { }
```
When we have warnings the code compile, however, we can have some unexpected behaviour in our code.

## Linker Errors
The linker join all the functions and files to create the executable.
This happens after the compilation and we can face some of the following common errors

### Declared but no defined functions
```cpp
void hi();  

int main() {
    hi();  
}
```
We have the declaration and we are calling it, however we do not have the definition.

### Symbols duplication
This happen when two or more files defined the same function o global variable, this means with the same name.

### You are not including a library
Example
```bash
undefined reference to `pthread_create`
```

## Runtime Errors
This type of errors only happen when the code is running, because the compiler does not detect it.
**Typical examples:**

**Invalid memory access**
```cpp
int* p = nullptr;
*p = 5;
```

**Divided by zero**
```cpp
int x = 0;
int y = 5 / x;
```

**Out of rante arrays**
```cpp
int a[2];
a[10] = 5;
```
**Overflow**
```cpp
char c = 300;
```
Runtime errors can cause
- Segmentation fault
- Abort
- Floating point exception

## Logic Errors
This time the code compile and run, however, it produces incorrect results
**Examples**

### Error condition
```cpp
if (x = 5) {}
```

### Wrong use of an operator
```cpp
if (a & b)
```

### Incorrect formulas
```cpp
float average = sum / 3; // When we are using 4 elements
```
### Incorrect logic
```cpp
if (age > 18 && age < 60) // But we are evaluatin a range from 18 to 60
```

That is a very dificult erros because
- Do not generate errors
- Do not generate crash
- Unpredictible behavior happen