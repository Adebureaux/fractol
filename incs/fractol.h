/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:38:42 by adeburea          #+#    #+#             */
/*   Updated: 2021/06/25 16:03:25 by adeburea         ###   ########.fr       */
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
# define MOVE_UP 119
# define MOVE_LEFT 97
# define MOVE_DOWN 115
# define MOVE_RIGHT 100
# define LEFT 65361
# define RIGHT 65363
# define ESCAPE 65307
# define MOV_S 0.12
# define ROT_S 0.035
# define TEX_W 64
# define TEX_H 64

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
};

typedef struct s_frac t_frac;
struct			s_frac
{
	void		*ptr;
	int			res_x;
	int			res_y;
};


#endif
