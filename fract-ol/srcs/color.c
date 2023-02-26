/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:20:01 by soohong           #+#    #+#             */
/*   Updated: 2023/02/26 12:28:15 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_color	get_color(int n, float max_iter)
{
	static int	r[16] = {66, 25, 9, 4, 0, 12, 24, 57, 134, 211,
		241, 248, 255, 204, 153, 106};
	static int	g[16] = {30, 7, 1, 4, 7, 44, 82, 125, 181, 236,
		233, 201, 170, 128, 87, 52};
	static int	b[16] = {15, 26, 47, 73, 100, 138, 177, 209, 229,
		248, 191, 95, 0, 0, 0, 3};
	int			i;
	t_color		color;

	if (n == max_iter)
	{
		color.red = 0;
		color.green = 0;
		color.blue = 0;
	}
	else
	{
		i = n % 16;
		color.red = r[i];
		color.green = g[i];
		color.blue = b[i];
	}
	return (color);
}
