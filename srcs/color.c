/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:10:35 by adeburea          #+#    #+#             */
/*   Updated: 2021/06/29 20:43:32 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	fill_rgb(t_rgb *rgb, unsigned int r, unsigned int g, unsigned int b)
{
	rgb->r = r;
	rgb->g = g;
	rgb->b = b;
}

int	hsv_to_rgb(unsigned int h, unsigned int s, unsigned int v)
{
	t_rgb	rgb;

	rgb.region = h / 43;
	rgb.remain = (h - (rgb.region * 43)) * 6;
	rgb.p = (v * (255 - s)) >> 8;
	rgb.q = (v * (255 - ((s * rgb.remain) >> 8))) >> 8;
	rgb.t = (v * (255 - ((s * (255 - rgb.remain)) >> 8))) >> 8;
	if (rgb.region == 0)
		fill_rgb(&rgb, v, rgb.t, rgb.p);
	else if (rgb.region == 1)
		fill_rgb(&rgb, rgb.q, v, rgb.p);
	else if (rgb.region == 2)
		fill_rgb(&rgb, rgb.p, v, rgb.t);
	else if (rgb.region == 3)
		fill_rgb(&rgb, rgb.p, rgb.q, v);
	else if (rgb.region == 4)
		fill_rgb(&rgb, rgb.t, rgb.p, v);
	else
		fill_rgb(&rgb, v, rgb.p, rgb.q);
	return (rgb.r << 16 | rgb.g << 8 | rgb.b);
}
