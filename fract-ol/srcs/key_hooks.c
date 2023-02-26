/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:20:01 by soohong           #+#    #+#             */
/*   Updated: 2023/02/26 20:28:42 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	void change_color_set(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_1)
		mlx->color_set = 0;
	if (keycode == KEY_2)
		mlx->color_set = 1;
	if (keycode == KEY_3)
		mlx->color_set = 2;
	if (keycode == KEY_4)
		mlx->color_set = 3;
	next_frame(mlx);
}

static	void move_camera(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_DOWN)
	{
		mlx->min_y += 0.05 * mlx->zoom;
		mlx->max_y += 0.05 * mlx->zoom;
	}
	if (keycode == KEY_UP)
	{
		mlx->min_y -= 0.05 * mlx->zoom;
		mlx->max_y -= 0.05 * mlx->zoom;
	}
	if (keycode == KEY_RIGHT)
	{
		mlx->min_x += 0.05 * mlx->zoom;
		mlx->max_x += 0.05 * mlx->zoom;
	}
	if (keycode == KEY_LEFT)
	{
		mlx->min_x -= 0.05 * mlx->zoom;
		mlx->max_x -= 0.05 * mlx->zoom;
	}
	next_frame(mlx);
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
		next_frame(mlx);
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
