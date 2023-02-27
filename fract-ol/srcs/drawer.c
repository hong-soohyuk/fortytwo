/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:33:40 by soohong           #+#    #+#             */
/*   Updated: 2023/02/27 20:53:46 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	mlx_pix_put(t_mlx *mlx, int x, int y, unsigned int color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	*(int *)(mlx->address + ((x + y * WIDTH) * mlx->bits_per_pixel)) = color;
}

void	pixel_loop(t_mlx *mlx)
{
	int	height;
	int	width;

	mlx_clear_window(mlx->mlx_ptr, mlx->window_ptr);
	height = 0;
	while (height < HEIGHT)
	{
		width = 0;
		while (width < WIDTH)
		{
			mlx_pix_put(mlx, width, height,
				set_color(mlx, mlx->fractal_function(mlx, width, height)));
			++width;
		}
		++height;
	}
	mlx_put_image_to_window(mlx->mlx_ptr,
		mlx->window_ptr, mlx->image_ptr, 0, 0);
}
