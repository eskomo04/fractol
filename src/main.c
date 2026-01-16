/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: essiakomo <essiakomo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 03:09:09 by eskomo            #+#    #+#             */
/*   Updated: 2026/01/16 23:15:52 by essiakomo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	input_instructions(void)
{
	write(1, "Input only as follows:\n", 26);
	write(1, "./fractol Mandelbrot\n", 22);
	write(1, "./fractol Julia <real part> <imaginary part>\n", 45);
	write(1, "Example for Julia set: ./fractol Julia -0.7 0.27015\n", 52);
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
			fract.julia_c.real = ft_atod(argv[2]);
			fract.julia_c.imaginary = ft_atod(argv[3]);
			init_julia(&fract, fract.julia_c.real, fract.julia_c.imaginary);
		}
		else if (argc == 2)
			init_mandelbrot(&fract);
		init_mlx(&fract);
		render_fractal(&fract);
		mlx_hook(fract.window, 2, 1L<<0, key_handler, &fract);
		mlx_hook(fract.window, 4, 1L<<2, mouse_handler, &fract);
		mlx_hook(fract.window, 17, 0, close_handler, &fract);
		mlx_loop(fract.connection);
		return (0);
	}
	else
	{
		input_instructions();
		exit(EXIT_FAILURE);
	}
}
