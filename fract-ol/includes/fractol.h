/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:55:04 by soohong           #+#    #+#             */
/*   Updated: 2023/02/21 19:02:08 by soohong          ###   ########.fr       */
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
# define MANDELBROT	"Mandelbrot"
# define JULIA		"Juila"

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	void	*image;
	char	*data;
	int		bits_per_pixel;
	int		sizeline;
	int		endian;
}	t_mlx;

typedef struct s_image
{
}	t_image;

#endif
