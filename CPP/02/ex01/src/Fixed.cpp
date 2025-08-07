/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:18 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/07 19:06:09 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <climits>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed( void ) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( const Fixed & f)
{
	this->_value = f.getRawBits();
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

Fixed::Fixed( const int i)
{
	std::cout << "Int constructor called" << std::endl;
	if (i > Fixed::_dividi(INT_MAX))
	{
		std::cout 	<< "[Error]: This int overflow Fixed class "
					<< "and was converted to FIXED_MAX"
					<< std::endl;
		this->_value = INT_MAX;
	}
	else if(i < Fixed::_dividi(INT_MIN))
	{
		std::cout 	<< "[Error]: This int overflow Fixed class "
					<< "and was converted to FIXED_MIN"
					<< std::endl;
		this->_value = INT_MIN;
	}
	this->_value = Fixed::_multipi(i);
	return ;
}

Fixed::Fixed( const float f )
{
	std::cout << "Float constructor called" << std::endl;
	if (f > Fixed::_dividf(float(__INT_MAX__)))
	{
		std::cout 	<< "[Error]: This float overflow Fixed class "
					<< "and was converted to FIXED_MAX"
					<< std::endl;
		this->_value = INT_MAX;
	}
	else if(f < Fixed::_dividf(INT_MIN))
	{
		std::cout 	<< "[Error]: This float overflow Fixed class "
					<< "and was converted to FIXED_MIN"
					<< std::endl;
		this->_value = INT_MIN;
	}
	else if (f < _dividf(1))
	{
		std::cout 	<< "[Error]: This float underflow Fixed class "
					<< "and was converted to 0"
					<< std::endl;
		this->_value = 0;
	}
	this->_value = Fixed::_multipf(f);
	return ;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed&	Fixed::operator=(const Fixed& f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &f)
		this->_value = f.getRawBits();
	return (*this);
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
	return ;
}

 float	Fixed::_multipf(const float f)
{
	int		i = 0;
	float	j = f;
	
	for (i = 0; i < _nbits; i++)
		j *= 2;
	return (j); 
}
 int		Fixed::_multipi(const int i)
{
	int k = 0;
	int j = i;
	
	for (k = 0; k < _nbits; k++)
		j *= 2;
	return (j); 
}

float	Fixed::_dividf(const float f)
{
	int		i = 0;
	float	j = f;
	
	for (i = 0; i < _nbits; i++)
		j /= 2;
	return (j); 
}

int		Fixed::_dividi(const int i)
{
	int k = 0;
	int j = i;
	
	for (k = 0; k < _nbits; k++)
		j /= 2;
	return (j); 
}

float	Fixed::toFloat( void ) const
{
	float	f = 0;
	
	f = Fixed::_dividf(this->_value);
	return (f);	
}

int		Fixed::toInt( void ) const
{
	return (Fixed::_dividi(this->_value));
}

std::ostream & operator<<(std::ostream & o, Fixed const & val)
{
	int i = val.toInt();
	int j = val.getRawBits() - i;
	 
	o << i << "." << j;
	return (o);
}
