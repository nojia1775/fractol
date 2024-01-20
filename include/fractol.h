/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:26:08 by nadjemia          #+#    #+#             */
/*   Updated: 2024/01/19 15:26:42 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include <math.h>

typedef struct z_s	z_t;
typedef struct data_s	data_t; 

z_t		fonction_julia(z_t z);
z_t		carre_i(z_t z);
void	print_i(z_t z);

typedef struct	z_s
{
	double	reel;
	double	imaginaire;
}	z_t;

typedef struct data_s
{
	void	*mlx_ptr;
	void	*win_ptr;
}	data_t;

#endif
