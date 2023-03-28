/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:20:01 by soohong           #+#    #+#             */
/*   Updated: 2023/03/28 01:11:08 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

unsigned int	set_color(t_mlx *mlx, int iter)
{
	static int	palettes[4][3] = {{5, 5, 5}, {3, 4, 7}, {3, 2, 4}, {1, 1, 2}};

	if (iter == mlx->max_iter)
		return (0x00000000);
	else
		return (
			((iter * iter * palettes[mlx->color_set][0]) % 255) << 16 |
			((iter * iter * palettes[mlx->color_set][1]) % 255) << 8 |
			((iter * iter * palettes[mlx->color_set][2]) % 255));
}
