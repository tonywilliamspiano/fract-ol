/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:41:11 by awilliam          #+#    #+#             */
/*   Updated: 2023/02/21 10:21:10 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	recursive(unsigned long long nb, unsigned int len, const char *b);

int	ft_putnbr_b(unsigned long long n, const char *b)
{
	unsigned int	len;

	len = (unsigned int)ft_strlen(b);
	return (recursive(n, len, b));
}

static int	recursive(unsigned long long nb, unsigned int len, const char *b)
{
	unsigned int	index;
	int				i;

	i = 0;
	if (nb > len - 1)
		i = recursive(nb / len, len, b);
	index = nb % len;
	write(1, (b + index), 1);
	i++;
	return (i);
}
