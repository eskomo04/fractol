/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: essiakomo <essiakomo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 05:29:47 by eskomo            #+#    #+#             */
/*   Updated: 2026/01/16 23:20:18 by essiakomo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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
            // 1. Convert pixel to complex number
            c = pixel_to_complex(x, y, fract);
            // 2. Calculate iterations
            if (!ft_strncmp(fract->fractal_name, "Mandelbrot", 11))
                iterations = mandelbrot_iterate(c, fract->max_iter);
            else
                iterations = julia_iterate(c, fract->julia_c, fract->max_iter);
            // 3. Get color
            color = get_color(iterations, fract->max_iter, 0);
            // 4. Put pixel
            put_pixel(&fract->img, x, y, color);
            x++;
        }
        y++;
    }
        mlx_put_image_to_window(fract->connection, fract->window, 
                            fract->img.img_ptr, 0, 0);
}
