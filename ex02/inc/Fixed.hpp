#ifndef __FIXED_H__
# define __FIXED_H__

# include	<iostream>

class Fixed
{
	private:
		int			_fixp;
		static const int	_bitFrac = 8;
	public:
		// Constructor: Default
		Fixed( void );
		// Constructor: Constant int to fixed point
		Fixed( const int num );
		// Constructor: Constant float to fixed point
		Fixed( const float num );
		// Constructor: Copy
		Fixed( Fixed& fixp );
		// Constructor: Constant: Copy
		Fixed( Fixed const &fixp );
		// Destructor
		~Fixed( void );
		// Operator: Assignation
		Fixed&			operator=( Fixed &fixp );
		// Operator: Assignation: Constant
		Fixed&			operator=( Fixed const &fixp );
		// Operator: Comparison: '>' == "Greater than"
		bool			operator>( const Fixed &fixp ) const;
		// Operator: Comparison: '<' == "Lower than"
		bool			operator<( const Fixed &fixp ) const;
		// Operator: Comparison: '>=' == "Greater-equal than"
		bool			operator>=( const Fixed &fixp ) const;
		// Operator: Comparison: '<=' == "Lower-equal than"
		bool			operator<=( const Fixed &fixp ) const;
		// Operator: Comparison: '==' == "Equal"
		bool			operator==( const Fixed &fixp ) const;
		// Operator: Comparison: '!=' == "Unequal"
		bool			operator!=( const Fixed &fixp ) const;
		// Operator: Arithmetic: '+' == "Addition"
		Fixed			operator+( const Fixed &fixp ) const;
		// Operator: Arithmetic: '-' == "subtraction"
		Fixed			operator-( const Fixed &fixp ) const;
		// Operator: Arithmetic: '*' == "Multiplication"
		Fixed			operator*( const Fixed &fixp ) const;
		// Operator: Arithmetic: '/' == "Division"
		Fixed			operator/( const Fixed &fixp ) const;
		// Operator: Arithmetic: '++' == "Pre-increment"
		Fixed			operator++( void );
		// Operator: Arithmetic: '++' == "Post-increment"
		Fixed			operator++( int );
		// Operator: Arithmetic: '--' == "Pre-decrement"
		Fixed			operator--( void );
		// Operator: Arithmetic: '--' == "Post-decrement"
		Fixed			operator--( int );
		// Static function: Minimun
		static Fixed&		min( Fixed& first, Fixed& second );
		// Static function: Constant: Minimun
		static const Fixed&	min( const Fixed& first, const Fixed& second );
		// Static function: Maximun
		static Fixed&		max( Fixed& first, Fixed& second );
		// Static function: Constant: Maximun
		static const Fixed&	max( const Fixed& first, const Fixed& second );
		// Getter: _fixp
		int			getRawBits( void ) const;
		// Setter: _fixp
		void			setRawBits( int const raw );
		// Conversor: Fixed point to float
		float			toFloat( void ) const;
		// Conversor: Fixed point to int
		int			toInt( void ) const;
};

// Operator: Output
std::ostream&	operator<<( std::ostream& out, Fixed& fixp );
// Operator: Constant: Output
std::ostream&	operator<<( std::ostream& out, const Fixed& fixp );

#endif
