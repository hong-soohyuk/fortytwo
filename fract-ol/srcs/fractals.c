/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:22:51 by soohong           #+#    #+#             */
/*   Updated: 2023/02/26 20:33:25 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_map	add_param(long double min_in, long double max_in,
	long double min_out, long double max_out)
{
	t_map map;

	map.min_in = min_in;
	map.max_in = max_in;
	map.min_out = min_out;
	map.max_out = max_out;
	return (map);
}

long double ft_map(long double x, t_map map)
{
	long double	return_val;

	return_val = map.min_out + (map.max_out - map.min_out) * ((x - map.min_in)
	/ (map.max_in - map.min_in));
	return (return_val);
}

int	mandelbrot(t_mlx *mlx, int x, int y)
{
	t_complex	p;
	t_complex	s;
	double		temp;
	int			i;

	p.real = 0;
	p.imaginary = 0;
	s.real = ft_map(x, add_param(0, WIDTH, mlx->min_x, mlx->max_x));
	s.imaginary = ft_map(y, add_param(0, HEIGHT, mlx->min_y, mlx->max_y));
	i = 0;
	while ((p.real * p.real) + (p.imaginary * p.imaginary) <= 4 && i < mlx->max_iter)
	{
		temp = p.real * p.real - p.imaginary * p.imaginary + s.real;
		p.imaginary = 2 * p.real * p.imaginary + s.imaginary;
		p.real = temp;
		i++;
	}
	return (i);
}

int		julia(t_mlx *mlx, int x, int y)
{
	long double mx;
	long double my;
	long double x_temp;
	int			i;

	i = 0;
	mx = ft_map(x, add_param(0, WIDTH, mlx->min_x, mlx->max_x));
	my = ft_map(y, add_param(0, HEIGHT, mlx->min_y, mlx->max_y));
	while (i < mlx->max_iter)
	{
		x_temp = (mx * mx - my * my) + mlx->c_real;
		my = 2.0f * mx * my + mlx->c_imag;
		mx = x_temp;
		if ((mx * mx + my * my) > 4.0f)
			break ;
		i++;
	}
	return (i);
}
