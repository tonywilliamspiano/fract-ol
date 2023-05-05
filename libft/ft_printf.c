/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:16:37 by awilliam          #+#    #+#             */
/*   Updated: 2023/02/21 10:20:01 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	lst;

	len = 0;
	va_start(lst, str);
	while (*str)
	{
		if (*str == '%' && ft_strchr("cspdiuxX%", *(str + 1)))
		{	
			str++;
			len += ft_conv_cases(lst, *str);
		}
		else
		{
			write(1, str, 1);
			len++;
		}
		str++;
	}
	va_end(lst);
	return (len);
}
