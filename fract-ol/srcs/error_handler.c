/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:58:11 by soohong           #+#    #+#             */
/*   Updated: 2023/02/27 20:59:46 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	exit_hook(void)
{
	exit(0);
	return (0);
}

int	print_options(void)
{
	ft_putendl_fd("Invalid Parameter :)", 1);
	ft_putendl_fd("ex1)	./fractol Mandelbrot", 1);
	ft_putendl_fd("ex2)	./fractol Julia", 1);
	ft_putendl_fd("ex3)	./fractol Tricorn", 1);
	return (0);
}
