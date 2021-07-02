/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:34:58 by adeburea          #+#    #+#             */
/*   Updated: 2021/07/02 14:48:18 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	julia_calc(t_frac *frac)
{
	int	i;

	i = -1;
	while (++i < frac->maxi)
	{
		frac->oldre = frac->newre;
		frac->oldim = frac->newim;
		frac->newre = frac->oldre * frac->oldre
			- frac->oldim * frac->oldim + frac->cre;
		frac->newim = 2 * frac->oldre * frac->oldim + frac->cim;
		if ((frac->newre * frac->newre + frac->newim * frac->newim) > 4)
			break ;
	}
	return (i);
}

void	julia_draw(t_frac *frac, t_mlx *mlx)
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
			frac->newre = 1.5 * (x - mlx->rx / 2)
				/ (0.5 * frac->zoom * mlx->rx) + frac->movex;
			frac->newim = (y - mlx->ry / 2)
				/ (0.5 * frac->zoom * mlx->ry) + frac->movey;
			i = julia_calc(frac);
			frac->color = (hsv_to_rgb(i % 256, 255, 255 * (i < frac->maxi)));
			mlx_pixel_draw(mlx, x, y, frac->color);
		}
	}
}

void	julia(t_frac *frac, t_mlx *mlx)
{
	frac->maxi = 128;
	frac->cre = -0.7;
	frac->cim = 0.27015;
	frac->zoom = 0.8;
	frac->movex = 0;
	frac->movey = 0;
	mlx->draw = &julia_draw;
	hook(mlx);
}
