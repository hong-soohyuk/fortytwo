/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:22:47 by soohong           #+#    #+#             */
/*   Updated: 2023/02/26 13:12:22 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	exit_hook(void)
{
	exit(0);
}

int	print_options()
{
	ft_putendl_fd("Invalid Parameter :)", 1);
	ft_putendl_fd("ex1)	./fractol Mandelbrot", 1);
	ft_putendl_fd("ex2)	./fractol Julia",1);
	return (0);
}

static void	init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->window_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, TITLE);
	mlx->image_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	mlx->address = mlx_get_data_addr(mlx->image_ptr, &mlx->bits_per_pixel,
			&mlx->sizeline, &mlx->endian);
	mlx_mouse_hook(mlx->window_ptr, mouse_zoom_hook, &mlx->mlx_ptr);
	mlx_hook(mlx->window_ptr, 2, 0, key_hook, &mlx->mlx_ptr);
	mlx_hook(mlx->window_ptr, 17, 0, exit_hook, &mlx->mlx_ptr);
	mlx_hook(mlx->window_ptr, MOTION_NOTIFY, MOTION_MASK, julia_mouse, &mlx->mlx_ptr);
}

void	default_config(t_mlx *mlx)
{
	mlx->min_x = -1.5f;
	mlx->max_x = 1.0f;
	mlx->min_y = -1.0f;
	mlx->max_y = 1.0f;
	mlx->move_x = 0.0f;
	mlx->move_y = 0.0f;
	mlx->zoom = 1.0f;
	mlx->max_iter = 100;
	mlx->julia_active = 0;
}

static void	arguments_handler(char *string, t_mlx *mlx)
{
	if (ft_strcmp(string, MANDELBROT) == 0)
		mlx->fractal_function = mandelbrot;
	else if (ft_strcmp(string, JULIA) == 0)
	{
		mlx->fractal_function = julia;
		mlx->c_real = -0.70176f;
		mlx->c_imag = -0.3842f;
	}
	else if (ft_strcmp(string, "temp") == 0)
		mlx->fractal_function = mandelbrot;
	else
		mlx->fractal_function = NULL;
}

int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc == 1)
		return (print_options());
	mlx = malloc(sizeof(t_mlx));
	arguments_handler(argv[1], mlx);
	if (mlx->fractal_function == NULL)
		return (print_options());
	init_mlx(mlx);
	default_config(mlx);
	pixel_loop(mlx);
	next_frame(mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
