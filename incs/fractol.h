/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:38:42 by adeburea          #+#    #+#             */
/*   Updated: 2021/06/29 20:54:29 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include "../libmlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"

# define ESCAPE 65307

typedef struct s_rgb	t_rgb;
struct			s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	p;
	unsigned char	q;
	unsigned char	t;
	unsigned char	region;
	unsigned int	remain;
};

typedef struct s_mlx	t_mlx;
struct			s_mlx
{
	void		*frac;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			len;
	int			endian;
	int			rx;
	int			ry;
};

typedef struct s_frac	t_frac;
struct			s_frac
{
	double	cre;
	double	cim;
	double	newre;
	double	newim;
	double	oldre;
	double	oldim;
	double	zoom;
	double	movex;
	double	movey;
	int		color;
	int		maxi;
};

void	julia(t_frac *frac, t_mlx *mlx);
void	mandelbrot(t_frac *frac, t_mlx *mlx);

void	exit_frac(int status, t_frac *frac, char *err);
int		exit_mlx(t_mlx *mlx);
int		exit_mlx_error(t_mlx *mlx, char *err);
int		key_escape(int keycode, t_mlx *mlx);

int		hsv_to_rgb(unsigned int h, unsigned int s, unsigned int v);

void	mlx_pixel_draw(t_mlx *mlx, int x, int y, int color);
void	start_mlx(t_frac *frac, t_mlx *mlx);

#endif
