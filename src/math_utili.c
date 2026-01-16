/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utili.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: essiakomo <essiakomo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 00:24:41 by eskomo            #+#    #+#             */
/*   Updated: 2026/01/16 23:19:00 by essiakomo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

/*
 * ft_atod - Converts a string to a double.
 * @param str The string to convert.
 * @return The converted double value.
 * Handles optional leading whitespace, '+'/'-' signs, integer and fractional parts.
 */

double	ft_atod(const char *str)
{
	double	integer_part;
	double	fractional_part;
	double	power;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	power = 1;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\n'))
		++str;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -sign;
	while (*str != '.' && *str)
		integer_part = (integer_part * 10) + (*str++ - '0');
	if (*str == '.')
		++str;
	while (*str)
	{
		power /= 10;
		fractional_part = fractional_part + (*str++ - '0') * power;
	}
	return (sign * (integer_part + fractional_part));
}

/**
 * ft_square_complex - Squares a complex number.
 
 */
t_complex	ft_square_complex(t_complex z)
{
	t_complex	result;

	result.real = z.real * z.real - z.imagainary * z.imagainary;
	result.imagainary = 2 * z.real * z.imagainary;
	return (result);
}

/**
 * ft_add_complex - Adds two complex numbers.
 */
t_complex	ft_add_complex(t_complex a, t_complex b)
{
	t_complex	result;

	result.real = a.real + b.real;
	result.imagainary = a.imagainary + b.imagainary;
	return (result);
}

