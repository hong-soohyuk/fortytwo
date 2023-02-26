/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:20:01 by soohong           #+#    #+#             */
/*   Updated: 2023/02/26 13:14:19 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	zoom_in(int x, int y, t_mlx *mlx)
{
	long double	zoom_factor;
	long double	move_x;
	long double	move_y;

	move_x = (long double)x * (long double)((mlx->max_x - mlx->min_x)
		/ (long double)WIDTH) + (long double)mlx->min_x;
	move_y = (long double)y * (long double)((mlx->max_y - mlx->min_y)
		/ (long double)HEIGHT) + (long double)mlx->min_y;
	zoom_factor = 0.9f;
	mlx->zoom *= zoom_factor;
	mlx->max_x = mlx->max_x * zoom_factor + move_x * (1 - zoom_factor);
	mlx->min_x = mlx->min_x * zoom_factor + move_x * (1 - zoom_factor);
	mlx->max_y = mlx->max_y * zoom_factor + move_y * (1 - zoom_factor);
	mlx->min_y = mlx->min_y * zoom_factor + move_y * (1 - zoom_factor);
	return (0);
}

static int	zoom_out(int x, int y, t_mlx *mlx)
{
	long double	zoom_factor;
	long double	move_x;
	long double	move_y;

	if (mlx->zoom > 2)
		return (0);
	move_x = (long double)x * (long double)((mlx->max_x - mlx->min_x)
			/ (long double)WIDTH) + mlx->min_x;
	move_y = (long double)y * ((long double)(mlx->max_y - mlx->min_y)
			/ (long double)HEIGHT) + mlx->min_y;
	zoom_factor = 1.1f;
	mlx->zoom *= zoom_factor;
	mlx->max_x = mlx->max_x * zoom_factor + move_x * (1 - zoom_factor);
	mlx->min_x = mlx->min_x * zoom_factor + move_x * (1 - zoom_factor);
	mlx->max_y = mlx->max_y * zoom_factor + move_y * (1 - zoom_factor);
	mlx->min_y = mlx->min_y * zoom_factor + move_y * (1 - zoom_factor);
	return (0);
}

int julia_mouse(int x, int y, t_mlx *mlx)
{
	long double	new_x;
	long double	new_y;

	if (mlx->julia_active)
	{
		new_x = ft_map(x, add_param(0, WIDTH, -1, 1));
		new_y = ft_map(y, add_param(0, HEIGHT, -1, 1));
		mlx->c_real = new_x;
		mlx->c_imag = new_y;
		next_frame(mlx);
	}
	return (0);
}

int	mouse_zoom_hook(int mousecode, int x, int y, t_mlx *mlx)
{
	if (mousecode == 4)
		zoom_in(x, y, mlx);
	else if (mousecode == 5)
		zoom_out(x, y, mlx);
	next_frame(mlx);
	return (0);
}
