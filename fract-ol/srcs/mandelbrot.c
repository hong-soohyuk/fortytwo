/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:22:51 by soohong           #+#    #+#             */
/*   Updated: 2023/02/23 19:45:10 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot_code(double i, double j)
{
	double	x;
	double	y;
	double	x0;
	double	y0;
	double	temp;
	int		n;

	x0 = (i - OFFSET_X) * 0.01;
	y0 = (OFFSET_Y - j) * 0.01;
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

int	get_color(int n, int base)
{
	return (base / n);
}

void	mandelbrot(t_mlx mlx)
{
	double	i;
	double	j;
	int		n;
	
	mlx_clear_window(mlx.mlx, mlx.window);
	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			n = mandelbrot_code(i, j);
			if (n == MAX_ITER)
				mlx_pix_put(&mlx, i, j, 0x00000000);
			else
				mlx_pix_put(&mlx, i, j, get_color(n, 0x00FFFFFF));
			j++;
		}
		++i;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.image, 0, 0);
	return ;
}
