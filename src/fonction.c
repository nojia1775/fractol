#include "../include/mlx.h"
#include "../include/fractol.h"
#include "../include/libft.h"
#include "../include/ft_printf.h"

z_t	fonction_julia(z_t z)
{
	z_t		result;

	result = carre_i(z);
	result.reel -= 1;
	return (result);
}

z_t	carre_i(z_t z)
{
	double	r;
	double	i;

	r = z.reel;
	i = z.imaginaire;
	z.reel = pow(r, 2) + (pow(i, 2) * -1);
	z.imaginaire = 2 * r * i;
	return (z);
}

void    print_i(z_t z)
{
        if (z.imaginaire < 0 && z.imaginaire != -1)
                ft_printf("%d - %di\n", z.reel, -z.imaginaire);
        else if (z.imaginaire > 0 && z.imaginaire != 1)
                ft_printf("%d + %di\n", z.reel, z.imaginaire);
        else if (z.imaginaire == 1)
                ft_printf("%d + i\n", z.reel);
        else if (z.imaginaire == -1)
                ft_printf("%d - i\n", z.reel);
        else if (z.imaginaire == 0)
                ft_printf("%d\n", z.reel);
}
