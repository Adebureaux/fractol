/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:18:55 by adeburea          #+#    #+#             */
/*   Updated: 2021/07/01 18:13:06 by adeburea         ###   ########.fr       */
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
	int	i;
	int	x;
	int	y;

	y = -1;
	while (++y < mlx->ry)
	{
		x = -1;
		while (++x < mlx->rx)
		{
			frac->pr = 1.5 * (x - mlx->rx / 2)
				/ (0.5 * frac->zoom * mlx->rx) + frac->movex;
			frac->pi = (y - mlx->ry / 2)
				/ (0.5 * frac->zoom * mlx->ry) + frac->movey;
			frac->newre = 0;
			frac->newim = 0;
			frac->oldre = 0;
			frac->oldim = 0;
			i = mandelbrot_calc(frac);
			frac->color = (hsv_to_rgb(i % 256, 255, 255 * (i < frac->maxi)));
			mlx_pixel_draw(mlx, x, y, frac->color);
		}
	}
}

void	mandelbrot(t_frac *frac, t_mlx *mlx)
{
	frac->maxi = 128;
	frac->zoom = 0.8;
	frac->movex = -0.5;
	frac->movey = 0;
	mlx->draw = &mandelbrot_draw;
	hook(mlx);
}
