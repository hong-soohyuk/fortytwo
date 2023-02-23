/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:20:01 by soohong           #+#    #+#             */
/*   Updated: 2023/02/23 21:35:43 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse_hook(int mousecode, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (mousecode == 4)
		mlx->scale *= 1.1;
	else if (mousecode == 5)
		mlx->scale /= 1.1;
	mandelbrot(mlx);
	return (0);
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->window);
		exit(0);
	}
	return (0);
}

int	get_color(int n)
{
	static int	r[16] = {66, 25, 9, 4, 0, 12, 24, 57, 134, 211,
		241, 248, 255, 204, 153, 106};
	static int	g[16] = {30, 7, 1, 4, 7, 44, 82, 125, 181, 236,
		233, 201, 170, 128, 87, 52};
	static int	b[16] = {15, 26, 47, 73, 100, 138, 177, 209, 229,
		248, 191, 95, 0, 0, 0, 3};
	int			i;

	i = n % 16;
	return ((r[i] << 16) | (g[i] << 8) | b[i]);
}

void	mlx_pix_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->address + (y * mlx->sizeline + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	exit_hook(void)
{
	exit(0);
}
