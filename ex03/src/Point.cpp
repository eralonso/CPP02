/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:03:42 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/05 11:03:43 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Point.hpp"

Point::Point( void ): _x( Fixed( 0 ) ), _y( Fixed( 0 )) , _z( Fixed( 0 ) ) {}

Point::Point( const float x, const float y ): _x( Fixed( x ) ), _y( Fixed( y ) ), _z( Fixed( 0 ) ) {}

Point::Point( const float x, const float y, const float z ): _x( Fixed( x ) ), _y( Fixed( y ) ), _z( Fixed( z ) ) {}

Point::Point( const Point& p ): _x( Fixed( p.getX() ) ), _y( Fixed( p.getY() ) ), _z( Fixed( p.getZ() ) ) {}

Point::~Point( void ) {}

Point&	Point::operator=( const Point& p )
{
	if (this != &p)
	{
		this->_x = p.getX();
		this->_y = p.getY();
		this->_z = p.getZ();
	}
	return (*this);
}

Point&	Point::operator=( Point& p )
{
	if (this != &p)
	{
		this->_x = p.getX();
		this->_y = p.getY();
		this->_z = p.getZ();
	}
	return (*this);
}

bool	Point::operator==( const Point& p ) const
{
	return ( this->getX() == p.getX() && this->getY() == p.getY() && this->getZ() == p.getZ() );
}

const Fixed&	Point::getX( void ) const
{
	return (this->_x);
}

const Fixed&	Point::getY( void ) const
{
	return (this->_y);
}

const Fixed&	Point::getZ( void ) const
{
	return (this->_z);
}

std::ostream&	operator<<( std::ostream& out, Point& p )
{
	out << "x: " << p.getX() << ", y: " << p.getY() << ", z: " << p.getZ();
	return ( out );
}
