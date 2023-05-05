/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:51:14 by awilliam          #+#    #+#             */
/*   Updated: 2022/12/21 12:04:54 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *str, int c, int n)
{
	unsigned char	*p_str;
	int				i;

	if (n == 0)
		return (NULL);
	i = 0;
	p_str = (unsigned char *)str;
	while (i < n)
	{
		if ((unsigned char)*(p_str + i) == (unsigned char)c)
			return (str + i);
		i++;
	}
	return (0);
}
