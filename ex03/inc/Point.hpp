/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:03:29 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/05 11:03:30 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT_H__
# define __POINT_H__

# include	"Fixed.hpp"

class Point
{
	private:
		Fixed	_x;
		Fixed	_y;
		Fixed	_z;
	public:
		Point( void );
		Point( const Point& p );
		Point( const float x, const float y );
		Point( const float x, const float y, const float z );
		~Point( void );
		Point&		operator=( const Point& p );
		Point&		operator=( Point& p );
		bool		operator==( const Point& p ) const;
		const Fixed&	getX( void ) const;
		const Fixed&	getY( void ) const;
		const Fixed&	getZ( void ) const;
};

std::ostream&	operator<<( std::ostream& out, Point& p );

#endif
