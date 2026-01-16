/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: essiakomo <essiakomo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 03:47:38 by eskomo            #+#    #+#             */
/*   Updated: 2026/01/16 23:07:07 by essiakomo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

/*
** JULIA SET ITERATION
**
** Similar to Mandelbrot, but with a key difference:
**   - c is a CONSTANT (the parameter you pass from command line)
**   - z STARTS at the pixel position (not at 0)
**   - Repeatedly calculate: z = z² + c
**
** Different values of c create completely different Julia sets!
**
** Popular c values to try:
**   c = -0.7 + 0.27i   (creates a swirly pattern)
**   c = -0.4 + 0.6i    (creates a dendrite/tree-like fractal)
**   c = 0.285 + 0.01i  (creates a dragon-like shape)
**   c = -0.8 + 0.156i  (creates a rabbit-like shape)
**
** Parameters:
**   z: Starting point (the pixel position in complex plane)
**   c: The Julia set constant (from command line arguments)
**   max_iter: Maximum iterations
**
** Returns:
**   Number of iterations before escape (or max_iter)
*/
int	julia_iterate(t_complex z, t_complex c, int max_iter)
{
	int		i;
	double	temp_real;

	// Note: z already starts at the pixel position
	// (passed as parameter, not initialized to 0)

	i = 0;
	while (i < max_iter)
	{
		// Check if escaped (|z|² > 4)
		if (z.real * z.real + z.imagainary * z.imagainary > 4.0)
			return (i);

		// Calculate z² + c
		temp_real = z.real * z.real - z.imagainary * z.imagainary;
		z.imagainary = 2.0 * z.real * z.imagainary;
		z.real = temp_real;

		// Add the constant c
		z.real += c.real;
		z.imagainary += c.imagainary;

		i++;
	}
	return (max_iter);
}

int	mandelbrot_iterate(t_complex c, int max_iter)
{
	t_complex	z;
	int			i;
	double		temp_real;

	// Start with z = 0 + 0i
	z.real = 0.0;
	z.imaginary = 0.0;
	i = 0;
	while (i < max_iter)
	{
		// Check if z has escaped (|z| > 2)
		// We use |z|² > 4 to avoid expensive sqrt() calculation
		// |z|² = real² + imaginary²
		if (z.real * z.real + z.imaginary * z.imaginary > 4.0)
			return (i); // Escaped after i iterations

		// Calculate z² + c
		// z² = (a + bi)² = (a² - b²) + (2ab)i
		temp_real = z.real * z.real - z.imaginary * z.imaginary;
		z.imaginary = 2.0 * z.real * z.imaginary;
		z.real = temp_real;

		// Add c to get z² + c
		z.real += c.real;
		z.imaginary += c.imaginary;
		i++;
	}
	// Didn't escape - this point is IN the Mandelbrot set
	return (max_iter);
}
