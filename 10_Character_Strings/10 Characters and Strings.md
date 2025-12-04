# Characters and Strings
C++ provides two major ways to work with text:
1. C-Style strings - using character arrays (`char[]`)
2. C++ strings - modern `std::string` class from the Standard Library
Before learning strings, we first understand how individual characters work.

## Character Functions
Characters in C++ are stored using the `char` type:
```cpp
char letter = 'A';
```
To perform operations on characters (like checking if a character is a digit or converting to uppercase), C++ provides functions in the `<cctype>` header.

**Common characters functions**
- `isalpha(c)` -> true if letter
- `isdigit(c)` -> true if digit 0-9
- `isalnum(c)` -> true if letter or digit
- `isspace(c)` -> checks for whitespace
- `islower(c)` -> true if lowercase
- `isupper(c)` -> true if uppercase
- `tolower(c)` -> convert to lowercase
- `toupper(c)` -> convert to uppercase

**Example**
```cpp
#include <cctype>

char c = 'A';

if (isalpha(c)) {
    c = tolower(c);   // becomes 'a'
}
```

## C-style strings
A C-style string is a sequence of characters stored in a `char` array and terminated by a null character `\0`
**Example:**
```cpp
char name[] = "John";
```
Internally stored as `J o h n \0`

**Key propierties:**
- Fixed size
- Stored as a character array
- Must always end with `\0`(null terminator)
- Easily casuses memory issues if not handled carefully
- Contiguous in memory
- implemented as an array of characters

## Working with C-Style Strings
To use C-style string functions, include `<cstring>`

**Common functions**
- `strlen(s)` -> length (not counting `\0`)
- `strcpy(dest, src)` -> copy string
- `strncpy(dest, src, n)` -> copy up to n characters
- `strcat(dest, src)` -> concatenate
- `strcmp(a, b)` -> comparate strings

### Examples
**Getting length**
```cpp
char word[] = "Hello";
size_t len = strlen(word);   // 5
```

**Copy strings**
```cpp
char dest[20];
strcpy(dest, "World");
```

**Concatenate**
```cpp
char a[20] = "Hello ";
char b[] = "World";

strcat(a, b); // a becomes "Hello World"
```

**Compare**
```cpp
strcmp("abc", "abc"); // 0  (equal)
strcmp("abc", "abd"); // negative (first < second)
strcmp("abd", "abc"); // positive (first > second)
```

**Important limitations**
- No automatic bounds checking
- Risk of butter

## C++ Strings (std::string)
`std::string` is a dynamic, safe, flexible string type provided by C++
do not forget to include the header `#include <string>`

**Characteristics**
- Need `#include <string>` library
- Are part of Standard Template Library (you can use std namespace)
- contiguous in memory
- Dynamic size
- Lots of useful member functions
- Can be easily converted to C-style Strings if needed

**Comparison between C-style and C++ strings:**
| C-Style (`char[]`)       | `std::string`            |
| ------------------------ | ------------------------ |
| fixed-size array         | grows dynamically        |
| manual memory            | automatic memory         |
| unsafe operations        | safe functions           |
| limited functions        | rich interface           |
| null terminator required | no need to manage `'\0'` |


## Working with C++ Strings
**Declaration**
```cpp
using namespace std
string name = "Alice";
string empty;           // empty string
string s2 {"Frank"};    // Frank
string s3 {s2};         // Frank
string s4 {"Franl", 3}; // Fra
string s5 {s3, 0, 2};      // Fr
string s6 (3, 'x');      // xxx
```

**Input and output**
```cpp
std::string name;
std::cin >> name;   // stops at whitespace
```
To read full lines:
```cpp
std::getline(std::cin, name);
```

**Accesing characters**
```cpp
char c = name[0];     // first character (no bounds check)
char c2 = name.at(1); // bounds-checked
```

**Getting length**
```cpp
name.length();
name.size();   // same
```

**Concatenation**
```cpp
std::string full = name + " Smith";
```

**Modifying strings**
```cpp
name += " Johnson";
```

**Substrings**
```cpp
std::string sub = name.substr(0, 3);  //first 3 characters
```

**Searching**
```cpp
size_t pos = name.find("ice");      // Return the position where it starts
```

**Comparison**
```cpp
if (name == "Alice") { ... }
```
Note: Comarisons work naturally (unlike `strcmp`)
Note2: we can use all the relational operators as `== != > >= < <=`

**Converting case**
C++ does not provide direct member functions, but you can use `<cctype>`
```cpp
for (char& c : name) {
    c = toupper(c);
}
```

**Converting to C-style string**
```cpp
const char* cstr = name.c_str();
```

## Sumary
- Character functions: Provided in `<cctype>` for testing or cenvering chars
- C-style strings: `char[]` arrays ending with `\0`
- C-style operations: Use `<cstring>` (`strlen`, `strcmp`, etc.)
- `std::string` : Modern, dynamic, safe C++ string class
- Working with `std::string`: easy concatenation, searching, substring, size, input

