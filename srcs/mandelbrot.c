/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:18:55 by adeburea          #+#    #+#             */
/*   Updated: 2021/06/29 21:10:19 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	hook_mandelbrot(t_mlx *mlx)
{
	t_mlx	tmp;

	mlx_destroy_image(mlx->mlx, mlx->img);
	tmp.img = mlx_new_image(mlx->mlx, mlx->rx, mlx->ry);
	tmp.addr = mlx_get_data_addr(tmp.img, &tmp.bpp, &tmp.len, &tmp.endian);
	mlx->img = tmp.img;
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (1);
}

void	mandelbrot(t_frac *frac, t_mlx *mlx)
{
	(void)frac;
	mlx_hook(mlx->win, 33, 1L << 17, exit_mlx, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, key_escape, mlx);
	mlx_loop_hook(mlx->mlx, hook_mandelbrot, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_loop(mlx->mlx);
}
