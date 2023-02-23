/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:55:04 by soohong           #+#    #+#             */
/*   Updated: 2023/02/23 19:27:52 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "../libmlx/mlx.h"
# include "../libft/includes/libft.h"


# define TITLE		"fract-ol"
# define HEIGHT		400
# define WIDTH		400
# define OFFSET_X	200
# define OFFSET_Y	200
# define MAX_ITER	128
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
}	t_mlx;

int		mouse_hook(int mousecode, t_mlx *mlx);
int		key_hook(int keycode, t_mlx *mlx);
int		exit_hook();
int		mandelbrot_code(double i, double j);
void	print_mandelbrot(t_mlx *mlx);
void	mandelbrot(t_mlx mlx);
void	mlx_pix_put(t_mlx *mlx, int x, int y, int color);

#endif