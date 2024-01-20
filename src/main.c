#include "../include/mlx.h"
#include "../include/fractol.h"
#include "../include/libft.h"
#include "../include/ft_printf.h"

#define WIDTH 1000
#define LENGTH 500

void	aff_fractal(data_t data); 
int		no_event(void *data);
int		h_keypress(int keycode, data_t *data);
int		close_win(void *data);

int		main(void)
{
	data_t	data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, LENGTH, "FRACTOL");
	mlx_key_hook(data.win_ptr, h_keypress, &data);
	mlx_hook(data.win_ptr, 17, 0, close_win, &data);
	aff_fractal(data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}

void	aff_fractal(data_t data)
{
	double	i;
	double	j;
	int		count;
	z_t		z;

	i = -2;
	while (i < 2)
	{
		j = -5;
		while (j < 5)
		{
			z.reel = i;
			z.imaginaire = j;
			count = 0;
			while (count++ < 10)
			{
				z = fonction_julia(z);
				if (fabs(z.reel) > 2 || fabs(z.imaginaire) > 2)
					break ;

			}
			if (fabs(z.reel) > 2 || fabs(z.imaginaire) > 2)
				mlx_pixel_put(data.mlx_ptr, data.win_ptr, i * 200 + WIDTH / 2, j * 200 + LENGTH / 2, 6911 + count * 10);
			j += 0.005;

		}
		i += 0.005;
	}
}

int	h_keypress(int keycode, data_t *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	return (0);
}

int	close_win(void *data)
{
	data_t	*param;

	param = (data_t *)data;
	mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	exit(0);
	return (0);
}
