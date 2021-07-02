/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:19:42 by adeburea          #+#    #+#             */
/*   Updated: 2021/07/02 14:48:59 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	free_frac(t_frac *frac)
{
	if (frac)
		free(frac);
}

void	exit_frac(int status, t_frac *frac)
{
	if (frac)
		free_frac(NULL);
	if (status)
	{
		printf(RED"error: invalid parameter'\n"RESET);
		printf(RED"1st arg: 'julia', 'mandelbrot', 'sierpinski'\n"RESET);
		printf(RED"2nd arg: 'int' (SPEED)\n"RESET);
	}
	else
		printf(GREEN"fractol exited properly\n"RESET);
	exit(status);
}

int	exit_mlx(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	mlx->mlx = NULL;
	exit_frac(EXIT_SUCCESS, mlx->frac);
	return (1);
}

int	exit_mlx_error(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	mlx->mlx = NULL;
	exit_frac(EXIT_FAILURE, mlx->frac);
	return (1);
}
