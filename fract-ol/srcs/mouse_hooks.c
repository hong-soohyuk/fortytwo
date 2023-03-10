/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:20:01 by soohong           #+#    #+#             */
/*   Updated: 2023/03/10 13:30:23 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	zoom_in(int x, int y, t_mlx *mlx)
{
	double	ratio;
	double	move_x;
	double	move_y;

	move_x = (double)x * (double)((mlx->width_end - mlx->width_start)
			/ (double)WIDTH) + (double)mlx->width_start;
	move_y = (double)y * (double)((mlx->height_end - mlx->height_start)
			/ (double)HEIGHT) + (double)mlx->height_start;
	ratio = 0.9f;
	mlx->zoom *= ratio;
	mlx->width_end = mlx->width_end * ratio + move_x * (1 - ratio);
	mlx->width_start = mlx->width_start * ratio + move_x * (1 - ratio);
	mlx->height_end = mlx->height_end * ratio + move_y * (1 - ratio);
	mlx->height_start = mlx->height_start * ratio + move_y * (1 - ratio);
	return (0);
}

static int	zoom_out(int x, int y, t_mlx *mlx)
{
	double	ratio;
	double	move_x;
	double	move_y;

	if (mlx->zoom > 2)
		return (0);
	move_x = (double)x * (double)((mlx->width_end - mlx->width_start)
			/ (double)WIDTH) + mlx->width_start;
	move_y = (double)y * ((double)(mlx->height_end - mlx->height_start)
			/ (double)HEIGHT) + mlx->height_start;
	ratio = 1.1f;
	mlx->zoom *= ratio;
	mlx->width_end = mlx->width_end * ratio + move_x * (1 - ratio);
	mlx->width_start = mlx->width_start * ratio + move_x * (1 - ratio);
	mlx->height_end = mlx->height_end * ratio + move_y * (1 - ratio);
	mlx->height_start = mlx->height_start * ratio + move_y * (1 - ratio);
	return (0);
}

int	julia_mouse(int x, int y, t_mlx *mlx)
{
	double	new_real;
	double	new_imaginary;

	if (mlx->julia_active)
	{
		new_real = find_real(x, -1, 1);
		new_imaginary = find_imaginary(y, -1, 1);
		mlx->c_real = new_real;
		mlx->c_imag = new_imaginary;
		pixel_loop(mlx);
	}
	return (0);
}

int	mouse_zoom_hook(int mousecode, int x, int y, t_mlx *mlx)
{
	if (mousecode == 4)
		zoom_in(x, y, mlx);
	else if (mousecode == 5)
		zoom_out(x, y, mlx);
	pixel_loop(mlx);
	return (0);
}
