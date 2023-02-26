/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:33:40 by soohong           #+#    #+#             */
/*   Updated: 2023/02/26 12:33:49 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	mlx_pix_put(t_mlx *mlx, int x, int y, t_color color)
{
	if ((x >= 0 || x <= WIDTH) && (y >= 0 || y <= HEIGHT))
	{
		mlx->address[(x * 4) + (y * WIDTH * 4) + 2] = color.red;
		mlx->address[(x * 4) + (y * WIDTH * 4) + 1] = color.green;
		mlx->address[(x * 4) + (y * WIDTH * 4)] = color.blue; //b
	}
}

void	pixel_loop(t_mlx *mlx)
{
	int	height;
	int	width;

	height = 0;
	while (height < HEIGHT)
	{
		width = 0;
		while (width < WIDTH)
		{
			mlx_pix_put(mlx, width, height,
				get_color(mlx->fractal_function(mlx, width, height), mlx->max_iter));
			++width;
		}
		++height;
	}
}

void	next_frame(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->window_ptr);
	pixel_loop(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->window_ptr, mlx->image_ptr, 0, 0);
}
