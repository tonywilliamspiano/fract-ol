/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:28:04 by awilliam          #+#    #+#             */
/*   Updated: 2022/12/21 11:27:02 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_rev_memcpy(void *dst, const void *src, int n);

void	*ft_memmove(void *dst, const void *src, int n)
{
	if (!src && !dst)
		return (0);
	if (n == 0)
		return (dst);
	if (dst < src)
		dst = ft_memcpy(dst, src, n);
	else
		dst = ft_rev_memcpy(dst, src, n);
	return (dst);
}

static void	*ft_rev_memcpy(void *dst, const void *src, int n)
{
	char	*p_src;
	char	*p_dst;

	p_src = (char *)src;
	p_dst = (char *)dst;
	while (n > 0)
	{
		*(p_dst + n - 1) = *(p_src + n - 1);
		n--;
	}
	return (p_dst);
}
