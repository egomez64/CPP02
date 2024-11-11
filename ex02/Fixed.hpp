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
	float toInt(void) const;

private:
	int _nb;
	const static int _bits = 8;

public:
	Fixed operator+(Fixed const &nb);
	Fixed operator-(Fixed const &nb);
	Fixed operator*(Fixed const &nb);
	Fixed operator/(Fixed const &nb);
	bool operator>(Fixed const &nb);
	bool operator<(Fixed const &nb);
	bool operator==(Fixed const &nb);
	bool operator!=(Fixed const &nb);
	bool operator>=(Fixed const &nb);
	bool operator<=(Fixed const &nb);
	Fixed &operator++();
	Fixed &operator--();
	Fixed operator++(int);
	Fixed operator--(int);
	static Fixed &min(Fixed &nb1, Fixed &nb2);
	static const Fixed &const_min(Fixed const &nb1, Fixed const &nb2);
	static Fixed &max(Fixed &nb1, Fixed &nb2);
	static const Fixed &const_max(Fixed const &nb1, Fixed const &nb2);
};

std::ostream &operator << (std::ostream &out, Fixed const &fx);

#endif