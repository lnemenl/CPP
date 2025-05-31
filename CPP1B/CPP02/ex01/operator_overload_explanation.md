# C++ Operator Overloading and Fixed-Point Number Conversions

## Table of Contents
1. [Copy Assignment Operator Overload](#copy-assignment-operator-overload)
2. [Insertion Operator (<<) Overload](#insertion-operator--overload)
3. [Fixed-Point Number Conversions](#fixed-point-number-conversions)
   - [Converting Integer to Fixed-Point](#converting-integer-to-fixed-point)
   - [Converting Floating-Point to Fixed-Point](#converting-floating-point-to-fixed-point)
   - [Converting Fixed-Point to Floating-Point](#converting-fixed-point-to-floating-point)
   - [Converting Fixed-Point to Integer](#converting-fixed-point-to-integer)

---

## Copy Assignment Operator Overload

### What is the Copy Assignment Operator?

The copy assignment operator (`operator=`) is a special member function that defines how an object is assigned from another object of the same type. It's called when an already-initialized object is assigned a new value from another existing object.

### Syntax and Structure

```cpp
class ClassName {
public:
    // Copy assignment operator declaration
    ClassName& operator=(const ClassName& other);
};

// Implementation
ClassName& ClassName::operator=(const ClassName& other) {
    // Check for self-assignment
    if (this != &other) {
        // Copy data from 'other' to 'this'
        // Release any resources that 'this' is holding
        // Allocate new resources if needed
        // Copy the actual data
    }
    return *this;
}
```

### Key Components Explained

1. **Return Type (`ClassName&`)**: Returns a reference to the current object to allow chain assignments (e.g., `a = b = c`)

2. **Parameter (`const ClassName& other`)**: 
   - `const`: The source object shouldn't be modified
   - `&`: Pass by reference for efficiency
   - `other`: The object being copied from

3. **Self-Assignment Check**: `if (this != &other)` prevents issues when an object is assigned to itself

4. **Return Statement**: `return *this` returns the current object by reference

### How It Works

When you write `object1 = object2;`, the compiler translates this to `object1.operator=(object2);`

### Important Considerations

- **Rule of Three/Five**: If you define a copy assignment operator, you likely need:
  - Destructor
  - Copy constructor
  - (C++11) Move constructor
  - (C++11) Move assignment operator

- **Deep vs Shallow Copy**: 
  - Shallow copy: Copies pointer values (dangerous for dynamic memory)
  - Deep copy: Allocates new memory and copies the actual data

### Example Pattern for Resource Management

```cpp
class ResourceManager {
private:
    int* data;
    size_t size;

public:
    ResourceManager& operator=(const ResourceManager& other) {
        if (this != &other) {
            // 1. Delete old resources
            delete[] data;
            
            // 2. Copy size
            size = other.size;
            
            // 3. Allocate new resources
            data = new int[size];
            
            // 4. Copy data
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
};
```

---

## Insertion Operator (<<) Overload

### What is the Insertion Operator?

The insertion operator (`<<`) is used with output streams (like `std::cout`) to send data to the stream. When overloaded for custom classes, it allows objects to be printed directly using `cout << object;`

### Syntax and Structure

```cpp
class ClassName {
    // Class members...
    
    // Friend function declaration (most common approach)
    friend std::ostream& operator<<(std::ostream& os, const ClassName& obj);
};

// Implementation (outside the class)
std::ostream& operator<<(std::ostream& os, const ClassName& obj) {
    // Insert obj's data into the output stream
    os << /* formatted representation of obj */;
    return os;
}
```

### Key Components Explained

1. **Return Type (`std::ostream&`)**: Returns the stream reference to enable chaining (e.g., `cout << obj1 << obj2`)

2. **First Parameter (`std::ostream& os`)**: 
   - The output stream (cout, file stream, string stream, etc.)
   - Passed by reference because streams can't be copied

3. **Second Parameter (`const ClassName& obj`)**: 
   - The object to be inserted into the stream
   - `const` because printing shouldn't modify the object
   - `&` for efficiency

4. **Friend Function**: Used because the left operand is a stream, not our class

### How It Works

When you write `cout << myObject;`, the compiler translates this to `operator<<(cout, myObject);`

### Implementation Patterns

#### Basic Implementation
```cpp
class Point {
private:
    double x, y;
    
public:
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};
```

#### With Stream Manipulators
```cpp
class Temperature {
private:
    double celsius;
    
public:
    friend std::ostream& operator<<(std::ostream& os, const Temperature& t) {
        // Preserve and restore stream state
        std::ios_base::fmtflags oldFlags = os.flags();
        std::streamsize oldPrecision = os.precision();
        
        os << std::fixed << std::setprecision(2) 
           << t.celsius << "°C";
        
        // Restore original state
        os.flags(oldFlags);
        os.precision(oldPrecision);
        
        return os;
    }
};
```

### Alternative: Member Function Approach (Less Common)

```cpp
class ClassName {
public:
    std::ostream& operator<<(std::ostream& os) const {
        os << /* data */;
        return os;
    }
};
// Usage: obj << cout; // Awkward!
```

### Best Practices

1. **Always return the stream reference** to support chaining
2. **Make it a friend function** for natural syntax
3. **Don't add endl or newline** unless it's part of the object's representation
4. **Consider stream state** when using manipulators
5. **Handle different stream types** (cout, file streams, string streams) uniformly

---

## Fixed-Point Number Conversions

### Understanding Fixed-Point Numbers

Fixed-point numbers are a way to represent fractional values using integers. They have:
- A fixed number of digits before the decimal point (integer part)
- A fixed number of digits after the decimal point (fractional part)

For example, with 8 fractional bits:
- The value 1.5 would be stored as 384 (1.5 × 2^8 = 384)
- The value 0.25 would be stored as 64 (0.25 × 2^8 = 64)

### Converting Integer to Fixed-Point

#### Concept
When converting an integer to fixed-point, you're essentially shifting the integer value to accommodate the fractional bits.

#### Mathematical Formula
```
fixed_point_value = integer_value × 2^fractional_bits
```

#### Process
1. Take the integer value
2. Shift it left by the number of fractional bits (multiply by 2^n)
3. The result is the fixed-point representation

#### Example
```cpp
// With 8 fractional bits:
int integer = 5;
int fractional_bits = 8;
int fixed_point = integer << fractional_bits;  // 5 × 256 = 1280
// Or: fixed_point = integer * (1 << fractional_bits);
```

#### What This Means
- The integer 5 becomes 1280 in fixed-point
- This represents 5.0 with 8 bits of fractional precision
- The lower 8 bits (all zeros) represent the fractional part

### Converting Floating-Point to Fixed-Point

#### Concept
Converting a floating-point number involves scaling it up and rounding to the nearest integer representation.

#### Mathematical Formula
```
fixed_point_value = round(float_value × 2^fractional_bits)
```

#### Process
1. Multiply the floating-point value by 2^fractional_bits
2. Round to the nearest integer
3. Store as the fixed-point value

#### Example
```cpp
// With 8 fractional bits:
float floating = 3.75f;
int fractional_bits = 8;
int fixed_point = static_cast<int>(roundf(floating * (1 << fractional_bits)));
// 3.75 × 256 = 960
```

#### What This Means
- The float 3.75 becomes 960 in fixed-point
- Binary: 960 = 0b1111000000
- Upper bits (0b11) represent 3
- Lower 8 bits (0b11000000) represent 0.75

### Converting Fixed-Point to Floating-Point

#### Concept
To convert back to floating-point, you divide by the scaling factor.

#### Mathematical Formula
```
float_value = fixed_point_value ÷ 2^fractional_bits
```

#### Process
1. Cast the fixed-point value to float
2. Divide by 2^fractional_bits
3. The result is the floating-point representation

#### Example
```cpp
// With 8 fractional bits:
int fixed_point = 960;
int fractional_bits = 8;
float floating = static_cast<float>(fixed_point) / (1 << fractional_bits);
// 960 ÷ 256 = 3.75
```

#### What This Means
- The division "shifts" the decimal point back
- Preserves the fractional information
- May have small rounding errors due to float precision

### Converting Fixed-Point to Integer

#### Concept
Converting to integer involves removing the fractional part, typically by shifting right.

#### Mathematical Formula
```
integer_value = fixed_point_value ÷ 2^fractional_bits
```

#### Process
1. Shift right by fractional_bits (or divide by 2^fractional_bits)
2. This discards the fractional part
3. The result is the integer part only

#### Example
```cpp
// With 8 fractional bits:
int fixed_point = 960;  // Represents 3.75
int fractional_bits = 8;
int integer = fixed_point >> fractional_bits;  // 960 ÷ 256 = 3
// Or: integer = fixed_point / (1 << fractional_bits);
```

#### Rounding Considerations

**Truncation (default with right shift):**
```cpp
int integer = fixed_point >> fractional_bits;  // Always rounds down
```

**Round to nearest:**
```cpp
int integer = (fixed_point + (1 << (fractional_bits - 1))) >> fractional_bits;
```

**Round up (ceiling):**
```cpp
int integer = (fixed_point + ((1 << fractional_bits) - 1)) >> fractional_bits;
```

### Practical Considerations

1. **Precision Loss**: Fixed-point has limited precision compared to floating-point
2. **Overflow**: Be careful when converting large values
3. **Underflow**: Very small values may become zero
4. **Rounding Errors**: Accumulate over multiple operations
5. **Performance**: Fixed-point arithmetic is often faster than floating-point on systems without FPU

### Common Fixed-Point Formats

- **Q15**: 1 sign bit, 0 integer bits, 15 fractional bits (range: -1 to 0.999...)
- **Q31**: 1 sign bit, 0 integer bits, 31 fractional bits
- **16.16**: 16 integer bits, 16 fractional bits
- **24.8**: 24 integer bits, 8 fractional bits

The choice depends on:
- Required range (how large numbers need to be)
- Required precision (how many decimal places)
- Available storage (32-bit, 64-bit, etc.)