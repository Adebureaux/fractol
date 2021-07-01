/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:33:47 by adeburea          #+#    #+#             */
/*   Updated: 2021/07/01 03:07:24 by adeburea         ###   ########.fr       */
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
		exit_frac(1, NULL);
	start_mlx(&frac, &mlx);
	if (ac > 2 && ft_isdigit(av[2][0]))
		frac.frame = ft_atoi(av[2]);
	else
		frac.frame = 500;
	if (!ft_strcmp(av[1], "julia"))
		julia(&frac, &mlx);
	else
		mandelbrot(&frac, &mlx);
}
