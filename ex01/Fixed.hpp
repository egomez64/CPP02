#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(int nb);
	Fixed(float nb);
	Fixed (const Fixed &src);
	Fixed &operator=(const Fixed &src);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

private:
	int _nb;
	const static int _bits = 8;
};

std::ostream &operator << (std::ostream &out, Fixed const &fx);

#endif