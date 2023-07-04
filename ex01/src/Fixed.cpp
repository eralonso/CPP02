#include	<iostream>
#include	<cmath>
#include	"Fixed.hpp"

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixp = 0;
}

Fixed::Fixed( const int num )
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixp = num << _bitFrac;
}

Fixed::Fixed( const float num )
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixp = roundf(num * (1 << _bitFrac));
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( Fixed& fixp )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixp;
}

Fixed::Fixed( Fixed const &fixp )
{
	std::cout << "Copy (const) constructor called" << std::endl;
	*this = fixp;
}

Fixed&	Fixed::operator=( Fixed const &fixp )
{
	std::cout << "Assignation (const) operator called" << std::endl;
	if (this != &fixp)
		this->_fixp = fixp.getRawBits();
	return (*this);
}

Fixed&	Fixed::operator=( Fixed &fixp )
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &fixp)
		this->_fixp = fixp.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	return (this->_fixp);
}

void	Fixed::setRawBits( int const raw )
{
	this->_fixp = raw;
}

int	Fixed::toInt( void ) const
{
	return (this->_fixp >> _bitFrac);
}

float	Fixed::toFloat( void ) const
{
	return (this->_fixp / static_cast<float>(1 << _bitFrac));
}

std::ostream&	operator<<( std::ostream& out, Fixed& fixp )
{
	out << fixp.toFloat();
	return (out);
}

