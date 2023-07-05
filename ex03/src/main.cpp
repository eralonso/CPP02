/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:03:37 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/05 11:03:38 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	<iomanip>
#include	"Point.hpp"

#define WIDTH	10
#define HEIGHT	10

bool	bsp( const Point a, const Point b, const Point c, const Point p );

bool	isEqual( const Point p, int x, int y )
{
	return ( p.getX().toInt() == x && p.getY().toInt() == y );
}

void	draw( const Point a, const Point b, const Point c, const Point p )
{
	for ( int i = WIDTH; i >= -WIDTH; i-- )
	{
		for ( int j = -HEIGHT; j <= HEIGHT; j++ )
		{
			if ( isEqual(a, j, i) )
				std::cout << "a";
			else if ( isEqual(b, j, i) )
				std::cout << "b";
			else if ( isEqual(c, j, i) ) 
				std::cout << "c";
			else if ( isEqual(p, j, i) )
				std::cout << "p";
			else
				std::cout << "#";
		}
		if ( i == 0 )
			std::cout << "---> y: 0" ;
		std::cout << std::endl;
	}
	std::cout << std::setw(WIDTH + 1) << "|" << std::endl;
	std::cout << std::setw(WIDTH + 4) << "|-->" << "x: 0" << std::endl;
}

void	point_in_triangle( Point a, Point b, Point c, Point p )
{
	std::cout << "a -> " << a << std::endl;
	std::cout << "b -> " << b << std::endl;
	std::cout << "c -> " << c << std::endl;
	std::cout << "p -> " << p << std::endl;
	std::cout << "res = " << bsp(a, b, c, p) << std::endl;
	draw(a, b, c, p);
}

int	main( void )
{
	point_in_triangle( Point( 0, 0 ), Point( 5, 0 ), Point( 0, 5 ), Point( 2, 2 ) );
	std::cout << std::endl;
	point_in_triangle( Point( -5, 0 ), Point( 5, 2 ), Point( 2, -5 ), Point( -2, 0 ) );
	std::cout << std::endl;
	point_in_triangle( Point( -7, 4 ), Point( 4, -1 ), Point( -2, 6 ), Point( 4, 2 ) );
	std::cout << std::endl;
	point_in_triangle( Point( 0, 0 ), Point( 5, 0 ), Point( 0, 5 ), Point( 2.5, 2.5 ) );
	std::cout << std::endl;
	point_in_triangle( Point( 0, 0 ), Point( 5, 0 ), Point( 0, 5 ), Point( 2.4, 2.5 ) );
	std::cout << std::endl;
	return (0);
}
