/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:20:01 by soohong           #+#    #+#             */
/*   Updated: 2023/03/10 13:25:18 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	change_color_set(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_1)
		mlx->color_set = 0;
	if (keycode == KEY_2)
		mlx->color_set = 1;
	if (keycode == KEY_3)
		mlx->color_set = 2;
	if (keycode == KEY_4)
		mlx->color_set = 3;
	pixel_loop(mlx);
}

static void	move_camera(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_DOWN)
	{
		mlx->height_start += 0.05 * mlx->zoom;
		mlx->height_end += 0.05 * mlx->zoom;
	}
	if (keycode == KEY_UP)
	{
		mlx->height_start -= 0.05 * mlx->zoom;
		mlx->height_end -= 0.05 * mlx->zoom;
	}
	if (keycode == KEY_RIGHT)
	{
		mlx->width_start += 0.05 * mlx->zoom;
		mlx->width_end += 0.05 * mlx->zoom;
	}
	if (keycode == KEY_LEFT)
	{
		mlx->width_start -= 0.05 * mlx->zoom;
		mlx->width_end -= 0.05 * mlx->zoom;
	}
	pixel_loop(mlx);
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESCAPE)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->window_ptr);
		exit(0);
	}
	if (keycode == KEY_BACKSPACE)
	{
		default_config(mlx);
		pixel_loop(mlx);
	}
	if (mlx->fractal_function == julia && keycode == KEY_J)
		mlx->julia_active = !mlx->julia_active;
	if (keycode == KEY_DOWN || keycode == KEY_UP
		|| keycode == KEY_RIGHT || keycode == KEY_LEFT)
		move_camera(keycode, mlx);
	if (keycode == KEY_1 || keycode == KEY_2
		|| keycode == KEY_3 || keycode == KEY_4)
		change_color_set(keycode, mlx);
	return (0);
}
