/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:47:42 by adeburea          #+#    #+#             */
/*   Updated: 2021/07/01 17:50:11 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	mandelbrot_calc(t_frac *frac)
{
	int	i;

	i = -1;
	while (++i < frac->maxi)
	{
		frac->oldre = frac->newre;
		frac->oldim = frac->newim;
		frac->newre = frac->oldre * frac->oldre
			- frac->oldim * frac->oldim + frac->pr;
		frac->newim = 2 * frac->oldre * frac->oldim + frac->pi;
		if ((frac->newre * frac->newre + frac->newim * frac->newim) > 4)
			break ;
	}
	return (i);
}

void	mandelbrot_draw(t_frac *frac, t_mlx *mlx)
{
	int	x;
	int	y;

	y = -1;
	while (++y < mlx->ry)
	{
		x = -1;
		while (++x < mlx->rx)
		{
			if
		    (
		      //Not both the first (rightmost) digits are '1' in base 3
		      !(
		           (x / 1) % 3 == 1
		        && (y / 1) % 3 == 1
		      )

		      &&

		      //Not both the second digits are '1' in base 3
		      !(
		           (x / 3) % 3 == 1
		        && (y / 3) % 3 == 1
		      )

		      &&

		      //Not both the third digits are '1' in base 3
		      !(
		           (x / 9) % 3 == 1
		        && (y / 9) % 3 == 1
		      )

		      &&

		      //Not both the fourth digits are '1' in base 3
		      !(
		           (x / 27) % 3 == 1
		        && (y / 27) % 3 == 1
		      )

		      &&

		      //Not both the fifth digits are '1' in base 3
		      !(
		           (x / 81) % 3 == 1
		        && (y / 81) % 3 == 1
		      )
		    )
			frac->color = (hsv_to_rgb(x % 256, 255, 255 * (y < frac->maxi)));
			mlx_pixel_draw(mlx, x, y, frac->color);
		}
	}
}

void	sierpinski(t_frac *frac, t_mlx *mlx)
{
	frac->maxi = 128;
	frac->zoom = 0.8;
	frac->movex = -0.5;
	frac->movey = 0;
	mlx->draw = &sierpinski_draw;
	hook(mlx);
}
