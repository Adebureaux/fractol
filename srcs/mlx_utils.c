/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:18:55 by adeburea          #+#    #+#             */
/*   Updated: 2021/06/29 21:10:35 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	mlx_pixel_draw(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->len + x * (mlx->bpp / 8));
	*(unsigned int *)dst = color;
}

void	start_mlx(t_frac *frac, t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->frac = frac;
	mlx_get_screen_size(mlx->mlx, &mlx->rx, &mlx->ry);
	mlx->win = mlx_new_window(mlx->mlx, mlx->rx, mlx->ry, "fractol");
	mlx->img = mlx_new_image(mlx->mlx, mlx->rx, mlx->ry);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->len, &mlx->endian);
}
