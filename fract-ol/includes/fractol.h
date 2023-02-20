/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:55:04 by soohong           #+#    #+#             */
/*   Updated: 2023/02/20 15:10:38 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "../mlx/mlx.h"
// # include "libft"


# define TITLE		"fract-ol"
# define HEIGHT		800
# define WIDTH		800
# define HELP_COLOR	800

enum	e_fractol
{
	MANDELBROT,
	JULIA,
	PHOENIX,
	BARNSLEY,
	FLAME,
	FLOWERBROT
};

typedef struct s_complex
{
	double	real;
	double	image;
}	t_complex;

typedef struct s_position
{
	int	x;
	int	y;
}t_position;

typedef struct s_colored_vector
{
	double			x;
	double			y;
	unsigned int	color;
}	t_colered_vector;

typedef struct s_image
{
	void	*mlx;
	void	*window;
	int		*image;
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
}	t_image;

#endif
