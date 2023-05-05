/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ret.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:51:50 by awilliam          #+#    #+#             */
/*   Updated: 2023/02/21 10:21:15 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	recursive_print(int nb, int fd);

int	ft_putnbr_ret(int n, int fd)
{
	int	ret;

	ret = 0;
	if (n < 0)
	{
		ret += 1;
		write (fd, "-", 1);
	}
	ret += recursive_print(n, fd);
	return (ret);
}

static int	recursive_print(int nb, int fd)
{
	char		c;
	int			len;

	len = 0;
	if (nb > 9 || nb < -9)
		len = recursive_print(nb / 10, fd);
	if (nb >= 0)
		c = nb % 10;
	else
		c = (nb % 10) * -1;
	c = c + '0';
	write(fd, &c, 1);
	len++;
	return (len);
}
