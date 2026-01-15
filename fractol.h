/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 02:43:28 by eskomo            #+#    #+#             */
/*   Updated: 2026/01/15 01:20:40 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"


# define WIDTH 1000
# define HEIGHT 1000

// Structures for complex numbers
typedef struct s_complex
{
	double	real;
	double	imagainary;
}				t_complex;
// Structures for fractal parameters
typedef struct s_fractal
{
//MLX parameters
	void	*connection;     // MLX connection
	void	*window;     // Window pointer
	t_img	img;          // The image we're going to draw

	char	*fractal_name;

	double		min_real;	// Left boundary
	double		max_real;	// Right boundary
	double		min_imag;	// Bottom boundary
	double		max_imag;	// Top boundary

	int			max_iter;

	t_complex	julia_c;

	double		zoom_fact;
	double		offset_x;
	double		offset_y;
}				t_fractal;

// Structures for image data
typedef struct s_img
{
	void	*img_ptr;
	char	*pixels;      // Pixel data (image buffer)
	int		bpp;          // Bits per pixel
	int		line_len;     // Bytes per line
	int		endian;
}			t_img;

// structures for MLX
typedef struct s_mlx
{

}			t_mlx;




//main,c
void	input_instructions(void);
#endif