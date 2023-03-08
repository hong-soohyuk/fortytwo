/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:55:04 by soohong           #+#    #+#             */
/*   Updated: 2023/03/08 17:14:31 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <string.h>
# include "../libmlx/mlx.h"
# include "../libft/includes/libft.h"
# include "mac_keycode.h"

# define TITLE		"fract-ol"
# define WIDTH		400
# define HEIGHT		400
# define MANDELBROT	"Mandelbrot"
# define JULIA		"Julia"
# define TRICORN	"Tricorn"

typedef struct s_map
{
	double	min_in;
	double	min_out;
	double	max_in;
	double	max_out;
}	t_map;

typedef struct s_complex
{
	double	real;
	double	imaginary;
}	t_complex;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*window_ptr;
	void	*image_ptr;
	char	*address;
	int		bits_per_pixel;
	int		sizeline;
	int		endian;
	int		color_set;
	float	max_iter;
	double	c_real;
	double	c_imag;
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	double	center_x;
	double	center_y;
	double	zoom;
	double	move_x;
	double	move_y;
	double	start_y;
	double	end_y;
	int		julia_active;
	int		fractal_selected;
	int		(*fractal_function)(struct s_mlx *mlx, int x, int y);
}	t_mlx;

void			default_config(t_mlx *mlx);
int				mouse_zoom_hook(int mousecode, int x, int y, t_mlx *mlx);
int				key_hook(int keycode, t_mlx *mlx);
int				exit_hook(void);
unsigned int	set_color(t_mlx *mlx, int iteration);
void			pixel_loop(t_mlx *mlx);
int				mandelbrot(t_mlx *mlx, int x, int y);
int				julia(t_mlx *mlx, int x, int y);
int				tricorn(t_mlx *mlx, int x, int y);
int				julia_mouse(int x, int y, t_mlx *mlx);
t_map			add_param(double min_in, double max_in, double min_out,
					double max_out);
double			ft_map(double x, t_map map);
void			throw_error(t_mlx *mlx);
int				exit_hook(void);

#endif
