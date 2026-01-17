/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 02:46:36 by eskomo            #+#    #+#             */
/*   Updated: 2026/01/17 03:53:02 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	create_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	get_color_psychedelic(int iterations, int max_iter, int shift)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iterations == max_iter)
		return (0x000000);
	t = (double)iterations / (double)max_iter;
	t = t + (shift / 100.0);
	r = (int)(sin(0.016 * iterations + 0 + shift) * 127 + 128);
	g = (int)(sin(0.013 * iterations + 2 + shift) * 127 + 128);
	b = (int)(sin(0.010 * iterations + 4 + shift) * 127 + 128);

	return (create_color(r, g, b));
}

int	get_color(int iterations, int max_iter, int shift)
{
	return (get_color_psychedelic(iterations, max_iter, shift));
}
