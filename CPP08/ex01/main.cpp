#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <limits>

void printTestHeader(const std::string& title)
{
    std::cout << "\n=== " << title << " ===\n";
}

int main()
{
    printTestHeader("Test 1 / Subject's Main Test");
    try
    {
        Span sp = Span(5);
        sp.addNumber(std::numeric_limits<int>::max());
        sp.addNumber(std::numeric_limits<int>::min());
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }

    // Test 2
    printTestHeader("Test 2 / Edge Case: Not Enough Numbers");
    try
    {
        Span sp = Span(5);
        sp.addNumber(42);
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Caught expected exception: " << e.what() << '\n';
    }

    // Test 3
    printTestHeader("Test 3 / Edge Case: Span is Full");
    try
    {
        Span sp = Span(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Caught expected exception: " << e.what() << '\n';
    }

    // Test 4
    printTestHeader("Test 4 / Iterator Range Test");
    try
    {
        Span sp = Span(10);
        std::vector<int> vec;
        for (int i = 0; i < 10; ++i)
        {
            vec.push_back(i * 2);
        }
        sp.addNumbers(vec.begin(), vec.end());
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }

    // Test 5
    printTestHeader("Test 5 / Iterator Range Overflow Test");
    try
    {
        Span sp = Span(5);
        std::list<int> lst;
        for (int i = 0; i < 10; ++i)
        {
            lst.push_back(i);
        }
        sp.addNumbers(lst.begin(), lst.end());
    }
    catch (const std::exception& e)
    {
        std::cerr << "Caught expected exception: " << e.what() << '\n';
    }
    
    // Test 6
    printTestHeader("Test 6 / Large Scale Test");
    try
    {
        std::vector<int> largeVec;
        largeVec.reserve(15000);
        for (int i = 0; i < 14000; ++i)
        {
            largeVec.push_back(rand());
        }
        
        Span sp(15000);
        sp.addNumbers(largeVec.begin(), largeVec.end());
        sp.addNumber(std::numeric_limits<int>::max());
        sp.addNumber(std::numeric_limits<int>::min());
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        std::cout << "Large scale test successful!" << std::endl;

    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}