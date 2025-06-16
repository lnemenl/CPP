# 🧠 C++ `const` Cheatsheet – Master It Once and For All

> A complete guide to understanding `const` in C++, with simple explanations and **concrete examples**.

---

## 📚 Table of Contents

1. [What Does `const` Mean?](#what-does-const-mean)
2. [Basic Const Variables](#basic-const-variables)
3. [Pointers and `const`](#pointers-and-const)
4. [Function Parameters](#function-parameters)
5. [Return Types](#return-types)
6. [Const Member Functions](#const-member-functions)
7. [Const Objects and References](#const-objects-and-references)
8. [Top-level vs Low-level Const](#top-level-vs-low-level-const)
9. [Mutable Keyword](#mutable-keyword)
10. [Const with Arrays](#const-with-arrays)
11. [Const with `constexpr`](#const-with-constexpr)
12. [Best Practices](#best-practices)
13. [Cheat Table Summary](#cheat-table-summary)
14. [Const Meaning Table (Full)](#const-meaning-table-full)

---

## What Does `const` Mean?

`const` means *read-only*. It tells the compiler that a variable, object, or function parameter **must not be modified**.

```cpp
const int a = 10;
a = 20; // ❌ Error: a is const
```

---

## Basic Const Variables

```cpp
const int age = 25;
age = 30; // ❌ Error: cannot assign to a const variable

int score = 100;
const int bonus = score + 20; // OK
```

Use `const` to create variables whose value should not change.

---

## Pointers and `const`

### Pointer to Const Value

```cpp
int x = 10;
int y = 20;
const int* ptr = &x; // pointer to a const int

*ptr = 5;    // ❌ Error: cannot change value through ptr
ptr = &y;    // ✅ OK: can point to another int
```

### Const Pointer to Non-Const Value

```cpp
int x = 10;
int y = 20;
int* const ptr = &x; // const pointer to int

*ptr = 5;    // ✅ OK
ptr = &y;    // ❌ Error: cannot change what ptr points to
```

### Const Pointer to Const Value

```cpp
int x = 10;
const int* const ptr = &x; // const pointer to const int

*ptr = 5;    // ❌ Error
ptr = &y;    // ❌ Error
```

---

## Function Parameters

### Pass by Value

```cpp
void printValue(const int x) {
    std::cout << x << std::endl;
    // x = 10; // ❌ Error
}
```

### Pass by Const Reference

```cpp
void greet(const std::string& name) {
    std::cout << "Hello, " << name << std::endl;
    // name += "!"; // ❌ Error
}

std::string user = "Alice";
greet(user); // ✅
```

### Pass by Const Pointer

```cpp
void show(const int* ptr) {
    std::cout << *ptr << std::endl;
    // *ptr = 42; // ❌ Error
}
```

---

## Return Types

### Returning Const by Value

```cpp
const int getAge() {
    return 30;
}

int a = getAge(); // OK, but const is ignored on return by value
```

### Returning Const Reference

```cpp
const std::string& getName() {
    static std::string name = "R";
    return name;
}

getName() += "123"; // ❌ Error
```

---

## Const Member Functions

```cpp
class User {
    std::string name;
public:
    User(std::string n) : name(n) {}

    std::string getName() const {
        return name;
    }

    void rename(const std::string& newName) {
        name = newName;
    }
};

void showUser(const User& u) {
    std::cout << u.getName(); // ✅ OK: getName() is const
    // u.rename("New"); // ❌ Error: rename is non-const
}
```

---

## Const Objects and References

```cpp
const User u("R");
u.getName(); // ✅
// u.rename("Someone Else"); // ❌ Error

void show(const User& userRef) {
    std::cout << userRef.getName(); // ✅
}
```

---

## Top-level vs Low-level Const

| Declaration            | Meaning                               |
| ---------------------- | ------------------------------------- |
| `const int a`          | a is const                            |
| `int* const ptr`       | ptr is const (cannot point elsewhere) |
| `const int* ptr`       | ptr points to const int               |
| `const int* const ptr` | both pointer and value are const      |

---

## Mutable Keyword

```cpp
class Logger {
    mutable int counter = 0;
public:
    void log() const {
        ++counter; // ✅ Allowed
        std::cout << "Logged: " << counter << " times" << std::endl;
    }
};

const Logger logger;
logger.log(); // ✅
```

---

## Const with Arrays

```cpp
const int nums[] = {1, 2, 3};
nums[0] = 10; // ❌ Error

int arr[] = {1, 2, 3};
const int* ptr = arr;
ptr[1] = 5; // ❌ Error
```

---

## Const with `constexpr`

```cpp
constexpr int max = 100; // known at compile-time
const int value = max + 10; // const, may be runtime

int array[max]; // ✅ OK if max is constexpr
```

---

## Best Practices

* ✅ Prefer `const` for values you don’t intend to modify.
* ✅ Use `const T&` for large objects in function parameters.
* ✅ Always mark member functions `const` if they don’t change object state.
* ✅ Use `const` in APIs to express intent and guarantee safety.

---

## Cheat Table Summary

| Code                        | Meaning                                |
| --------------------------- | -------------------------------------- |
| `const int a = 5;`          | a cannot change                        |
| `int* ptr`                  | normal pointer                         |
| `const int* ptr`            | pointer to const int                   |
| `int* const ptr`            | const pointer to int                   |
| `const int* const ptr`      | const pointer to const int             |
| `void f(const int x)`       | x cannot be modified in function       |
| `void f(const T& x)`        | x passed by const ref                  |
| `int get() const`           | function doesn't modify object         |
| `const std::string& name()` | caller can't modify returned reference |

---

## 📋 Const Meaning Table (Full)

| Declaration                           | Simple Meaning                         | What it Protects                 | Example                                | What’s Allowed / Not Allowed           |
| ------------------------------------- | -------------------------------------- | -------------------------------- | -------------------------------------- | -------------------------------------- |
| `const int a = 5;`                    | `a` is a constant value                | The **value** itself             | `a = 10;` ❌                            | Value cannot change                    |
| `int* ptr;`                           | Regular pointer                        | Nothing                          | `*ptr = 5;`, `ptr = &x;` ✅             | Fully mutable                          |
| `const int* ptr;` / `int const* ptr;` | Pointer to a const int                 | The **value being pointed to**   | `*ptr = 5;` ❌<br>`ptr = &x;` ✅         | Can't modify pointed value             |
| `int* const ptr = &x;`                | Const pointer to an int                | The **pointer itself**           | `*ptr = 5;` ✅<br>`ptr = &y;` ❌         | Can't point elsewhere                  |
| `const int* const ptr = &x;`          | Const pointer to const int             | **Pointer + Value**              | `*ptr = 5;` ❌<br>`ptr = &y;` ❌         | Nothing is modifiable                  |
| `void foo(const int x)`               | `x` is a const copy                    | Local value inside function      | `x = 5;` ❌                             | Not modifiable (but copied)            |
| `void foo(const int& x)`              | Const reference to value               | The **referenced argument**      | `x = 5;` ❌                             | Efficient + safe for large objects     |
| `void foo(int* const ptr)`            | Pointer is const                       | Can't reassign `ptr`             | `*ptr = 42;` ✅<br>`ptr = &y;` ❌        | Good if ptr should not move            |
| `void foo(const int* ptr)`            | Pointer to const                       | Can't change pointed value       | `*ptr = 42;` ❌<br>`ptr = &y;` ✅        | Safe when reading only                 |
| `void foo(const int* const ptr)`      | Const pointer to const int             | Neither ptr nor value            | `*ptr = 42;`, `ptr = &z;` ❌            | Most restricted                        |
| `const int& getX();`                  | Returns const ref                      | Caller can't modify return value | `getX() = 99;` ❌                       | Good for returning internal state      |
| `int& getX();`                        | Returns ref                            | Caller **can** modify value      | `getX() = 99;` ✅                       | Risky if returning internal data       |
| `int getX() const;`                   | Member function won't modify object    | Protects object state            | Called on `const obj` ✅                | Can’t modify members                   |
| `void foo(const MyClass& obj);`       | Const ref to object                    | Can’t change the object          | `obj.setX()` ❌ if setX is non-const    | Efficient + safe                       |
| `mutable int counter;`                | Can be modified even in `const` method | Bypasses `const`                 | In `void log() const { counter++; }` ✅ | Rare but useful for caching or logging |

---

## 🎓 Bonus: Practical Rule of Thumb

> Read const declarations **right to left**:

* `int const*` → pointer to const int
* `int* const` → const pointer to int
* `int const* const` → const pointer to const int

---

For further mastery, test yourself by reading and rewriting const expressions. Let me know if you want to generate a quiz or project involving `const` in real-world C++ code.
