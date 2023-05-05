/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 10:22:35 by awilliam          #+#    #+#             */
/*   Updated: 2023/02/21 10:44:20 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_conv_cases_helper(va_list lst, char which);

int	ft_conv_cases(va_list lst, char which)
{
	int		len;

	if (which == 'i' || which == 'd')
		len = ft_putnbr_ret(va_arg(lst, int), 1);
	else if (which == '%')
		len = ft_putstr("%", 1);
	else if (which == 's')
		len = ft_putstr(va_arg(lst, char *), 1);
	else if (which == 'x')
		len = ft_putnbr_b(va_arg(lst, unsigned int), "0123456789abcdef");
	else if (which == 'X')
		len = ft_putnbr_b(va_arg(lst, unsigned int), "0123456789ABCDEF");
	else if (which == 'u')
		len = ft_putnbr_b(va_arg(lst, unsigned int), "0123456789");
	else if (which == 'p')
	{
		len = ft_putstr("0x", 1);
		len += ft_putnbr_b(va_arg(lst, unsigned long long), "0123456789abcdef");
	}
	else
		return (ft_conv_cases_helper(lst, which));
	return (len);
}

static int	ft_conv_cases_helper(va_list lst, char which)
{
	char	c;

	if (which == 'c')
	{
		c = va_arg(lst, int);
		write (1, &c, 1);
		return (1);
	}
	else
		return (0);
}
