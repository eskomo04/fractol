/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 02:29:29 by eskomo            #+#    #+#             */
/*   Updated: 2026/01/17 04:07:02 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	close_handler(t_fractal *fract)
{
	mlx_destroy_image(fract->connection, fract->img.img_ptr);
	mlx_destroy_window(fract->connection, fract->window);
	mlx_destroy_display(fract->connection);
	free(fract->connection);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_handler(int keycode, t_fractal *fract)
{
	if (keycode == KEY_ESC)
		close_handler(fract);
	return (0);
}

void	zoom_fractal(t_fractal *fractal, int mouse_x,
			int mouse_y, double zoom_factor)
{
	t_complex	mouse_complex;
	double		real_width;
	double		imag_height;
	// double		real_center;
	// double		imag_center;

	mouse_complex = pixel_to_complex(mouse_x, mouse_y, fractal);
	real_width = fractal->max_real - fractal->min_real;
	imag_height = fractal->max_imag - fractal->min_imag;
	real_width *= zoom_factor;
	imag_height *= zoom_factor;
	fractal->min_real = mouse_complex.real - (real_width * mouse_x / WIDTH);
	fractal->max_real = mouse_complex.real + (real_width
			* (WIDTH - mouse_x) / WIDTH);
	fractal->min_imag = mouse_complex.imagainary - (imag_height
			* (HEIGHT - mouse_y) / HEIGHT);
	fractal->max_imag = mouse_complex.imagainary
		+ (imag_height * mouse_y / HEIGHT);
}

int	mouse_handler(int button, int x, int y, t_fractal *fract)
{
	if (button == MOUSE_WHEEL_UP)
	{
		zoom_fractal(fract, x, y, 0.9);
		render_fractal(fract);
	}
	else if (button == MOUSE_WHEEL_DOWN)
	{
		zoom_fractal(fract, x, y, 1.1);
		render_fractal(fract);
	}
	return (0);
}

