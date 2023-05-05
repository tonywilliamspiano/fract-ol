/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:51:50 by awilliam          #+#    #+#             */
/*   Updated: 2022/12/21 14:58:41 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursive_print(int nb, int fd);

void	ft_putnbr_fd(int n, int fd)
{	
	if (n < 0)
		write (fd, "-", 1);
	recursive_print(n, fd);
	return ;
}

static void	recursive_print(int nb, int fd)
{
	char	c;

	if (nb > 9 || nb < -9)
		recursive_print(nb / 10, fd);
	if (nb >= 0)
		c = nb % 10;
	else
		c = (nb % 10) * -1;
	c = c + '0';
	write(fd, &c, 1);
	return ;
}
