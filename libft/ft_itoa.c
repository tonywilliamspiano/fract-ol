/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:41:11 by awilliam          #+#    #+#             */
/*   Updated: 2022/12/21 14:56:52 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		recursive(char	*str, int nb, int counter);
static int		get_length(int n);

char	*ft_itoa(int n)
{	
	char	*result;
	char	*ptr;
	int		len;
	int		neg;

	if (n >= 0)
		neg = 0;
	else
		neg = 1;
	len = get_length(n);
	result = malloc(len + neg + 1);
	if (result == NULL)
		return (0);
	result[len + neg] = 0;
	ft_bzero(result, len + neg);
	ptr = result;
	if (n < 0)
	{
		ptr[0] = '-';
		ptr++;
	}
	recursive(ptr, n, 0);
	return (result);
}

static int	get_length(int n)
{
	int			len;

	len = 1;
	while (n / 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	recursive(char	*str, int nb, int counter)
{
	char	c;

	if (nb > 9 || nb < -9)
		counter = recursive(str, nb / 10, counter);
	if (nb >= 0)
		c = nb % 10;
	else
		c = (nb % 10) * -1;
	str[counter] = c + '0';
	counter++;
	return (counter);
}
