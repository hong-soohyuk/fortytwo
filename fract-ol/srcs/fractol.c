/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:22:47 by soohong           #+#    #+#             */
/*   Updated: 2023/02/23 21:14:49 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	print_options()
{
	ft_putendl_fd("Invalid Parameter :)", 1);
	ft_putendl_fd("ex1)	./fractol Mandelbrot", 1);
	ft_putendl_fd("ex2)	./fractol Juila",1);
	return (0);
}

void	set_window(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, TITLE);
	mlx->image = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->address = mlx_get_data_addr(mlx->image, &mlx->bits_per_pixel, &mlx->sizeline, &mlx->endian);
	mlx->scale = 0.005;
	mlx_hook(mlx->window, 4, 0, mouse_hook, &mlx->mlx);
	mlx_hook(mlx->window, 2, 0, key_hook, &mlx->mlx);
	mlx_hook(mlx->window, 17, 0, exit_hook, &mlx->mlx);
}

int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc == 1)
		return (print_options());
	mlx = malloc(sizeof(t_mlx));
	set_window(mlx);
	if (ft_strcmp(argv[1], MANDELBROT) == 0)
	{
		if (argc != 2)
			return (print_options());
		mandelbrot(mlx);
	}
	if (ft_strcmp(argv[1], JULIA) == 0)
	{
		if (argc != 4)
			return (print_options());
	}
	mlx_loop(mlx->mlx);
	return (0);
}
