/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 03:47:38 by eskomo            #+#    #+#             */
/*   Updated: 2026/01/15 00:43:44 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_iterate(t_complex c, t_complex z, int max_iter)
{
	int	iter;

	iter = 0;
	while (ft_hypo_to_origin(z) <= 2 && iter < max_iter)
	{
		z = ft_square_complex(z);
		z.real += c.real;
		z.imagainary += c.imagainary;
		iter++;
	}
	return (iter);
}