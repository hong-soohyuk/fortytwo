/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:20:01 by soohong           #+#    #+#             */
/*   Updated: 2023/03/22 20:25:06 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

unsigned int	set_color(t_mlx *mlx, int iter)
{
	static int	palettes[4][4] = {{255, 5, 5, 5}, {255, 3, 4, 7},
	{10, 6, 4, 8}, {100, 1, 0, 1}};

	if (iter == mlx->max_iter)
		return (0x00000000);
	else
		return (
			((iter * iter * palettes[mlx->color_set][0]) % 255) << 24 |
			((iter * iter * palettes[mlx->color_set][1]) % 255) << 16 |
			((iter * iter * palettes[mlx->color_set][2]) % 255) << 8 |
			((iter * iter * palettes[mlx->color_set][3]) % 255));
}
