/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:22:47 by soohong           #+#    #+#             */
/*   Updated: 2023/02/21 20:23:44 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (ft_strcmp(argv[1], MANDELBROT) == 0)
	{
		if (argc != 2)
			return (0);
		mandelbrot();
	}
	if (ft_strcmp(argv[1], JULIA) == 0)
	{
		if (argc != 4)
			return (0);
	}
	return (0);
}
