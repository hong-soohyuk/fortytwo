/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:58:11 by soohong           #+#    #+#             */
/*   Updated: 2023/03/08 15:52:06 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	exit_hook(void)
{
	exit(0);
	return (0);
}

void	throw_error(t_mlx *mlx)
{
	ft_putstr_fd("\033[31mError : ", 2);
	ft_putstr_fd(strerror(22), 2);
	ft_putstr_fd("\n\033[0m", 2);
	ft_putendl_fd("\033[1;35mex1) ./fractol Mandelbrot\033[0m", 1);
	ft_putendl_fd("\033[1;35mex2) ./fractol Julia\033[0m", 1);
	ft_putendl_fd("\033[1;35mex3) ./fractol Tricorn\033[0m", 1);
	if (mlx)
		free(mlx);
	exit(2);
}
