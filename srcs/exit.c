/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:19:42 by adeburea          #+#    #+#             */
/*   Updated: 2021/06/29 21:09:52 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	free_frac(t_frac *frac)
{
	if (frac)
		free(frac);
}

void	exit_frac(int status, t_frac *frac, char *err)
{
	if (frac)
		free_frac(NULL);
	if (status)
		printf(RED"error: %s\n"RESET, err);
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
	exit_frac(EXIT_SUCCESS, mlx->frac, NULL);
	return (1);
}

int	exit_mlx_error(t_mlx *mlx, char *err)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	mlx->mlx = NULL;
	exit_frac(EXIT_FAILURE, mlx->frac, err);
	return (1);
}

int	key_escape(int keycode, t_mlx *mlx)
{
	if (keycode == ESCAPE)
		exit_mlx(mlx);
	return (1);
}
