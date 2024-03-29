/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:22:47 by soohong           #+#    #+#             */
/*   Updated: 2023/03/28 01:07:41 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, TITLE);
	mlx->image_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	mlx->address = mlx_get_data_addr(mlx->image_ptr, &mlx->bits_per_pixel,
			&mlx->sizeline, &mlx->endian);
	mlx->bits_per_pixel /= 8;
	mlx_mouse_hook(mlx->win_ptr, mouse_zoom_hook, &mlx->mlx_ptr);
	mlx_hook(mlx->win_ptr, 2, 0, key_hook, &mlx->mlx_ptr);
	mlx_hook(mlx->win_ptr, 17, 0, exit_hook, &mlx->mlx_ptr);
	mlx_hook(mlx->win_ptr, 6, 0, julia_mouse, &mlx->mlx_ptr);
}

void	default_config(t_mlx *mlx)
{
	mlx->width_start = -2.0f;
	mlx->width_end = 2.0f;
	mlx->height_start = -2.0f;
	mlx->height_end = 2.0f;
	mlx->move_x = 0.0f;
	mlx->move_y = 0.0f;
	mlx->zoom = 1.0f;
	mlx->max_iter = 128;
	mlx->color_set = 0;
	mlx->julia_active = 0;
}

static void	set_fractal_type(int argc, char *argv[], t_mlx *mlx)
{
	if (ft_strcmp(argv[1], MANDELBROT) == 0 && argc == 2)
		mlx->fractal_function = mandelbrot;
	else if (ft_strcmp(argv[1], JULIA) == 0 && argc == 2)
	{
		mlx->fractal_function = julia;
		mlx->c_real = -0.344068f;
		mlx->c_imag = 0.620447f;
	}
	else if (ft_strcmp(argv[1], JULIA) == 0 && argc == 4)
	{
		mlx->fractal_function = julia;
		mlx->c_real = 0.02f * (ft_atoi(argv[2]) % 100);
		mlx->c_imag = 0.02f * (ft_atoi(argv[3]) % 100);
	}
	else if (ft_strcmp(argv[1], TRICORN) == 0 && argc == 2)
		mlx->fractal_function = tricorn;
	else
		mlx->fractal_function = NULL;
}

int	main(int argc, char *argv[])
{
	t_mlx	*mlx;

	if (!(argc == 2 || argc == 4))
		throw_error(NULL);
	mlx = malloc(sizeof(t_mlx));
	set_fractal_type(argc, argv, mlx);
	if (mlx->fractal_function == NULL)
		throw_error(mlx);
	init_mlx(mlx);
	default_config(mlx);
	pixel_loop(mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
