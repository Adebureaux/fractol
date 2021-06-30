/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 00:02:37 by adeburea          #+#    #+#             */
/*   Updated: 2021/06/30 16:35:24 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	mouse_press(int mousecode, int x, int y, t_mlx *mlx)
{
	t_frac	*frac;

	frac = mlx->frac;
	if (mousecode == 4 || mousecode == 1)
	{
		if (x < mlx->rx / 2)
		{
			frac->movex -= 0.0003 * x;
			frac->movey += 0.0003 * y;
		}
		else
		{
			frac->movex += 0.0003 * x;
			frac->movey -= 0.0003 * y;
		}
		frac->zoom *= pow(1.001, frac->frame);
		frac->maxi++;
	}
	else if (mousecode == 5 || mousecode == 2)
	{
		frac->movex += 0.0003 * x;
		frac->movey -= 0.0003 * y;
		frac->zoom /= pow(1.001, frac->frame);
		frac->maxi--;
	}
	return (x + y);
}

int	key_press(int keycode, t_mlx *mlx)
{
	t_frac	*frac;

	frac = mlx->frac;
	if (keycode == ESCAPE)
		exit_mlx(mlx);
	else if (keycode == UP)
		frac->movey -= 0.0003 * frac->frame / frac->zoom;
	else if (keycode == LEFT)
		frac->movex -= 0.0003 * frac->frame / frac->zoom;
	else if (keycode == RIGHT)
		frac->movex += 0.0003 * frac->frame / frac->zoom;
	else if (keycode == DOWN)
		frac->movey += 0.0003 * frac->frame / frac->zoom;
	return (1);
}

void	hook(t_mlx *mlx)
{
	mlx_hook(mlx->win, 33, 1L << 17, exit_mlx, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, key_press, mlx);
	mlx_mouse_hook(mlx->win, mouse_press, mlx);
	mlx_loop_hook(mlx->mlx, redraw, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_loop(mlx->mlx);
}
