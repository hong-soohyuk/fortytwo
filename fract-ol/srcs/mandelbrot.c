/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:22:51 by soohong           #+#    #+#             */
/*   Updated: 2023/02/23 21:33:53 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	mandelbrot_code(double i, double j, t_mlx *mlx)
{
	double	x;
	double	y;
	double	x0;
	double	y0;
	double	temp;
	int		n;

	x0 = (i - OFFSET_X) * mlx->scale;
	y0 = (OFFSET_Y - j) * mlx->scale;
	x = 0;
	y = 0;
	n = 0;
	while ((x * x) + (y * y) <= 4 && n < MAX_ITER)
	{
		temp = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = temp;
		n++;
	}
	return (n);
}

void	mandelbrot(t_mlx *mlx)
{
	double	i;
	double	j;
	int		n;

	mlx_clear_window(mlx->mlx, mlx->window);
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			n = mandelbrot_code(i, j, mlx);
			if (n == MAX_ITER)
				mlx_pix_put(mlx, i, j, 0x00000000);
			else
				mlx_pix_put(mlx, i, j, get_color(n));
			j++;
		}
		++i;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image, 0, 0);
	return ;
}
