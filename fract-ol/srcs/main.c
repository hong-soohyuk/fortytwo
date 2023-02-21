/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:02:54 by soohong           #+#    #+#             */
/*   Updated: 2023/02/21 19:48:58 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdlib.h>

int	mouse_hook(int keycode, t_mlx *mlx)
{
	(void) keycode;
	(void) mlx;
	return (0);
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if(keycode == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->window);
		exit(0);
	}
	return (0);
}

int	my_exit()
{
	exit(0);
	return (0);
}

void	mandelbrot(void)
{
	t_mlx mlx;

	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, TITLE);
	mlx.image = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	mlx_get_data_addr(mlx.image, &mlx.bits_per_pixel, &mlx.sizeline, &mlx.endian);
	//setting
	//print mandel
	mlx_mouse_hook(mlx.window, mouse_hook, &mlx);
	mlx_key_hook(mlx.window, key_hook, &mlx);
	mlx_hook(mlx.window, 17, 0, my_exit, &mlx);
	mlx_loop(mlx.mlx);
	return ;
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (ft_strcmp(argv[1], MANDELBROT) == 0)
	{
		if (argc != 2)
			return (0);
		mandelbrot();
	}
	if (ft_strcmp(argv[1], JULIA) == 0)
	{
		if (argc != 4)
			return (0);
	}
	return (0);
}