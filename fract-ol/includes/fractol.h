/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:55:04 by soohong           #+#    #+#             */
/*   Updated: 2023/02/21 20:22:04 by soohong          ###   ########.fr       */
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

typedef struct s_complex
{
	double	real;
	double	image;
}	t_complex;

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

int		mouse_hook(int mousecode, t_mlx *mlx);
int		key_hook(int keycode, t_mlx *mlx);
int		exit_hook();
int		mandelbrot_code(double i, double j, t_mlx *mlx);
void	print_mandelbrot(t_mlx *mlx);
void	mandelbrot(void);