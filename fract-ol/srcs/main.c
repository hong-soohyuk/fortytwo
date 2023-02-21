#include "../includes/fractol.h"

int	main(void)
{
	t_mlx mlx;

	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, TITLE);
	mlx.image = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	mlx_loop(mlx.mlx);
	return (0);
}