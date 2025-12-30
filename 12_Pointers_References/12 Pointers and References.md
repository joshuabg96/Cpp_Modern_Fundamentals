# Pointers and References
Pointers and references allow you to work directly with memory in C++. They are fundamental for understanding dynamic memory, arrays, data structures and efficient programming

## What is a Pointer?
A pointer is a variable that stores the memory address of another variable
**Example**
```cpp
int x = 10;
int* ptr = &x;      // ptr stores the address of x
```
Pointer do not store values directly, but the address where the value lives.

Pointer are powerful because they allow:
- Indirect access to variables
- Dynamic memory management
- Efficient handling of large data strcutures
- Sharing data between functions

## Declaring Pointers
**Syntax**
```cpp
type* pointerName;
```
**Examples**
```cpp
int* p;       // pointer to int
double* q;    // pointer to double
char* letter; // pointer to char
```

Pointer must be initialized before use
```cpp
int x = 5;
int* p = &x;

// Another ways to initialize a pointer
int* in_ptr {};
double* double_ptr {nullptr}; // nullptr starting C++11
```
Uninitialized pointer are dangerous because we have gargabe that if you are a lucky person, can modify a code section and crash it.
```cpp
int* p; // Contains garbage address
```

## Accesing the pointer address and Storing Address in a pointer
Get the address of a variable using `&`
Variables are stored in unique addresses
```cpp
int x = 42;
int* a = &x;  // p stores the address of x
int* p;
cout << "Value of p is:" << p << endl;      // Garbage
cout << "Address of p is" << &p << endl;     // Ex: 0x61ff18
cout << "Size of p is:" << sizeof p << endl;    // 4 (bytes)
p = nullptr;        // set p to point nowhere
cout << "Value of p is:" << p << endl;          // 0
```
Print an address
```cpp
std::cout << p;         // Example address: 0x7ffee123abcd
```

### Size of
sizeof a pointer variable
- Do not confuse the size of a pointer and the size of what it points to
- All pointers in a program have the same size
- They may be pointing to very large or very small types

**Example**
```cpp
int* p1 {nullptr};
double* p2 {nullptr};
unsigned long long* p3 {nullptr};
vector<string>* p4 {nullptr};
string* p5 {nullptr};
```
**Note**
The size of the pointer is the same for all ot them, However, when we write a data type of the pointer, it defines what the pointer is pointing.

## Dereferencing a pointer
Dereferencing means accessing the value stored at the pointer's address.
Use the `*` operator:
```cpp
int x = 10;
int* p = &x;

std::cout << *p;   // prints 10
```
You can modify the original variable through the pointer:
```cpp
*p = 20;   // x becomes 20
```

## Dynamic memory allocation
Dynamic memory is allocated at runtime using `new` and free with `delete`
Recall C++ arrays 
- we have to explicitly provide the size and it was fixed.
- But vectors grow and shrink dynamically

**Allocating a single value**
```cpp
int* p = new int;       // allocates an int
cout << p << endl;      // Address Ex: 0x2747f28
cout << *p << endl;     // 12345463 - garbage
*p = 50;
cout << *p << endl;     // 50
```

**Allocating with initialization**
```cpp
int* p = new int(10);
```

**Allocating an array**
```cpp
int* arr = new int[5];
```

**Freeing memory**
```cpp
delete p;         // for single variable
delete[] arr;     // for arrays
```
**important**
Failing to free memory causes memory leaks

## The Relationship between arrays and pointers
- Arrays automatically convert to pointers
- The value of an array name is the address of the first element in the array
- The value of a pointer variable is an address
- If the pointer points to the same data type as the array element then the pointer and the array name can be used interchangeably (almost)
```cpp
int arr[5] = {1, 2, 3, 4, 5};

int* p = arr;      // same as &arr[0]
```
So, we can access array elements using pointers:
```cpp
*(p + 2)   // equals arr[2]
```
**Key points:**
- `arr`is constat (can not be reassigned)
- A pointer can move and array name can not.

## Pointer Arithmetic
Pointer arithmetic moves through memory based on the size of the type
Given:
```cpp
int arr[] = {10, 20, 30};
int* p = arr;
```
We can use some operations to move throught the address
Valid operations:
- `p++, p--`
- `p + n`
- `p - n`
- `p += n` `p -= n`
- Comparison: `p < q` `p == q`
Pointer arithmetic works only inside the same array
Pointer comparison does not compare the data where they point it compares the address.

**Example**
```cpp
int arr[] = {10, 20, 30};
int* p = arr;
```

**How compare pointer data?**
Easy the way that we use to compare data is using `*`
```cpp
int s1 {10};
int s2 {10};

int *p1 {&s1};
int *p2 {&s2};
int *p3 {&s1};
cout << (*p1 == *p2) << endl;   // true
cout << (*p1 == *p3) << endl;   // true
```

## Const and pointers
There are three forms of const with pointers:

### Pointer to const data
You can not modify the data through the pointer (modify the address)
```cpp
const int* p = &x;
*p = 10;        // Error
p = &y;         // Allowed
```

### Const pointer
The pointer cannot cahnge, but the data can.
```cpp
int* const p = &x;
p = &y;         // Error
*p = 10;        // Allowed
```

### Const pointer to const data
Neither pointer nor data can change
```cpp
const int* const p = &x;
```

## Passing pointer to functions
Pointer allow functions to modify variables in the caller
**Example**
```cpp
void setToZero(int* p) {
    *p = 0;
}

int x = 5;
setToZero(&x);   // x becomes 0
```

Useful for
- modifying caller data
- passing large arrays
- dynamic memory management

## Returning a pointer from a function
Functions can return pointers, but with caution
**Valid returning dynamically allocated memory**
```cpp
int* createInt() {
    return new int(100);
}
```
callre must free the memory:
```cpp
int* p = createInt();
delete p;
```
**Invalid**
Returning pointer to local variable
```cpp
int* bad() {
    int x = 10;
    return &x;   // x is destroyed when function ends
}
```
This causes undefined behavior

## Potential pointer pitfalls
### Uninitialized pointers
```cpp
int* p; // undefined address
```

### Dangling pointers
Pointing to memory that is already freed
```cpp
int* p = new int(5);
delete p;
*p = 10;  // undefined behavior
```

### Memory leaks
Not freeing memory:
```cpp
int* p = new int(10);
// no delete → leak
```

### Dobule delete
```cpp
delete p;
delete p; // crash
```
### Buffer overflows
Using pointers incorrectly to access past array bounds

## What is a Reference?
A reference is an alias to another variable
**Syntax**
```cpp
int x = 10;
int& ref = x;
```
Now `ref` and `x` refer to the same variable

Properties of references:
- Must be initialized at declaration
- Can not be null
- Can not be reseated (can not refer to a different variable)
- Safer and simpler than pointer

**Example**
```cpp
ref = 20;  // x becomes 20
```

## L-values and R-Values
### L-values
- Has a persistent location in memory
- You can take its address
- Can appear on the left side of `=`
**Examples**
```cpp
int x;
x = 5;
```

### R-value
- Temporary value
- Does not have a persistent address
- Can not appear on the left side of `=`
**Examples**
```cpp
5
x + 2
functionReturnValue()
```

### Reference types:
#### L-value reference
```cpp
int& ref = x;  // OK
int& ref2 = 10; // cannot bind to rvalue
```

#### R-value reference
```cpp
int&& temp = 10; // binds to temporary
```
Used for move semantics and optimization

## Summary Table
- Pointer: Variable holding memory address
- Dereference: Access value at pointers address
- Dynamic memory: `new` / `delete`
- Array vs pointers: Array decay to pointers
- Pointer arithmetic: Move through array elements
- const pointers: Control pointer / data mutability
- Passing pointers: Allows functions to modify caller variables
- Returning pointeres: Safe only if memory persists
- Pitfalls: Dangling pointers, leak, wild pointers
- Reference: Alias to an existing variable
- L-values / R-values: Determine what references can bin to