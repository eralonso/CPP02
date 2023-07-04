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
