# Arrays and Vectors

## Arrays
### What is an array?
An array is fixed size, sequential collection of elements all of the same type, stored contiguosly in memory.
So this is a compund data type or data structure because it is a collection of elements and all the elements are of the same type.
Properties:
- Fixed length (can not grow or shrink)
- All elements share the same type
- Elements are indexed starting from 0
- Fast access due to contiguous memory

**Example idea**
A shelf with boxes side by side where each box stores the same kind of item.

**Characteristics**
- Fixed size
- Elements are all the same type
- Stored contiguously in memory
- Individual elements can be accessed by their position or index
- First element is at index 0 and last element at index size -1
- No checking to see if you are out of bounds
- Very efficient
- Iteration is often used to process

### How is it works?
The Array variable saves the direction of the first element or where the array starts and if we want to write, read or modify one element of the array the compiler calculate, based on the array's data type how many byte it has to mode forware to access to the correct value.

For example:
```cpp
int array[] = {1,2,3,4,5};
array[0] = 0;               // To modify the value it has to move 0 spaces forward
array[4] = 10;              // To modify the value it has to move 4 bytes * 4 spaces forward to point to the correct space
```

### Why we use arrays
Arrays are used when we need:
- To store multiple values under one name
- Fast random access (constant O(1) time)
- Predictable memory layout
- High efficiency for low level or performance critical code.

**Examples**
- Storing sensor readings
- Managing ist of grades, scores, or temperatures
- Buffers in embedded systems or network programming

### Declaration and Initialization
#### Declaring an array
```cpp
type arrayName[size];
```
**Example:**
```cpp
int numbers[5];
```
This creates space for 5 integers

#### Initializing an array
**Full initialization**
```cpp
int scores[5] = {10, 20, 30, 40, 50};
```

**Partial initialization (Others become 0)**
```cpp
int data[5] = {1, 2}; // becomes {1,2,0,0,0}
```

**Implicit size**
```cpp
int primes[] = {2, 3, 5, 6, 11};    // the compiler determines that the size is 5
```

**Default Initialization (global arrays only)**
```cpp
int arr[10]; // global -> all elements = 0
```
Local arrays have garbage values unless initilalized
However global set all the elements to 0

### Accessing Array Elements
Elemetns are accessed using the index operator `[ ]`
#### Access to an element
```cpp
int values[3] = {10, 20, 30};
cout << values[0];  // prints 10
cout << values[2];  // prints 30
```

#### modifying elements
```cpp
int values[3] = {10, 20, 30};
values[1] = 99; // array becomes {10, 99, 30}
```

#### Important considerations
Array do not perform bound checking and this can overwrite memory and cause runtime error
So, it's important to know the size of the array.
```cpp
int a[3];
a[10] = 5; // Undefined behavior
```

## Multidimensional Arrays
A multidimensional array is an array of arrays.
The most common is the two dimensional array, typically used to represent tables, matrices, or grinds.

### Declaration
```cpp
int matrix[3][4]; // 3 rows, 4 columns
```

### Initialization
```cpp
int matrix[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

### Access
```cpp
cout << matrix[0][1]; //prints 2 (row 0, column 1)
```

**Memory layout**
Elements are stored in row major order (row by row)

## Vectors
### What they are
A vector is a dynamic array from the C++ standar library `<vector>`
it can grow or shrink in size automatically
```cpp
#include <vector>
std::vector<int> numbers;
```
or usigin namespaces
```cpp
#include <vector>
using namespace std
vector<int> numbers (10);   // Vector of 10 integers
```

Vectors provide:
- Automatic memory management
- Safe access methods
- Flexible and modern container usage
- Rich functionality (insertions, deletions, iterations, etc.)

Characteristics:
- Dynamic size
- Elements are all the same type
- Stored contiguosly in memory
- Individual elements can be accessed by their position or index
- Provides may useful function that do bounds check
- Elements initialized to zero
- Very efficient.

### Vectors vs Arrays
| Feature             | Arrays              | Vectors                         |
| ------------------- | ------------------- | ------------------------------- |
| Size                | Fixed               | Dynamic                         |
| Memory              | Contiguous          | Contiguous                      |
| Initialization      | Manual              | Easy & flexible                 |
| Safety              | No bounds check     | `at()` provides bounds checking |
| Functions available | Almost none         | Many (push_back, size, clear…)  |
| Recommended use?    | Low-level, embedded | General C++ programming         |

**Key advantages of vectors:**
- Dynamic resizing (`push_back`, `pop_back`)
- Size tracking via `.size()`
- Safe access with `.at()`
- Can be copied, passed to functions, returned from functions
- Work naturally with modern C++ features (range based for, iterators)

### Declaration and Initialization
**Empty Vector**
```cpp
std::vector<int> v;
```

**Vector with size N (default initialized)**
```cpp
std::vector<int> v(5);   // {0,0,0,0,0}
```

**Vector with size N and initial value**
```cpp
std::vector<int> v(5, 10);  // {10,10,10,10,10}
```

**Initialization list**
```cpp
std::vector<int> v = {1, 2, 3, 4};
```

**Accessing elements**
```cpp
cout << v[0];   // no bounds checking
cout << v.at(2); // safe access with exceptions
```

**Adding elements**
```cpp
v.push_back(99);            // Add an element at the end of the vector
```

**Removing last elements**
```cpp
v.pop_back()
```

**Getting Size**
```cpp
cout << v.size();
```

**Multidimensional Vectors**
```cpp
#include <vector>
using namespace std;
// We are creating a vector of vectors
vector <vector<int>> movie_rating
{
    {1,2,3,4},
    {1,2,3,4},
    {1,2,3,4}
};
```

**Access to multidimensional vectors**
```cpp
cout << movie_ratings[0][0] << endl;            // we can access as an array
cout << movie_rating.at(0).at(0) << endl;       // We can access using .at() too
```

## Sumary
- Array: Fixed size, contiguous block of same type elements
- Vector: Dynamic, resizable array with usefil features
- Access: `array[index]` or `vector.at(index)`
- Multidimensional array: Array of arrays (matrix)
- Vector advantages: Safety, flexibility, functions, dynamic size