/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:20:01 by soohong           #+#    #+#             */
/*   Updated: 2023/02/26 13:01:05 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	int move_camera(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_DOWN)
	{
		mlx->min_y += 0.1 * mlx->zoom;
		mlx->max_y += 0.1 * mlx->zoom;
	}
	if (keycode == KEY_UP)
	{
		mlx->min_y -= 0.1 * mlx->zoom;
		mlx->max_y -= 0.1 * mlx->zoom;
	}
	if (keycode == KEY_RIGHT)
	{
		mlx->min_x += 0.1 * mlx->zoom;
		mlx->max_x += 0.1 * mlx->zoom;
	}
	if (keycode == KEY_LEFT)
	{
		mlx->min_x -= 0.1 * mlx->zoom;
		mlx->max_x -= 0.1 * mlx->zoom;
	}
	next_frame(mlx);
	return (-1);
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
	move_camera(keycode, mlx);
	return (0);
}
