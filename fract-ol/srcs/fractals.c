/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:22:51 by soohong           #+#    #+#             */
/*   Updated: 2023/03/08 16:01:32 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_map	add_param(double min_in, double max_in, double min_out, double max_out)
{
	t_map	map;

	map.min_in = min_in;
	map.max_in = max_in;
	map.min_out = min_out;
	map.max_out = max_out;
	return (map);
}

double	ft_map(double x, t_map map)
{
	return (map.min_out + (map.max_out - map.min_out) * ((x - map.min_in)
		/ (map.max_in - map.min_in)));
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
	while ((p.real * p.real) + (p.imaginary * p.imaginary) <= 4
		&& i < mlx->max_iter)
	{
		temp = p.real * p.real - p.imaginary * p.imaginary + s.real;
		p.imaginary = 2 * p.real * p.imaginary + s.imaginary;
		p.real = temp;
		i++;
	}
	return (i);
}

int	julia(t_mlx *mlx, int x, int y)
{
	double	mx;
	double	my;
	double	x_temp;
	int		i;

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

int	tricorn(t_mlx *mlx, int x, int y)
{
	t_complex	p;
	t_complex	s;
	double		temp;
	int			i;

	s.real = ft_map(x, add_param(0, WIDTH, mlx->min_x, mlx->max_x));
	s.imaginary = ft_map(y, add_param(0, HEIGHT, mlx->min_y, mlx->max_y));
	p.real = s.real;
	p.imaginary = s.imaginary;
	i = 0;
	while ((p.real * p.real) + (p.imaginary * p.imaginary) <= 4
		&& i < mlx->max_iter)
	{
		temp = p.real * p.real - p.imaginary * p.imaginary + s.real;
		p.imaginary = -2 * p.real * p.imaginary + s.imaginary;
		p.real = temp;
		i++;
	}
	return (i);
}
