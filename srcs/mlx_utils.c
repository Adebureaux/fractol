/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:18:55 by adeburea          #+#    #+#             */
/*   Updated: 2021/07/01 03:53:04 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	start_mlx(t_frac *frac, t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->frac = frac;
	mlx_get_screen_size(mlx->mlx, &mlx->rx, &mlx->ry);
	if (mlx->rx > 1200)
		mlx->rx -= 600;
	mlx->win = mlx_new_window(mlx->mlx, mlx->rx, mlx->ry, "fractol");
	mlx->img = mlx_new_image(mlx->mlx, mlx->rx, mlx->ry);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->len, &mlx->endian);
}

void	print_frac(t_frac *frac)
{
	printf(GREEN"------------------------------------------------\n"RESET);
	printf("X POS : %f\n", frac->movex);
	printf("Y POS : %f\n", frac->movey);
	printf("ZOOM  : %f\n", frac->zoom);
	printf("ITER  : %d\n", frac->maxi);
	printf(GREEN"------------------------------------------------\n"RESET);
	printf("Click or scroll to zoom-in and zoom-out\n");
	printf("Use arrow to move axis\n");
	printf("Use + or - to change the number of iterations\n");
	printf(GREEN"------------------------------------------------\n\n"RESET);
}

int		redraw(t_mlx *mlx)
{
	t_mlx	tmp;

	mlx_destroy_image(mlx->mlx, mlx->img);
	tmp.img = mlx_new_image(mlx->mlx, mlx->rx, mlx->ry);
	tmp.addr = mlx_get_data_addr(tmp.img, &tmp.bpp, &tmp.len, &tmp.endian);
	tmp.rx = mlx->rx;
	tmp.ry = mlx->ry;
	mlx->draw(mlx->frac, &tmp);
	mlx->img = tmp.img;
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (1);
}

void	mlx_pixel_draw(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->len + x * (mlx->bpp / 8));
	*(unsigned int *)dst = color;
}
