/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:03:33 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/05 11:03:34 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	<cmath>
#include	"Fixed.hpp"

// Constructor: Default
Fixed::Fixed( void )
{
	this->_fixp = 0;
}

// Constructor: Constant integer to fixed point
Fixed::Fixed( const int num )
{
	this->_fixp = num << _bitFrac;
}

// Constructor: Constant float to fixed point
Fixed::Fixed( const float num )
{
	this->_fixp = roundf(num * (1 << _bitFrac));
}

// Destructor
Fixed::~Fixed( void )
{
}

// Constructor: Copy
Fixed::Fixed( Fixed& fixp )
{
	*this = fixp;
}

// Constructor; Constant copy
Fixed::Fixed( const Fixed &fixp )
{
	*this = fixp;
}

// Getter: _fixp
int	Fixed::getRawBits( void ) const
{
	return (this->_fixp);
}

// Setter: _fixp
void	Fixed::setRawBits( int const raw )
{
	this->_fixp = raw;
}

// Conversor: Fixed point to integer
int	Fixed::toInt( void ) const
{
	return (this->_fixp >> _bitFrac);
}

// Conversor: Fixed point to float
float	Fixed::toFloat( void ) const
{
	return (this->_fixp / static_cast<float>(1 << _bitFrac));
}

// Operator: Assignation: Constant
Fixed&	Fixed::operator=( const Fixed &fixp )
{
	if (this != &fixp)
		this->_fixp = fixp.getRawBits();
	return (*this);
}

// Operator: Assignation
Fixed&	Fixed::operator=( Fixed &fixp )
{
	if (this != &fixp)
		this->_fixp = fixp.getRawBits();
	return (*this);
}

// Operator: Comparison: '>' == "Greater than"
bool	Fixed::operator>( const Fixed &fixp ) const
{
	return ( this->_fixp > fixp.getRawBits() );
}

// Operator: Comparison: '<' == "Lower than"
bool	Fixed::operator<( const Fixed &fixp ) const
{
	return ( this->_fixp < fixp.getRawBits() );
}

// Operator: Comparison: '>=' == "Greater-equal than"
bool	Fixed::operator>=( const Fixed &fixp ) const
{
	return ( this->_fixp >= fixp.getRawBits() );
}

// Operator: Comparison: '<=' == "Lower-equal than"
bool	Fixed::operator<=( const Fixed &fixp ) const
{
	return ( this->_fixp <= fixp.getRawBits() );
}

// Operator: Comparison: '==' == "Equal"
bool	Fixed::operator==( const Fixed &fixp ) const
{
	return ( this->_fixp == fixp.getRawBits() );
}

// Operator: Comparison: '!=' == "Unequal than"
bool	Fixed::operator!=( const Fixed &fixp ) const
{
	return ( this->_fixp != fixp.getRawBits() );
}

// Operator: Arithmetic: '+' == "Addition"
Fixed	Fixed::operator+( const Fixed &fixp ) const
{
	return ( this->toFloat() + fixp.toFloat() );
}

// Operator: Arithmetic: '-' == "Subtraction"
Fixed	Fixed::operator-( const Fixed &fixp ) const
{
	return ( this->toFloat() +- fixp.toFloat() );
}

// Operator: Arithmetic: '*' == "Mulitiplication"
Fixed	Fixed::operator*( const Fixed &fixp ) const
{
	return ( this->toFloat() * fixp.toFloat() );
}

// Operator: Arithmetic: '/' == "Division"
Fixed	Fixed::operator/( const Fixed &fixp ) const
{
	return ( this->toFloat() / fixp.toFloat() );
}

// Operator: Arithmetic: '++' == "Pre-increment"
Fixed	Fixed::operator++( void )
{
	this->_fixp += 1;
	return (*this);
}

// Operator: Arithmetic: '++' == "Post-increment"
Fixed	Fixed::operator++( int )
{
	Fixed	pre( *this );
	this->_fixp += 1;
	return ( pre );
}

// Operator: Arithmetic: '--' == "Pre-decrement"
Fixed	Fixed::operator--( void )
{
	this->_fixp -= 1;
	return ( *this );
}

// Operator: Arithmetic: '--' == "Post-decrement"
Fixed	Fixed::operator--( int )
{
	Fixed	pre( *this );
	this->_fixp -= 1;
	return ( pre );
}

// Static function: Minimun
Fixed&	Fixed::min( Fixed& first, Fixed& second )
{
	if ( first < second )
		return ( first );
	return ( second );
}

// Static function: Constant: Minimun
const Fixed&	Fixed::min( const Fixed& first, const Fixed& second )
{
	if ( first < second )
		return ( first );
	return ( second );
}

// Static function: Maximun
Fixed&	Fixed::max( Fixed& first, Fixed& second )
{
	if ( first > second )
		return ( first );
	return ( second );
}

// Static function: Constant: Maximun
const Fixed&	Fixed::max( const Fixed& first, const Fixed& second )
{
	if ( first > second )
		return ( first );
	return ( second );
}

// Operator: Output
std::ostream&	operator<<( std::ostream& out, Fixed& fixp )
{
	out << fixp.toFloat();
	return (out);
}

// Operator: Constant: Output
std::ostream&	operator<<( std::ostream& out, const Fixed& fixp )
{
	out << fixp.toFloat();
	return (out);
}

