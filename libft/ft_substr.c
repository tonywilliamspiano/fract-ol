/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:27:01 by awilliam          #+#    #+#             */
/*   Updated: 2022/12/21 11:32:08 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;

	if ((start > (unsigned long)ft_strlen(s)) || !(*s))
	{
		dst = malloc(1);
		if (dst == NULL)
			return (0);
		dst[0] = 0;
		return (dst);
	}
	s = &s[start];
	if ((unsigned long)ft_strlen(s) < len)
		len = ft_strlen(s);
	dst = malloc(len + 1);
	if (dst == NULL)
		return (0);
	ft_strlcpy(dst, s, len + 1);
	return (dst);
}
