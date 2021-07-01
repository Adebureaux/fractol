/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:33:47 by adeburea          #+#    #+#             */
/*   Updated: 2021/07/01 17:32:32 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	print_frac(t_frac *frac)
{
	printf(GREEN"------------------------------------------------\n"RESET);
	printf("X POS : %f\n", frac->movex);
	printf("Y POS : %f\n", frac->movey);
	printf("ZOOM  : %f\n", frac->zoom);
	printf("ITER  : %d\n", frac->maxi);
	printf(GREEN"------------------------------------------------\n"RESET);
	printf("Scroll to zoom-in and zoom-out\n");
	printf("Use spacebar to move forward\n");
	printf("Use arrow or click to move axis\n");
	printf("Use + or - to change the number of iterations\n");
	printf(GREEN"------------------------------------------------\n\n"RESET);
}

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
	printf(GREEN"------------------------------------------------\n"RESET);
	printf("Press h to get info\n");
	printf("Scroll to zoom-in and zoom-out\n");
	printf("Use spacebar to move forward\n");
	printf("Use arrow or left-click to move axis\n");
	printf("Use + or - to change the number of iterations\n");
	printf(GREEN"------------------------------------------------\n\n"RESET);
	if (!ft_strcmp(av[1], "julia"))
		julia(&frac, &mlx);
	else
		mandelbrot(&frac, &mlx);
}
