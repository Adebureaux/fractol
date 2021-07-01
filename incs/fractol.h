/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:38:42 by adeburea          #+#    #+#             */
/*   Updated: 2021/07/01 17:33:03 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include "../libmlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define ESCAPE 65307
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363
# define PLUS 65451
# define MINUS 65453
# define SPACE 32
# define HELP 104

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

typedef struct s_frac	t_frac;
struct			s_frac
{
	double	pr;
	double	pi;
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
	int		frame;
	int		maxi;
};

typedef struct s_mlx	t_mlx;
struct			s_mlx
{
	void		(*draw)(t_frac *, t_mlx *);
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

void			julia(t_frac *frac, t_mlx *mlx);
void			mandelbrot(t_frac *frac, t_mlx *mlx);
void			print_frac(t_frac *frac);
void			exit_frac(int status, t_frac *frac);
int				exit_mlx(t_mlx *mlx);
int				hsv_to_rgb(unsigned int h, unsigned int s, unsigned int v);
void			start_mlx(t_frac *frac, t_mlx *mlx);
int				redraw(t_mlx *mlx);
void			mlx_pixel_draw(t_mlx *mlx, int x, int y, int color);
void			hook(t_mlx *mlx);

#endif
