/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:55:04 by soohong           #+#    #+#             */
/*   Updated: 2023/02/26 20:49:46 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "../libmlx/mlx.h"
# include "../libft/includes/libft.h"
# include "mac_keycode.h"


# define TITLE		"fract-ol"
# define WIDTH		1280
# define HEIGHT		720
# define MOTION_MASK (1L<<6)
# define MOTION_NOTIFY	6
// # define OFFSET_X	400
// # define OFFSET_Y	400
// # define MAX_ITER	256
# define MANDELBROT	"Mandelbrot"
# define JULIA		"Julia"

typedef struct	s_rgba
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	a;
}	t_rgba;

typedef union		u_color
{
	int			value;
	t_rgba		rgba;
}					t_color;

typedef struct s_map
{
	long double	min_in;
	long double	min_out;
	long double	max_in;
	long double	max_out;
}	t_map;

typedef struct s_complex
{
	long double	real;
	long double	imaginary;
}	t_complex;

typedef struct		s_palette
{
	uint8_t		count;
	int			cycle;
	int			colors[16];
}					t_palette;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*window_ptr;
	void		*image_ptr;
	char		*address;
	int			bits_per_pixel;
	int			sizeline;
	int			endian;
	int			color_set;
	float		max_iter;
	long double	c_real;
	long double	c_imag;
	long double	min_x;
	long double	max_x;
	long double	min_y;
	long double	max_y;
	long double	center_x;
	long double	center_y;
	long double	zoom;
	long double	move_x;
	long double	move_y;
	long double	start_y;
	long double	end_y;
	int			julia_active;
	int			fractal_selected;
	int			(*fractal_function)(struct s_mlx *mlx, int x, int y);
}	t_mlx;

void	default_config(t_mlx *mlx);
int		mouse_zoom_hook(int mousecode, int x, int y, t_mlx *mlx);
int		key_hook(int keycode, t_mlx *mlx);
int		exit_hook(void);
t_color	set_color(t_mlx *mlx, int iteration);
void	pixel_loop(t_mlx *mlx);
void	next_frame(t_mlx *mlx);
int		mandelbrot(t_mlx *mlx, int x, int y);
int		julia(t_mlx *mlx, int x, int y);
int		julia_mouse(int x, int y, t_mlx *mlx);
t_map	add_param(long double min_in, long double max_in,
	long double min_out, long double max_out);
long double ft_map(long double x, t_map map);

#endif
