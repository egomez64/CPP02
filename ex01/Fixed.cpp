#include "Fixed.hpp"

Fixed::Fixed() : _nb(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nb) {
	this->_nb = nb << _bits;
}

Fixed::Fixed(const float nb)
{
	this->_nb = roundf(nb * (1 << _bits));
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_nb = src.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_nb;
}

void Fixed::setRawBits(int const raw)
{
	_nb = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(_nb) / (1 << _bits));
}

int Fixed::toInt(void) const
{
	return (static_cast<int>(Fixed::toFloat()));
}

std::ostream &operator << (std::ostream &out, Fixed const &fx)
{
	out << fx.toFloat();
	return (out);
}
