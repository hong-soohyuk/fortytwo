/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:55:04 by soohong           #+#    #+#             */
/*   Updated: 2023/02/21 14:27:25 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "../libmlx/mlx.h"
# include "../libft/includes/libft.h"


# define TITLE		"fract-ol"
# define HEIGHT		1080
# define WIDTH		1920
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

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	int		*image;
}	t_mlx;

typedef struct s_image
{
	char	*data;
	int		bits_per_pixel;
	int		sizeline;
	int		endian;
}	t_image;

#endif
