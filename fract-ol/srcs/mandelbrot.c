/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:22:51 by soohong           #+#    #+#             */
/*   Updated: 2023/02/21 20:22:52 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdlib.h>

int	mandelbrot_code(double i, double j, t_mlx *mlx)
{
	t_complex	z;
	t_complex	c;
	double		temp;
	int			n;

	z.real = 0;
	z.image = 0;
	// c.real = mlx.
	return (0);
}

void	print_mandelbrot(t_mlx *mlx)
{
	double	i;
	double	j;
	int		n;
	
	mlx_clear_window(mlx->mlx, mlx->window);
	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			n = mandelbrot_code(i, j, mlx);
			// if (n == N_MAX)
			mlx_pixel_put(mlx->mlx, mlx->window, i, j, 0x00000000);
			//else
			// mlx_pixel_put(mlx->mlx, mlx->window, i, j, 0x00000000);
			j++;
		}
		++i;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image, 0, 0);
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
	mlx_hook(mlx.window, 17, 0, exit_hook, &mlx);
	mlx_loop(mlx.mlx);
	return ;
}
