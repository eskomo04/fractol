



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

void	zoom_fractal(t_fractal *fractal, int mouse_x, int mouse_y, double zoom_factor)
{
	t_complex	mouse_complex;
	double		real_width;
	double		imag_height;
	double		real_center;
	double		imag_center;

	// Step 1: Find the complex number under the mouse BEFORE zoom
	mouse_complex = pixel_to_complex(mouse_x, mouse_y, fractal);

	// Step 2: Calculate current dimensions
	real_width = fractal->max_real - fractal->min_real;
	imag_height = fractal->max_imag - fractal->min_imag;

	// Step 3: Apply zoom by scaling the dimensions
	real_width *= zoom_factor;
	imag_height *= zoom_factor;

	// Step 4: Recenter around the mouse position
	// The mouse should still point to the same complex number after zoom
	fractal->min_real = mouse_complex.real - (real_width * mouse_x / WIDTH);
	fractal->max_real = mouse_complex.real + (real_width * (WIDTH - mouse_x) / WIDTH);
	fractal->min_imag = mouse_complex.imagainary - (imag_height * (HEIGHT - mouse_y) / HEIGHT);
	fractal->max_imag = mouse_complex.imagainary + (imag_height * mouse_y / HEIGHT);
}

int mouse_handler(int button, int x, int y, t_fractal *fract)
{
	//Zoom in
	if (button == MOUSE_WHEEL_UP)
	{
		zoom_fractal(fract, x, y, 0.9); // Zoom in by 10%
		render_fractal(fract);			// Re-render the fractal
	}
	//Zoom out
	else if (button == MOUSE_WHEEL_DOWN)
	{
		zoom_fractal(fract, x, y, 1.1); // Zoom out by 10%
		render_fractal(fract);			// Re-render the fractal
	}
}

