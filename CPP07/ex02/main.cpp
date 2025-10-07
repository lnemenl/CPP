// #include <iostream>
// #include <string>
// #include "Array.hpp"
// #include <utility>

// // A simple helper function to create an Array.
// // When this function returns, its local 'arr' object is destroyed,
// // but the C++ standard allows its contents to be moved directly into the destination
// // variable in main(), creating a temporary (rvalue) that enables the move constructor.
// Array<int> createIntArray(size_t size)
// {
//     std::cout << "\n--- Entering createIntArray ---\n";
//     Array<int> arr(size);
//     for (size_t i = 0; i < size; ++i) {
//         arr[i] = i * 10;
//     }
//     std::cout << "--- Leaving createIntArray ---\n";
//     return arr; // This return creates a temporary (rvalue)
// }

// int main()
// {
//     std::cout << "========= Test 1: The Basics (Construction & Access) =========\n";
    
//     // Create an array of 5 integers. Calls the Sizing Constructor.
//     Array<int> a(5);
    
//     // Populate the array using the subscript operator.
//     for (size_t i = 0; i < a.size(); ++i)
//     {
//         a[i] = i;
//     }
    
//     std::cout << "Array 'a' created and populated.\n\n";

//     //========= The Rule of Three (The "Photocopies") =========//
    
//     std::cout << "========= Test 2: Copy Operations (The expensive photocopies) =========\n";

//     // 2a. Copy Constructor
//     // We are creating a brand new object 'b' from an existing object 'a'.
//     // This MUST make a deep copy to ensure 'b' and 'a' are independent.
//     std::cout << "Creating 'b' from 'a'...\n";
//     Array<int> b = a; // Triggers the COPY CONSTRUCTOR
    
//     std::cout << "\nModifying b[0] to 99...\n";
//     b[0] = 99;
    
//     std::cout << "a[0] is: " << a[0] << " (Unaffected, as it should be)\n";
//     std::cout << "b[0] is: " << b[0] << " (Changed)\n\n";

//     // 2b. Copy Assignment
//     // We are assigning an existing object 'a' to another existing object 'c'.
//     // 'c' must first delete its old data and then make a deep copy of 'a's data.
//     Array<int> c(2); // Create 'c' with some initial data
//     std::cout << "\nCreating 'c' and then assigning 'a' to it...\n";
//     c = a; // Triggers the COPY ASSIGNMENT OPERATOR
    
//     std::cout << "\nModifying c[1] to 111...\n";
//     c[1] = 111;

//     std::cout << "a[1] is: " << a[1] << " (Unaffected)\n";
//     std::cout << "c[1] is: " << c[1] << " (Changed)\n\n";


//     //========= The Rule of Five (The "Efficient Moves") =========//

//     std::cout << "========= Test 3: Move Operations (The efficient resource steal) =========\n";

//     // 3a. Move Constructor
//     // We are creating a new object 'd' from a temporary (rvalue).
//     // The temporary is the unnamed Array object returned by createIntArray(3).
//     // Instead of copying, we just "steal" the internal pointer from the temporary.
//     std::cout << "Creating 'd' by moving from a temporary...\n";
//     Array<int> d = createIntArray(3); // Triggers the MOVE CONSTRUCTOR (not the copy constructor!)
    
//     std::cout << "\nArray 'd' has been created. Its size is: " << d.size() << " and d[1] is: " << d[1] << "\n\n";
    
//     // 3b. Move Assignment
//     // We are assigning a temporary to an existing object 'd'.
//     // 'd' will free its current data and then steal the data from the temporary.
//     std::cout << "Assigning a new temporary array to 'd'...\n";
//     d = createIntArray(7); // Triggers the MOVE ASSIGNMENT OPERATOR
    
//     std::cout << "\nArray 'd' has been reassigned. Its new size is: " << d.size() << " and d[6] is: " << d[6] << "\n\n";
    
//     std::cout << "========= Test 4: Exception Handling =========\n";
//     try
//     {
//         std::cout << "Attempting to access d[99] (out of bounds)...\n";
//         std::cout << d[99]; // This will throw an exception
//     }
//     catch (const std::exception& e)
//     {
//         // The exception thrown by the subscript operator is caught here.
//         std::cout << "Successfully caught exception: " << e.what() << '\n';
//     }

//     std::cout << "\n========= End of main: Destructors will be called now =========\n";
//     // As a, b, c, and d go out of scope, their destructors are called in reverse order of creation.
//     return 0;
// }


#include <iostream>
#include "Array.hpp"
#include <chrono>   // For high-precision timing
#include <utility>  // For std::move

// A large number of elements to make the performance difference obvious.
#define ARRAY_SIZE 10000000

// A swap function that FORCES the use of the Copy Constructor and Copy Assignment.
// This simulates how a class with only the Rule of Three would behave.
template<typename T>
void swap_copy(Array<T>& a, Array<T>& b)
{
    std::cout << "--- Attempting swap using ONLY copy semantics ---\n";
    // This line MUST call the Copy Constructor. It has to make a full, deep copy of 'a'.
    Array<T> temp = a;
    // These lines MUST call the Copy Assignment Operator for a deep copy.
    a = b;
    b = temp;
    std::cout << "--- Swap by copy finished ---\n";
}

// A swap function that uses std::move to trigger the Move Constructor and Move Assignment.
// This shows the power of the Rule of Five.
template<typename T>
void swap_move(Array<T>& a, Array<T>& b)
{
    std::cout << "--- Attempting swap using MOVE semantics ---\n";
    // This line triggers the MOVE Constructor. It just steals 'a's pointer. No allocation.
    Array<T> temp = std::move(a);
    // These lines trigger the MOVE Assignment Operator. Just pointer swaps.
    a = std::move(b);
    b = std::move(temp);
    std::cout << "--- Swap by move finished ---\n";
}

int main()
{
    std::cout << "Creating arrays with " << ARRAY_SIZE << " elements each.\n\n";

    // ========================================================================
    // TEST 1: The slow way (Rule of Three)
    // ========================================================================
    {
        std::cout << "========= TEST 1: The Rule of Three World (Slow Copy Swap) =========\n";
        Array<int> arr1_copy(ARRAY_SIZE);
        Array<int> arr2_copy(ARRAY_SIZE);
        // (No need to fill them with data, the allocation is the expensive part)

        // Get the current time before the operation
        auto start = std::chrono::high_resolution_clock::now();

        swap_copy(arr1_copy, arr2_copy);

        // Get the current time after the operation
        auto end = std::chrono::high_resolution_clock::now();

        // Calculate the duration in milliseconds
        std::chrono::duration<double, std::milli> duration = end - start;

        std::cout << "\n>>> PERFORMANCE RESULT (Copy Swap): " << duration.count() << " ms\n\n";
    }


    // ========================================================================
    // TEST 2: The fast way (Rule of Five)
    // ========================================================================
    {
        std::cout << "========= TEST 2: The Rule of Five World (Fast Move Swap) =========\n";
        Array<int> arr1_move(ARRAY_SIZE);
        Array<int> arr2_move(ARRAY_SIZE);

        auto start = std::chrono::high_resolution_clock::now();

        swap_move(arr1_move, arr2_move);

        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> duration = end - start;

        std::cout << "\n>>> PERFORMANCE RESULT (Move Swap): " << duration.count() << " ms\n\n";
    }

    std::cout << "========= CONCLUSION =========\n";
    std::cout << "Compare the two timings. The difference is the reason the Rule of Five is essential for performance.\n";
    std::cout << "The first test spent its time allocating and copying " << ARRAY_SIZE * 2 << " integers.\n";
    std::cout << "The second test spent its time swapping a few pointers.\n";

    return 0;
}

/*
    The Magic of std::move
    So, what does std::move actually do?

    std::move does not move anything.

    It's a bit of a misleading name. std::move is simply a cast. It takes an object and casts it into an rvalue reference.

    It's like putting a "For Sale - Contents Must Go!" sign on a house.
    The house (the object) is still there, but you've signaled to everyone
    that its contents are up for grabs because the owner is leaving.


    The compiler sees the line: Array<T> temp = std::move(a);

    It looks at the right side. The variable a is an lvalue (it has a name).

    The std::move() function casts the lvalue a into an rvalue reference (Array&&).

    The compiler now needs to choose a constructor for temp. It has two choices:

    Array(const Array& source) (the copy constructor)

    Array(Array&& source) (the move constructor)

    Since the input is now an rvalue reference,
    the compiler sees a perfect match for the move constructor.
    It chooses that doorway, and the fast move happens.

    Without std::move(a), the compiler would only see the lvalue a.
    The only valid doorway would be the copy constructor, and it would be forced to make a slow copy.
    
*/
