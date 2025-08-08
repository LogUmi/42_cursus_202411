/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:18 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/08 20:21:13 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <climits>
#include <cmath>
#include "Fixed.hpp"

// ****************************************************************************
// Constructors and destructor
// ****************************************************************************

Fixed::Fixed( void ) : _value(0)
{
	//std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( const Fixed & f)
{
	this->_value = f.getRawBits();
	//std::cout << "Copy constructor called" << std::endl;
	return ;
}

Fixed::Fixed( const int i)
{
	//std::cout << "Int constructor called" << std::endl;
	if (i > (INT_MAX / (1 << this->_nbits)))
	{
		std::cout 	<< "[Error]: This int overflow Fixed class "
					<< "and was converted to FIXED_MAX"
					<< std::endl;
		this->_value = INT_MAX;
	}
	else if(i < (INT_MIN / (1 << this->_nbits)))
	{
		std::cout 	<< "[Error]: This int overflow Fixed class "
					<< "and was converted to FIXED_MIN"
					<< std::endl;
		this->_value = (INT_MIN);
	}
	else
		this->_value = i * (1 << this->_nbits);
	return ;
}

Fixed::Fixed( const float f )
{
	//std::cout << "Float constructor called" << std::endl;
	if (f > (float(INT_MAX) / (1 << this->_nbits)))
	{
		std::cout 	<< "[Error]: This float overflow Fixed class "
					<< "and was converted to FIXED_MAX"
					<< std::endl;
		this->_value = INT_MAX;
	}
	else if(f < (float(INT_MIN) / (1 << this->_nbits)))
	{
		std::cout 	<< "[Error]: This float overflow Fixed class "
					<< "and was converted to FIXED_MIN"
					<< std::endl;
		this->_value = INT_MIN;
	}
	else if ((f < 1 && f > 0) && f < (float(1) / (1 << this->_nbits)))
	{
		std::cout 	<< "[Error]: This float underflow Fixed class "
					<< "and was converted to 0"
					<< std::endl;
		this->_value = 0;
	}
	else if ((f > -1 && f < 0) && (f * -1.0f) < (float(1) / (1 << this->_nbits)))
	{
		std::cout 	<< "[Error]: This float underflow Fixed class "
					<< "and was converted to 0"
					<< std::endl;
		this->_value = 0;
	}
	else
		this->_value = roundf(f * (1 << _nbits));
	return ;
}

Fixed::~Fixed( void )
{
	//std::cout << "Destructor called" << std::endl;
	return ;
}

// ****************************************************************************
// overload of comparatives operators
// ****************************************************************************

bool	Fixed::operator>( const Fixed& f ) const
{
	return (this->_value > f._value);
}

bool	Fixed::operator<( const Fixed& f ) const
{
	return (this->_value < f._value);
}

bool	Fixed::operator>=( const Fixed& f ) const
{
	return (this->_value >= f._value);
}

bool	Fixed::operator<=( const Fixed& f ) const
{
	return (this->_value <= f._value);
}

bool	Fixed::operator==( const Fixed& f ) const
{
	return (this->_value == f._value);
}

bool	Fixed::operator!=( const Fixed& f ) const
{
	return (this->_value != f._value);
}

// ****************************************************************************
// overload of calculation operators
// ****************************************************************************

Fixed&	Fixed::operator=(const Fixed& f)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &f)
		this->_value = f.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+( const Fixed& f )
{
	Fixed	temp;

	temp.setRawBits(this->_value + f._value);
	return (temp);
}

Fixed	Fixed::operator-( const Fixed& f )
{
	Fixed	temp;

	temp.setRawBits(this->_value - f._value);
	return (temp);
}

Fixed	Fixed::operator*( const Fixed& f )
{
	Fixed	temp;

	temp.setRawBits((this->_value * f._value / (1 << this->_nbits)));
	return (temp);
}

Fixed	Fixed::operator/( const Fixed& f )
{
		Fixed	temp;

		temp.setRawBits((this->_value * (1 << this->_nbits)) / f._value);
		return (temp);
}

// ****************************************************************************
// overload of increment and decrement operators
// ****************************************************************************

Fixed&	Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed&	Fixed::operator--()
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp (*this);

	this->_value++;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp (*this);

	this->_value--;
	return (temp);
}

// ****************************************************************************
// overload of stream operators
// ****************************************************************************

std::ostream & operator<<(std::ostream & o, Fixed const & val)
{
	o << val.toFloat();
	return (o);
}

// ****************************************************************************
// member functions
// ****************************************************************************

int		Fixed::getRawBits( void ) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits( int const raw )
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
	return ;
}

 float	Fixed::toFloat( void ) const
{
	return (float(this->_value) / float(1 << this-> _nbits));	
}

int		Fixed::toInt( void ) const
{
	return (this->_value / (1 << this-> _nbits));
}

Fixed&	Fixed::min(Fixed & a, Fixed & b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed & a, const Fixed & b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed & a, Fixed & b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed & a, const Fixed & b)
{
	if (a > b)
		return (a);
	return (b);
}
