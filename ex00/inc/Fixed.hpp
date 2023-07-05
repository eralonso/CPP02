/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:02:32 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/05 11:02:33 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_H__
# define __FIXED_H__

class Fixed
{
	private:
		int			_intp;
		static const int	_bitFrac = 8;
	public:
		Fixed( void );
		Fixed( Fixed& fixp );
		~Fixed( void );
		Fixed&	operator=( Fixed& fixp );
		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif
