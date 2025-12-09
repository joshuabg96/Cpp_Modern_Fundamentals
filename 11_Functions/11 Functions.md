# Functions
Functions are one of the most important building blocks in C++. They allow you to break a program into smaller, reusable pieces that perform specific tasks.

## What is a function?
A function is a named block of code that performs a specific task.
Functions allow us to:
- Avoid repeating code
- Organize programs into logical units
- Improve readability and maintainability
- Reuse the same logic multiple times
**Example:**
```cpp
int add(int a, int b) {
    return a + b;
}
```

## Function Definition
To define a function we have some things that we need to considere:
- Name
    - The name of the function
    - Same rules as for variables
    - Should be maningful, Usually a verb or verb phrase
- Parameter list
    - The variables passed into the function
    - Their types must be specified
- Return type
    - The type of the datat that is returned from the function
- Body 
    - The statements that are executed when the function is called
    - It has to be in curly braces {}

**Syntax**
```cpp
return_type function_name(parameter_list) {
    // body
}
```

**Example**
```cpp
double square(double x) {
    y = statement(x)
    return y;
}
```

## Function Prototypes (Function Declarations)
the compiler must know about a function before it is used
- Define functions before calling them
    - It is ok for small programs
    - It is not practical solution for large programs
- Use function prototypes
    - Tells the compiler what it needs to know without a full function definition
    - Also called forward declarations
    - Placed at the beginning of the program
    - Also sued in our own header file (.h)

**Syntax**
```cpp
return_type function_name(parameter_list);
```

**Example:**
```cpp
int add(int a, int b);   // prototype

int main() {
    add(3, 4);
}

int add(int a, int b) {  // definition
    return a + b;
}
```

## Function Parameters and the Return statement
- When we call a function, we can pass in data to that function
- In the function call they are called arguments
- In the functions definition they are called parameters
- They must match in number, order, and in type

### Parameters
The parameters are the values that you will pass into a function

**Example:**
```cpp
void display(int number) {  // number is a parameter
    std::cout << number;
}
```

**Return statement**
- if a function returns a value then it must use return statement that return a value
- if a fucntion does not return a value (void) then the return statement is optional
- return statemen can occur anywhere in the body of the function
- Return statement immediately exits the function
- We can have multiple return statements in a function
    - Avoid many return statement in a function
- The return value is the result of the function call.

**Exmaple**
```cpp
int multiply(int x, int y) {
    return x * y;
}
```
Functions with `void` return type do not return a value
```cpp
void greet() {
    std::cout << "Hello!";
}
```

## Default argument values
- When a function si called, all arguments must be supplied
- Sometimes, some of the arguments have the same values most of the time
- We can tell the compiler to use default values of the arguments are not supplied
- Default values can be in the prototype or definition, not both
    - bet practice - in the prototype
    - must appear at the taul end of the parameter list.
- Can have multiple default values
    - Must appear consecutively at the tail end of the parameter list
**Syntax**
Default must be declared in the prorotype or the first declaration, not in the definition;
**Example**
```cpp
void greet(std::string name = "Guest") {
    std::cout << "Hello " << name;
}
```
**Calls**
```cpp
greet();            // Hello Guest
greet("Alice");     // Hello Alice
```

## Overloading functions
Function overloading allows multiple functions with:
- The same name
- Different parameter lists
The return type alone is no enough to overload

- We can have functions that have different parameter lists that have the same name
- A type of polymorphism
    - We can have the same name work with different data types to execute similar behavior
- The compiler must be able to tell the functions apart based on the aprameter lists and argument supplied.

**polymorphism**
Means many forms for the same concept (or name)

```cpp
int add(int a, int b);
double add(double a, double b);
string add(string a, string b);
```
**Note**
The compiler does best match searching the function where the signature match with the arguments
the signature check:
- Parameter type
- Number of parameters
- Parameter order

**Warning**
The return data type does not define an overloading functions
```cpp
int foo(int x);
double foo(int x);    // Error: the single difference is the return type
```
In this sistuation the compiler can not make a difference because both of them receive `int` as parameter.

### Valid Examples
***Different parameter number**
```cpp
void area(int r);
void area(int w, int h);
```

**Different data type parameter**
```cpp
void sum(int a, int b);
void sum(double a, double b);
```

**Different parameter order**
```cpp
void print(int a, double b);
void print(double b, int a);
```
## Parsing arrays to functions
When an array is passed to a function:
- We can pass an array to a function by providing square brackets in the formal parameter description `void print_array(int numbers []);`
- The array element are Not coppued
- Since the array name evaluates to the location of the array in memory this address is what is copied
- The function has no idea how many elements are int he array since all it knows is the location of the first element.
- The array decays to a pointer
- The function receives a pointer to the first element
- The size must usually be passed separately

**Example**
```cpp
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
}

int main() {
    int numbers[] = {1, 2, 3};
    printArray(numbers, 3);
}
```

- We can tell the compiler that fucntion paramters are const (read onnly)
- This could be useful in the print_array fucntion since it should not modify the array

```cpp
void print_array(const int numbers [], size_t size) 
{
    for(size_t i{0}; i < size; i++)
    {
        cout << numbers[i] << endl;
    }
}
```

**Equivalent pointer notation**
```cpp
void printArray(int* arr, int size);
```

In C++ parameters are passed in two main ways:

### Pass by reference
Sometimes we wanto be able to change the actual parameter from within the function body, in order to achieve this we need the location or address of the actual parameter
We saw how this is the effect iwht array, but what about other variable types?
We can sue reference parameteres to tell the compiler to pass in reference to the actual parameter, the formal parameter will now be an alias for the actual parameter.
**Example**
```cpp
void print(vector<int> &v);

int main()
{
    vector<int> data {1,2,3,4,5};
    print(data);
    return 0;
}

void print(vector<int> &v)
{
    for(auto num: v)
        cout << num << endl;
}
```

### Passs by value (default)
- When you pass data into a function it is passed by value
- A copy of the data is passed to the function
- Whatever changes you make to the parameter in the function does not affect the argument that was passed in.
**Example**
```cpp
void print(vector<int> v);

int main()
{
    vector<int> data {1,2,3,4,5};
    print(data);
    return 0;
}

void print(vector<int> v)
{
    for(auto num: v)
        cout << num << endl;
}
```

**Formal vs Actual parameters**
- Formal parameters - the parameters defined in the function header
- Actual parameters - the aprameter used in the function call, the arguments

```cpp
void foo(int x) {
    x = 20;         // Formal parameter
}

int main()
{
    int x = 10;     // Acutual parameter
    foo(x);
    return 0;
}
```

### Pass by reference
Use `&`to allow the function to modify the original variable
```cpp
void foo(int& x) {
    x = 20;
}
```
**Call:**
```cpp
int n = 10;
foo(n);   // n becomes 20
```
Reference semantics are essential for:
- Efficiency (Avoid copying)
- Modifying external variables
- Working with large objects

## Scope Rules
Scope determines where a varaible can be accessed
### Local or Block scope
- Identifiers declared in a block {}
- Function parameters have block scope
- Only visible within the block {} where declared
- Function local variables are only active while the function is executing
- Local variables are not preserved between function calls
- With nested blocks inner blocks can see but outer block cannnot see int
```cpp
void func() {
    int x = 10;  // local
}
```

#### Static local variables
Using static local variables the value is perserved between function calls and only initialized the first time the function is called

### Global scope
Variables declared outside any function or class and can be used in all the .cpp file
it is visible to all parts aof the program after the global identifier has been declared
Global constants are ok, however, do not use it unless necessary
```cpp
int count = 0;  // global
```

### Block scope
It is declared inside a loop and it can only be used inside this block
```cpp
if (true) {
    int x = 5;   // only inside this block
}
```

**Important Rules**
- Local variables hide global variables with the same name
- Lifetime of local variables lasts only inside their block
- Avoid global variables unless necessary.

## How do function calls work?
When a function is called:
1. Memory is allocated for parameters (Stack frame)
2. Arguments are passed (by value or reference)
3. Execution jump to the function body
4. The function runs
5. A return value is computed (if needed)
6. The stack frame is destroyed
7. Control return to the caller

The stack handles:
- Local variables
- Return address
- Parameteres
This is why deep recursion can cause stack overflow.

## Inline Functions
An inline function suggests to the compiler to replace the function call with the actual function conde to avoid overhead.
**Example:**
```cpp
inline int square(int x) {
    return x * x;
}
```
Useful for:
- Very small functions
- Performance critical code
Modern compiler often optimize automatically, so inline is just a hint.

## Recursive functions
A function is recursive if it calls itself
Each call crates a new stack frame
**Requirements**
- Base case: stop recursion
- Recursive case: calls itself with modified input

**Important**
- If recursion does not eventually stop you will have infinite recursion
- Recursion can be resource intensive
- Only use recursive solution when it makes sense

**Typical Example (Factorial)**
```cpp
int factorial(int n) {
    if (n == 0) return 1;     // base case
    return n * factorial(n-1); // recursive call
}
```

**Common uses:**
- Mathematical functions
- Tree traversal
- Searching and sorting algorithms
- Divide and conquer algorithms

**Caution**
Too much recursion may cause stack overflow

## Sumary
- Function: A reusable block of code
- Prorotype: Declares a function before its use
- Parameters: Input values to the function
- Return: Sends value back to caller
- Default arguments: Proide fallback values
- Overliading: Same function name, different parameters
- Pass by reference: Allows modification of original variable
- Arrays as parameters: Arrays decay to pointers
- Scope rules: Control variable visibility
- Function calls: Stack based execution
- Inline functions: Suggest in place expansion
- Recursion: Function calling itself.