/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:33:47 by adeburea          #+#    #+#             */
/*   Updated: 2021/07/01 18:13:47 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	print_help(void)
{
	printf(GREEN"------------------------------------------------\n"RESET);
	printf("Scroll to zoom-in and zoom-out\n");
	printf("Use spacebar to move forward\n");
	printf("Use arrow or click to move axis\n");
	printf("Use + or - to change the number of iterations\n");
	printf(GREEN"------------------------------------------------\n\n"RESET);
}

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

	if (ac < 2 || (ft_strcmp(av[1], "julia") && ft_strcmp(av[1], "mandelbrot")
			&& ft_strcmp(av[1], "sierpinski")))
		exit_frac(EXIT_FAILURE, NULL);
	start_mlx(&frac, &mlx);
	if (ac > 2 && ft_isdigit(av[2][0]))
		frac.frame = ft_atoi(av[2]);
	else
		frac.frame = 500;
	print_help();
	if (!ft_strcmp(av[1], "julia"))
		julia(&frac, &mlx);
	else if (!ft_strcmp(av[1], "mandelbrot"))
		mandelbrot(&frac, &mlx);
	else
		sierpinski(&mlx);
}
