#include "Fixed.hpp"

int	main(void)
{
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);
    a = Fixed(1234.4321f);
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    //Overflow tests
    try
	{
        Fixed overflowInt(std::numeric_limits<int>::max());
        std::cout << "overflowInt constructed: " << overflowInt << std::endl;
    }
	catch (const std::exception& ex)
	{
        std::cout << "Exception for overflowInt: " << ex.what() << std::endl;
    }

    try
	{
        Fixed underflowInt(std::numeric_limits<int>::min());
        std::cout << "underflowInt constructed: " << underflowInt << std::endl;
    }
	catch (const std::exception& ex)
	{
        std::cout << "Exception for underflowInt: " << ex.what() << std::endl;
    }

    try
	{
        Fixed overflowFloat(static_cast<float>(std::numeric_limits<int>::max()) * 1000.0f);
        std::cout << "overflowFloat constructed: " << overflowFloat << std::endl;
    }
	catch (const std::exception& ex)
	{
        std::cout << "Exception for overflowFloat: " << ex.what() << std::endl;
    }

    try
	{
        Fixed underflowFloat(static_cast<float>(std::numeric_limits<int>::min()) * 1000.0f);
        std::cout << "underflowFloat constructed: " << underflowFloat << std::endl;
    }
	catch (const std::exception& ex)
	{
        std::cout << "Exception for underflowFloat: " << ex.what() << std::endl;
    }

    return 0;
}