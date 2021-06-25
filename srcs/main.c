/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:33:47 by adeburea          #+#    #+#             */
/*   Updated: 2021/06/25 16:02:48 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	free_frac(t_frac *frac)
{
	if (frac)
		free(frac->ptr);
}

void	exit_frac(int status, t_frac *frac, char *err)
{
	free_frac(frac);
	if (status)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(err, 2);
	}
	else
		ft_putstr_fd("Cub3d exited properly\n", 1);
	exit(status);
}

int		main(int ac, char **av)
{
	t_frac	frac;
	t_mlx	mlx;

	if (ac < 2)
		exit_frac(EXIT_FAILURE, NULL, "Wrong number of arguments\n");
	if (ft_strcmp(av[1], "julia"))
		julia(&frac, &mlx);
	// else if (ft_strcmp(ft_toupper(av[1]), "MANDELBROT"))
	// 	madelbrot();
	exit_frac(EXIT_SUCCESS, NULL, NULL);
}
