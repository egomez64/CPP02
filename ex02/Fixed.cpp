#include "Fixed.hpp"

Fixed::Fixed() : _nb(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nb) {
	this->_nb = nb << _bits;
}

Fixed::Fixed(const float nb)
{
	this->_nb = roundf(nb * ( 1 << _bits));
}

Fixed::Fixed(const Fixed &src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_nb = src.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return _nb;
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

// --------------------
// Operator overloading
// --------------------

std::ostream &operator << (std::ostream &out, Fixed const &fx)
{
	out << fx.toFloat();
	return (out);
}

// --------------------
// Arithmetic operation
// --------------------

Fixed Fixed::operator+(Fixed const &nb)
{
	Fixed new_nb;
	new_nb._nb =  this->getRawBits() + nb.getRawBits();
	return (new_nb);
}

Fixed Fixed::operator-(Fixed const &nb)
{
	Fixed new_nb;
	new_nb._nb = this->getRawBits() - nb.getRawBits();
	return (new_nb);
}

Fixed Fixed::operator*(Fixed const &nb)
{
	Fixed new_nb;
	new_nb._nb = (this->getRawBits() * nb.getRawBits()) / (1 << _bits);
	return (new_nb);
}

Fixed Fixed::operator/(Fixed const &nb)
{
	if (nb.getRawBits() == 0) {
		std::cout << "can't divide by 0" << std::endl;
		return 0;
	}
	Fixed new_nb;
	new_nb._nb = (this->getRawBits() / nb.getRawBits()) * (1 << _bits);
	return (new_nb);
}

// ----------
// Comparator
// ----------

bool Fixed::operator>(Fixed const &nb) const
{
	if (this->getRawBits() > nb.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(Fixed const &nb) const
{
	if (this->getRawBits() < nb.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(Fixed const &nb)
{
	if (this->getRawBits() == nb.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(Fixed const &nb)
{
	if (this->getRawBits() != nb.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(Fixed const &nb)
{
	if (this->getRawBits() <= nb.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(Fixed const &nb)
{
	if (this->getRawBits() >= nb.getRawBits())
		return (true);
	return (false);
}

// -------------------------------
// Incrementation / decrementation
// -------------------------------

Fixed &Fixed::operator++()
{
	this->_nb += 1;
	return (*this);
}

Fixed &Fixed::operator--()
{
	this->_nb -= 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	++(*this);
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	--(*this);
	return (tmp);
}

// ------------------
// min / max function
// ------------------

Fixed &Fixed::min(Fixed &nb1, Fixed &nb2)
{
	if (nb1 < nb2)
		return (nb1);
	return (nb2);
}

const Fixed &Fixed::min(Fixed const &nb1, Fixed const &nb2)
{
	if (nb1 < nb2)
		return (nb1);
	return (nb2);
}

Fixed &Fixed::max(Fixed &nb1, Fixed &nb2)
{
	if (nb1 > nb2)
		return (nb1);
	return (nb2);
}

const Fixed &Fixed::max(Fixed const &nb1, Fixed const &nb2)
{
	if (nb1 > nb2)
		return (nb1);
	return (nb2);
}

