/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:20:01 by soohong           #+#    #+#             */
/*   Updated: 2023/02/21 20:23:53 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse_hook(int mousecode, t_mlx *mlx)
{
	(void)mlx;
	if (mousecode == 4)
		ft_putstr_fd("scroll up", 1);
	else if (mousecode == 5)
		ft_putstr_fd("scroll down", 1);
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

int	exit_hook()
{
	exit(0);
}
