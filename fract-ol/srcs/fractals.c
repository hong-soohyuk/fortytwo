/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:22:51 by soohong           #+#    #+#             */
/*   Updated: 2023/03/27 19:24:09 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	find_real(double x, double width_start, double width_end)
{
	return (width_start + (width_end - width_start) * (x / WIDTH));
}

double	find_imaginary(double y, double height_start, double height_end)
{
	return (height_start + (height_end - height_start) * (y / HEIGHT));
}

int	mandelbrot(t_mlx *mlx, int x, int y)
{
	t_complex	p;
	t_complex	s;
	double		temp;
	int			i;

	p.real = 0;
	p.imaginary = 0;
	s.real = find_real(x, mlx->width_start, mlx->width_end);
	s.imaginary = find_imaginary(y, mlx->height_start, mlx->height_end);
	i = 0;
	while ((p.real * p.real) + (p.imaginary * p.imaginary) <= 4
		&& i < mlx->max_iter)
	{
		temp = p.real * p.real - p.imaginary * p.imaginary + s.real;
		p.imaginary = 2.0f * p.real * p.imaginary + s.imaginary;
		p.real = temp;
		i++;
	}
	return (i);
}

int	julia(t_mlx *mlx, int x, int y)
{
	double	real;
	double	imaginary;
	double	x_temp;
	int		i;

	i = 0;
	real = find_real(x, mlx->width_start, mlx->width_end);
	imaginary = find_imaginary(y, mlx->height_start, mlx->height_end);
	while (i < mlx->max_iter && (real * real + imaginary * imaginary) <= 4)
	{
		x_temp = (real * real - imaginary * imaginary) + mlx->c_real;
		imaginary = 2.0f * real * imaginary + mlx->c_imag;
		real = x_temp;
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

	s.real = find_real(x, mlx->width_start, mlx->width_end);
	s.imaginary = find_imaginary(y, mlx->height_start, mlx->height_end);
	p.real = s.real;
	p.imaginary = s.imaginary;
	i = 0;
	while ((p.real * p.real) + (p.imaginary * p.imaginary) <= 4
		&& i < mlx->max_iter)
	{
		temp = p.real * p.real - p.imaginary * p.imaginary + s.real;
		p.imaginary = -2.0f * p.real * p.imaginary + s.imaginary;
		p.real = temp;
		i++;
	}
	return (i);
}
