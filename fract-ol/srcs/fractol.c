/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:22:47 by soohong           #+#    #+#             */
/*   Updated: 2023/02/23 19:19:06 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_window(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, TITLE);
	mlx->image = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->address = mlx_get_data_addr(mlx->image, &mlx->bits_per_pixel, &mlx->sizeline, &mlx->endian);
	mlx_mouse_hook(mlx->window, mouse_hook, &mlx);
	mlx_key_hook(mlx->window, key_hook, &mlx);
	mlx_hook(mlx->window, 17, 0, exit_hook, &mlx);
}

void	open_window(t_mlx mlx)
{
}

int	main(int argc, char **argv)
{
	t_mlx mlx;
	
	if (argc == 1)
		return (0);
	set_window(&mlx);
	if (ft_strcmp(argv[1], MANDELBROT) == 0)
	{
		if (argc != 2)
			return (0);
		mandelbrot(mlx);
	}
	if (ft_strcmp(argv[1], JULIA) == 0)
	{
		if (argc != 4)
			return (0);
	}
	mlx_loop(mlx.mlx);
	return (0);
}
