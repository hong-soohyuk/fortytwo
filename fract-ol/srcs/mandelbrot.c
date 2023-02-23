/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:22:51 by soohong           #+#    #+#             */
/*   Updated: 2023/02/23 21:49:46 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	mandelbrot_code(double i, double j, t_mlx *mlx)
{
	t_complex	p;
	t_complex	s;
	double		temp;
	int			n;

	s.real = (i - OFFSET_X) * mlx->scale;
	s.imaginary = (OFFSET_Y - j) * mlx->scale;
	p.real = 0;
	p.imaginary = 0;
	n = 0;
	while ((p.real * p.real) + (p.imaginary * p.imaginary) <= 4 && n < MAX_ITER)
	{
		temp = p.real * p.real - p.imaginary * p.imaginary + s.real;
		p.imaginary = 2 * p.real * p.imaginary + s.imaginary;
		p.real = temp;
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
