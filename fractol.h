/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: essiakomo <essiakomo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 02:43:28 by eskomo            #+#    #+#             */
/*   Updated: 2026/01/16 23:19:13 by essiakomo        ###   ########.fr       */
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
# include "../minilibx-linux/mlx.h"

# define WIDTH 1000
# define HEIGHT 1000

// Add missing constants:
# define KEY_ESC 53           // For Linux 65307(might be 53 for macOS)
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define MAX_ITERATIONS 100
// Structures for complex numbers
typedef struct s_complex
{
	double	real;
	double	imagainary;
}				t_complex;

// Structures for image data
typedef struct s_img
{
	void	*img_ptr;
	char	*pixels;      // Pixel data (image buffer)
	int		bpp;          // Bits per pixel
	int		line_len;     // Bytes per line
	int		endian;
}			t_img;

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









//main,c

//events.c
int		close_handler(t_fractal *fract);
int		key_handler(int keycode, t_fractal *fract);
void	zoom_fractal(t_fractal *fractal, int mouse_x, int mouse_y, double zoom_factor);
int		mouse_handler(int button, int x, int y, t_fractal *fract);
//fractal.c
int		julia_iterate(t_complex c, t_complex z, int max_iter);
int		mandelbrot_iterate(t_complex c, int max_iter);
//fractol.c
int	julia_iterate(t_complex z, t_complex c, int max_iter);
int	mandelbrot_iterate(t_complex c, int max_iter);
//init.c
void	init_mandelbrot(t_fractal *fract);
void	init_julia(t_fractal *fract, double real, double imaginary);
void	init_mlx(t_mlx *mlx);
//math_utili.c
double	ft_atod(const char *str);
t_complex	ft_square_complex(t_complex z);
t_complex	ft_add_complex(t_complex a, t_complex b);
//render.c
void	render_fractal(t_fractal *fract);
void	put_pixel(t_img *img, int x, int y, int color);
#endif