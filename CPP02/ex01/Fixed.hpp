#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
#include <limits>

class Fixed
{
	private:
		int _value;
		static const int fract_bits = 8;
	
	public:
		Fixed();
		Fixed(const Fixed& obj);
		Fixed& operator=(const Fixed& obj);
		~Fixed();
		Fixed(const int num);
		Fixed(const float num);
		float toFloat(void) const;
		int toInt(void) const;
		
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif
