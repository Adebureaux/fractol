/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:09:49 by adeburea          #+#    #+#             */
/*   Updated: 2021/06/24 13:01:21 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		c;
	long int	lgi;

	lgi = n;
	if (lgi < 0)
	{
		write(fd, "-", 1);
		lgi = -lgi;
	}
	if (lgi >= 10)
	{
		ft_putnbr_fd(lgi / 10, fd);
		ft_putnbr_fd(lgi % 10, fd);
	}
	else
	{
		c = lgi + '0';
		write(fd, &c, 1);
	}
}
