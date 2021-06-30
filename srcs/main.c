/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:33:47 by adeburea          #+#    #+#             */
/*   Updated: 2021/06/30 16:30:50 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	main(int ac, char **av)
{
	t_frac	frac;
	t_mlx	mlx;
	char	err[44];

	ft_strcpy(err, "valid parameter are 'julia' or 'mandelbrot'");
	if (ac < 2 || (ft_strcmp(av[1], "julia") && ft_strcmp(av[1], "mandelbrot")))
		exit_frac(1, NULL, "valid parameter are 'julia' or 'mandelbrot'");
	start_mlx(&frac, &mlx);
	if (ac > 2)
		frac.maxi = ft_atoi(av[2]);
	if (!ft_strcmp(av[1], "julia"))
		julia(&frac, &mlx);
	else
		mandelbrot(&frac, &mlx);
}
