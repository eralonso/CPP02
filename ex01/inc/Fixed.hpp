/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:02:52 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/05 11:02:53 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_H__
# define __FIXED_H__

# include	<iostream>

class Fixed
{
	private:
		int			_fixp;
		static const int	_bitFrac = 8;
	public:
		Fixed( void );
		Fixed( const int num );
		Fixed( const float num );
		Fixed( Fixed& fixp );
		Fixed( Fixed const &fixp );
		~Fixed( void );
		Fixed&	operator=( Fixed &fixp );
		Fixed&	operator=( Fixed const &fixp );
		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int	toInt( void ) const;
};

std::ostream&	operator<<( std::ostream& out, Fixed& fixp );

#endif
