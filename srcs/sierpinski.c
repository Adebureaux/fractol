/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:47:42 by adeburea          #+#    #+#             */
/*   Updated: 2021/07/01 18:15:45 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	sierpinski_draw(t_frac *frac, t_mlx *mlx)
{
	int	x;
	int	y;

	(void)frac;
	y = -1;
	while (++y < mlx->ry)
	{
		x = -1;
		while (++x < mlx->rx)
		{
			frac->color = (hsv_to_rgb(x % 256, 255, 255));
			if (!((x / 1) % 3 == 1 && (y / 1) % 3 == 1)
				&& !((x / 3) % 3 == 1 && (y / 3) % 3 == 1)
				&& !((x / 9) % 3 == 1 && (y / 9) % 3 == 1)
				&& !((x / 27) % 3 == 1 && (y / 27) % 3 == 1)
				&& !((x / 81) % 3 == 1 && (y / 81) % 3 == 1))
				mlx_pixel_draw(mlx, x, y, frac->color);
		}
	}
}

void	sierpinski(t_mlx *mlx)
{
	mlx->draw = &sierpinski_draw;
	hook(mlx);
}
