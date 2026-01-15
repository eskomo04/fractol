/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 05:29:47 by eskomo            #+#    #+#             */
/*   Updated: 2026/01/14 05:30:32 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->pixels + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	render_fractal(t_mlx *mlx, t_fractal *fract)
{
	// Placeholder for rendering logic
	// This function should implement the actual fractal rendering
	// based on the parameters in the t_fractal structure.
}