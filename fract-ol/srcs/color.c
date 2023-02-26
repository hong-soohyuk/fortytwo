/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:20:01 by soohong           #+#    #+#             */
/*   Updated: 2023/02/26 20:25:01 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	color_set_rgb(t_color *color, int color_set, int iteration)
{
	if (color_set == 0)
	{
		color->red = (iteration * 4) % 255;
		color->green = (iteration * 4) % 255;
		color->blue = (iteration * 8) % 255;
	}
	else if (color_set == 1)
	{
		color->red = (iteration * 5) % 255;
		color->green = (iteration * 5) % 255;
		color->blue = (iteration * 5) % 255;
	}
}

t_color	set_color(t_mlx *mlx, int iteration)
{
	t_color		color;

	if (iteration == mlx->max_iter)
	{
		color.red = 0;
		color.green = 0;
		color.blue = 0;
	}
	else
		color_set_rgb(&color, mlx->color_set, iteration);
	return (color);
}
