/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:55:04 by soohong           #+#    #+#             */
/*   Updated: 2023/02/23 21:33:49 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "../libmlx/mlx.h"
# include "../libft/includes/libft.h"


# define TITLE		"fract-ol"
# define HEIGHT		800
# define WIDTH		800
# define OFFSET_X	400
# define OFFSET_Y	400
# define MAX_ITER	256
# define MANDELBROT	"Mandelbrot"
# define JULIA		"Juila"

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	void	*image;
	char	*address;
	int		bits_per_pixel;
	int		sizeline;
	int		endian;
	double	scale;
}	t_mlx;

int		mouse_hook(int mousecode, int x, int y, t_mlx *mlx);
int		key_hook(int keycode, t_mlx *mlx);
int		exit_hook();
int		get_color(int n);
void	mandelbrot(t_mlx *mlx);
void	mlx_pix_put(t_mlx *mlx, int x, int y, int color);

#endif