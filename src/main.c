/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 03:09:09 by eskomo            #+#    #+#             */
/*   Updated: 2026/01/14 05:24:07 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	input_instructions(void)
{
	ft_printf("Input only as follows:\n");
	ft_printf("./fractol Mandelbrot\n");
	ft_printf("./fractol Julia <real part> <imaginary part>\n");
	ft_printf("Example for Julia set: ./fractol Julia -0.7 0.27015\n");
}

int	main(int argc, char **argv)
{
	t_fractal	fract;

	if ((argc == 2 && !ft_strncmp(argv[1], "Mandelbrot", 11))
		|| (argc == 4 && !ft_strncmp(argv[1], "Julia", 6)))
	{
		fract.fractal_name = argv[1];
		if (argc == 4)
		{
			fract.julia_real = ft_atod(argv[2]);
			fract.julia_imagainary = ft_atod(argv[3]);
		}
		// Call the appropriate fractal function here
		return (0);
	}
	else
	{
		put_instructions();
		exit(EXIT_FAILURE);
	}
}
