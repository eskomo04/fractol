/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 05:29:47 by eskomo            #+#    #+#             */
/*   Updated: 2026/01/17 03:28:16 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_complex	pixel_to_complex(int x, int y, t_fractal *fractal)
{
	t_complex	c;
	double		real_range;
	double		imag_range;

	real_range = fractal->max_real - fractal->min_real;
	imag_range = fractal->max_imag - fractal->min_imag;
	c.real = fractal->min_real + ((double)x / WIDTH) * real_range;
	c.imagainary = fractal->max_imag - ((double)y / HEIGHT) * imag_range;
	return (c);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->pixels + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	render_fractal(t_fractal *fract)
{
	int			x;
	int			y;
	t_complex	c;
	int			iterations;
	int			color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c = pixel_to_complex(x, y, fract);
			if (!ft_strncmp(fract->fractal_name, "Mandelbrot", 10))
				iterations = mandelbrot_iterate(c, fract->max_iter);
			else
				iterations = julia_iterate(c, fract->julia_c, fract->max_iter);
			color = get_color(iterations, fract->max_iter, 0);
			put_pixel(&fract->img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->connection, fract->window,
		fract->img.img_ptr, 0, 0);
}
