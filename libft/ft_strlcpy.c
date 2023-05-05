/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:05:13 by awilliam          #+#    #+#             */
/*   Updated: 2022/12/15 10:58:49 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	counter;

	counter = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[counter] != '\0' && counter < size)
	{
		dest[counter] = src[counter];
		counter++;
	}
	if (counter == 0 || counter < size)
		counter++;
	dest[counter - 1] = '\0';
	return (ft_strlen(src));
}
