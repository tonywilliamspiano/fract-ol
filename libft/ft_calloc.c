/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:02:27 by awilliam          #+#    #+#             */
/*   Updated: 2022/12/22 10:41:53 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;
	size_t	x;

	x = count * size;
	if (x / count != size)
		return (0);
	arr = malloc(count * size);
	if (arr == NULL)
		return (0);
	ft_bzero(arr, count * size);
	return (arr);
}
