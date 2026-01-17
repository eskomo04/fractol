/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 05:04:31 by eskomo            #+#    #+#             */
/*   Updated: 2026/01/17 02:48:11 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_mandelbrot(t_fractal *fract)
{
	fract->fractal_name = "Mandelbrot";
	fract->min_real = -2.0;
	fract->max_real = 1.0;
	fract->min_imag = -1.5;
	fract->max_imag = 1.5;
	fract->max_iter = 100;
}

void	init_julia(t_fractal *fract, double real, double imag)
{
	fract->fractal_name = "Julia";
	fract->min_real = -2.0;
	fract->max_real = 2.0;
	fract->min_imag = -2.0;
	fract->max_imag = 2.0;
	fract->max_iter = 100;
	fract->julia_c.real = real;
	fract->julia_c.imagainary = imag;
}

void	init_mlx(t_fractal *mlx)
{
	mlx->connection = mlx_init();
	if (!mlx->connection)
	{
		ft_printf("Error: MLX initialization failed.\n");
		exit(EXIT_FAILURE);
	}
	mlx->window = mlx_new_window(mlx->connection, WIDTH, HEIGHT, mlx->fractal_name);
	if (!mlx->window)
	{
		mlx_destroy_display(mlx->connection);
		free(mlx->connection);
		ft_printf("Error: Window creation failed.\n");
		exit(EXIT_FAILURE);
	}
	mlx->img.img_ptr = mlx_new_image(mlx->connection, WIDTH, HEIGHT);
	if (!mlx->img.img_ptr)
	{
		mlx_destroy_window(mlx->connection, mlx->window);
		mlx_destroy_display(mlx->connection);
		free(mlx->connection);
		ft_printf("Error: Image creation failed.\n");
		exit(EXIT_FAILURE);
	}
	mlx->img.pixels = mlx_get_data_addr(mlx->img.img_ptr,
			&mlx->img.bpp, &mlx->img.line_len, &mlx->img.endian);
}
