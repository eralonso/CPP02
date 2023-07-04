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
