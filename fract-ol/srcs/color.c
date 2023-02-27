/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:20:01 by soohong           #+#    #+#             */
/*   Updated: 2023/02/27 14:21:16 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

unsigned int	set_color(t_mlx *mlx, int iter)
{
	static int	palettes[3][3] = {{3, 4, 7}, {5, 5, 5}, {30, 80, 40}};

	if (iter == mlx->max_iter)
		return (0x00000000);
	else
		return (
		((iter * iter * palettes[mlx->color_set][0]) % 255) << 16 |
		((iter * iter * palettes[mlx->color_set][1]) % 255) << 8 |
		((iter * iter * palettes[mlx->color_set][2]) % 255));
}
