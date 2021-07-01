/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 00:02:37 by adeburea          #+#    #+#             */
/*   Updated: 2021/07/01 04:14:31 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int		mouse_press(int mousecode, int x, int y, t_mlx *mlx)
{
	t_frac	*frac;

	frac = mlx->frac;
	if (mousecode == 4 || mousecode == 1)
	{
		frac->zoom *= pow(1.001, frac->frame);
		if (x < mlx->rx / 2)
			frac->movex -= 0.0003 * x / frac->zoom;
		else
			frac->movex += 0.0003 * x / frac->zoom;
		if (y < mlx->ry / 2)
			frac->movey -= 0.0003 * y * 2 / frac->zoom;
		else
			frac->movey += 0.0003 * y * 2 / frac->zoom;
	}
	else if (mousecode == 5 || mousecode == 3)
		frac->zoom /= pow(1.001, frac->frame);
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
	else if (keycode == PLUS)
		frac->maxi *= 2;
	else if (keycode == MINUS && frac->maxi > 2)
		frac->maxi /= 2;
	else if (keycode == HELP)
		print_frac(frac);

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
